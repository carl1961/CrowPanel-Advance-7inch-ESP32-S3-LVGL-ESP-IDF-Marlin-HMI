#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "lvgl.h"
#include "display/esp32_s3.h"
#include "ui/ui.h"
#include "ui/screens.h"
#include "stc8h1k28.h"
#include "driver/uart.h"
#include <math.h>
#include "driver/gpio.h"

extern "C" {
#include "hmi_ui_sync.h"
}

#define MARLIN_UART_NUM      UART_NUM_1
#define MARLIN_TX_PIN        GPIO_NUM_20
#define MARLIN_RX_PIN        GPIO_NUM_19
#define SERIAL_BUF_SIZE      1024
#define MAX_GCODE_LEN        64
#define COMMAND_QUEUE_LEN    20

#define LOG_QUEUE_LEN        64
#define LOG_LINE_MAX         512
#define MAX_FILES            50
#define FILE_NAME_LEN        64
#define SFM27_CTRL_GPIO GPIO_NUM_8
#define SFM27_BOOT_BEEP_MS      300
#define SFM27_M500_BEEP_MS      600

static const char *TAG = "MARLIN_HMI";


extern "C" void jog_reset_z_homed(const char *reason);
extern "C" void ui_show_save_eeprom_prompt(const char *reason);
extern "C" void jog_screen_set_status(const char *msg);
extern "C" void filament_screen_update_temps(float current_t, float target_t);

static bool s_g34_running = false;
static bool s_g29_running = false;
static bool s_homing_active = false;
static TickType_t s_homing_started_tick = 0;
static stc8h1k28_handle_t stc8 = NULL;

static bool s_m500_pending = false;

/*
static void buzzer_long_beep_task(void *arg) {
    (void)arg;
    if (stc8 != NULL) {
        stc8h1k28_buzzer_on(stc8);
        vTaskDelay(pdMS_TO_TICKS(600));
        stc8h1k28_buzzer_off(stc8);
    }
    vTaskDelete(NULL);
}

static void trigger_m500_success_beep(void) {
    if (stc8 == NULL) return;
    xTaskCreate(buzzer_long_beep_task, "beep500", 1536, NULL, 2, NULL);
}
*/
static void update_file_browser_ui(void);
static float pos_x = 0.0f, pos_y = 0.0f, pos_z = 0.0f;

static bool s_printing = false;
static int64_t s_start_us = 0;

static bool s_is_paused = false;

// Temperature & heating state tracking for M105 polling during heat-up

static float s_nozzle_current = 0.0f;
static float s_nozzle_target  = 0.0f;
static float s_bed_current    = 0.0f;
static float s_bed_target     = 0.0f;
static bool s_heating_active  = false;
static uint8_t s_m27_busy_backoff = 0;
static bool s_boot_usb_synced = false;

static bool is_heating(void) {
    if (s_heating_active) {
        return true;
    }
    const float margin = 3.0f;
    bool nozzle_heating = (s_nozzle_target > 30.0f) && (s_nozzle_current < s_nozzle_target - margin);
    bool bed_heating    = (s_bed_target    > 30.0f) && (s_bed_current    < s_bed_target    - margin);
    return nozzle_heating || bed_heating;
}

static void record_outbound_temp_cmd(const char *command) {
    if (!command) return;

    const char *s_param = strstr(command, "S");
    float val = s_param ? strtof(s_param + 1, NULL) : 0.0f;

    if (strncmp(command, "M104", 4) == 0) {
        s_nozzle_target = val;
        if (val <= 1.0f) {
            s_heating_active = false;
        }
    } else if (strncmp(command, "M109", 4) == 0) {
        s_nozzle_target = val;
        if (val > 30.0f) {
            s_heating_active = true;
        }
    } else if (strncmp(command, "M140", 4) == 0) {
        s_bed_target = val;
        if (val <= 1.0f) {
            s_heating_active = false;
        }
    } else if (strncmp(command, "M190", 4) == 0) {
        s_bed_target = val;
        if (val > 30.0f) {
            s_heating_active = true;
        }
    }
}

// ─── Types ───────────────────────────────────────────────────────────────────

typedef struct {
    char line[LOG_LINE_MAX];
} log_item_t;

// ─── Globals ─────────────────────────────────────────────────────────────────

QueueHandle_t log_queue = NULL;
QueueHandle_t marlin_cmd_queue = NULL;

bool marlin_connected = false;
bool isPrinting = false;
uint32_t last_marlin_reply_ms = 0;

// M20 file list state
static char file_list[MAX_FILES][FILE_NAME_LEN];
extern "C" {
    int file_count = 0;
}
static bool capturing_files = false;


// Print progress state
static uint32_t print_bytes_current = 0;
static uint32_t print_bytes_total = 0;
static char current_job[FILE_NAME_LEN] = {0};
static char pending_filename[FILE_NAME_LEN] = {0};
static lv_obj_t *modal_overlay = NULL;

// ─── Forward declarations ────────────────────────────────────────────────────
extern "C" void update_clock_labels_timer(lv_timer_t *timer);
void parse_marlin_line(const char *line);

