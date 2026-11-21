#include "actions.h"
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "screens.h"
#include "esp_log.h"
#include "ui/ui.h"
#include "lvgl.h"
#include "nvs_flash.h"
#include "nvs.h"
#include "display/esp32_s3.h"
#include "esp_system.h"
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <esp_err.h>
#include "hmi_ui_sync.h"











extern void send_gcode(const char *cmd);
extern QueueHandle_t log_queue;

typedef struct {
    uint16_t tx, ty;  // raw touch coords
    uint16_t px, py;  // expected screen coords
} cal_point_t;


static lv_obj_t *keyboard = NULL;
static const char *TAG = "TIME";


void load_time_setting_screen(void)
{
    struct tm now = {};
    time_t t = time(NULL);
    localtime_r(&t, &now); 

    lv_roller_set_selected(objects.roller_hour,   now.tm_hour,       LV_ANIM_OFF);
    lv_roller_set_selected(objects.roller_minute, now.tm_min,        LV_ANIM_OFF);
    lv_roller_set_selected(objects.roller_day,    now.tm_mday,       LV_ANIM_OFF);
    lv_roller_set_selected(objects.roller_month,  now.tm_mon,        LV_ANIM_OFF);
    lv_roller_set_selected(objects.roller_year,   now.tm_year - 126, LV_ANIM_OFF);  // 2026-1900=126

    loadScreen(SCREEN_ID_TIME_DATE_SETTING_SCREEN);
}



void action_save_time_setting(lv_event_t *e) {
    int hour   = lv_roller_get_selected(objects.roller_hour);
    int minute = lv_roller_get_selected(objects.roller_minute);
    int day    = lv_roller_get_selected(objects.roller_day) ;
    int month  = lv_roller_get_selected(objects.roller_month) + 1;
    int year   = lv_roller_get_selected(objects.roller_year) + 2026;

    struct tm time_to_set = {};
    time_to_set.tm_year  = year - 1900;
    time_to_set.tm_mon   = month - 1;
    time_to_set.tm_mday  = day;
    time_to_set.tm_hour  = hour;
    time_to_set.tm_min   = minute;
    time_to_set.tm_sec   = 0;

    if (bm8563_set_time(rtc_handle, &time_to_set) == ESP_OK) {
        // Sync ESP32 system clock
        time_t t = mktime(&time_to_set);
        struct timeval now = { .tv_sec = t, .tv_usec = 0 };
        settimeofday(&now, NULL);

        ESP_LOGI(TAG, "Time saved: %04d-%02d-%02d %02d:%02d",
                 year, month, day, hour, minute);
    } else {
        ESP_LOGE(TAG, "Failed to write time to BM8563.");
    }

    loadScreen(SCREEN_ID_MAIN_SCREEN);
}


// Action triggered when the user taps "Back" or returns from the time setting screen
void action_return_to_main(lv_event_t * e) {
    action_save_time_setting(e);
    loadScreen(SCREEN_ID_MAIN_SCREEN);
}

// Action triggered when the user taps "Save & Apply " on the time setting screen
void action_save_time_button_time_date_setting_screen(lv_event_t * e) {
    action_save_time_setting(e);
    loadScreen(SCREEN_ID_MAIN_SCREEN);
}

// Action triggered when the user taps "CANCEL" on the time setting screen
void action_cancel_time_settings(lv_event_t *e) {
    ESP_LOGI("TIME", "Time setting cancel action triggered.");
	loadScreen(SCREEN_ID_MAIN_SCREEN); 
}

// Action triggered when the user taps "Set Time" on the main screen
void action_time_date_setting_screen(lv_event_t *e) {
    ESP_LOGI("TIME", "Time setting action triggered.");
	//loadScreen(SCREEN_ID_TIME_DATE_SETTING_SCREEN);  
	load_time_setting_screen();
}


