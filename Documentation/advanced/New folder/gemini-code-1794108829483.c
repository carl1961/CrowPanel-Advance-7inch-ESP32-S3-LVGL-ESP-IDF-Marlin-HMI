#include "actions.h"
#include "screens.h"
#include "ui.h"
#include "vars.h"
#include "esp_log.h"
#include "ui/ui.h"
#include "nvs_flash.h"
#include "nvs.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include "../display/esp32_s3.h"
#include "driver/i2c.h"

static const char *TAG = "GUI_ACTIONS";

// Action triggered when opening the time/date setting screen
void action_time_date_setting_screen(lv_event_t *e) {
    // 1. Load the time/date setting screen via EEZ Studio
    loadScreen(SCREEN_ID_TIME_DATE_SETTING_SCREEN);

    // 2. Fetch current system time
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);

    // 3. Set roller selected indices (assuming 0-indexed roller options)
    // Hour (0 - 23)
    if (objects.roller_hour) {
        lv_roller_set_selected(objects.roller_hour, timeinfo.tm_hour, LV_ANIM_OFF);
    }

    // Minute (0 - 59)
    if (objects.roller_minute) {
        lv_roller_set_selected(objects.roller_minute, timeinfo.tm_min, LV_ANIM_OFF);
    }

    // Day (1 - 31, index is day - 1)
    if (objects.roller_day) {
        lv_roller_set_selected(objects.roller_day, timeinfo.tm_mday - 1, LV_ANIM_OFF);
    }

    // Month (January = 0, December = 11)
    if (objects.roller_month) {
        lv_roller_set_selected(objects.roller_month, timeinfo.tm_mon, LV_ANIM_OFF);
    }

    // Year (Offset from your base year, e.g., 2026 = index 0)
    if (objects.roller_year) {
        int year_index = (timeinfo.tm_year + 1900) - 2026;
        if (year_index < 0) year_index = 0;
        lv_roller_set_selected(objects.roller_year, year_index, LV_ANIM_OFF);
    }
}

void action_save_time_setting(lv_event_t *e) {
    int hour   = lv_roller_get_selected(objects.roller_hour);
    int minute = lv_roller_get_selected(objects.roller_minute);
    int day    = lv_roller_get_selected(objects.roller_day) + 1;
    int month  = lv_roller_get_selected(objects.roller_month) + 1;
    int year   = lv_roller_get_selected(objects.roller_year) + 2026;

    struct tm timeinfo = {};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon  = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = hour;
    timeinfo.tm_min  = minute;
    timeinfo.tm_sec  = 0;
    
    time_t t = mktime(&timeinfo);
    struct timeval now = { .tv_sec = t, .tv_usec = 0 };
    settimeofday(&now, NULL);

    ESP_LOGI("TIME", "System time updated from EEZ Studio rollers.");
    loadScreen(SCREEN_ID_MAIN_SCREEN);
}

// Action triggered when the user taps "Back" or returns from the time setting screen
void action_return_to_main(lv_event_t * e) {
    action_save_time_setting(e);
    loadScreen(SCREEN_ID_MAIN_SCREEN);
}

// Action triggered when the user taps "Save & Apply" on the time setting screen
void action_save_time_button_time_date_setting_screen(lv_event_t * e) {
    action_save_time_setting(e);
    loadScreen(SCREEN_ID_MAIN_SCREEN);
}

// Action triggered when the user taps "CANCEL" on the time setting screen
void action_cancel_time_settings(lv_event_t *e) {
    ESP_LOGI("TIME", "Time setting cancel action triggered.");
    loadScreen(SCREEN_ID_MAIN_SCREEN); 
}

// Clock update timer callback
void update_clock_labels_timer(lv_timer_t * timer) {
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);

    char time_str[16];
    char date_str[16];

    // Format time (e.g., "03:45 PM")
    strftime(time_str, sizeof(time_str), "%I:%M %p", &timeinfo);
    
    // Format date (e.g., "11/06/2026")
    strftime(date_str, sizeof(date_str), "%m/%d/%Y", &timeinfo);

    // Update UI labels safely using objects structure
    if (objects.time_label_main_screen) lv_label_set_text(objects.time_label_main_screen, time_str);
    if (objects.date_year_label_main_screen) lv_label_set_text(objects.date_year_label_main_screen, date_str);
    if (objects.time_label_print_screen) lv_label_set_text(objects.time_label_print_screen, time_str);
    if (objects.date_year_label_print_screen) lv_label_set_text(objects.date_year_label_print_screen, date_str);
    if (objects.time_label_time_date_setting_screen) lv_label_set_text(objects.time_label_time_date_setting_screen, time_str);
    if (objects.date_year_label_time_date_setting_screen) lv_label_set_text(objects.date_year_label_time_date_setting_screen, date_str);
}

// Navigation actions
void action_main_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_MAIN_SCREEN);
}