/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"

#define CTL_Z       CTL_T(KC_Z)
#define GUI_TAB     GUI_T(KC_TAB)
#define CTL_SLSH    CTL_T(KC_SLSH)
#define LT_NAVA     LT(_NAV, KC_A)
#define LT_NAVS     LT(_NAV, KC_SCLN)
#define LT_SYM      LT(_SYM, KC_S)
#define LT_NUM      LT(_NUM, KC_D)
#define LT_FUN      LT(_FUN, KC_F)
#define LT_GUI      LT(_GUI, KC_G)

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _ADJUST,
  _NAV,
  _SYM,
  _NUM,
  _FUN,
  _GUI,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | DEL  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   [  |   {  | Alt  | GUI  | Tab  |Space |Enter | Bksp | GUI  | Alt  |   }  |  ]   |
 * `-----------------------------------------+-----------------------------------------'
 */
[_QWERTY] = {
  {KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_MINS},
  {KC_ESC,  LT_NAVA, LT_SYM,  LT_NUM,  LT_FUN,  LT_GUI,  KC_H,    KC_J,    KC_K,    KC_L,    LT_NAVS,  KC_QUOT},
  {KC_LSPO, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLSH, KC_RSPC},
  {KC_LBRC, KC_LCBR, KC_LALT, KC_LGUI, GUI_TAB, KC_SPC,  KC_ENT,  KC_BSPC, KC_RGUI, KC_RALT, KC_RCBR,  KC_RBRC}
},

/* Arrow
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | NAV  | HOME | PgUp | PgDn | End  | LEFT | DOWN |  UP  | RIGHT| NAV  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------'-----------------------------------------'
 */
[_NAV] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   +  |   &  |   *  |   (  |   )  |  _   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | SYM  |      |      |      |   ~  |   $  |   %  |   ^  |   |  |  `   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   =  |   !  |   @  |   #  |   \  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = {
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_MINS)},
  {_______, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD, S(KC_4), S(KC_5), S(KC_6), KC_PIPE, KC_GRV},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  S(KC_1), S(KC_2), S(KC_3), KC_BSLS, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   +  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      | NUM  |      |      |   *  |   4  |   5  |   6  |   .  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   =  |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = {
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {_______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_DOT,  _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  KC_1,    KC_2,    KC_3,    _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* FUN
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  F7  |  F8  |  F9  |  F10 |Reset |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      | FUN  |      |      |  F4  |  F5  |  F6  |  F11 |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F12 |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUN] = {
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  RESET},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* GUI
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | I3 7 | I3 8 | I3 9 | I3 0 |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      | GUI  |      | I3 4 | I3 5 | I3 6 |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | I3 1 | I3 2 | I3 3 |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GUI] = {
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD(7),   TD(8),   TD(9),   TD(0),   _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, TD(4),   TD(5),   TD(6),   XXXXXXX, _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD(1),   TD(2),   TD(3),   XXXXXXX, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF, _______, _______, _______},
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______,  _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______}
}

};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //i3... Tap once for desktop #, twice move select to desktop #
  [0]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_0), S(LALT(KC_0))),
  [1]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_1), S(LALT(KC_1))),
  [2]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_2), S(LALT(KC_2))),
  [3]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_3), S(LALT(KC_3))),
  [4]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_4), S(LALT(KC_4))),
  [5]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_5), S(LALT(KC_5))),
  [6]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_6), S(LALT(KC_6))),
  [7]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_7), S(LALT(KC_7))),
  [8]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_8), S(LALT(KC_8))),
  [9]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_9), S(LALT(KC_9))),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode switched to qwerty\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