// Clock update timer callback
void update_clock_labels_timer(lv_timer_t * timer) {
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);

    char time_str[16];
    char date_str[16];

    // Format time (e.g., "03:45 PM")
    strftime(time_str, sizeof(time_str), "%I:%M %p", &timeinfo);
    
    // Format date (e.g., "11/06/2026")
    strftime(date_str, sizeof(date_str), "%m/%d/%Y", &timeinfo);

    // Update UI labels safely using objects structure
    if (objects.time_label_main_screen) lv_label_set_text(objects.time_label_main_screen, time_str);
    if (objects.date_year_label_main_screen) lv_label_set_text(objects.date_year_label_main_screen, date_str);
    
    if (objects.time_label_print_screen) lv_label_set_text(objects.time_label_print_screen, time_str);
    if (objects.date_year_label_print_screen) lv_label_set_text(objects.date_year_label_print_screen, date_str);
    
    if (objects.time_label_time_date_setting_screen) lv_label_set_text(objects.time_label_time_date_setting_screen, time_str);
    if (objects.date_year_label_time_date_setting_screen) lv_label_set_text(objects.date_year_label_time_date_setting_screen, date_str);
}

// Call this once after ui_init() in app_main:
// lv_timer_create(update_clock_labels_timer, 1000, NULL);
static const char *TAG_CAL = "CAL";

static bool calibration_mode = false;
static int cal_step = 0;

static const cal_point_t expected_targets[4] = {
    { .px = 45,  .py = 92  },
    { .px = 755, .py = 92  },
    { .px = 755, .py = 440 },
    { .px = 45,  .py = 440 }
};

static cal_point_t active_cal_pts[4];

// ---- Affine solve + verify  ----

typedef struct {
    float a, b, c;  // x_screen = a*rx + b*ry + c
    float d, e, f;  // y_screen = d*rx + e*ry + f
} affine_t;

// Solve 3x3 system M*x = r using Cramer's rule
static bool solve3(const float m[9], const float r[3], float out[3]) {
    float m00=m[0], m01=m[1], m02=m[2];
    float m10=m[3], m11=m[4], m12=m[5];
    float m20=m[6], m21=m[7], m22=m[8];
    float r0=r[0], r1=r[1], r2=r[2];

    float det = m00*(m11*m22 - m12*m21)
              - m01*(m10*m22 - m12*m20)
              + m02*(m10*m21 - m11*m20);
    if (fabsf(det) < 1e-6f) return false;

    out[0] = ( r0*(m11*m22 - m12*m21)
             - m01*(r1*m22 - m12*r2)
             + m02*(r1*m21 - m11*r2)) / det;

    out[1] = ( m00*(r1*m22 - m12*r2)
             - r0 *(m10*m22 - m12*m20)
             + m02*(m10*r2 - r1*m20)) / det;

    out[2] = ( m00*(m11*r2 - r1*m21)
             - m01*(m10*r2 - r1*m20)
             + r0 *(m10*m21 - m11*m20)) / det;

    return true;
}

// Compute affine from 3 raw→screen point pairs
static bool affine_from_3(const cal_point_t *pts, affine_t *m) {
    // x system: a*rx + b*ry + c = sx
    float mx[9] = {
        (float)pts[0].tx, (float)pts[0].ty, 1.0f,
        (float)pts[1].tx, (float)pts[1].ty, 1.0f,
        (float)pts[2].tx, (float)pts[2].ty, 1.0f
    };
    float rx[3] = { (float)pts[0].px, (float)pts[1].px, (float)pts[2].px };
    float ry[3] = { (float)pts[0].py, (float)pts[1].py, (float)pts[2].py };
    float sol[3];

    if (!solve3(mx, rx, sol)) return false;
    m->a = sol[0]; m->b = sol[1]; m->c = sol[2];

    // y system: d*rx + e*ry + f = sy
    if (!solve3(mx, ry, sol)) return false;
    m->d = sol[0]; m->e = sol[1]; m->f = sol[2];
    return true;
}

// Apply affine: raw → screen
static void affine_apply(const affine_t *m, float rx, float ry, float *sx, float *sy) {
    *sx = m->a * rx + m->b * ry + m->c;
    *sy = m->d * rx + m->e * ry + m->f;
}   

