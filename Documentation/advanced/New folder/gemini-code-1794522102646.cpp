void append_print_log(const char *line) {
    if (!line) return;
    
    char buf[256];
    snprintf(buf, sizeof(buf), "%s\n", line);

    if (lvgl_port_lock(pdMS_TO_TICKS(200))) {
        if (objects.print_status_log) {
            // Keep text length under 4KB to avoid heap issues
            if (lv_textarea_get_text(objects.print_status_log) &&  
                strlen(lv_textarea_get_text(objects.print_status_log)) > 4096) {
                lv_textarea_set_text(objects.print_status_log, "");
            }
            lv_textarea_add_text(objects.print_status_log, buf);
            lv_textarea_set_cursor_pos(objects.print_status_log, LV_TEXTAREA_CURSOR_LAST);
        }
        
        if (objects.print_status_log_print_screen) {
            lv_textarea_add_text(objects.print_status_log_print_screen, buf);
            lv_textarea_set_cursor_pos(objects.print_status_log_print_screen, LV_TEXTAREA_CURSOR_LAST);
        }
        
        lvgl_port_unlock();
    }
}