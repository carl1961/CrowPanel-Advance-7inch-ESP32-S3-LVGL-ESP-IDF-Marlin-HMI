void init_touch(i2c_master_bus_handle_t i2c_bus_handle, esp_lcd_touch_handle_t *touch_handle) {
    ESP_LOGI(TAG, "Install Touch driver");
    
    const esp_lcd_touch_config_t tp_cfg = {
        .x_max = LCD_H_RES,
        .y_max = LCD_V_RES,
        .rst_gpio_num = GPIO_NUM_NC, 
        .int_gpio_num = GPIO_NUM_1,
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
    
    // Ensure struct type is fully declared here:
    esp_lcd_panel_io_i2c_config_t tp_io_config = {                                       
        .dev_addr = 0x5D, 
        .scl_speed_hz = I2C_CLK_SPEED_HZ,
        .control_phase_bytes = 1,           
        .dc_bit_offset = 0,                 
        .lcd_cmd_bits = 16,                 
        .flags = {                            
            .disable_control_phase = 1,     
        }                                   
    };

    ESP_LOGI(TAG, "Create LCD panel IO handle");
    esp_lcd_new_panel_io_i2c_v2(i2c_bus_handle, &tp_io_config, &tp_io_handle);
    ESP_LOGI(TAG, "Create a new GT911 touch driver");
    esp_lcd_touch_new_i2c_gt911(tp_io_handle, &tp_cfg, touch_handle);
}