// ─── Log queue ───────────────────────────────────────────────────────────────
void log_queue_init(void) {
    log_queue = xQueueCreate(LOG_QUEUE_LEN, sizeof(log_item_t));
}

void append_print_log(const char *line) {
    if (log_queue == NULL || line == NULL) return;
    log_item_t item;
    snprintf(item.line, LOG_LINE_MAX, "%s", line);
    xQueueSend(log_queue, &item, 0);
}

void ui_set_print_active(bool active) {
    if (active && !s_printing) {
        s_printing = true;
        s_start_us = esp_timer_get_time();
    } else if (!active) {
        s_printing = false;
    }
}

void ui_update_print_times(uint32_t cur_bytes, uint32_t total_bytes) {
    if (!s_printing || total_bytes == 0) {
        if (objects.time_elapsed) {
            lv_label_set_text(objects.time_elapsed, "0h 00m");
        }
        if (objects.time_remaining) {
            lv_label_set_text(objects.time_remaining, "--");
        }
        return;
    }

    uint32_t elapsed_s = (uint32_t)((esp_timer_get_time() - s_start_us) / 1000000ULL);
    if (objects.time_elapsed) {
        lv_label_set_text_fmt(objects.time_elapsed, "%luh %02lum", elapsed_s / 3600U, (elapsed_s % 3600U) / 60U);
    }

    // Wait until at least 30s and 2% progress before estimating remaining time
    if (objects.time_remaining) {
        if (cur_bytes > 0 && cur_bytes < total_bytes && elapsed_s >= 30 && (cur_bytes * 50ULL) >= total_bytes) {
            uint64_t rem_s = ((uint64_t)elapsed_s * (total_bytes - cur_bytes)) / cur_bytes;
            lv_label_set_text_fmt(objects.time_remaining, "%luh %02lum", (uint32_t)(rem_s / 3600U), (uint32_t)((rem_s % 3600U) / 60U));
        } else if (cur_bytes >= total_bytes) {
            lv_label_set_text(objects.time_remaining, "0h 00m");
        } else {
            lv_label_set_text(objects.time_remaining, "--");
        }
    }
}

void ui_set_fan_pwm(uint8_t pwm) {
    int pct = ((int)pwm * 100 + 127) / 255;
    if (objects.fan_speed_slider_print_screen) {
        lv_slider_set_value(objects.fan_speed_slider_print_screen, pct, LV_ANIM_OFF);
    }
    if (objects.fan_speed_percentage) {
        lv_label_set_text_fmt(objects.fan_speed_percentage, "%d%%", pct);
    }
}

static void parse_fan_telemetry(const char *line) {
    if (!line) return;

    // Match "M106 ... S<0-255>" (e.g. "M106 S128" or "echo:M106 P0 S128")
    const char *m106 = strstr(line, "M106");
    if (m106) {
        const char *s_pos = strstr(m106, "S");
        if (s_pos) {
            int pwm = atoi(s_pos + 1);
            if (pwm < 0) pwm = 0;
            if (pwm > 255) pwm = 255;
            ui_set_fan_pwm((uint8_t)pwm);
            return;
        }
    }

    // Fallback for fan lines containing "<num>%"
    if (strstr(line, "fan") != NULL || strstr(line, "Fan") != NULL) {
        const char *pct_pos = strchr(line, '%');
        if (pct_pos && pct_pos > line) {
            const char *p = pct_pos - 1;
            while (p > line && ((*p >= '0' && *p <= '9') || *p == ' ')) {
                p--;
            }
            int pct = atoi(p);
            if (pct >= 0 && pct <= 100) {
                uint8_t pwm = (uint8_t)((pct * 255 + 50) / 100);
                ui_set_fan_pwm(pwm);
            }
        }
    }
}

// Buzzer SFM-27 DC: 3-24 V

// Set to your free GPIO wired through 1 kOhm to the 2N2222 base (with 10 kOhm to GND)
#ifndef SFM27_CTRL_GPIO
#define SFM27_CTRL_GPIO   GPIO_NUM_NC
#endif

#define SFM27_M500_BEEP_MS      600

static volatile bool s_sfm27_beep_running = false;

static void sfm27_gpio_init(void) {
    if (SFM27_CTRL_GPIO == GPIO_NUM_NC) {
        ESP_LOGW(TAG, "SFM-27 GPIO not set; skipping init");
        return;
    }

    gpio_config_t io_cfg = {
        .pin_bit_mask = (1ULL << SFM27_CTRL_GPIO),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };

    esp_err_t err = gpio_config(&io_cfg);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "SFM-27 gpio_config failed: %s", esp_err_to_name(err));
        return;
    }

    gpio_set_level(SFM27_CTRL_GPIO, 0);
}

static void sfm27_m500_beep_task(void *arg) {
    (void)arg;

    if (SFM27_CTRL_GPIO != GPIO_NUM_NC) {
        gpio_set_level(SFM27_CTRL_GPIO, 1);
        vTaskDelay(pdMS_TO_TICKS(SFM27_M500_BEEP_MS));
        gpio_set_level(SFM27_CTRL_GPIO, 0);
    }

    s_sfm27_beep_running = false;
    vTaskDelete(NULL);
}

