#include QMK_KEYBOARD_H

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
  {KC_SPC , KC_BSPC}, // Shift <space> is <b-space>
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // main layer (alphas)
    [0] = LAYOUT_split_3x5_3(
    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
    KC_A,           KC_S,           KC_D,           LT(2, KC_F),    KC_G,                    KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,
    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                    KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,
                                    KC_LALT,        LT(1, KC_ESC),  KC_SPC,                  KC_RSFT,        KC_RCTL,        KC_RGUI
    ),
    // numbers, symbols, and math related things
    [1] = LAYOUT_split_3x5_3(
    KC_PMNS,        KC_7,           KC_8,           KC_9,           KC_PPLS,                 KC_GRV,         KC_CIRC,         KC_LPRN,        KC_RPRN,        KC_BSLS,
    KC_0,           KC_4,           KC_5,           KC_6,           KC_EQL,                  KC_ASTR,        KC_DLR,          KC_LBRC,        KC_RBRC,        KC_QUOT,
    KC_NO,          KC_1,           KC_2,           KC_3,           KC_NO,                   KC_NO,          KC_UNDS,         KC_COMM,        KC_DOT,         KC_SLSH,
                                    KC_NO,          KC_TRNS,        KC_NO,                   KC_RSFT,        KC_RCTL,         KC_RGUI
    ),
    // general navigation
    [2] = LAYOUT_split_3x5_3(
    KC_ESC,        KC_NO,          LSFT(KC_TAB),   KC_NO,          KC_NO,                   KC_NO,          KC_VOLD,        KC_VOLU,        KC_NO,          KC_NO,
    KC_ENT,        KC_NO,          KC_TAB,         KC_TRNS,        KC_NO,                   KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        KC_ENT,
    LGUI(KC_DLR),  KC_NO,          KC_NO,          KC_NO,          KC_NO,                   KC_NO,          KC_BRID,        KC_BRIU,        KC_NO,          KC_NO,
                                   KC_NO,          KC_LSFT,        KC_BSPC,                 KC_RSFT,        KC_RCTL,        KC_RGUI
    ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_ESC):
            return TAPPING_TERM - 50;
        case LT(2, KC_F):
            return TAPPING_TERM - 65;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_custom_shift_keys(keycode, record)) {
        return false; // Custom shift keys handled, no further processing needed
    }
    switch (keycode) {
        case LT(2, KC_F):
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_RSFT)) {
                    tap_code(KC_F); // If shift is held, send KC_F directly
                    return false;
                } else {
                    return true;
                }
            }
    }
    return true; // Let QMK handle all other keycodes
}


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}


//    blank layer
//    [x] = LAYOUT_split_3x5_3(
//    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_NO,          KC_NO,        KC_NO,
//    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_NO,          KC_NO,        KC_NO,
//    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_NO,          KC_NO,        KC_NO,
//                                    KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_NO
//    )
