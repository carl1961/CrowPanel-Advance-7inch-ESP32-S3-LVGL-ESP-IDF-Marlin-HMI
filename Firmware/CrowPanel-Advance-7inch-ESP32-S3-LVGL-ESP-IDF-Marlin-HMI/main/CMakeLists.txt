# main/CMakeLists.txt

FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/main/*.*)

idf_component_register(SRCS ${app_sources} 
                       INCLUDE_DIRS "."
					   
					   "ui"
                       "display"
                       					   
                       REQUIRES
					   lvgl
					   stc8h1k28
					   bm8563
					   esp_lcd_touch
					   esp_lcd_touch_gt911
					   nvs_flash
					   esp_driver_i2c
					   esp_driver_uart
)