static void show_only_crosshair(int index) {
    lv_obj_add_flag(objects.crosshair_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.crosshair_2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.crosshair_3, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.crosshair_4, LV_OBJ_FLAG_HIDDEN);

    lv_obj_t *ch = NULL;
    if (index == 0) ch = objects.crosshair_1;
    else if (index == 1) ch = objects.crosshair_2;
    else if (index == 2) ch = objects.crosshair_3;
    else if (index == 3) ch = objects.crosshair_4;
    if (ch) {
        lv_obj_clear_flag(ch, LV_OBJ_FLAG_HIDDEN);
        // reset to white
        lv_obj_set_style_img_recolor(ch, lv_color_hex(0xFFFFFF), 0);
        lv_obj_set_style_img_recolor_opa(ch, LV_OPA_COVER, 0);
    }
}

void action_on_calibration_touch(lv_event_t *e) {
    if (!calibration_mode || cal_step >= 4) return;

    static uint32_t last_tap = 0;
    uint32_t now = xTaskGetTickCount();
    if (now - last_tap < pdMS_TO_TICKS(800)) {
        lv_label_set_text(objects.cal_status_label, "Too fast – wait a moment");
		ESP_LOGW(TAG, "Too fast – restarting calibration");
        goto reject;
        return;
    }
    last_tap = now;

    lv_indev_t *indev = lv_indev_get_act();
	lv_point_t p;
	lv_indev_get_point(indev, &p);
	uint16_t raw_x = p.x;
	uint16_t raw_y = p.y;
 //       return;
    

    if (cal_step > 0) {
        int dx = abs((int)raw_x - (int)active_cal_pts[cal_step - 1].tx);
        int dy = abs((int)raw_y - (int)active_cal_pts[cal_step - 1].ty);
        if (dx < 30 && dy < 30) {
            lv_label_set_text(objects.cal_status_label, "Too close to last point");
            ESP_LOGW(TAG, "Too close to last point – restarting");
            goto reject;
        }
    }

    const uint16_t exp_raw_x[4] = {60, 770, 770, 60};
    const uint16_t exp_raw_y[4] = {100, 100, 440, 440};
    if (abs((int)raw_x - exp_raw_x[cal_step]) > 150 ||
        abs((int)raw_y - exp_raw_y[cal_step]) > 150) {
        lv_label_set_text(objects.cal_status_label, "Tap closer to the cross-hair");
		ESP_LOGW(TAG, "Too far from cross-hair – restarting");
        goto reject;
    }

    // Accepted
    active_cal_pts[cal_step].tx = raw_x;
    active_cal_pts[cal_step].ty = raw_y;
    active_cal_pts[cal_step].px = expected_targets[cal_step].px;
    active_cal_pts[cal_step].py = expected_targets[cal_step].py;

    // Turn current cross-hair green
    lv_obj_t *ch = NULL;
    if (cal_step == 0) ch = objects.crosshair_1;
    else if (cal_step == 1) ch = objects.crosshair_2;
    else if (cal_step == 2) ch = objects.crosshair_3;
    else if (cal_step == 3) ch = objects.crosshair_4;
    if (ch) {
        lv_obj_set_style_img_recolor(ch, lv_color_hex(0x00FF00), 0);
        lv_obj_set_style_img_recolor_opa(ch, LV_OPA_COVER, 0);
    }

    ESP_LOGI(TAG, "Point %d/4 accepted", cal_step + 1);
    lv_label_set_text(objects.cal_status_label, "Good press next cross-hair");
    cal_step++;

    // Show only the next cross-hair
    if (cal_step < 4) {
        show_only_crosshair(cal_step);
    }

    if (cal_step >= 4) {
        affine_t m;
        if (!affine_from_3(active_cal_pts, &m)) {
		    ESP_LOGE(TAG, "Calibration failed – start over");
            lv_label_set_text(objects.cal_status_label, "Calibration failed – start over");
            goto reject;
        }

        float vx, vy;
        affine_apply(&m, (float)active_cal_pts[3].tx, (float)active_cal_pts[3].ty, &vx, &vy);
        int vdx = (int)(vx - (float)active_cal_pts[3].px);
        int vdy = (int)(vy - (float)active_cal_pts[3].py);

        ESP_LOGI(TAG, "Verify: expected (%d,%d) got (%.1f,%.1f) err=(%d,%d)",
                 active_cal_pts[3].px, active_cal_pts[3].py, vx, vy, vdx, vdy);

        if (vdx * vdx + vdy * vdy > 30 * 30) {
            // Turn first cross-hair red
            if (objects.crosshair_1) {
                lv_obj_set_style_img_recolor(objects.crosshair_1, lv_color_hex(0xFF0000), 0);
                lv_obj_set_style_img_recolor_opa(objects.crosshair_1, LV_OPA_COVER, 0);
            }
            lv_label_set_text(objects.cal_status_label, "Last touch failed – please try again");
            cal_step = 1;               // retry the first point
            show_only_crosshair(1);
            return;     
        }

        // Success
        touch_save_calibration(active_cal_pts);
        calibration_mode = false;
        lv_label_set_text(objects.cal_status_label, "Calibration saved – rebooting");
        ESP_LOGI(TAG, "Calibration verified and saved – rebooting");
		vTaskDelay(pdMS_TO_TICKS(500));
        esp_restart();
    }
    return;

reject:
    cal_step = 0;
    calibration_mode = true;
    show_only_crosshair(0);
    lv_label_set_text(objects.cal_status_label, "Calibration reset – start again");
}

