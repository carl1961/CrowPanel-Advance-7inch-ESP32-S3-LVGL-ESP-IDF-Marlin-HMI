void init_touch(i2c_master_bus_handle_t i2c_bus_handle, esp_lcd_touch_handle_t *touch_handle) {
    ESP_LOGI(TAG, "Install Touch driver");
    
    const esp_lcd_touch_config_t tp_cfg = {
        .x_max = LCD_H_RES,
        .y_max = LCD_V_RES,
        .rst_gpio_num = GPIO_NUM_NC, 
        .int_gpio_num = GPIO_NUM_NC, // Changed from GPIO_NUM_1 to prevent interrupt conflicts
        .levels = {
            .reset = 0,
            .interrupt = 0,
        },
        .flags = {
            .swap_xy = 0,
            .mirror_x = 0,
            .mirror_y = 0,
        },
    };
    
    esp_lcd_panel_io_handle_t tp_io_handle = NULL;
    esp_lcd_touch_io_config_t tp_io_cfg = ESP_LCD_TOUCH_IO_I2C_GT911_CONFIG();
    
    esp_lcd_new_panel_io_i2c(i2c_bus_handle, &tp_io_cfg, &tp_io_handle);
    esp_lcd_touch_new_i2c_gt911(tp_io_handle, &tp_cfg, touch_handle);
}