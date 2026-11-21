#include "esp32_s3.h"
#include "esp_lcd_panel_rgb.h"
#include "esp_lcd_touch_gt911.h"
#include "esp_heap_caps.h"
#include "esp_log.h"

static const char *TAG_DISP = "ESP32_S3_DISP";

#define LCD_H_RES 800
#define LCD_V_RES 480

static lv_disp_draw_buf_t disp_buf;
static lv_color_t *buf1 = NULL;
static lv_color_t *buf2 = NULL;
static esp_lcd_touch_handle_t g_touch_handle = NULL;

static bool notify_lvgl_flush_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx) {
    lv_disp_drv_t *disp_driver = (lv_disp_drv_t *)user_ctx;
    lv_disp_flush_ready(disp_driver);
    return false;
}

static void lvgl_flush_cb(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map) {
    esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t) drv->user_data;
    esp_lcd_panel_draw_bitmap(panel_handle, area->x1, area->y1, area->x2 + 1, area->y2 + 1, color_map);
}

static void touchpad_read(lv_indev_drv_t *drv, lv_indev_data_t *data) {
    if (g_touch_handle == NULL) {
        data->state = LV_INDEV_STATE_REL;
        return;
    }
    uint16_t x[1], y[1], strength[1];
    uint8_t count = 0;

    esp_lcd_touch_read_data(g_touch_handle);
    if (esp_lcd_touch_get_coordinates(g_touch_handle, x, y, strength, &count, 1) && count > 0) {
        data->point.x = x[0];
        data->point.y = y[0];
        data->state = LV_INDEV_STATE_PR;
    } else {
        data->state = LV_INDEV_STATE_REL;
    }
}

void init_extender(i2c_master_bus_handle_t i2c_bus_handle, stc8h1k28_handle_t *stc8h1k28_handle) {
    // Wake-up pulse for STC8H1K28 Backlight/IO MCU on GPIO 1
    gpio_config_t io_conf = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL << GPIO_NUM_1)
    };
    gpio_config(&io_conf);
    gpio_set_level(GPIO_NUM_1, 0);
    vTaskDelay(pdMS_TO_TICKS(120));
    gpio_set_direction(GPIO_NUM_1, GPIO_MODE_INPUT);
    vTaskDelay(pdMS_TO_TICKS(100));

    stc8h1k28_init(i2c_bus_handle, stc8h1k28_handle, NULL);
    ESP_LOGI(TAG_DISP, "STC8H1K28 IO expander initialized.");
}

void init_rtc(i2c_master_bus_handle_t i2c_bus_handle, bm8563_handle_t *rtc_handle) {
    bm8563_init(i2c_bus_handle, rtc_handle);
    ESP_LOGI(TAG_DISP, "BM8563 RTC initialized.");
}

void init_lcd(esp_lcd_panel_handle_t *panel_handle) {
    esp_lcd_rgb_panel_config_t panel_config = {
        .clk_src = LCD_CLK_SRC_DEFAULT,
        .timings = {
            .pclk_hz = 16000000,
            .h_res = LCD_H_RES,
            .v_res = LCD_V_RES,
            .hsync_back_porch = 8,
            .hsync_front_porch = 8,
            .hsync_pulse_width = 4,
            .vsync_back_porch = 8,
            .vsync_front_porch = 8,
            .vsync_pulse_width = 4,
            .flags.pclk_active_neg = true,
        },
        .data_width = 16,
        .hsync_gpio_num = GPIO_NUM_40,
        .vsync_gpio_num = GPIO_NUM_41,
        .de_gpio_num = GPIO_NUM_42,
        .pclk_gpio_num = GPIO_NUM_39,
        .disp_gpio_num = GPIO_NUM_NC,
        .data_gpio_nums = {
            GPIO_NUM_21, GPIO_NUM_47, GPIO_NUM_48, GPIO_NUM_45,
            GPIO_NUM_38, GPIO_NUM_9,  GPIO_NUM_10, GPIO_NUM_11,
            GPIO_NUM_12, GPIO_NUM_13, GPIO_NUM_14, GPIO_NUM_7,
            GPIO_NUM_17, GPIO_NUM_18, GPIO_NUM_3,  GPIO_NUM_46
        },
        .flags.fb_in_psram = true,
    };

    ESP_ERROR_CHECK(esp_lcd_new_rgb_panel(&panel_config, panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_reset(*panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(*panel_handle));
    ESP_LOGI(TAG_DISP, "RGB LCD panel initialized.");
}

void init_touch(i2c_master_bus_handle_t i2c_bus_handle, esp_lcd_touch_handle_t *touch_handle) {
    esp_lcd_panel_io_handle_t tp_io_handle = NULL;
    esp_lcd_panel_io_i2c_config_t tp_io_config = ESP_LCD_TOUCH_IO_I2C_GT911_CONFIG();
    tp_io_config.scl_speed_hz = 400000;

    esp_lcd_touch_config_t tp_cfg = {
        .x_max = LCD_H_RES,
        .y_max = LCD_V_RES,
        .rst_gpio_num = GPIO_NUM_NC,
        .int_gpio_num = GPIO_NUM_NC,
    };

    ESP_ERROR_CHECK(esp_lcd_new_panel_io_i2c_v2(i2c_bus_handle, &tp_io_config, &tp_io_handle));
    ESP_ERROR_CHECK(esp_lcd_touch_new_i2c_gt911(tp_io_handle, &tp_cfg, touch_handle));
    g_touch_handle = *touch_handle;
    ESP_LOGI(TAG_DISP, "GT911 Touch controller initialized.");
}

void init_lvgl(esp_lcd_panel_handle_t panel_handle, esp_lcd_touch_handle_t touch_handle) {
    lv_init();
    buf1 = (lv_color_t *)heap_caps_malloc(LCD_H_RES * 50 * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);
    buf2 = (lv_color_t *)heap_caps_malloc(LCD_H_RES * 50 * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, LCD_H_RES * 50);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = LCD_H_RES;
    disp_drv.ver_res = LCD_V_RES;
    disp_drv.flush_cb = lvgl_flush_cb;
    disp_drv.draw_buf = &disp_buf;
    disp_drv.user_data = panel_handle;
    lv_disp_drv_register(&disp_drv);

    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;
    lv_indev_drv_register(&indev_drv);

    ESP_LOGI(TAG_DISP, "LVGL port and drivers registered.");
}