// Action triggered when the user taps "START CAL" on the calibration screen
void action_start_calibration_clicked(lv_event_t *e) {
    calibration_mode = true;
    cal_step = 0;
    show_only_crosshair(0);
    lv_label_set_text(objects.cal_status_label, "Tap the cross-hair");
    ESP_LOGI(TAG, "Calibration started – tap near each cross-hair");
}

// Action triggered when the user taps "CANCEL" on the calibration screen
void action_on_cancel_calibration(lv_event_t *e) {
    calibration_mode = false;
    cal_step = 0;
    ESP_LOGI("CAL", "Calibration cancel action triggered.");
    loadScreen(SCREEN_ID_MAIN_SCREEN); 
}

// Helper – send a line to Marlin (adjust the serial port if needed)
//static void send_gcode(const char *cmd) {
    // UART transmission stub
//}

void action_show_gcode_popup(lv_event_t * e) {
    lv_obj_clear_flag(objects.gcode_popup, LV_OBJ_FLAG_HIDDEN);
}

void action_hide_gcode_popup(lv_event_t * e) {
    lv_obj_add_flag(objects.gcode_popup, LV_OBJ_FLAG_HIDDEN);
}

void action_send_btn_m119(lv_event_t * e) { send_gcode("M119"); }
void action_send_btn_m114(lv_event_t * e) { send_gcode("M114"); }
void action_send_btn_m122(lv_event_t * e) { send_gcode("M122"); }
void action_send_btn_m105(lv_event_t * e) { send_gcode("M105"); }
void action_send_btn_m503(lv_event_t * e) { send_gcode("M503"); }
void action_send_btn_g28(lv_event_t * e) { send_gcode("G28"); }
void action_send_btn_g29(lv_event_t * e) { send_gcode("G29"); }
void action_send_btn_m84(lv_event_t * e) { send_gcode("M84"); }
void action_send_btn_m112(lv_event_t * e) { send_gcode("M112"); }

void action_send_custom_gcode(lv_event_t * e) {
    const char *txt = lv_textarea_get_text(objects.custom_gcode);
    if (txt && txt[0]) {
        send_gcode(txt);
        lv_textarea_set_text(objects.custom_gcode, "");
    }
    if (keyboard) lv_obj_add_flag(keyboard, LV_OBJ_FLAG_HIDDEN);
}

