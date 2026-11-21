void append_print_log(const char *text) {
    if (!text) return;
    
    // Always mirror to serial monitor for debugging
    ESP_LOGI("MARLIN_LOG", "%s", text);

    if (lvgl_port_lock(portMAX_DELAY)) {
        // Update main screen log if loaded
        if (print_status_log) {
            lv_textarea_add_text(print_status_log, text);
            lv_textarea_add_text(print_status_log, "\n");
            lv_textarea_set_cursor_pos(print_status_log, LV_TEXTAREA_CURSOR_LAST);
        }
        
        // Update print screen log if loaded
        if (print_status_log_print_screen) {
            lv_textarea_add_text(print_status_log_print_screen, text);
            lv_textarea_add_text(print_status_log_print_screen, "\n");
            lv_textarea_set_cursor_pos(print_status_log_print_screen, LV_TEXTAREA_CURSOR_LAST);
        }
        
        lvgl_port_unlock();
    }
}