// Calibration struct expected by actions.c
typedef struct {
    int px;
    int py;
    int tx;
    int ty;
} cal_point_t;

// Global touch calibration and raw read stubs for actions.c compatibility
extern "C" {
    static cal_point_t active_cal_pts[4];
    
    bool gt911_direct_read_raw(uint16_t *x, uint16_t *y) {
        if (tp == NULL) return false;
        uint16_t touch_x[1];
        uint16_t touch_y[1];
        uint16_t strength[1];
        uint8_t touch_cnt = 0;
        
        esp_lcd_touch_read_data(tp);
        if (esp_lcd_touch_get_coordinates(tp, touch_x, touch_y, strength, &touch_cnt, 1) && touch_cnt > 0) {
            *x = touch_x[0];
            *y = touch_y[0];
            return true;
        }
        return false;
    }

    void touch_save_calibration(cal_point_t *pts) {
        for (int i = 0; i < 4; i++) {
            active_cal_pts[i] = pts[i];
        }
        // Add NVS save logic here if needed
    }
}