void action_clear_custom_gcode(lv_event_t * e) {
    lv_textarea_set_text(objects.custom_gcode, "");
    if (keyboard) lv_obj_add_flag(keyboard, LV_OBJ_FLAG_HIDDEN);
}

static void keyboard_event_cb(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_READY) {          // user pressed the keyboard’s OK/checkmark
        if (keyboard) lv_obj_add_flag(keyboard, LV_OBJ_FLAG_HIDDEN);
    }
}

static const char *gcode_map[] = {
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n",
    "G", "M", "X", "Y", "Z", "E", "F", "S", "U","V", "\n",
    " ", ".", "-", LV_SYMBOL_BACKSPACE, "\n",
    LV_SYMBOL_OK, ""
};

static const lv_btnmatrix_ctrl_t gcode_ctrl[] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 1, 1, 1,
    2
};

void action_show_keyboard(lv_event_t * e) {
    if (keyboard == NULL) {
        keyboard = lv_keyboard_create(lv_scr_act());
        lv_obj_set_size(keyboard, 800, 200);
        lv_obj_align(keyboard, LV_ALIGN_BOTTOM_MID, 0, -200);
        lv_keyboard_set_textarea(keyboard, objects.custom_gcode);
        lv_keyboard_set_map(keyboard, LV_KEYBOARD_MODE_USER_1, gcode_map, gcode_ctrl);
        lv_keyboard_set_mode(keyboard, LV_KEYBOARD_MODE_USER_1);
        lv_obj_add_event_cb(keyboard, keyboard_event_cb, LV_EVENT_READY, NULL);
    }
    lv_obj_clear_flag(keyboard, LV_OBJ_FLAG_HIDDEN);
}

//File browser buttons


void action_refresh_file_list_button(lv_event_t * e) {
    // Clear the file browser list widget directly on button press
    if (objects.file_browser_list) {
        lv_obj_clean(objects.file_browser_list);
    }

    // Send G-code sequence to Marlin via your command queue or send function
    send_gcode("M22");   // Release media
    vTaskDelay(pdMS_TO_TICKS(100));
    send_gcode("M21");   // Re-initialize media slot
    vTaskDelay(pdMS_TO_TICKS(100));
    send_gcode("M20 L"); // Request file list
}

void action_clear_log(lv_event_t * e) {
    if (objects.print_status_log) {
        lv_textarea_set_text(objects.print_status_log, "");
    }
}

void action_power_off_button_main_screen(lv_event_t * e) {
    // Add power off / M81 command logic if applicable
	send_gcode("M81");
}

void action_go_back_folder(lv_event_t * e) {
    // Add folder navigation logic
}

void action_reboot_button_main_screen(lv_event_t * e) {
    // Add reboot command logic
	send_gcode("M997");
}


// Track the current sort mode state (e.g., 0: Name Ascending, 1: Name Descending, 2: Date/Size)
static int sort_mode = 0;

void action_sort_files(lv_event_t * e) {
    // Get the event object (the button) so we can update its label if desired
    lv_obj_t * btn = lv_event_get_target(e);
    
    // Cycle through 3 different sort states on each press
    sort_mode = (sort_mode + 1) % 3;

    switch (sort_mode) {
        case 0:
            // Mode 0: Sort by Name Ascending
            send_gcode("M34 S1");
            ESP_LOGI("UI", "Sort Mode: Name Ascending");
            break;
        case 1:
            // Mode 1: Sort by Name Descending
            send_gcode("M34 S-1");
            ESP_LOGI("UI", "Sort Mode: Name Descending");
            break;
        case 2:
            // Mode 2: Sort by Date/Time (or whatever alternate parameter your build supports)
            send_gcode("M34 F-1 S1");
            ESP_LOGI("UI", "Sort Mode: Date/Time");
            break;
    }

    // Automatically trigger a file list refresh so the UI updates immediately
    send_gcode("M20 L");
}

// Include the header declaring send_gcode here, e.g.:
// #include "marlin_serial.h"

