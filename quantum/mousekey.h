/*
Copyright 2011 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <stdint.h>
#include "host.h"

#ifndef MK_3_SPEED

/* max value on report descriptor */
#    ifndef MOUSEKEY_MOVE_MAX
#        define MOUSEKEY_MOVE_MAX 127
#    elif MOUSEKEY_MOVE_MAX > 127
#        error MOUSEKEY_MOVE_MAX needs to be smaller than 127
#    endif

#    ifndef MOUSEKEY_WHEEL_MAX
#        define MOUSEKEY_WHEEL_MAX 127
#    elif MOUSEKEY_WHEEL_MAX > 127
#        error MOUSEKEY_WHEEL_MAX needs to be smaller than 127
#    endif

#    ifndef MOUSEKEY_MOVE_DELTA
#        if defined(MK_KINETIC_SPEED)
#            define MOUSEKEY_MOVE_DELTA 16
#        elif defined(MOUSEKEY_INERTIA)
#            define MOUSEKEY_MOVE_DELTA 1
#        else
#            define MOUSEKEY_MOVE_DELTA 8
#        endif
#    endif
#    ifndef MOUSEKEY_DELAY
#        if defined(MK_KINETIC_SPEED)
#            define MOUSEKEY_DELAY 5
#        elif defined(MOUSEKEY_INERTIA)
#            define MOUSEKEY_DELAY 150 // allow single-pixel movements before repeat activates
#        else
#            define MOUSEKEY_DELAY 10
#        endif
#    endif
#    ifndef MOUSEKEY_INTERVAL
#        if defined(MK_KINETIC_SPEED)
#            define MOUSEKEY_INTERVAL 10
#        elif defined(MOUSEKEY_INERTIA)
#            define MOUSEKEY_INTERVAL 16 // 60 fps
#        else
#            define MOUSEKEY_INTERVAL 20
#        endif
#    endif
#    ifndef MOUSEKEY_MAX_SPEED
#        if defined(MOUSEKEY_INERTIA)
#            define MOUSEKEY_MAX_SPEED 32
#        else
#            define MOUSEKEY_MAX_SPEED 10
#        endif
#    endif
#    ifndef MOUSEKEY_TIME_TO_MAX
#        if defined(MOUSEKEY_INERTIA)
#            define MOUSEKEY_TIME_TO_MAX 32
#        else
#            define MOUSEKEY_TIME_TO_MAX 30
#        endif
#    endif
#    ifndef MOUSEKEY_WHEEL_DELAY
#        define MOUSEKEY_WHEEL_DELAY 10
#    endif
#    ifndef MOUSEKEY_WHEEL_INTERVAL
#        define MOUSEKEY_WHEEL_INTERVAL 80
#    endif
#    ifndef MOUSEKEY_WHEEL_DELTA
#        define MOUSEKEY_WHEEL_DELTA 1
#    endif
#    ifndef MOUSEKEY_WHEEL_MAX_SPEED
#        define MOUSEKEY_WHEEL_MAX_SPEED 8
#    endif
#    ifndef MOUSEKEY_WHEEL_TIME_TO_MAX
#        define MOUSEKEY_WHEEL_TIME_TO_MAX 40
#    endif

#    ifndef MOUSEKEY_FRICTION
#        define MOUSEKEY_FRICTION 24 // 0 to 255
#    endif
#    ifndef MOUSEKEY_INITIAL_SPEED
#        define MOUSEKEY_INITIAL_SPEED 100
#    endif
#    ifndef MOUSEKEY_BASE_SPEED
#        define MOUSEKEY_BASE_SPEED 5000
#    endif
#    ifndef MOUSEKEY_DECELERATED_SPEED
#        define MOUSEKEY_DECELERATED_SPEED 400
#    endif
#    ifndef MOUSEKEY_ACCELERATED_SPEED
#        define MOUSEKEY_ACCELERATED_SPEED 3000
#    endif
#    ifndef MOUSEKEY_WHEEL_INITIAL_MOVEMENTS
#        define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 16
#    endif
#    ifndef MOUSEKEY_WHEEL_BASE_MOVEMENTS
#        define MOUSEKEY_WHEEL_BASE_MOVEMENTS 32
#    endif
#    ifndef MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS
#        define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48
#    endif
#    ifndef MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS
#        define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8
#    endif

#else /* #ifndef MK_3_SPEED */

#    ifndef MK_C_OFFSET_UNMOD
#        define MK_C_OFFSET_UNMOD 16
#    endif
#    ifndef MK_C_INTERVAL_UNMOD
#        define MK_C_INTERVAL_UNMOD 16
#    endif
#    ifndef MK_C_OFFSET_0
#        define MK_C_OFFSET_0 1
#    endif
#    ifndef MK_C_INTERVAL_0
#        define MK_C_INTERVAL_0 32
#    endif
#    ifndef MK_C_OFFSET_1
#        define MK_C_OFFSET_1 4
#    endif
#    ifndef MK_C_INTERVAL_1
#        define MK_C_INTERVAL_1 16
#    endif
#    ifndef MK_C_OFFSET_2
#        define MK_C_OFFSET_2 32
#    endif
#    ifndef MK_C_INTERVAL_2
#        define MK_C_INTERVAL_2 16
#    endif

