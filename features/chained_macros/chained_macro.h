#include "quantum.h"

// one action: press/release `keycode`, then wait `next_delay` ms
typedef struct {
    uint16_t keycode;
    bool     press;
    uint32_t next_delay;
} macro_action_t;

// Chained macro declaration
// NEVER set a macro WITHOUT DELAYS to LOOPING, it will brick the keyboard
//Max length if 2^8 (uint8)
typedef struct {
    const macro_action_t *actions;
    uint8_t               length;
    deferred_token        token;
    uint8_t               index;
    bool                  loops;
} looping_macro_t;

// start/restart, no-op if already running
void start_macro(looping_macro_t *macro);

// stop early, no-op if not running
void stop_macro(looping_macro_t *macro);

// declare & init a macro in one line (length auto)
#define DEFINE_LOOPING_MACRO(name, action_array, looping) static looping_macro_t name = {.actions = action_array,.length = (sizeof(action_array) / sizeof((action_array)[0])),.token = INVALID_DEFERRED_TOKEN,.index = 0,.loops = looping}