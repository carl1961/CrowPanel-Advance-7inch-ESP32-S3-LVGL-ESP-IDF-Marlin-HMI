static bool force_marlin_link(void) {
    const int bauds[] = {115200, 250000}; // Test common Marlin baud rates
    const char *cmds[] = {"M115\n", "M105\n"};
    
    for (int b = 0; b < 2; b++) {
        uart_set_baudrate(MARLIN_UART_NUM, bauds[b]);
        uart_flush(MARLIN_UART_NUM);
        vTaskDelay(pdMS_TO_TICKS(100));
        
        for (int c = 0; c < 2; c++) {
            uart_write_bytes(MARLIN_UART_NUM, cmds[c], strlen(cmds[c]));
            vTaskDelay(pdMS_TO_TICKS(200));
            
            uint8_t rbuf[256] = {0};
            int len = uart_read_bytes(MARLIN_UART_NUM, rbuf, sizeof(rbuf) - 1, pdMS_TO_TICKS(200));
            if (len > 0) {
                marlin_connected = true;
                ESP_LOGI("MARLIN", "Handshake established at %d baud", bauds[b]);
                return true;
            }
        }
    }
    return false;
}