static void trigger_m500_success_beep(void) {
    if (SFM27_CTRL_GPIO == GPIO_NUM_NC || s_sfm27_beep_running) {
        return;
    }

    s_sfm27_beep_running = true;
    BaseType_t ok = xTaskCreate(sfm27_m500_beep_task, "sfm27_m500", 2048, NULL, 2, NULL);
    if (ok != pdPASS) {
        s_sfm27_beep_running = false;
        ESP_LOGW(TAG, "Failed to create sfm27_m500 task");
    }
}

// ─── G-code send ─────────────────────────────────────────────────────────────

extern "C" void send_gcode(const char *command) {
    if (!command || command[0] == '\0') return;
    record_outbound_temp_cmd(command);

	if (strncmp(command, "M500", 4) == 0) {
		s_m500_pending = true;
	}

    if (strncmp(command, "G28", 3) == 0) {
        s_homing_active = true;
        s_homing_started_tick = xTaskGetTickCount();
    } else if (strncmp(command, "G34", 3) == 0) {
        s_g34_running = true;
        s_g29_running = false;
    } else if (strncmp(command, "G29", 3) == 0) {
        s_g29_running = true;
        s_g34_running = false;
    }

    if (marlin_cmd_queue != NULL) {
        xQueueSend(marlin_cmd_queue, command, pdMS_TO_TICKS(50));
    }
    if (log_queue != NULL) {
        log_item_t item;
        snprintf(item.line, LOG_LINE_MAX, "> %s", command);
        xQueueSend(log_queue, &item, 0);
    }
}

static void request_usb_file_list(void) {
    send_gcode("M22 U");
    vTaskDelay(pdMS_TO_TICKS(150));
    send_gcode("M21 U");
    vTaskDelay(pdMS_TO_TICKS(150));
    send_gcode("M20 L");
}

// ─── UI callbacks ────────────────────────────────────────────────────────────

static void fan_slider_event_cb(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code != LV_EVENT_VALUE_CHANGED && code != LV_EVENT_RELEASED) {
        return;
    }

    lv_obj_t *slider = lv_event_get_target(e);
    if (!slider) return;

    int pct = (int)lv_slider_get_value(slider);
    if (pct < 0) pct = 0;
    if (pct > 100) pct = 100;

    if (objects.fan_speed_percentage) {
        lv_label_set_text_fmt(objects.fan_speed_percentage, "%d%%", pct);
    }

    if (code == LV_EVENT_RELEASED) {
        int pwm = (pct * 255 + 50) / 100;
        char cmd[MAX_GCODE_LEN];
        snprintf(cmd, sizeof(cmd), "M106 S%d", pwm);
        send_gcode(cmd);
    }
}

// ─── File browser ────────────────────────────────────────────────────────────

static void update_file_browser_ui(void) {
    if (log_queue == NULL) return;
    log_item_t item;
    snprintf(item.line, LOG_LINE_MAX, "LIST_CLEAR");
    xQueueSend(log_queue, &item, 0);
    for (int i = 0; i < file_count; i++) {
        snprintf(item.line, LOG_LINE_MAX, "LIST_ADD:%.63s", file_list[i]);
        xQueueSend(log_queue, &item, 0);
    }
}

static void confirm_print_cb(lv_event_t *e) {
    lv_obj_t *mbox = lv_event_get_current_target(e);
    if (!mbox) return;

    uint16_t btn_idx = lv_msgbox_get_active_btn(mbox);

    if (btn_idx == 0) {  // "Print"
        print_bytes_current = 0;
        print_bytes_total = 0;
        snprintf(current_job, sizeof(current_job), "%s", pending_filename);
        isPrinting = true;
        s_is_paused = false;
        ui_set_print_active(true);

        ESP_LOGI(TAG, "Start print selected: '%s'", current_job);

        char cmd[MAX_GCODE_LEN];
        snprintf(cmd, sizeof(cmd), "M23 %.59s", pending_filename);
        send_gcode(cmd);
        send_gcode("M24");

        if (objects.print_screen) {
            lv_scr_load(objects.print_screen);
        }
    }

    if (modal_overlay) {
        lv_obj_del_async(modal_overlay);
        modal_overlay = NULL;
    }
}

static void show_print_confirmation(const char *filename) {
    snprintf(pending_filename, sizeof(pending_filename), "%s", filename);

    lv_obj_t *scr = lv_scr_act();
    modal_overlay = lv_obj_create(scr);
    lv_obj_set_size(modal_overlay, LV_PCT(100), LV_PCT(100));
    lv_obj_set_pos(modal_overlay, 0, 0);
    lv_obj_set_style_bg_opa(modal_overlay, LV_OPA_50, 0);
    lv_obj_set_style_bg_color(modal_overlay, lv_color_black(), 0);
    lv_obj_add_flag(modal_overlay, LV_OBJ_FLAG_CLICKABLE);

    static const char *btn_labels[] = {"Print", "Cancel", NULL};
    lv_obj_t *mbox = lv_msgbox_create(modal_overlay, "Confirm Print", filename, btn_labels, false);
    lv_obj_center(mbox);
    lv_obj_add_event_cb(mbox, confirm_print_cb, LV_EVENT_VALUE_CHANGED, NULL);
}

