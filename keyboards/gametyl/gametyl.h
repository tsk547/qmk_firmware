// Copyright 2022 Brandon Smith (@tsk547)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

#define XXX KC_NO

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT_split_4x6_3(\
    L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05 \
    L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15 \
    L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25 \
    L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35 \
                                 L43, L44,         R41, R42 \
                                      L45,         R40 \
) { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { XXX, XXX, XXX, L43, L44, L45 }, \
\
    { R00, R01, R02, R03, R04, R05 }, \
    { R10, R11, R12, R13, R14, R15 }, \
    { R20, R21, R22, R23, R24, R25 }, \
    { R30, R31, R32, R33, R34, R35 }, \
    { R40, R41, R42, KC_NO, KC_NO, KC_NO }, \
}

// #define LAYOUT_split_3x5_3(\
//   L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05\
//   L10, L11, L12, L13, L14, L15,                         R10, R11, R12, R13, R14, R15\
//   L20, L21, L22, L23, L24, L25,                         R20, R21, R22, R23, R24, R25\
//   L30, L31, L32, L33, L34, L35,                         R30, R31, R32, R33, R34, R35\
//                  L43, L44, L45,                          R40, R41, R42            \
//   ) \
//   { \
//     { L00,   L01,   L02, L03, L04, L05}, \
//     { L10,   L11,   L12, L13, L14, L15}, \
//     { L20,   L21,   L22, L23, L24, L25}, \
//     { L30,   L31,   L32, L33, L34, L35}, \
//     { KC_NO, KC_NO, KC_NO, L43, L44, L45}, \
//                                           \
//     { R00, R01, R02, R03,   R04, R05  }, \
//     { R10, R11, R12, R13,   R14, R15  }, \
//     { R20, R21, R22, R23,   R24, R25  }, \
//     { R30, R31, R32, R33,   R34, R3S5  }, \
//     { R40, R41, R42, KC_NO, KC_NO, KC_NO }, \
// }

