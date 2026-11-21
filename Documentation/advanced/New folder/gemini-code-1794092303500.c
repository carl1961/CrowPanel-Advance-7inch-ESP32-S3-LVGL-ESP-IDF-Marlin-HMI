#include "gui.h"
#include "screens.h"
#include "ui.h"
#include "vars.h"
#include <time.h>
#include <sys/time.h>

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