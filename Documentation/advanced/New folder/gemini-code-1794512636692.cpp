extern "C" void send_gcode(const char* command) {
    if (!command) return;
    
    // Send over UART1 to Marlin
    char buf[64];
    snprintf(buf, sizeof(buf), "%s\n", command);
    uart_write_bytes(MARLIN_UART_NUM, buf, strlen(buf));

    // Immediately echo to your EEZ Studio terminal text area
    if (lvgl_port_lock(portMAX_DELAY)) {
        // Assuming objects.terminal_textarea exists in your EEZ project
        // lv_textarea_add_text(objects.terminal_textarea, buf);
        lvgl_port_unlock();
    }
}