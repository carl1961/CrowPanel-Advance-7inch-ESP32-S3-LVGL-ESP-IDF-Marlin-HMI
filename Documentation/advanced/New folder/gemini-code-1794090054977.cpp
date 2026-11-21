#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_err.h"
#include "esp_log.h"
#include "driver/i2c_master.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_touch.h"
#include "lvgl.h"
#include "ui.h"
#include "display/esp32_s3.h"

static const char *TAG_MAIN = "MAIN";

// Explicit C linkage for LVGL tick increment
extern "C" {
    void lv_tick_inc(uint32_t tick_period);
}

static void increase_lvgl_tick(void *arg) {
    lv_tick_inc(2);
}

extern "C" void app_main(void) {
    ESP_LOGI(TAG_MAIN, "Initializing CrowPanel HMI (Modular Architecture)...");

    // 1. Initialize I2C Master Bus (SDA=15, SCL=16)
    i2c_master_bus_config_t bus_conf = {
        .i2c_port = I2C_NUM_0,
        .sda_io_num = GPIO_NUM_15,
        .scl_io_num = GPIO_NUM_16,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags = { .enable_internal_pullup = true }
    };
    i2c_master_bus_handle_t bus_handle = NULL;
    ESP_ERROR_CHECK(i2c_new_master_bus(&bus_conf, &bus_handle));

    // 2. Initialize Peripherals via Modular Functions
    stc8h1k28_handle_t stc_handle = NULL;
    bm8563_handle_t rtc_handle = NULL;
    esp_lcd_panel_handle_t panel_handle = NULL;
    esp_lcd_touch_handle_t touch_handle = NULL;

    init_extender(bus_handle, &stc_handle);
    init_rtc(bus_handle, &rtc_handle);
    init_lcd(&panel_handle);
    init_touch(bus_handle, &touch_handle);

    // Set backlight brightness (0 = max brightness on STC8H)
    stc8h1k28_set_brightness(stc_handle, 0);

    // 3. Initialize LVGL & Register Drivers
    init_lvgl(panel_handle, touch_handle);

    // 4. Start LVGL Tick Timer (2ms period)
    const esp_timer_create_args_t lvgl_tick_timer_args = {
        .callback = &increase_lvgl_tick,
        .name = "lvgl_tick"
    };
    esp_timer_handle_t lvgl_tick_timer = NULL;
    ESP_ERROR_CHECK(esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(lvgl_tick_timer, 2000));

    // 5. Initialize EEZ Studio UI
    ui_init();
    ESP_LOGI(TAG_MAIN, "EEZ Studio UI initialized successfully.");

    // 6. Main LVGL Handler Loop
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(10));
        lv_timer_handler();
    }
}