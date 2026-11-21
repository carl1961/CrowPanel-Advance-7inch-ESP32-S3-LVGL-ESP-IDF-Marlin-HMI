// LVGL timer:
static void update_print_screen_timer(lv_timer_t *timer) {
    (void)timer;

    // Dynamically update READY / PRINTING status labels on both screens
    const char *status_text = isPrinting ? "PRINTING" : "READY";

    // Define colors: Soft green for READY, bright cyan/blue for PRINTING
    lv_color_t status_color = isPrinting ? lv_color_hex(0x00D2FF) : lv_color_hex(0x00FF88);

    if (objects.print_ready_label_main_screen) {
        lv_label_set_text(objects.print_ready_label_main_screen, status_text);
        lv_obj_set_style_text_color(objects.print_ready_label_main_screen, status_color, 0);
    }
    if (objects.print_ready_label_print_screen) {
        lv_label_set_text(objects.print_ready_label_print_screen, status_text);
        lv_obj_set_style_text_color(objects.print_ready_label_print_screen, status_color, 0);
    }

    // Update job filename label
    if (objects.job_label_print_screen) {
        lv_label_set_text(objects.job_label_print_screen, isPrinting ? current_job : "No Job Active");
    }

    if (!isPrinting) {
        return;
    }

    // Calculate percentage complete (stays 0% until M27 reports byte counts)
    int pct = 0;
    if (print_bytes_total > 0) {
        pct = (int)(((uint64_t)print_bytes_current * 100ULL) / (uint64_t)print_bytes_total);
        if (pct < 0) pct = 0;
        if (pct > 100) pct = 100;
    }

    // Update progress text label
    if (objects.printing_progress_print_screen) {
        char buf[32];
        snprintf(buf, sizeof(buf), "%d%%", pct);
        lv_label_set_text(objects.printing_progress_print_screen, buf);
    }

    // Update slider indicator value
    if (objects.printing_progress_slider_print_screen) {
        lv_slider_set_value(objects.printing_progress_slider_print_screen, pct, LV_ANIM_OFF);
    }
}