#    ifndef MK_W_OFFSET_UNMOD
#        define MK_W_OFFSET_UNMOD 1
#    endif
#    ifndef MK_W_INTERVAL_UNMOD
#        define MK_W_INTERVAL_UNMOD 40
#    endif
#    ifndef MK_W_OFFSET_0
#        define MK_W_OFFSET_0 1
#    endif
#    ifndef MK_W_INTERVAL_0
#        define MK_W_INTERVAL_0 360
#    endif
#    ifndef MK_W_OFFSET_1
#        define MK_W_OFFSET_1 1
#    endif
#    ifndef MK_W_INTERVAL_1
#        define MK_W_INTERVAL_1 120
#    endif
#    ifndef MK_W_OFFSET_2
#        define MK_W_OFFSET_2 1
#    endif
#    ifndef MK_W_INTERVAL_2
#        define MK_W_INTERVAL_2 20
#    endif

#endif /* #ifndef MK_3_SPEED */

#ifndef MOUSEKEY_OVERLAP_MOVE_DELTA
#    define MOUSEKEY_OVERLAP_MOVE_DELTA MOUSEKEY_MOVE_DELTA
#endif
#ifndef MOUSEKEY_OVERLAP_WHEEL_DELTA
#    define MOUSEKEY_OVERLAP_WHEEL_DELTA MOUSEKEY_WHEEL_DELTA
#endif
#ifndef MOUSEKEY_OVERLAP_INTERVAL
#    define MOUSEKEY_OVERLAP_INTERVAL MOUSEKEY_INTERVAL
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern uint8_t mk_delay;
extern uint8_t mk_interval;
extern uint8_t mk_max_speed;
extern uint8_t mk_time_to_max;
extern uint8_t mk_wheel_max_speed;
extern uint8_t mk_wheel_time_to_max;

void           mousekey_task(void);
void           mousekey_on(uint8_t code);
void           mousekey_off(uint8_t code);
void           mousekey_clear(void);
void           mousekey_send(void);
report_mouse_t mousekey_get_report(void);
bool           should_mousekey_report_send(report_mouse_t *mouse_report);

#ifdef __cplusplus
}
#endif/*
Copyright 2011 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <stdint.h>
#include "host.h"

#ifndef MK_3_SPEED

/* max value on report descriptor */
#    ifndef MOUSEKEY_MOVE_MAX
#        define MOUSEKEY_MOVE_MAX 127
#    elif MOUSEKEY_MOVE_MAX > 127
#        error MOUSEKEY_MOVE_MAX needs to be smaller than 127
#    endif

#    ifndef MOUSEKEY_WHEEL_MAX
#        define MOUSEKEY_WHEEL_MAX 127
#    elif MOUSEKEY_WHEEL_MAX > 127
#        error MOUSEKEY_WHEEL_MAX needs to be smaller than 127
#    endif

#    ifndef MOUSEKEY_MOVE_DELTA
#        if defined(MK_KINETIC_SPEED)
#            define MOUSEKEY_MOVE_DELTA 16
#        elif defined(MOUSEKEY_INERTIA)
#            define MOUSEKEY_MOVE_DELTA 1
#        else
#            define MOUSEKEY_MOVE_DELTA 8
#        endif
#    endif
#    ifndef MOUSEKEY_DELAY
#        if defined(MK_KINETIC_SPEED)
#            define MOUSEKEY_DELAY 5
#        elif defined(MOUSEKEY_INERTIA)
#            define MOUSEKEY_DELAY 150 // allow single-pixel movements before repeat activates
#        else
#            define MOUSEKEY_DELAY 10
#        endif
#    endif
#    ifndef MOUSEKEY_INTERVAL
#        if defined(MK_KINETIC_SPEED)
#            define MOUSEKEY_INTERVAL 10
#        elif defined(MOUSEKEY_INERTIA)
#            define MOUSEKEY_INTERVAL 16 // 60 fps
#        else
#            define MOUSEKEY_INTERVAL 20
#        endif
#    endif
#    ifndef MOUSEKEY_MAX_SPEED
#        if defined(MOUSEKEY_INERTIA)
#            define MOUSEKEY_MAX_SPEED 32
#        else
#            define MOUSEKEY_MAX_SPEED 10
#        endif
#    endif
#    ifndef MOUSEKEY_TIME_TO_MAX
#        if defined(MOUSEKEY_INERTIA)
#            define MOUSEKEY_TIME_TO_MAX 32
#        else
#            define MOUSEKEY_TIME_TO_MAX 30
#        endif
#    endif
#    ifndef MOUSEKEY_WHEEL_DELAY
#        define MOUSEKEY_WHEEL_DELAY 10
#    endif
#    ifndef MOUSEKEY_WHEEL_INTERVAL
#        define MOUSEKEY_WHEEL_INTERVAL 80
#    endif
#    ifndef MOUSEKEY_WHEEL_DELTA
#        define MOUSEKEY_WHEEL_DELTA 1
#    endif
#    ifndef MOUSEKEY_WHEEL_MAX_SPEED
#        define MOUSEKEY_WHEEL_MAX_SPEED 8
#    endif
#    ifndef MOUSEKEY_WHEEL_TIME_TO_MAX
#        define MOUSEKEY_WHEEL_TIME_TO_MAX 40
#    endif

