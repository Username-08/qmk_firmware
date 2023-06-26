// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │GUI├───┐           ┌───┤Alt│
     *               └───┤Bsp├───┐   ┌───┤Ent├───┘
     *                   └───┤   │   │   ├───┘
     *                       └───┘   └───┘
     */
    // clang-format off
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_RALT,
        CTL_T(KC_GRV),  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    LT(3, KC_DEL),
        KC_NO,          KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                               KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
                                     LT(2, KC_ESC), KC_BSPC,  KC_LSFT,                        KC_LGUI,    KC_SPC,   LT(1, KC_ENT)
    ),
    [1] = LAYOUT_split_3x6_3(
        KC_TRNS,  KC_QUOTE,    KC_DLR,     KC_COLN,    KC_DQT,     KC_EXLM,                            KC_HASH,   KC_PERC,  KC_CIRC,   KC_AMPR,    KC_PIPE,   KC_TRNS,
        KC_TRNS,  KC_LT,    KC_LBRC,    KC_LCBR,    KC_LPRN,    KC_BSLS,                               KC_ASTR,   KC_PLUS, KC_EQL,    KC_MINS,    KC_UNDS,   KC_TRNS,
        KC_TRNS,  KC_GT,    KC_RBRC,    KC_RCBR,    KC_RPRN,    KC_AT,                               KC_K,      KC_M,    KC_COMM,   KC_DOT,     KC_SLSH,   KC_TRNS,
                                         KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS,  KC_TRNS
    ),
    [2] = LAYOUT_split_3x6_3(
        KC_TRNS,  KC_UNDS,    KC_ASTR,            KC_MINS,         KC_EQL,     KC_PLUS,                            KC_TRNS,   KC_1,  KC_2,   KC_3,    KC_TRNS,   KC_TRNS,
        KC_TRNS,  KC_PERC,    LALT_T(KC_SLSH),    KC_COMM,    KC_DOT, KC_BSLS,                            KC_ASTR,   KC_4, KC_5,    KC_6,    KC_0,   KC_TRNS,
        KC_TRNS,  KC_TRNS,    LSG(KC_NO),            KC_LPRN,         KC_RPRN,    KC_TRNS,                             KC_TRNS,      KC_7,    KC_8,   KC_9,     KC_TRNS,   KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS,  KC_TRNS
    ),
    [3] = LAYOUT_split_3x6_3(
        KC_TRNS,  KC_TRNS,    KC_HOME,            KC_UP,         KC_END,     KC_PGUP,                            KC_TRNS,   KC_F1,  KC_F2,   KC_F3,    KC_F10,   KC_TRNS,
        KC_TRNS,  KC_TRNS,    KC_LEFT,            KC_DOWN,         KC_RIGHT,     KC_PGDN,                            KC_TRNS,   KC_F4, KC_F5,    KC_F6,    KC_F11,   KC_TRNS,
        KC_TRNS,  KC_TRNS,    KC_TRNS,            KC_TRNS,         KC_TRNS,    KC_TRNS,                             KC_TRNS,      KC_F7,    KC_F8,   KC_F9,     KC_F12,   KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS,  KC_TRNS
    )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
