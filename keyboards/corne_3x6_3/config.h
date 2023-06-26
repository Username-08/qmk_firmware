// Copyright 2023 Username-08 (@Username-08)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
#define TAPPING_TERM 300
// #define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS


#define MATRIX_ROW_PINS_RIGHT {B12, B13, B14, A10}
#define MATRIX_COL_PINS_RIGHT {B0, A0, B1, B11, A3, A1}

#define USE_SERIAL
#define SERIAL_DEBUG
#define SOFT_SERIAL_PIN A5
#define SELECT_SOFT_SERIAL_SPEED 3
#define SPLIT_MAX_CONNECTION_ERRORS 10


// #define SPLIT_USB_DETECT
// #define SPLIT_USB_TIMEOUT 5000

#define EE_HANDS



// #define BACKLIGHT_PWM_DRIVER  PWMD2
// #define BACKLIGHT_PWM_CHANNEL 1
// //
// #define ADC_PIN A0
//
// #define RGB_CI_PIN A2
