void append_print_log(const char *line) {
    char buf[256];
    snprintf(buf, sizeof(buf), "%s\n", line);

    if (lvgl_port_lock(pdMS_TO_TICKS(50))) {
        // Main screen log
        if (objects.print_status_log) {
            // Optional: Keep text length under ~4KB to avoid heap exhaustion
            if (lv_textarea_get_text(objects.print_status_log) && 
                strlen(lv_textarea_get_text(objects.print_status_log)) > 4096) {
                lv_textarea_set_text(objects.print_status_log, "");
            }
            lv_textarea_add_text(objects.print_status_log, buf);
            lv_textarea_set_cursor_pos(objects.print_status_log, LV_TEXTAREA_CURSOR_LAST);
        }
        
        // Print screen log (only valid if screen is currently active)
        if (objects.print_status_log_print_screen) {
            lv_textarea_add_text(objects.print_status_log_print_screen, buf);
            lv_textarea_set_cursor_pos(objects.print_status_log_print_screen, LV_TEXTAREA_CURSOR_LAST);
        }
        lvgl_port_unlock();
    }
}