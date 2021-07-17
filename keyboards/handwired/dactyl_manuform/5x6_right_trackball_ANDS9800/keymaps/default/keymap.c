/* Copyright 2021 zangxc
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

#include "5x6_right_trackball_ANDS9800.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE
};

// Defines the keycodes used by our macros in process_record_user

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
            KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, \
            KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, \
            KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, \
            KC_N, KC_M, KC_COMM, KC_DOT, KC_DOWN, KC_RIGHT, \
                        KC_LEFT, KC_UP,           \
                KC_SPACE,                     \
        KC_RCTRL,                               \
    KC_RGUI, KC_RSFT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