void action_usb_mount_button_main_screen(lv_event_t *e) {
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        // Release before re-mounting so a stale USB handle resets cleanly
        send_gcode("M22 U\n");
        send_gcode("M21 U\n");
    }
}

void action_setting_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_SETTING_SCREEN);
}

void action_screen_calibrate(lv_event_t * e) {
    loadScreen(SCREEN_ID_SCREEN_CALIBRATE);
}

void action_main_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_MAIN_SCREEN);
}

void action_print_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_PRINT_SCREEN);
}


void action_job_label_print_screen(lv_event_t *e) {
    // TODO: Implement action job_label_print_screen here
}

void action_fan_speed_slider_print_screen(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *slider = lv_event_get_target(e);
    int pct = lv_slider_get_value(slider); // Assumes slider range is 0..100

    // 1. Update the percentage label live while dragging
    if (code == LV_EVENT_VALUE_CHANGED && objects.fan_speed_percentage != NULL) {
        lv_label_set_text_fmt(objects.fan_speed_percentage, "%d%%", pct);
    }

    // 2. Send M106 once when the finger lifts (or value finishes changing) so UART isn't flooded
    if (code == LV_EVENT_RELEASED) {
        int pwm = (pct * 255 + 50) / 100;
        char cmd[24];
        snprintf(cmd, sizeof(cmd), "M106 S%d\n", pwm);
        // Replace the line below with your actual UART send call:
        send_gcode(cmd);
    }
}

void action_fan_speed_percentage(lv_event_t *e) {
    // TODO: Implement action fan_speed_percentage here
}

void action_stop_button_print_screen(lv_event_t *e) {
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        // Abort SD/USB print in Marlin
        send_gcode("M524\n");
        // Optional safe stop cleanup: turn off hotend, bed, and part fan
        send_gcode("M104 S0\n");
        send_gcode("M140 S0\n");
        send_gcode("M106 S0\n");
    }
}


static void lift_z_before_home(void) {
    send_gcode("G91\n");
    send_gcode("G1 Z10 F600\n");
    send_gcode("G90\n");
}

void action_home_all_button_print_screen(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_PRESSED || code == LV_EVENT_CLICKED) {
        lift_z_before_home();
        send_gcode("G28\n");
    }
}

void action_home_x_button_print_screen(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_PRESSED || code == LV_EVENT_CLICKED) {
        lift_z_before_home();
        send_gcode("G28 X\n");
    }
}

void action_home_y_button_print_screen(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_PRESSED || code == LV_EVENT_CLICKED) {
        lift_z_before_home();
        send_gcode("G28 Y\n");
    }
}

void action_home_z_button_print_screen(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_PRESSED || code == LV_EVENT_CLICKED) {
        lift_z_before_home();
        send_gcode("G28 Z\n");
    }
}

// ─── Fine-Tuning Target Temps ─────────────────────────────────────────────────────────────

static bool s_dragging_nozzle = false;
static TickType_t s_nozzle_hold_until = 0;

static bool s_dragging_bed = false;
static TickType_t s_bed_hold_until = 0;

bool ui_should_ignore_nozzle_sync(void) {
    return s_dragging_nozzle || (xTaskGetTickCount() < s_nozzle_hold_until);
}

bool ui_should_ignore_bed_sync(void) {
    return s_dragging_bed || (xTaskGetTickCount() < s_bed_hold_until);
}

void action_nozzle_arc_print_screen(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *arc = lv_event_get_target(e);
    if (arc == NULL) return;

    int32_t target_c = lv_arc_get_value(arc);

    if (code == LV_EVENT_PRESSED || code == LV_EVENT_PRESSING) {
        s_dragging_nozzle = true;
        if (objects.nozzle_arc_target_print_screen != NULL) {
            lv_label_set_text_fmt(objects.nozzle_arc_target_print_screen, "%ld°", (long)target_c);
        }
    } else if (code == LV_EVENT_VALUE_CHANGED) {
        if (objects.nozzle_arc_target_print_screen != NULL) {
            lv_label_set_text_fmt(objects.nozzle_arc_target_print_screen, "%ld°", (long)target_c);
        }
    } else if (code == LV_EVENT_RELEASED) {
        s_dragging_nozzle = false;
        s_nozzle_hold_until = xTaskGetTickCount() + pdMS_TO_TICKS(1500);
        if (objects.nozzle_arc_target_print_screen != NULL) {
            lv_label_set_text_fmt(objects.nozzle_arc_target_print_screen, "%ld°", (long)target_c);
        }
        char cmd[24];
        snprintf(cmd, sizeof(cmd), "M104 S%ld\n", (long)target_c);
        send_gcode(cmd);
    }
}

