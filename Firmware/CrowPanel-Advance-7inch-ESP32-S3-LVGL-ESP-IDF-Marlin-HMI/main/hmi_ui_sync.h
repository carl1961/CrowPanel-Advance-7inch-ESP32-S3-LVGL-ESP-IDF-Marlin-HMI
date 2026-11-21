#pragma once
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif
bool ui_should_ignore_nozzle_sync(void);
bool ui_should_ignore_bed_sync(void);
void ui_set_paused_state(bool paused);

#ifdef __cplusplus
}
#endif