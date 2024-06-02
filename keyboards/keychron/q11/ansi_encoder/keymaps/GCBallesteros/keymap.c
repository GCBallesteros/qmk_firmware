/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"


// Left-hand home row mods
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)

// Toggle layer 2 or tab
#define L2_TAB LT(2, KC_TAB)

// Calculator or ESC at CapsLock position
#define ESC_CA LT(3, KC_ESC)

// Extra keycodes
// defined on: keychron/common/keychron_common.h
// - VIMEND (g_)

// Combos
const uint16_t PROGMEM test_combo1[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_HOME, KC_END, COMBO_END};
const uint16_t PROGMEM test_combo3[] = {KC_G, KC_H, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_ENT),
    COMBO(test_combo2, KC_ENT),
    COMBO(test_combo3, KC_UNDS),
};

enum layers{
    _BASE,
    _NAV,
    _SYMBOL,
    _NUM,
    /* _RGB, */
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        MC_1,     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  XXXXXXX,  XXXXXXX,            KC_PGUP,
        MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  XXXXXXX,            KC_PGDN,
        MC_3,     ESC_CA,   KC_A,     KC_S,     HOME_D,   HOME_F,   KC_G,     KC_H,     HOME_J,   HOME_K,   KC_L,     KC_SCLN,  KC_QUOT,            XXXXXXX,            KC_HOME,
        MC_4,     KC_ENT,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            XXXXXXX,  KC_UP,
        MC_5,     XXXXXXX,  KC_LOPTN, KC_LCMMD, MO(_NAV),           L2_TAB,                       KC_SPC,             KC_RCMMD, MO(_NUM), KC_RCTL,  KC_LEFT,  KC_DOWN, KC_RGHT),

    [_NAV] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_HOME,  KC_END,   XXXXXXX,  XXXXXXX,  _______,  _______,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  KC_ESC,   KC_CIRC,  KC_DLR,   KC_LSFT,  KC_LCTL,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_ENT,   XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DEL,   XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_SPC,                       KC_BSPC,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    [_SYMBOL] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  KC_GRV,   KC_LABK,  KC_RABK,  XXXXXXX,  XXXXXXX,  KC_BSLS,  KC_ASTR,  KC_UNDS,  KC_AMPR,  XXXXXXX,  _______,  _______,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  _______,  KC_EXLM,  KC_MINS,  KC_PLUS,  KC_EQL,   KC_HASH,  KC_PIPE,  KC_LPRN,  KC_RPRN,  KC_AT,    XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  KC_TILD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_CIRC,  KC_DLR,   KC_PERC,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            _______,                      KC_BSPC,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    [_NUM] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PLUS,  KC_ASTR,  XXXXXXX,  XXXXXXX,  KC_7,     KC_8,     KC_9,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  _______,  XXXXXXX,  KC_LCTL,  KC_MINS,  KC_SLSH,  XXXXXXX,  KC_0,     KC_4,     KC_5,     KC_6,     XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_0,     KC_1,     KC_2,     KC_3,     XXXXXXX,            XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_DOT,                       KC_BSPC,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    /* [_RGB] = LAYOUT_91_ansi( */
    /*     RGB_TOG,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  _______,  RGB_TOG, */
    /*     _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______, */
    /*     _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______, */
    /*     _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______, */
    /*     _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______, */
    /*     _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______), */

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SYMBOL] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_NUM]    = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }

    switch (keycode) {
    case VIMEND:
        if (record->event.pressed) {
            SEND_STRING("g" SS_DELAY(50) "_");
        }
        return false;
    }

    return true;
}
