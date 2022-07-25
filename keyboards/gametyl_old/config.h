#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define PRODUCT_ID 0x3536
#define DEVICE_VER 0x0001
#define VENDOR_ID    0x444D
#define MANUFACTURER tsk5
#define PRODUCT    gametyl

/* mouse config */
#define MOUSEKEY_INTERVAL    20
#define MOUSEKEY_DELAY       0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED   7
#define MOUSEKEY_WHEEL_DELAY 0

#ifdef RGB_MATRIX_ENABLE
// #  define RGB_DISABLE_TIMEOUT 300000 // number of milliseconds to wait until disabling effects
// #  define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#  define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#  define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#  define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#  define RGB_MATRIX_HUE_STEP 8
#  define RGB_MATRIX_SAT_STEP 8
#  define RGB_MATRIX_VAL_STEP 8
#  define RGB_MATRIX_SPD_STEP 10

# define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
# define ENABLE_RGB_MATRIX_HUE_WAVE

#endif

/* key matrix size */
// Rows are doubled-up
/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }
// #define MATRIX_ROW_PINS { F6, F7, B1, B3, B2, B6 }
#define MATRIX_ROW_PINS { F7, B1, B3, B2, B6 }

#define DIODE_DIRECTION COL2ROW

// WS2812 RGB LED strip input and number of LEDs
#define RGB_DI_PIN D3
#define DRIVER_LED_TOTAL 54
#define RGB_MATRIX_SPLIT { 27, 27 }
#define RGB_MATRIX_CENTER { 133, 45 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
// #ifdef USE_SERIAL
//   #undef USE_SERIAL
// #endif
// #ifdef SOFT_SERIAL_PIN
//   #undef SOFT_SERIAL_PIN
// #endif

#define SOFT_SERIAL_PIN D0

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Enables This makes it easier for fast typists to use dual-function keys */
#define PERMISSIVE_HOLD