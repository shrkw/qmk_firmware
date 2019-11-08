/* Copyright 2019 Biacco42
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
  QWERTY = SAFE_RANGE,
  MCR1,
  MCR2,
  MCR3,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MCR1:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("D83EDD14"));  // 🤔
      }
      return false;
      break;
    case MCR2:
      if (record->event.pressed) {
        send_unicode_hex_string("0035 0030 0030 0030 5146 5186 6B32 3057 3044 0021");  // 5000兆円欲しい!
      }
      return false;
      break;
    case MCR3:
      if (record->event.pressed) {
        SEND_STRING("hellohello");
      }
      return false;
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    MCR1,  MCR2,  LGUI(LALT(KC_LEFT)), LGUI(LALT(KC_RIGHT)) \
  )
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

