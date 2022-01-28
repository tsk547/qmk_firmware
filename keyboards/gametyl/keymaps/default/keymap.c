// Copyright 2022 Brandon Smith (@tsk547)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY
};

enum custom_keycodes {
    VVV = KC_TRNS,
    XXX = KC_NO,
    EnSH = MT(MOD_LSFT, KC_ENT);
    OSCHAT = OSL(_FFCHAT);

};

enum macro_events {
    M_CHAT = SAFE_RANGE,
    M_ECHAT,
    M_JUMP
}

bool spam_space;
unit16_t spam_timer = flase;
unit16_t spam_interval = 100;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) { // This will do most of the grunt work with the keycodes.
    case M_CHAT:
      if (record->event.pressed) {
        tap_code(KC_ENT);
        layer_move(_FFCHAT);
      } 
      break;
      return false;
    case: M_ECHAT:
      if (record->event.pressed) {
        tap_code(KC_ESC);
        layer_move(_FFXIV);
      } 
      break;
      return false;
    case: M_JUMP:
      if (record->event.pressed){
        spam_space ^= 1; 
        spam_timer = timer_read();
      } else {

      }
      break;
      return false;
  }
  return true;
}

void matrix_scan_user(void) {
  if (spam_space && timer_elapsed(spam_timer) >= spam_interval) {
     spam_timer = timer_read();
     tap_code(KC_SPC);
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_QWERTY] = LAYOUT_split_3x5_3(
        //|-----------------------------------------------------|                    |-----------------------------------------------------|
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_RCTL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_SPC,  (layer),   (os),    EnSH, (layer),  (fn)
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),
    [_SYMBOLS] = LAYOUT_split_3x5_3(
        //|-----------------------------------------------------|                    |-----------------------------------------------------|
        //      `      f1       f2       f3      f4      f5                             f6       f7        f8       f9      f10      -
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        //             f11      f12                                                                       up        [       ]        =
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        //                           DF(_FFXIV),                                                left      down    right              ;
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        //                                                                                                                  \
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),
    [_FFXIV] = LAYOUT_split_3x5_3(
        //|-----------------------------------------------------|                    |-----------------------------------------------------|
        //                                                F1                            M_JUMP  NUM7     NUM9
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        //                     alt     space              F2                            Hud up  KC_1     KC_4     KC_7    KC_0 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        //    tab    f11      ctrl      NUM8    shift     F3                            NUM0    KC_2     KC_5     KC_8    KC_MINS
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        //                    NUM4      NUM2     NUM6     F4                           hud down KC_3     KC_6     KC_9    KC_EQL
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_SPC,  (layer), ,           M_CHAT, OSCHAT   KC_ESC,     
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),
    [_FFCHAT] = LAYOUT_split_3x5_3(
        //|-----------------------------------------------------|                    |-----------------------------------------------------|
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_RCTL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_SPC,  (layer),   (os),    EnSH,    (layer), M_ECHAT
        //                                    |--------+--------+--------|  |--------+--------+--------|
};


 