static void file_browser_click_cb(lv_event_t *e) {
    ESP_LOGI(TAG, "File browser clicked");
    lv_obj_t *btn = lv_event_get_target(e);
    if (!btn) return;
    lv_obj_t *label = lv_obj_get_child(btn, 0);
    if (!label) return;
    const char *filename = lv_label_get_text(label);
    if (!filename || strlen(filename) == 0) return;

    show_print_confirmation(filename);
}



// ─── Marlin line parser ──────────────────────────────────────────────────────

void parse_marlin_line(const char *line) {
    if (line == NULL || line[0] == '\0') return;
	
	if (s_m500_pending) {
		if (strstr(line, "Error:") != NULL || strstr(line, "err:") != NULL) {
			s_m500_pending = false;
		} else if (strstr(line, "Settings Stored") != NULL ||
            strcmp(line, "ok") == 0 || strncmp(line, "ok ", 3) == 0) {
			s_m500_pending = false;
			trigger_m500_success_beep();
		}
	}
	
    if (strstr(line, "External Reset") != NULL) {
        s_boot_usb_synced = false;
        isPrinting = false;
        s_is_paused = false;
        s_heating_active = false;
        print_bytes_current = 0;
        print_bytes_total = 0;
        ui_set_print_active(false);
        ESP_LOGI(TAG, "Marlin External Reset detected -> will re-sync USB file list");
    }



    // Back off M27/M114 polling temporarily when Marlin reports busy (e.g., M190/M109/G28)
    if (strstr(line, "echo:busy: processing") != NULL) {
        if (s_m27_busy_backoff < 3) {
            s_m27_busy_backoff = 3;
        }
        return;
    }

    // Track heating & pause notifications from Marlin
    if (strstr(line, "//action:notification") != NULL) {
        if (strstr(line, "Heating") != NULL) {
            s_heating_active = true;
            s_is_paused = false;
        }
        if (strstr(line, "Print Paused") != NULL) {
            s_is_paused = true;
        } else if (strstr(line, "Resuming") != NULL || strstr(line, "Resume") != NULL) {
            s_is_paused = false;
        }
    }

    // M27 progress: "SD printing byte 123456/7829494"
    if (strncmp(line, "SD printing byte ", 17) == 0) {
        unsigned long cur = 0, tot = 0;
        if (sscanf(line + 17, "%lu/%lu", &cur, &tot) == 2) {
            print_bytes_current = (uint32_t)cur;
            print_bytes_total = (uint32_t)tot;
            if (tot > 0) {
                isPrinting = true;
                s_is_paused = false;
                ui_set_print_active(true);
            }
            ESP_LOGI(TAG, "M27 progress: %lu / %lu", cur, tot);
        }
        return;
    }


    // Inside parse_marlin_line(const char *line) in main.cpp:
	
if (s_homing_active) {
        if (strstr(line, "Error:") != NULL || strstr(line, "Homing Failed") != NULL) {
            s_homing_active = false;
            jog_screen_set_status("Homing failed");
        } else if ((strcmp(line, "ok") == 0 || strncmp(line, "ok ", 3) == 0) &&
                   (xTaskGetTickCount() - s_homing_started_tick) >= pdMS_TO_TICKS(1500)) {
            s_homing_active = false;
            if (objects.status_log_jog_screen) {
                const char *cur = lv_textarea_get_text(objects.status_log_jog_screen);
                if (cur && strncmp(cur, "Homing ", 7) == 0) {
                    if (strstr(cur, "(G28 Z)") != NULL) {
                        jog_screen_set_status("Homing Z complete");
                    } else if (strstr(cur, "(G28 X)") != NULL) {
                        jog_screen_set_status("Homing X complete");
                    } else if (strstr(cur, "(G28 Y)") != NULL) {
                        jog_screen_set_status("Homing Y complete");
                    } else {
                        jog_screen_set_status("Homing All complete");
                    }
                }
            }
        }
    }

    if (s_g34_running) {
        if (strstr(line, "Error:") != NULL || strstr(line, "Homing Failed") != NULL) {
            s_g34_running = false;
            jog_screen_set_status("Z Auto-Align (G34) failed");
        } else if (strcmp(line, "ok") == 0 || strncmp(line, "ok ", 3) == 0) {
            s_g34_running = false;
            jog_screen_set_status("Z Auto-Align (G34) complete");
            ui_show_save_eeprom_prompt("Z Auto-Align complete");
        }
    }

    if (s_g29_running) {
        if (strstr(line, "Error:") != NULL || strstr(line, "Homing Failed") != NULL) {
            s_g29_running = false;
            jog_screen_set_status("Auto Bed Level (G29) failed");
        } else if (strcmp(line, "ok") == 0 || strncmp(line, "ok ", 3) == 0) {
            s_g29_running = false;
            jog_screen_set_status("Auto Bed Level (G29) complete");
            ui_show_save_eeprom_prompt("Bed leveling complete");
        }
    }

    // M20 file list parsing
    if (strcmp(line, "Begin file list") == 0) {
        file_count = 0;
        capturing_files = true;
        return;
    }
    if (strcmp(line, "End file list") == 0) {
        capturing_files = false;
        update_file_browser_ui();
        return;
    }
    if (capturing_files && file_count < MAX_FILES) {
        char *target_name = (char *)line;
        char *first_space = strchr((char *)line, ' ');
        if (first_space) {
            char *second_space = strchr(first_space + 1, ' ');
            if (second_space) {
                target_name = second_space + 1;
            }
        }
        snprintf(file_list[file_count], FILE_NAME_LEN, "%.63s", target_name);
        file_count++;
        return;
    }

    // Print start / completion detection
    if (strstr(line, "Start SD print job:") != NULL) {
        isPrinting = true;
        s_is_paused = false;
        ui_set_print_active(true);
        ESP_LOGI(TAG, "Marlin confirmed SD print start");
    }
    if (strstr(line, "Done printing file") != NULL || strstr(line, "Not SD printing") != NULL) {
        isPrinting = false;
        s_is_paused = false;
        s_heating_active = false;
        print_bytes_current = 0;
        print_bytes_total = 0;
        ui_set_print_active(false);
        ESP_LOGI(TAG, "Marlin reported print ended/inactive");
    }

    parse_fan_telemetry(line);

 // Coordinate updates (main screen + print screen + jog screen)
 
 
    char coord_buf[16];
    const char *xPos = strstr(line, "X:");
    if (xPos && (xPos == line || xPos[-1] == ' ')) {
        if (sscanf(xPos, "X:%f", &pos_x) == 1) {
            snprintf(coord_buf, sizeof(coord_buf), "%.2f", pos_x);
            if (objects.x_location_main_screen) {
                lv_label_set_text(objects.x_location_main_screen, coord_buf);
            }
            if (objects.x_position_print_screen) {
                lv_label_set_text(objects.x_position_print_screen, coord_buf);
            }
            if (objects.x_position_label_jog_screen) {
                lv_label_set_text(objects.x_position_label_jog_screen, coord_buf);
            }
        }
    }
    const char *yPos = strstr(line, "Y:");
    if (yPos && (yPos == line || yPos[-1] == ' ')) {
        if (sscanf(yPos, "Y:%f", &pos_y) == 1) {
            snprintf(coord_buf, sizeof(coord_buf), "%.2f", pos_y);
            if (objects.y_location_main_screen) {
                lv_label_set_text(objects.y_location_main_screen, coord_buf);
            }
            if (objects.y_position_print_screen) {
                lv_label_set_text(objects.y_position_print_screen, coord_buf);
            }
            if (objects.y_position_label_jog_screen) {
                lv_label_set_text(objects.y_position_label_jog_screen, coord_buf);
            }
        }
    }
    const char *zPos = strstr(line, "Z:");
    if (zPos && (zPos == line || zPos[-1] == ' ')) {
        if (sscanf(zPos, "Z:%f", &pos_z) == 1) {
            snprintf(coord_buf, sizeof(coord_buf), "%.2f", pos_z);
            if (objects.z_location_main_screen) {
                lv_label_set_text(objects.z_location_main_screen, coord_buf);
            }
            if (objects.z_position_print_screen) {
                lv_label_set_text(objects.z_position_print_screen, coord_buf);
            }
            if (objects.z_position_label_jog_screen) {
                lv_label_set_text(objects.z_position_label_jog_screen, coord_buf);
            }
        }
    }

    // Temperature + target updates (main screen + print screen arcs/labels)
    float hcur = -1.0f, hset = -1.0f;
    float bcur = -1.0f, bset = -1.0f;
    float dcur = -1.0f;
    char buf[16];

    const char *tPos = strstr(line, "T:");
    if (tPos && (tPos == line || tPos[-1] == ' ')) {
        // Accept both "T:xx /yy" and "T:xx/yy"
        if (sscanf(tPos, "T:%f /%f", &hcur, &hset) >= 1 ||
            sscanf(tPos, "T:%f/%f",  &hcur, &hset) >= 1) {

            if (hcur >= 0.0f) {
                s_nozzle_current = hcur;

                if (objects.nozzle_temp_main_screen) {
                    snprintf(buf, sizeof(buf), "%.0f°", hcur);
                    lv_label_set_text(objects.nozzle_temp_main_screen, buf);
                }
                if (objects.nozzle_arc_temp_print_screen) {
                    snprintf(buf, sizeof(buf), "%.0f°", hcur);
                    lv_label_set_text(objects.nozzle_arc_temp_print_screen, buf);
                }
            }

            if (hset >= 0.0f) {
                s_nozzle_target = hset;

                if (!ui_should_ignore_nozzle_sync()) {
                    if (objects.nozzle_arc_print_screen) {
                        lv_arc_set_value(objects.nozzle_arc_print_screen, (int32_t)hset);
                    }
                    if (objects.nozzle_arc_target_print_screen) {
                        snprintf(buf, sizeof(buf), "%.0f°", hset);
                        lv_label_set_text(objects.nozzle_arc_target_print_screen, buf);
                    }
                }
            }
			
			// Keep Filament Change screen temp state & labels in sync with M105
            if (s_nozzle_current >= 0.0f) {
                float tgt_for_ui = (s_nozzle_target >= 0.0f) ? s_nozzle_target : 0.0f;
                filament_screen_update_temps(s_nozzle_current, tgt_for_ui);
            }
        }
    }

    const char *bPos = strstr(line, "B:");
    if (bPos && (bPos == line || bPos[-1] == ' ')) {
        if (sscanf(bPos, "B:%f /%f", &bcur, &bset) >= 1 ||
            sscanf(bPos, "B:%f/%f",  &bcur, &bset) >= 1) {

            if (bcur >= 0.0f) {
                s_bed_current = bcur;

                if (objects.bed_temp_main_screen) {
                    snprintf(buf, sizeof(buf), "%.0f°", bcur);
                    lv_label_set_text(objects.bed_temp_main_screen, buf);
                }
                if (objects.bed_arc_temp_print_screen) {
                    snprintf(buf, sizeof(buf), "%.0f°", bcur);
                    lv_label_set_text(objects.bed_arc_temp_print_screen, buf);
                }
            }

            if (bset >= 0.0f) {
                s_bed_target = bset;

                if (!ui_should_ignore_bed_sync()) {
                    if (objects.bed_arc_print_screen) {
                        lv_arc_set_value(objects.bed_arc_print_screen, (int32_t)bset);
                    }
                    if (objects.bed_arc_target_print_screen) {
                        snprintf(buf, sizeof(buf), "%.0f°", bset);
                        lv_label_set_text(objects.bed_arc_target_print_screen, buf);
                    }
                }
            }
        }
    }

    // Clear explicit heating latch once current temps are within 3C of active targets (or targets are 0)
    bool nozzle_done = (s_nozzle_target <= 30.0f) || (s_nozzle_current >= s_nozzle_target - 3.0f);
    bool bed_done    = (s_bed_target    <= 30.0f) || (s_bed_current    >= s_bed_target    - 3.0f);
    if ((tPos || bPos) && nozzle_done && bed_done) {
        s_heating_active = false;
    }

    // Chamber / drivers temp
    const char *cPos = strstr(line, "C:");
    if (cPos && (cPos == line || cPos[-1] == ' ') && sscanf(cPos, "C:%f", &dcur) == 1 && dcur >= 0.0f) {
        if (objects.drivers_temp_main_screen) {
            snprintf(buf, sizeof(buf), "%.0f°", dcur);
            lv_label_set_text(objects.drivers_temp_main_screen, buf);
        }
    }
}