#    ifndef MOUSEKEY_FRICTION
#        define MOUSEKEY_FRICTION 24 // 0 to 255
#    endif
#    ifndef MOUSEKEY_INITIAL_SPEED
#        define MOUSEKEY_INITIAL_SPEED 100
#    endif
#    ifndef MOUSEKEY_BASE_SPEED
#        define MOUSEKEY_BASE_SPEED 5000
#    endif
#    ifndef MOUSEKEY_DECELERATED_SPEED
#        define MOUSEKEY_DECELERATED_SPEED 400
#    endif
#    ifndef MOUSEKEY_ACCELERATED_SPEED
#        define MOUSEKEY_ACCELERATED_SPEED 3000
#    endif
#    ifndef MOUSEKEY_WHEEL_INITIAL_MOVEMENTS
#        define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 16
#    endif
#    ifndef MOUSEKEY_WHEEL_BASE_MOVEMENTS
#        define MOUSEKEY_WHEEL_BASE_MOVEMENTS 32
#    endif
#    ifndef MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS
#        define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48
#    endif
#    ifndef MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS
#        define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8
#    endif

#else /* #ifndef MK_3_SPEED */

#    ifndef MK_C_OFFSET_UNMOD
#        define MK_C_OFFSET_UNMOD 16
#    endif
#    ifndef MK_C_INTERVAL_UNMOD
#        define MK_C_INTERVAL_UNMOD 16
#    endif
#    ifndef MK_C_OFFSET_0
#        define MK_C_OFFSET_0 1
#    endif
#    ifndef MK_C_INTERVAL_0
#        define MK_C_INTERVAL_0 32
#    endif
#    ifndef MK_C_OFFSET_1
#        define MK_C_OFFSET_1 4
#    endif
#    ifndef MK_C_INTERVAL_1
#        define MK_C_INTERVAL_1 16
#    endif
#    ifndef MK_C_OFFSET_2
#        define MK_C_OFFSET_2 32
#    endif
#    ifndef MK_C_INTERVAL_2
#        define MK_C_INTERVAL_2 16
#    endif

#    ifndef MK_W_OFFSET_UNMOD
#        define MK_W_OFFSET_UNMOD 1
#    endif
#    ifndef MK_W_INTERVAL_UNMOD
#        define MK_W_INTERVAL_UNMOD 40
#    endif
#    ifndef MK_W_OFFSET_0
#        define MK_W_OFFSET_0 1
#    endif
#    ifndef MK_W_INTERVAL_0
#        define MK_W_INTERVAL_0 360
#    endif
#    ifndef MK_W_OFFSET_1
#        define MK_W_OFFSET_1 1
#    endif
#    ifndef MK_W_INTERVAL_1
#        define MK_W_INTERVAL_1 120
#    endif
#    ifndef MK_W_OFFSET_2
#        define MK_W_OFFSET_2 1
#    endif
#    ifndef MK_W_INTERVAL_2
#        define MK_W_INTERVAL_2 20
#    endif

#endif /* #ifndef MK_3_SPEED */

#ifndef MOUSEKEY_OVERLAP_MOVE_DELTA
#    define MOUSEKEY_OVERLAP_MOVE_DELTA MOUSEKEY_MOVE_DELTA
#endif
#ifndef MOUSEKEY_OVERLAP_WHEEL_DELTA
#    define MOUSEKEY_OVERLAP_WHEEL_DELTA MOUSEKEY_WHEEL_DELTA
#endif
#ifndef MOUSEKEY_OVERLAP_INTERVAL
#    define MOUSEKEY_OVERLAP_INTERVAL MOUSEKEY_INTERVAL
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern uint8_t mk_delay;
extern uint8_t mk_interval;
extern uint8_t mk_max_speed;
extern uint8_t mk_time_to_max;
extern uint8_t mk_wheel_max_speed;
extern uint8_t mk_wheel_time_to_max;

void           mousekey_task(void);
void           mousekey_on(uint8_t code);
void           mousekey_off(uint8_t code);
void           mousekey_clear(void);
void           mousekey_send(void);
report_mouse_t mousekey_get_report(void);
bool           should_mousekey_report_send(report_mouse_t *mouse_report);

#ifdef __cplusplus
}
#endif
