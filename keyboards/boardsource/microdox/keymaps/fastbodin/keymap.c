#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(
    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
    KC_A,           KC_S,           KC_D,           LT(2, KC_F),    KC_G,                       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,
    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                       KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,
                                    MO(3),          LT(1, KC_ESC),  KC_BSPC,                    KC_SPC,         RSFT_T(KC_ENT), KC_RCTL),
    [1] = LAYOUT_split_3x5_3(
    KC_PMNS,        KC_7,           KC_8,           KC_9,           KC_PPLS,                    KC_GRV,         KC_CIRC,        KC_LPRN,        KC_RPRN,        KC_BSLS,
    KC_0,           KC_4,           KC_5,           KC_6,           KC_PEQL,                    KC_ASTR,        KC_DLR,         KC_LBRC,        KC_RBRC,        KC_QUOT,
    KC_PDOT,        KC_1,           KC_2,           KC_3,           KC_PDOT,                    KC_NO,          KC_UNDS,        KC_COMM,        KC_DOT,         KC_SLSH,
                                    KC_NO,          KC_TRNS,        KC_NO,                      KC_SPC,         KC_RSFT,        KC_RCTL),
    [2] = LAYOUT_split_3x5_3(
    LGUI(KC_DLR),   LGUI(KC_HASH),   LSFT(KC_TAB),   KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_VOLD,        KC_VOLU,        KC_NO,
    KC_NO,          KC_ENT,         KC_TAB,         KC_TRNS,        KC_NO,                      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        KC_ENT,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_BRID,        KC_BRIU,        KC_NO,
                                    KC_NO,          KC_LSFT,        KC_BSPC,                    KC_SPC,         KC_NO,          KC_RCTL),
    [3] = LAYOUT_split_3x5_3(
    LALT(KC_F),     KC_NO,          KC_NO,          KC_NO,          LGUI(KC_T),                 LCA(KC_A),      LCA(KC_W),      LCA(KC_S),      LCA(KC_D),      LALT(KC_C),
    KC_NO,          LGUI(KC_S),     KC_NO,          LGUI(KC_F),     KC_NO,                      LALT(KC_H),     LALT(KC_J),     LALT(KC_K),     LALT(KC_L),     KC_NO,
    LGUI(KC_Z),     KC_NO,          LGUI(KC_C),     LGUI(KC_V),     KC_NO,                      LGUI(KC_N),     LGUI(KC_M),     LCTL(KC_LEFT),  LCTL(KC_RGHT),  LGUI(KC_DLR),
                                    KC_TRNS,        KC_NO,          KC_NO,                      LGUI(KC_SPC),   KC_RSFT,        KC_RCTL)
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_ENT):
            // Immediately select the hold action when another key is pressed.
            return 1;
        case LT(1, KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return 1;
        default:
            // Do not select the hold action when another key is pressed.
            return 0;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2, KC_F):
            return TAPPING_TERM - 65;
        default:
            return TAPPING_TERM;
    }
}