// ─── Background tasks ────────────────────────────────────────────────────────

static void marlin_tx_task(void *arg) {
    (void)arg;
    char cmd[MAX_GCODE_LEN];
    while (1) {
        if (xQueueReceive(marlin_cmd_queue, cmd, portMAX_DELAY)) {
            cmd[sizeof(cmd) - 1] = '\0';
            size_t len = strlen(cmd);
            if (len == 0) {
                continue;
            }
            bool is_m23 = (strncmp(cmd, "M23 ", 4) == 0);
            if (len < sizeof(cmd) - 1 && cmd[len - 1] != '\n') {
                cmd[len++] = '\n';
                cmd[len] = '\0';
            }
            ESP_LOGI(TAG, "UART1 TX: %.*s",
                     (int)(len > 0 && cmd[len - 1] == '\n' ? len - 1 : len),
                     cmd);
            uart_write_bytes(MARLIN_UART_NUM, cmd, len);
            uart_wait_tx_done(MARLIN_UART_NUM, pdMS_TO_TICKS(100));
            if (is_m23) {
                vTaskDelay(pdMS_TO_TICKS(150));
            }
        }
    }
}

static void marlin_rx_task(void *arg) {
    (void)arg;
    uint8_t rx_buf[256];
    static char line_accumulator[512];
    static size_t line_pos = 0;

    while (1) {
        int len = uart_read_bytes(MARLIN_UART_NUM, rx_buf, sizeof(rx_buf) - 1, pdMS_TO_TICKS(20));
        if (len > 0) {
            last_marlin_reply_ms = xTaskGetTickCount() * portTICK_PERIOD_MS;
            marlin_connected = true;

            for (int i = 0; i < len; i++) {
                char c = (char)rx_buf[i];
                if (c == '\n') {
                    line_accumulator[line_pos] = '\0';
                    if (line_pos > 0) {
                        ESP_LOGI(TAG, "UART1 RX: %s", line_accumulator);
                        if (lvgl_port_lock(100)) {
                            parse_marlin_line(line_accumulator);

                            // Marlin boot / reset / halt / homing failure detection
                            if (strstr(line_accumulator, "start") == line_accumulator ||
                                strstr(line_accumulator, "Marlin ") != NULL ||
                                strncmp(line_accumulator, "!!", 2) == 0 ||
                                strstr(line_accumulator, "Error:") != NULL ||
                                strstr(line_accumulator, "Homing Failed") != NULL ||
                                strstr(line_accumulator, "Printer halted") != NULL) {
                                jog_reset_z_homed("Z homed cleared (reset/error) - Home Z before Z-");
                            }

                            if (strstr(line_accumulator, "T:") == NULL &&
                                strcmp(line_accumulator, "ok") != 0 &&
                                strncmp(line_accumulator, "ok ", 3) != 0 &&
                                !capturing_files &&
                                strcmp(line_accumulator, "Begin file list") != 0 &&
                                strcmp(line_accumulator, "End file list") != 0) {
                                append_print_log(line_accumulator);
                            }
                            lvgl_port_unlock();
                        }
                    }
                    line_pos = 0;
                } else if (c != '\r' && line_pos < sizeof(line_accumulator) - 1) {
                    line_accumulator[line_pos++] = c;
                }
            }
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

static void watchdog_task(void *arg) {
    (void)arg;
    uint8_t poll_counter = 0;

    while (1) {
        uint32_t now_ms = xTaskGetTickCount() * portTICK_PERIOD_MS;

        if (marlin_connected && !s_boot_usb_synced) {
            s_boot_usb_synced = true;
            request_usb_file_list();
        }

        // Connection watchdog
        if (marlin_connected && (now_ms - last_marlin_reply_ms > 10000)) {
            marlin_connected = false;
            ESP_LOGI(TAG, "Watchdog timeout -> polling M105");
            send_gcode("M105");
        }

        // Regular temperature polling
        poll_counter++;

        if (is_heating()) {
            // While heating -> poll every 2 seconds
            if (poll_counter >= 2) {
                poll_counter = 0;
                send_gcode("M105");
            }
        } else if (isPrinting || marlin_connected) {
            // While printing or just connected -> poll every 3 seconds
            if (poll_counter >= 3) {
                poll_counter = 0;
                send_gcode("M105");
            }
        } else {
            poll_counter = 0;
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

// ─── LVGL timer ──────────────────────────────────────────────────────────────

static void update_print_screen_timer(lv_timer_t *timer) {
    (void)timer;

    const char *status_text = isPrinting ? (s_is_paused ? "PAUSED" : "PRINTING") : "READY";
    lv_color_t status_color = isPrinting
        ? (s_is_paused ? lv_color_hex(0xFFB300) : lv_color_hex(0x00D2FF))
        : lv_color_hex(0x00FF88);

    if (objects.print_ready_label_main_screen) {
        lv_label_set_text(objects.print_ready_label_main_screen, status_text);
        lv_obj_set_style_text_color(objects.print_ready_label_main_screen, status_color, 0);
    }
    if (objects.print_ready_label_print_screen) {
        lv_label_set_text(objects.print_ready_label_print_screen, status_text);
        lv_obj_set_style_text_color(objects.print_ready_label_print_screen, status_color, 0);
    }

    if (objects.job_label_print_screen) {
        lv_label_set_text(objects.job_label_print_screen, isPrinting ? current_job : "No Job Active");
    }

    if (!isPrinting) {
        ui_update_print_times(0, 0);
        return;
    }

    // Poll M27 and M114 while printing, backing off when Marlin reports busy
    static uint8_t poll_tick = 0;
    poll_tick++;
    if (s_m27_busy_backoff > 0) {
        s_m27_busy_backoff--;
    } else if ((poll_tick % 6) == 3) {
        send_gcode("M27");
    } else if ((poll_tick % 6) == 0) {
        send_gcode("M114");
    }

    int pct = 0;
    if (print_bytes_total > 0) {
        pct = (int)(((uint64_t)print_bytes_current * 100ULL) / (uint64_t)print_bytes_total);
        if (pct < 0) pct = 0;
        if (pct > 100) pct = 100;
    }

    if (objects.printing_progress_print_screen) {
        char buf[32];
        snprintf(buf, sizeof(buf), "%d%%", pct);
        lv_label_set_text(objects.printing_progress_print_screen, buf);
    }

    if (objects.printing_progress_slider_print_screen) {
        lv_slider_set_value(objects.printing_progress_slider_print_screen, pct, LV_ANIM_OFF);
    }

    ui_update_print_times(print_bytes_current, print_bytes_total);
}

static void ui_sync_all_coordinates(void) {
    char buf[16];

    snprintf(buf, sizeof(buf), "%.2f", pos_x);
    if (objects.x_location_main_screen) {
        lv_label_set_text(objects.x_location_main_screen, buf);
    }
    if (objects.x_position_print_screen) {
        lv_label_set_text(objects.x_position_print_screen, buf);
    }
    if (objects.x_position_label_jog_screen) {
        lv_label_set_text(objects.x_position_label_jog_screen, buf);
    }

    snprintf(buf, sizeof(buf), "%.2f", pos_y);
    if (objects.y_location_main_screen) {
        lv_label_set_text(objects.y_location_main_screen, buf);
    }
    if (objects.y_position_print_screen) {
        lv_label_set_text(objects.y_position_print_screen, buf);
    }
    if (objects.y_position_label_jog_screen) {
        lv_label_set_text(objects.y_position_label_jog_screen, buf);
    }

    snprintf(buf, sizeof(buf), "%.2f", pos_z);
    if (objects.z_location_main_screen) {
        lv_label_set_text(objects.z_location_main_screen, buf);
    }
    if (objects.z_position_print_screen) {
        lv_label_set_text(objects.z_position_print_screen, buf);
    }
    if (objects.z_position_label_jog_screen) {
        lv_label_set_text(objects.z_position_label_jog_screen, buf);
    }
}

static void sfm27_pulse_ms(uint32_t duration_ms) {
    if (SFM27_CTRL_GPIO == GPIO_NUM_NC) {
        return;
    }
    gpio_set_level(SFM27_CTRL_GPIO, 1);
    vTaskDelay(pdMS_TO_TICKS(duration_ms));
    gpio_set_level(SFM27_CTRL_GPIO, 0);
}

// ─── App main ────────────────────────────────────────────────────────────────

extern "C" void app_main(void) {
    init_display();
    ESP_LOGI(TAG, "Start LVGL");
    // 1. Initialize SFM-27 control pin low before display/LVGL/Marlin startup
    sfm27_gpio_init();
    struct tm rtc_time = {};
    if (bm8563_get_time(rtc_handle, &rtc_time) == ESP_OK) {
        ESP_LOGI(TAG, "RTC: %04d-%02d-%02d %02d:%02d:%02d",
                 rtc_time.tm_year + 1900, rtc_time.tm_mon + 1, rtc_time.tm_mday,
                 rtc_time.tm_hour, rtc_time.tm_min, rtc_time.tm_sec);
        time_t t = mktime(&rtc_time);
        struct timeval tv = { .tv_sec = t, .tv_usec = 0 };
        settimeofday(&tv, NULL);
    }

    stc8 = stc8h1k28_get_handle();
    stc8h1k28_buzzer_on(stc8);
    vTaskDelay(pdMS_TO_TICKS(500));
    stc8h1k28_buzzer_off(stc8);

    uart_config_t uart_config = {};
    uart_config.baud_rate    = 115200;
    uart_config.data_bits  = UART_DATA_8_BITS;
    uart_config.parity     = UART_PARITY_DISABLE;
    uart_config.stop_bits  = UART_STOP_BITS_1;
    uart_config.flow_ctrl  = UART_HW_FLOWCTRL_DISABLE;
    uart_config.source_clk = UART_SCLK_DEFAULT;

    uart_param_config(MARLIN_UART_NUM, &uart_config);
    uart_set_pin(MARLIN_UART_NUM, MARLIN_TX_PIN, MARLIN_RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(MARLIN_UART_NUM, SERIAL_BUF_SIZE * 2, 0, 0, NULL, 0);
    uart_flush_input(MARLIN_UART_NUM);
    log_queue_init();
    marlin_cmd_queue = xQueueCreate(COMMAND_QUEUE_LEN, MAX_GCODE_LEN);
	
// UI Init Display Screens

    if (lvgl_port_lock(portMAX_DELAY)) {
        ui_init();
	// 2. Short boot confirmation chirp on the 5V SFM-27
    sfm27_pulse_ms(SFM27_BOOT_BEEP_MS);
    	
    if (objects.print_status_log) {
        lv_textarea_set_text(objects.print_status_log, "");
    }
    if (objects.file_browser_list) {
        lv_obj_add_event_cb(objects.file_browser_list, file_browser_click_cb, LV_EVENT_CLICKED, NULL);
    }
    if (objects.fan_speed_slider_print_screen) {
        lv_obj_add_event_cb(objects.fan_speed_slider_print_screen, fan_slider_event_cb, LV_EVENT_ALL, NULL);
    }
        lv_timer_create(update_clock_labels_timer, 1000, NULL);
        lv_timer_create(update_print_screen_timer, 1000, NULL);
        lvgl_port_unlock();
    }

    xTaskCreate(marlin_rx_task, "rx", 4096, NULL, 5, NULL);
    xTaskCreate(marlin_tx_task, "tx", 3072, NULL, 3, NULL);
    xTaskCreate(watchdog_task,  "wd", 3072, NULL, 1, NULL);

    vTaskDelay(pdMS_TO_TICKS(1500));

    
 // Initialize position labels right after creating screens
 
 
pos_x = 0.0f;
    pos_y = 0.0f;
    pos_z = 0.0f;

    if (lvgl_port_lock(portMAX_DELAY)) {
        ui_sync_all_coordinates();
        lvgl_port_unlock();
    }

    // Enable auto-report (primary method)
    send_gcode("M155 S2");
    vTaskDelay(pdMS_TO_TICKS(300));
    send_gcode("M114");
    vTaskDelay(pdMS_TO_TICKS(300));
	

}