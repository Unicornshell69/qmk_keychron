//made by Unicornshell for the keychron v6 max ansi encoder
//this shitty code allows to call auto_click_start(keycode) and auto_click_stop()
//it can only autoclick one key at a time
//original code here: https://getreuer.info/posts/keyboards/mouse-turbo-click/index.html

#include "custom_turbo_behaviour/autoclick.h"



#ifndef AUTOCLICK_PERIOD
#   define AUTOCLICK_PERIOD 100
#endif

static deferred_token click_token = INVALID_DEFERRED_TOKEN;


//keeps track of the spammed key up and down state
static bool key_pressed = false;
//global variable, the key to spam
static uint16_t auto_key_keycode;

// callback function used with deferred execution. It alternates between registering and unregistering `auto_key_keycode`.
static uint32_t auto_click_callback(uint32_t trigger_time, void* cb_arg) {
  if (key_pressed) {
    unregister_code16(auto_key_keycode);
    key_pressed = false;
  } else {
    key_pressed = true;
    register_code16(auto_key_keycode);
  }
  return AUTOCLICK_PERIOD / 2;  // Execute again in half a period.
}

// starts the autoclicker with the given keycode
void auto_click_start(uint16_t keycode) {
  auto_key_keycode = keycode;
  if (click_token == INVALID_DEFERRED_TOKEN) {
    uint32_t next_delay_ms = auto_click_callback(0, NULL);
    click_token = defer_exec(next_delay_ms, auto_click_callback, NULL);
  }
}

// stops the autoclicker by cancelling the callback and releasing the key
void auto_click_stop(void) {
  if (click_token != INVALID_DEFERRED_TOKEN) {
    cancel_deferred_exec(click_token);
    click_token = INVALID_DEFERRED_TOKEN;
    // when stopping, release the key if it is pressed
    if (key_pressed && auto_key_keycode != 0) {
      unregister_code16(auto_key_keycode);
      key_pressed = false;
    }
  }
}
