static void update_file_browser_ui(void) {
    if (objects.file_browser_list == NULL) return;

    // Safely lock LVGL port before manipulating UI elements from background tasks
    if (lvgl_port_lock(pdMS_TO_TICKS(50))) {
        // Clear existing list items
        lv_obj_clean(objects.file_browser_list);

        for (int i = 0; i < file_count; i++) {
            // Add list button with long filename text
            lv_obj_t * btn = lv_list_add_btn(objects.file_browser_list, NULL, file_list[i]);
            
            // Enable checkable state for highlighting selection
            lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE);
            
            // Apply dark theme background and text colors matching your console panels
            lv_obj_set_style_bg_color(btn, lv_color_hex(0x1e2229), LV_PART_MAIN);
            lv_obj_set_style_text_color(btn, lv_color_hex(0xdddddd), LV_PART_MAIN);
            
            // Selected / Checked state accent color (deep blue with white text)
            lv_obj_set_style_bg_color(btn, lv_color_hex(0x005588), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(btn, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_CHECKED);
            
            // Attach click event callback
            lv_obj_add_event_cb(btn, file_browser_click_cb, LV_EVENT_CLICKED, NULL);
        }
        lvgl_port_unlock();
    }
}