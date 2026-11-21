extern "C" void update_clock_labels_timer(lv_timer_t *timer) {
    struct tm rtc_time = {};
    if (bm8563_get_time(get_rtc_handle(), &rtc_time) == ESP_OK) {
        char time_buf[16];
        snprintf(time_buf, sizeof(time_buf), "%02d:%02d", rtc_time.tm_hour, rtc_time.tm_min);
        // Update your LVGL clock label here if desired
    }
}