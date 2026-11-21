#include "esp_http_server.h"
#include "driver/uart.h"
#include "esp_log.h"

#define MARLIN_UART_NUM UART_NUM_1

extern "C" void send_gcode(const char *command);

static esp_err_t gcode_upload_post_handler(httpd_req_t *req) {
    char filename[64] = "uploaded.gco";
    
    // Read custom filename header from the upload request
    size_t hdr_len = httpd_req_get_hdr_value_len(req, "X-Filename");
    if (hdr_len > 0 && hdr_len < sizeof(filename)) {
        httpd_req_get_hdr_value_str(req, "X-Filename", filename, sizeof(filename));
    }

    ESP_LOGI("HTTP", "Starting wireless upload for file: %s", filename);

    // 1. Send M28 to open file for writing on the Octopus onboard SD card
    char m28_cmd[128];
    snprintf(m28_cmd, sizeof(m28_cmd), "M28 %s\n", filename);
    uart_write_bytes(MARLIN_UART_NUM, m28_cmd, strlen(m28_cmd));
    uart_wait_tx_done(MARLIN_UART_NUM, pdMS_TO_TICKS(100));
    vTaskDelay(pdMS_TO_TICKS(250)); // Allow Marlin file buffer to initialize

    // 2. Allocate buffer and stream incoming chunks directly to UART
    size_t buf_size = 1024;
    char *buf = (char *)malloc(buf_size);
    if (!buf) {
        httpd_resp_send_500(req);
        return ESP_FAIL;
    }

    int remaining = req->content_len;
    while (remaining > 0) {
        int recv_len = httpd_req_recv(req, buf, remaining < buf_size ? remaining : buf_size);
        if (recv_len <= 0) {
            if (recv_len == HTTPD_SOCK_ERR_TIMEOUT) {
                continue; // Retry on network timeout
            }
            free(buf);
            httpd_resp_send_500(req);
            return ESP_FAIL;
        }

        // Stream raw gcode chunk straight to Marlin
        uart_write_bytes(MARLIN_UART_NUM, buf, recv_len);
        remaining -= recv_len;
    }
    free(buf);

    // 3. Send M29 to close and save the file on the SD card
    const char *m29_cmd = "M29\n";
    uart_write_bytes(MARLIN_UART_NUM, m29_cmd, strlen(m29_cmd));
    uart_wait_tx_done(MARLIN_UART_NUM, pdMS_TO_TICKS(100));
    vTaskDelay(pdMS_TO_TICKS(500));

    ESP_LOGI("HTTP", "Upload complete. Refreshing file list...");

    // 4. Automatically re-query M20 L so the UI updates with the new file
    send_gcode("M20 L");

    httpd_resp_sendstr(req, "G-code uploaded successfully!");
    return ESP_OK;
}

void start_wifi_webserver(void) {
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();

    if (httpd_start(&server, &config) == ESP_OK) {
        httpd_uri_t upload_uri = {
            .uri       = "/upload",
            .method    = HTTP_POST,
            .handler   = gcode_upload_post_handler,
            .user_ctx  = NULL
        };
        httpd_register_uri_handler(server, &upload_uri);
        ESP_LOGI("HTTP", "HTTP server started successfully.");
    }
}