void action_bed_arc_print_screen(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *arc = lv_event_get_target(e);
    if (arc == NULL) return;

    int32_t target_c = lv_arc_get_value(arc);

    if (code == LV_EVENT_PRESSED || code == LV_EVENT_PRESSING) {
        s_dragging_bed = true;
        if (objects.bed_arc_target_print_screen != NULL) {
            lv_label_set_text_fmt(objects.bed_arc_target_print_screen, "%ld°", (long)target_c);
        }
    } else if (code == LV_EVENT_VALUE_CHANGED) {
        if (objects.bed_arc_target_print_screen != NULL) {
            lv_label_set_text_fmt(objects.bed_arc_target_print_screen, "%ld°", (long)target_c);
        }
    } else if (code == LV_EVENT_RELEASED) {
        s_dragging_bed = false;
        s_bed_hold_until = xTaskGetTickCount() + pdMS_TO_TICKS(1500);
        if (objects.bed_arc_target_print_screen != NULL) {
            lv_label_set_text_fmt(objects.bed_arc_target_print_screen, "%ld°", (long)target_c);
        }
        char cmd[24];
        snprintf(cmd, sizeof(cmd), "M140 S%ld\n", (long)target_c);
        send_gcode(cmd);
    }
}

// ─── Pause/Resume Print ─────────────────────────────────────────────────────────────

static bool s_is_paused = false;

static void apply_pause_resume_visuals(bool paused) {
    lv_obj_t *btn_obj = objects.pause_button_print_screen;
    lv_obj_t *label_obj = objects.pause_resume_button_label;

    if (label_obj != NULL) {
        lv_label_set_text(label_obj, paused ? "RESUME" : "PAUSE");
        lv_obj_set_style_text_color(label_obj, lv_color_hex(0xffffff), LV_PART_MAIN);
    }

    if (btn_obj != NULL) {
        uint32_t bg_hex = paused ? 0x08ed05U : 0xfba002U;
        lv_obj_set_style_bg_color(btn_obj, lv_color_hex(bg_hex), LV_PART_MAIN);
        lv_obj_set_style_bg_opa(btn_obj, LV_OPA_COVER, LV_PART_MAIN);
    }
}

void ui_set_paused_state(bool paused) {
    s_is_paused = paused;
    apply_pause_resume_visuals(s_is_paused);
}

void action_pause_resume_button_label(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_PRESSED || code == LV_EVENT_CLICKED) {
        ESP_LOGI("PAUSE", "Pause/Resume triggered (code=%d), state=%d", (int)code, (int)s_is_paused);
        if (!s_is_paused) {
            send_gcode("M25\n");
            // Lift nozzle 10mm away from the part (relative move, then back to absolute)
            send_gcode("G91\n");
            send_gcode("G1 Z10 F600\n");
            send_gcode("G90\n");
            ui_set_paused_state(true);
        } else {
            // Lower nozzle back 10mm before resuming SD/USB playback
            send_gcode("G91\n");
            send_gcode("G1 Z-10 F600\n");
            send_gcode("G90\n");
            send_gcode("M24\n");
            ui_set_paused_state(false);
        }
    }
}




// Nozzle PID
//void action_pid_nozzle(lv_event_t *e) {
//    queue_gcode_command("M303 E0 S200\n");
//}

// Bed PID
//void action_pid_bed(lv_event_t *e) {
//    queue_gcode_command("M303 E-1 S60\n");
//}   