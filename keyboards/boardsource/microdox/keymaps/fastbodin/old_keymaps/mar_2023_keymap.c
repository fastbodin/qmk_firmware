#include QMK_KEYBOARD_H

#define ONESHOT_TIMEOUT 1500  /* Time (in ms) before the one shot key is released */

#define OSM_G OSM(MOD_LGUI)

#define OSM_S OSM(MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // main layer, alphas
    [0] = LAYOUT_split_3x5_3(
    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
    KC_A,           KC_S,           LT(3, KC_D),    LT(2, KC_F),    KC_G,                       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,
    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                       KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,
                                    KC_NO,          LT(1, KC_ESC),  KC_SPC,                     KC_RSFT,        MO(4),          KC_NO
    ),
    // this layer is for numbers, symbols, and math related things
    [1] = LAYOUT_split_3x5_3(
    KC_PMNS,        KC_7,           KC_8,           KC_9,           KC_PPLS,                    KC_GRV,         KC_CIRC,        KC_LPRN,        KC_RPRN,        KC_BSLS,
    KC_0,           KC_4,           KC_5,           KC_6,           KC_PEQL,                    KC_ASTR,        KC_DLR,         KC_LBRC,        KC_RBRC,        KC_QUOT,
    KC_BSPC,        KC_1,           KC_2,           KC_3,           KC_SPC,                     KC_NO,          KC_UNDS,        KC_COMM,        KC_DOT,         KC_SLSH,
                                    KC_NO,          KC_TRNS,        KC_NO,                      KC_RSFT,        MO(5),          KC_NO
    ),
    // this layer is for general navigation and nvim
    [2] = LAYOUT_split_3x5_3(
    KC_BSPC,       KC_NO,          LSFT(KC_TAB),   KC_NO,          KC_NO,                      RCTL(KC_Y),     KC_NO,          KC_VOLD,        KC_VOLU,        KC_NO,
    KC_ENT,        KC_NO,          KC_TAB,         KC_TRNS,        KC_NO,                      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        KC_ENT,
    KC_NO,         KC_NO,          KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_BRID,        KC_BRIU,        KC_NO,
                                   KC_NO,          KC_LSFT,        KC_BSPC,                    KC_RSFT,        KC_RCTL,        KC_NO
    ),
    // this layer is for aerospace nagivation and GUI operations
    [3] = LAYOUT_split_3x5_3(
    LGUI(KC_DLR),   LGUI(KC_V),     KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          RSA(KC_MINS),   RSA(KC_EQL),  KC_NO,
    KC_NO,          LGUI(KC_C),     KC_TRNS,        LALT(KC_TAB),   KC_NO,                      RALT(KC_H),     RALT(KC_J),     RALT(KC_K),     RALT(KC_L),   KC_NO,
    LGUI(KC_Z),     KC_NO,          KC_NO,          KC_NO,          KC_NO,                      RGUI(KC_N),     KC_NO,          RALT(KC_COMM),  KC_NO,        RALT(KC_SLSH),
                                    KC_NO,          KC_LGUI,        LGUI(KC_SPC),               KC_RSFT,        KC_RCTL,        KC_NO
    ),
    // this is the control layer
    [4] = LAYOUT_split_3x5_3(
    LCTL(KC_Q),     LCTL(KC_W),     LCTL(KC_E),     LCTL(KC_R),     LCTL(KC_T),                 RCTL(KC_Y),     RCTL(KC_U),      RCTL(KC_I),    RCTL(KC_O),   RCTL(KC_P),
    LCTL(KC_A),     LCTL(KC_S),     LCTL(KC_D),     LCTL(KC_F),     LCTL(KC_G),                 RCTL(KC_H),     RCTL(KC_J),      RCTL(KC_K),    RCTL(KC_L),   RCTL(KC_SCLN),
    LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_B),                 RCTL(KC_N),     RCTL(KC_M),      RCTL(KC_COMM), RCTL(KC_DOT), RCTL(KC_SLSH),
                                    KC_NO,          MO(5),          KC_NO,                      KC_NO,          KC_TRNS,         KC_NO
    ),
    //this layer navigates between workspaces in aerospace
    [5] = LAYOUT_split_3x5_3(
    LALT(KC_Q),     LALT(KC_W),     LALT(KC_E),     LALT(KC_R),     LALT(KC_T),                 RALT(KC_Y),     RALT(KC_U),      RALT(KC_I),    RALT(KC_O),   RALT(KC_P),
    LALT(KC_A),     LALT(KC_S),     LALT(KC_D),     LALT(KC_F),     LALT(KC_G),                 OSM_S,          OSM_S,           OSM_S,         OSM_S,        KC_NO,
    LALT(KC_Z),     LALT(KC_X),     LALT(KC_C),     LALT(KC_V),     LALT(KC_B),                 RALT(KC_N),     RALT(KC_M),      KC_NO,         KC_DOT,       KC_NO,
                                    KC_NO,          KC_TRNS,        KC_NO,                      KC_NO,          KC_TRNS,         KC_NO
    )
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_ESC):
            return TAPPING_TERM - 65;
        case LT(2, KC_F):
            return TAPPING_TERM - 65;
        case LT(3, KC_D):
            return TAPPING_TERM - 65;
        default:
            return TAPPING_TERM;
    }
}


//    blank layer
//    [x] = LAYOUT_split_3x5_3(
//    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_NO,          KC_NO,        KC_NO,
//    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_NO,          KC_NO,        KC_NO,
//    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_NO,          KC_NO,        KC_NO,
//                                    KC_NO,          KC_NO,          KC_NO,                      KC_NO,          KC_NO,          KC_NO
//    )

//bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        // Immediately select the hold action when another key is pressed.
//        //case RSFT_T(KC_SPC):
//        //    return 1;
//        //case LT(1, KC_ESC):
//        //    return 1;
//        default:
//            // Do not select the hold action when another key is pressed.
//            return 0;
//    }
//}


