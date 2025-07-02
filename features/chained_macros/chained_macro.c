#include "chained_macro.h"

//! if callback has a 0ms delay it is canceled
//! if callback has a 0ms delay it is canceled
//! if callback has a 0ms delay it is canceled
//& I'm going to throw my pc at a fucking wall


// deferred callback
static uint32_t step_macro(uint32_t trigger_time, void *cb_arg) {
    looping_macro_t *macro = (looping_macro_t*)cb_arg;
    if (!macro) return 0; //in case someone is feeling funny

    while (true) {
        // end‑of‑list check
        if (macro->index >= macro->length) {
            if (macro->loops) {
                macro->index = 0;
            } else {
                stop_macro(macro);
                return 0;
            }
        }

        // pull the next action
        const macro_action_t *act = &macro->actions[macro->index++];

		if (act->press) {
			register_code16(act->keycode);
		} else {
			unregister_code16(act->keycode);
		}
		if (act->next_delay>0) {
			return act->next_delay;
		}
		//else loop again
    }
}

// macro start/restart
void start_macro(looping_macro_t *macro) {
    if (macro->token != INVALID_DEFERRED_TOKEN) return; 
    macro->index = 0;
    // loop the macro actions until a delay is found (or the end), then set the callback.
    uint32_t first_delay = step_macro(0,macro);
    if (first_delay) {
        macro->token = defer_exec(first_delay, step_macro, macro);
    }

}

// stop a running macro early, unpress keys
// if the macro is not running, noops
void stop_macro(looping_macro_t *macro) {
    if (macro->token == INVALID_DEFERRED_TOKEN) return;
    cancel_deferred_exec(macro->token);
    macro->token = INVALID_DEFERRED_TOKEN;
    // (Optional) you could scan through macro->actions[] and make sure
    // all keys that were held down are released here.
    for (uint8_t i = 0; i < macro->length; ++i) {
        if (macro->actions[i].press) {
            unregister_code16(macro->actions[i].keycode);
        }
    }
}