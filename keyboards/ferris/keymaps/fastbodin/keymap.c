#include QMK_KEYBOARD_H

#define OSM_G OSM(MOD_LGUI)
#define OSM_S OSM(MOD_LSFT)

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
  {KC_SPC , KC_BSPC}, // Shift <space> is <b-space>
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // main layer (alphas)
    [0] = LAYOUT_split_3x5_2(
    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
    KC_A,           KC_S,           KC_D,           LT(3, KC_F),    KC_G,                    KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,
    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                    KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,
                                                    LT(2, KC_ESC),  KC_SPC,                  KC_RSFT,        MO(1)
    ),
    // manual control layer
    [1] = LAYOUT_split_3x5_2(
    LCTL(KC_Q),     LCTL(KC_W),     LCTL(KC_E),     LCTL(KC_R),     LCTL(KC_T),              RCTL(KC_Y),     RCTL(KC_U),     RCTL(KC_I),     RCTL(KC_O),     RCTL(KC_P),
    LCTL(KC_A),     LCTL(KC_S),     LCTL(KC_D),     LCTL(KC_F),     LCTL(KC_G),              RCTL(KC_H),     RCTL(KC_J),     RCTL(KC_K),     RCTL(KC_L),     RCTL(KC_SCLN),
    LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_B),              RCTL(KC_N),     RCTL(KC_M),     RCTL(KC_COMM),  RCTL(KC_DOT),   RCTL(KC_SLSH),
                                                    MO(4),          KC_BSPC,                 KC_NO,          KC_TRNS
    ),
    // this layer is for numbers, symbols, and math related things
    [2] = LAYOUT_split_3x5_2(
    KC_PMNS,        KC_7,           KC_8,           KC_9,           KC_PPLS,                 KC_GRV,         KC_CIRC,         KC_LPRN,        KC_RPRN,        KC_BSLS,
    KC_0,           KC_4,           KC_5,           KC_6,           KC_EQL,                  KC_ASTR,        KC_DLR,          KC_LBRC,        KC_RBRC,        KC_QUOT,
    KC_NO,          KC_1,           KC_2,           KC_3,           KC_NO,                   KC_NO,          KC_UNDS,         KC_COMM,        KC_DOT,         KC_SLSH,
                                                    KC_TRNS,        KC_NO,                   KC_RSFT,        MO(4)
    ),
    // this layer is for general navigation and nvim
    [3] = LAYOUT_split_3x5_2(
    KC_ESC,        LALT(KC_TAB),   LSFT(KC_TAB),   KC_NO,          KC_NO,                   RCTL(KC_Y),     KC_VOLD,        KC_VOLU,        KC_NO,          RCTL(KC_P),
    KC_ENT,        OSM_G,          KC_TAB,         KC_TRNS,        KC_NO,                   KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        KC_ENT,
    LGUI(KC_DLR),  KC_NO,          KC_NO,          KC_NO,          KC_NO,                   RCTL(KC_N),     RGUI(KC_MINS),  RGUI(KC_EQL),   KC_NO,          KC_NO,
                                                   KC_LSFT,        KC_BSPC,                 KC_RSFT,        KC_RCTL
    ),
    //this layer navigates between workspaces in aerospace
    [4] = LAYOUT_split_3x5_2(
    QK_BOOT,        LALT(KC_W),     LALT(KC_E),     LALT(KC_R),     LALT(KC_T),             RALT(KC_Y),     RSA(KC_MINS),    RSA(KC_EQL),   RALT(KC_O),   RALT(KC_P),
    LALT(KC_A),     LALT(KC_S),     LALT(KC_D),     LALT(KC_F),     LALT(KC_G),             RALT(KC_H),     RALT(KC_J),      RALT(KC_K),    RALT(KC_L),   OSM_S,
    LALT(KC_Z),     LALT(KC_X),     LALT(KC_C),     LALT(KC_V),     LALT(KC_B),             RALT(KC_N),     RALT(KC_M),      RSFT(KC_COMM), KC_DOT,       RALT(KC_SLSH),
                                                    KC_TRNS,        KC_NO,                  KC_NO,          KC_TRNS
    )
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(3, KC_F):
            return TAPPING_TERM - 75;
        case LT(2, KC_ESC):
            return TAPPING_TERM - 75;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_custom_shift_keys(keycode, record)) {
        return false; // Custom shift keys handled, no further processing needed
    }
    switch (keycode) {
        case LT(3, KC_F):
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
        case LT(2, KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}



//    // main layer (alphas)
//    [0] = LAYOUT_split_3x5_2(
//    KC_W,           KC_L,           KC_Y,           KC_P,           KC_B,                    KC_Z,           KC_F,           KC_O,           KC_U,           KC_QUOT,
//    KC_C,           KC_R,           KC_S,           KC_T,           KC_G,                    KC_M,           KC_N,           KC_E,           KC_I,           KC_A,
//    KC_Q,           KC_J,           KC_V,           KC_D,           KC_K,                    KC_X,           KC_H,           KC_SLSH,        KC_COMM,        KC_DOT,
//                                                    LT(2, KC_ESC),  KC_SPC,                  KC_RSFT,        MO(1)
//    ),
//
//    // manual control layer
//    [1] = LAYOUT_split_3x5_2(
//    LCTL(KC_Q),     LCTL(KC_W),     LCTL(KC_E),     LCTL(KC_R),     LCTL(KC_T),              RCTL(KC_Y),     RCTL(KC_U),     RCTL(KC_I),     RCTL(KC_O),     RCTL(KC_P),
//    LCTL(KC_A),     LCTL(KC_S),     LCTL(KC_D),     LCTL(KC_F),     LCTL(KC_G),              RCTL(KC_H),     RCTL(KC_J),     RCTL(KC_K),     RCTL(KC_L),     RCTL(KC_SCLN),
//    LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_B),              RCTL(KC_N),     RCTL(KC_M),     RCTL(KC_COMM),  RCTL(KC_DOT),   RCTL(KC_SLSH),
//                                                    MO(4),          KC_BSPC,                 KC_NO,          KC_TRNS
//    ),
