/* Copyright 2024 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"
#include "features/autoclick_behaviour/autoclick.h"


enum {
    AUTOLMB = NEW_SAFE_RANGE,
    AUTORMB,
    SNAP,
};

//shorthand names for mouse keys
#define MS_UP KC_MS_U
#define MS_DOWN KC_MS_D
#define MS_LEFT KC_MS_L
#define MS_RGHT KC_MS_R
#define MS_WHLU KC_MS_WH_UP
#define MS_WHLD KC_MS_WH_DOWN
#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2

//mac/win_mouse is a custom layer containing mouse controls. I think I only need one layer, but let's add one for mac and one for windows
enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    MAC_MS,
    WIN_MS,
};
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,    KC_SNAP,  BAT_LVL,  RGB_MOD,  KC_F13,   KC_F14,   KC_F15,   KC_F16,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD,TG(MAC_MS),MO(MAC_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [MAC_FN] = LAYOUT_ansi_109(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
    [WIN_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_SWNS,  BAT_LVL,  KC_CALC,  _______,  SNAP   ,  AUTOLMB,  AUTORMB,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT, TG(WIN_MS),MO(WIN_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [WIN_FN] = LAYOUT_ansi_109(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  _______,  KC_MPLY,  _______,  KC_MPLY,  KC_MRWD,  KC_MPRV,  KC_MNXT,  KC_MFFD,    RGB_TOG,    KC_SNAP,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
    [MAC_MS] = LAYOUT_ansi_109(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  MS_WHLU,  MS_UP,    MS_WHLD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  MS_LEFT,  MS_DOWN,  MS_RGHT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        MS_BTN2,  _______,  _______,                                MS_BTN1,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
    [WIN_MS] = LAYOUT_ansi_109(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  MS_WHLU,  MS_UP,    MS_WHLD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  MS_LEFT,  MS_DOWN,  MS_RGHT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        MS_BTN2,  _______,  _______,                                MS_BTN1,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [MAC_MS]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_MS]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

#include "rgb_matrix.h"
#include "host.h"

#define SET_LED_ON(idx) rgb_matrix_set_color(idx, 255, 255, 255)

static bool LMB_Autoclick_enabled = false;
static bool RMB_Autoclick_enabled = false;
static bool snaptap_enabled = false;


//called when a custom indicator changes value, updates the indicators when the backlight is off
//I should probably add this to wireless/indicator.c
void update_led_status_user(void) {
    if (!rgb_matrix_is_enabled() || (rgb_matrix_is_enabled() && rgb_matrix_timeouted())) {
        led_set(host_keyboard_leds());
    }
}

void user_state_indicate(void) {
#    if defined(AUTOCLK_0_INDEX)
    if (LMB_Autoclick_enabled) {
        SET_LED_ON(AUTOCLK_0_INDEX);
    }
#    endif
#    if defined(AUTOCLK_1_INDEX)
    if (RMB_Autoclick_enabled) {
        SET_LED_ON(AUTOCLK_1_INDEX);
    }
#    endif
#    if defined(SNAPTAP_INDEX)
    if (snaptap_enabled) {
        SET_LED_ON(SNAPTAP_INDEX);
    }
#    endif
}

//do not shutdown rgb matrix when any of those lights are ON
bool rgb_matrix_driver_allow_shutdown_user(void) {
    return !(LMB_Autoclick_enabled || RMB_Autoclick_enabled || snaptap_enabled);
}


bool process_autoclick(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AUTOLMB:
            if (record->event.pressed) {
                LMB_Autoclick_enabled = !LMB_Autoclick_enabled;
                RMB_Autoclick_enabled = false;
            } else if (!LMB_Autoclick_enabled) {
                auto_click_stop();
            }
            update_led_status_user();
            return false;
        case AUTORMB:
            if (record->event.pressed) {
                RMB_Autoclick_enabled = !RMB_Autoclick_enabled;
                LMB_Autoclick_enabled = false;
            } else if (!RMB_Autoclick_enabled) {
                auto_click_stop();
            }
            update_led_status_user();
            return false;
        case OVERRIDDEN_AUTOCLICK_KEY:
            if (LMB_Autoclick_enabled || RMB_Autoclick_enabled) {
                if (record -> event.pressed) {
                    if (LMB_Autoclick_enabled) { //override 1
                        auto_click_start(MS_BTN1);
                    } else { //override 2
                        auto_click_start(MS_BTN2);
                    }
                } else {
                    auto_click_stop();
                }
                return false;

            } else {
                return true;
            }
        default:
            return true; // Process all other keycodes normally
    }
}


typedef struct {
    uint8_t keycode;
    bool pressed : 1;
    bool registered : 1;
    //skipped cannot be unregistered while pressed
    bool skipped : 1;
    //nullified is always unregistered on opposite press
    bool nullify : 1;
} snaptap_t;

snaptap_t AKey = {KC_A, false, false, false, false};
snaptap_t DKey = {KC_D, false, false, false, false};

snaptap_t WKey = {KC_W, false, false, true, false};
snaptap_t SKey = {KC_S, false, false, false, true};


bool process_snaptap_key(snaptap_t *key, keyrecord_t *record, snaptap_t *opposite) {
    key->pressed = (record->event.pressed);
    if (key->pressed) {
        //release opposite key on press
        if (opposite->registered) {
            //allows override of certain keys, so they take priority over others. Meant for skipped & nullified together
            //skips releasing the key if it has the .skipped flag, so it takes priority over its opposite
            if (!opposite->skipped) {
                unregister_code(opposite->keycode);
                opposite->registered = false;
            }

            //if both keys are pressed, nullify this key
            //this behaviour makes this key unregister itself when both it and the opposite are pressed.
            if (key->nullify) {
                key->registered = false;
                return false;
            }
        }
    } else {
        //restore opposite key state on this key's release
        if (opposite->pressed && !opposite->registered) {
            register_code(opposite->keycode);
            opposite->registered = true;
        }
        //when nullify is true, there is a chance for the key to have never been registered
        //ex: Wv-Sv-S^-W^ | S was only pressed while W also was, which nullified it
        if (key->nullify && !key->registered) {
            return false;
        }
    }
    //as long as we don't exit early, the key registered will match the key pressed because it will be handled normally
    key->registered = key->pressed;
    return true;
}


//NOTE: go to tmk_core > protocol > host.c > host_keyboard_leds to change default led state when disconnected


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == SNAP) {
        if (record->event.pressed) {
            snaptap_enabled = !snaptap_enabled;
            update_led_status_user();
        }
        return false;
    } else if (snaptap_enabled) {
        if (keycode == AKey.keycode) {
            return process_snaptap_key(&AKey, record, &DKey);
        } else if (keycode == DKey.keycode) {
            return process_snaptap_key(&DKey, record, &AKey);
        } else if (keycode == WKey.keycode) {
            return process_snaptap_key(&WKey, record, &SKey);
        } else if (keycode == SKey.keycode){
            return process_snaptap_key(&SKey, record, &WKey);
        }
    }

    if (!process_autoclick(keycode, record)) {
        return false;
    }

    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    return true;
}

