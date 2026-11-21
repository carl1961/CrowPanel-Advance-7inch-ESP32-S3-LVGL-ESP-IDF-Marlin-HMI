#include "time_task.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "ui.h"
#include <time.h>
#include <sys/time.h>

static const char *TAG = "TIME_TASK";

static void time_task_entry(void *arg) {
    char time_str[16];
    char date_str[16];

    while (1) {
        time_t now;
        struct tm timeinfo;
        time(&now);
        localtime_r(&now, &timeinfo);

        // Format time and date strings
        strftime(time_str, sizeof(time_str), "%I:%M %p", &timeinfo);
        strftime(date_str, sizeof(date_str), "%m/%d/%Y", &timeinfo);

        // Update UI labels across your EEZ Studio screens safely
        if (objects.time_label_main_screen) lv_label_set_text(objects.time_label_main_screen, time_str);
        if (objects.date_year_label_main_screen) lv_label_set_text(objects.date_year_label_main_screen, date_str);
        
        if (objects.time_label_print_screen) lv_label_set_text(objects.time_label_print_screen, time_str);
        if (objects.date_year_label_print_screen) lv_label_set_text(objects.date_year_label_print_screen, date_str);
        
        if (objects.time_label_time_date_setting_screen) lv_label_set_text(objects.time_label_time_date_setting_screen, time_str);
        if (objects.date_year_label_time_date_setting_screen) lv_label_set_text(objects.date_year_label_time_date_setting_screen, date_str);

        // Poll every second
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void time_task_start(void) {
    xTaskCreate(time_task_entry, "time_task", 4096, NULL, 5, NULL);
    ESP_LOGI(TAG, "Time background task started successfully.");
}