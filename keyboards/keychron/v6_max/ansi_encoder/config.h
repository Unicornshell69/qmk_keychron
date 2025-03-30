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

#pragma once

#ifdef RGB_MATRIX_ENABLE
/* RGB Matrix driver configuration */
#    define DRIVER_COUNT 2
#    define RGB_MATRIX_LED_COUNT 108

#    define SPI_SCK_PIN A5
#    define SPI_MISO_PIN A6
#    define SPI_MOSI_PIN A7

#    define DRIVER_CS_PINS \
        { B8, B9 }
#    define SNLED23751_SPI_DIVISOR 16
#    define SPI_DRIVER SPID1

/* Set LED driver current */
#    define SNLED27351_CURRENT_TUNE \
        { 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28 }

/* Set to infinit, which is use in USB mode by default */
#    define RGB_MATRIX_TIMEOUT RGB_MATRIX_TIMEOUT_INFINITE

/* Allow shutdown of led driver to save power */
#    define RGB_MATRIX_DRIVER_SHUTDOWN_ENABLE
/* Turn off backlight on low brightness to save power */
#    define RGB_MATRIX_BRIGHTNESS_TURN_OFF_VAL 32

/* Indications */
#    define NUM_LOCK_INDEX 37
#    define CAPS_LOCK_INDEX 61
#    define LOW_BAT_IND_INDEX \
        { 97 }

#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS

    /* Custom Key Indications */
#    define SNAPTAP_INDEX 17
#    define AUTOCLK_0_INDEX 18
#    define AUTOCLK_1_INDEX 19

#endif


/* Autoclicker Settings
This does nothing unless the autoclicker functions are used in keymap.c */
#define AUTOCLICK_PERIOD 30
#define OVERRIDDEN_AUTOCLICK_KEY KC_CAPS
            /* DEPRECATED */
//#    define AUTOCLICK_KEY_0 KC_MS_BTN1
//#    define AUTOCLICK_KEY_1 KC_MS_BTN2


//via layer count
#ifdef VIA_ENABLE
#    define DYNAMIC_KEYMAP_LAYER_COUNT 6
#endif

/* mouse settings */
#ifdef MOUSE_ENABLE
#    define MK_KINETIC_SPEED //speed up slow down mode
#    define MOUSEKEY_INTERVAL 10 //ms between movements
#    define MOUSEKEY_MOVE_DELTA 20 //acceleration initial -> base
#    define MOUSEKEY_INITIAL_SPEED 100 //speed at the beginning
#    define MOUSEKEY_BASE_SPEED 2500 //speed after being accelerated
#    define MOUSEKEY_ACCELERATED_SPEED 2000 //no fucking clue
#    define MOUSEKEY_DECELERATED_SPEED 200 /*no fucking clue*/
#endif



/* nrko is ON by default now */
//#ifdef NKRO_ENABLE
//#   define FORCE_NKRO
//#endif
