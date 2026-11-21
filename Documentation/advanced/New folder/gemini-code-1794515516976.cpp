static void marlin_rx_task(void *arg) {
    uint8_t rx_buf[128];
    static char line_accumulator[256];
    static size_t line_pos = 0;

    while (1) {
        int len = uart_read_bytes(MARLIN_UART_NUM, rx_buf, sizeof(rx_buf) - 1, pdMS_TO_TICKS(20));
        if (len > 0) {
            last_marlin_reply_ms = xTaskGetTickCount() * portTICK_PERIOD_MS;
            marlin_connected = true;

            for (int i = 0; i < len; i++) {
                char c = (char)rx_buf[i];
                if (c == '\n') {
                    line_accumulator[line_pos] = '\0';
                    if (line_pos > 0) {
                        snprintf(last_marlin_line, sizeof(last_marlin_line), "%s", line_accumulator);
                        new_line_ready = true;
                        
                        // 1. Always parse lines to update temperature dials and background state
                        parse_marlin_line(last_marlin_line);

                        // 2. Filter out temperature reports (T:) and basic ok acknowledgements 
                        //    so the console textarea doesn't get flooded.
                        if (strstr(last_marlin_line, "T:") == NULL && 
                            strcmp(last_marlin_line, "ok") != 0 && 
                            strncmp(last_marlin_line, "ok ", 3) != 0) {
                            append_print_log(last_marlin_line);
                        }
                    }
                    line_pos = 0;
                } else if (c != '\r' && line_pos < sizeof(line_accumulator) - 1) {
                    line_accumulator[line_pos++] = c;
                }
            }
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}