#include QMK_KEYBOARD_H

#define ONESHOT_TIMEOUT 1500  /* Time (in ms) before the one shot key is released */

#define OSM_S_A OSM(MOD_RALT|MOD_RSFT)

#define OSM_G OSM(MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // main layer, alphas
    [0] = LAYOUT_split_3x5_3(
    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
    KC_A,           KC_S,           LT(3, KC_D),    LT(2, KC_F),    KC_G,                       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,
    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                       KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,
                                    KC_NO,          LT(1, KC_ESC),  KC_BSPC,                    RSFT_T(KC_SPC), KC_RCTL,        KC_NO
    ),
    // this layer is for numbers, symbols, and math related things
    [1] = LAYOUT_split_3x5_3(
    KC_PMNS,        KC_7,           KC_8,           KC_9,           KC_PPLS,                    KC_GRV,         KC_CIRC,        KC_LPRN,        KC_RPRN,        KC_BSLS,
    KC_0,           KC_4,           KC_5,           KC_6,           KC_PEQL,                    KC_ASTR,        KC_DLR,         KC_LBRC,        KC_RBRC,        KC_QUOT,
    KC_NO,          KC_1,           KC_2,           KC_3,           KC_PDOT,                    KC_NO,          KC_UNDS,        KC_COMM,        KC_DOT,         KC_SLSH,
                                    KC_NO,          KC_TRNS,        KC_NO,                      RSFT_T(KC_SPC), KC_RCTL,   KC_NO
    ),
    // this layer is for general navigation and nvim
    [2] = LAYOUT_split_3x5_3(
    OSM_G,          LGUI(KC_V),     LSFT(KC_TAB),   KC_NO,          KC_NO,                      LCTL(KC_Y),     KC_NO,          KC_VOLU,        KC_VOLD,        RCTL(KC_P),
    KC_ENT,         LGUI(KC_C),     KC_TAB,         KC_TRNS,        KC_NO,                      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        KC_ENT,
    LGUI(KC_Z),     KC_NO,          KC_NO,          KC_NO,          KC_NO,                      LCTL(KC_N),     KC_NO,          KC_BRIU,        KC_BRID,        KC_NO,
                                    KC_NO,          KC_LSFT,        KC_LGUI,                    RSFT_T(KC_SPC), KC_RCTL,        KC_NO
    ),
    // this layer is for aerospace nagivation
    [3] = LAYOUT_split_3x5_3(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                      OSM(MOD_RALT),  OSM_S_A,        KC_NO,          RSA(KC_MINS), RSA(KC_EQL),
    KC_NO,          KC_NO,          KC_TRNS,        LALT(KC_TAB),   KC_NO,                      RALT(KC_H),     RALT(KC_J),     RALT(KC_K),     RALT(KC_L),   KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          RALT(KC_COMM),  KC_NO,        RALT(KC_SLSH),
                                    KC_NO,          KC_NO,          KC_NO,                      KC_RSFT,        KC_NO,          KC_NO
    ),
};
//    blank layer
//    [x] = LAYOUT_split_3x5_3(
//    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_NO,          KC_NO,        KC_NO,
//    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_NO,          KC_NO,        KC_NO,
//    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_NO,          KC_NO,        KC_NO,
//                                    KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_NO
//    )

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Immediately select the hold action when another key is pressed.
        case RSFT_T(KC_SPC):
            return 1;
        //case LT(1, KC_ESC):
        //    return 1;
        default:
            // Do not select the hold action when another key is pressed.
            return 0;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2, KC_F):
            return TAPPING_TERM - 65;
        //case RSFT_T(KC_SPC):
        //    return TAPPING_TERM- 100;
        case LT(1, KC_ESC):
            return TAPPING_TERM - 65;
        default:
            return TAPPING_TERM;
    }
}
