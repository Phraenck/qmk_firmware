/* Copyright 2020 ec965
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

enum custom_keycodes {
  CSTM_YES = SAFE_RANGE,
  CSTM_NA1,
  CSTM_NO,
  CSTM_NA2,
  CSTM_SIGN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_all(
        KC_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV, KC_BSPACE,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        MO(1),      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT,    KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, KC_RSFT, _______,
        KC_LCTL,    KC_LGUI, KC_LALT,                   _______,   KC_SPC,  _______,                     MO(3),   MO(1),   _______, MO(2),  KC_RCTL
    ),
	[1] = LAYOUT_all(
        KC_TILDE, KC_F1,   KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        _______,  KC_7,    KC_8,      KC_9,    _______, _______, KC_CALC, KC_PGUP, KC_UP,   KC_PGDN,  KC_PSCR, _______, _______, _______,
        _______,  KC_4,    KC_5,      KC_6,    KC_MUTE, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______,
        _______,  _______, KC_1,      KC_2,    KC_3,    KC_0,    _______, KC_END,  _______, _______,  _______, _______, _______, _______, _______,
        _______,  _______, KC_APP,                      _______, _______, _______,                    _______, _______, _______, _______, _______
    ),
	[2] = LAYOUT_all(
        RESET,   KC_F1,    KC_F2,    KC_F3,   KC_F4,    KC_F5,   KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, KC_DEL,
        _______, RGB_TOG,  RGB_MOD,  RGB_HUD, RGB_HUI,  RGB_SAD, RGB_SAI,   RGB_VAD, RGB_VAI, RGB_M_R, RGB_M_P, _______, _______,  _______,
        _______, CSTM_YES, CSTM_NA1, CSTM_NO, CSTM_NA2, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
        _______, _______,  _______,  _______, _______,  _______, _______,   _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_PGUP, _______,
        _______, _______,  KC_APP,                      _______, CSTM_SIGN, _______,                   _______, _______,  KC_END, KC_PGDN, KC_HOME
    ),
	[3] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,                   _______, _______, _______, _______, _______
    ),
};

#include "sendstring_dvorak.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case CSTM_YES:
      if(record->event.pressed)
        SEND_STRING("Yes\n");

      break;
    case CSTM_NA1:
      if(record->event.pressed)
        SEND_STRING("NA\n");

      break;
    case CSTM_NO:
      if(record->event.pressed)
        SEND_STRING("No\n");

      break;
    case CSTM_NA2:
      if(record->event.pressed)
        SEND_STRING("N/A\n");

      break;
    case CSTM_SIGN:
      if(record->event.pressed)
        SEND_STRING("Frank Duvendack");

      break;
  }

  return true;
}
