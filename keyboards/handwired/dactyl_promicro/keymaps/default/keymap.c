#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define ONE_GRV LT(1,KC_GRAVE)
#define CTL_Z LCTL_T(KC_Z)
#define ALT_SHFT LALT(KC_LSFT)
#define ALT_MENU LALT_T(KC_MENU)
#define LG_QUOT LGUI_T(KC_QUOT)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_SLS LCTL_T(KC_SLSH)
#define LT2_COL LT(_RAISE, KC_SCLN)
void keyboard_pre_init_user(void) {
    setPinOutput(B0);  // initialize B0 for LED
    setPinOutput(D5);  // initialize B1 for LED
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _RAISE:
            writePinLow(D5);
            writePinLow(B0);
            break;
        case _LOWER:
            writePinHigh(D5);
            writePinLow(B1);
            break;
        default:
            writePinHigh(D5);
            writePinHigh(B0);
            break;
    }
    return state;
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x6(
        KC_GRV , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_ESC , KC_Q  ,KC_W   , KC_E  , KC_R  , KC_T  ,                                        KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS,
 LCTL_T(KC_TAB), KC_A  ,KC_S   , KC_D  , KC_F  , KC_G  ,                                        KC_H   , KC_J  , KC_K  , KC_L  ,LT2_COL,LG_QUOT,
        KC_LSFT, KC_Z , KC_X   , KC_C  , KC_V  , KC_B  ,                                        KC_N   , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSHIFT,
                     KC_LCTL,KC_LOPT, LGUI_T(KC_SPC), TT(_RAISE),                                                    TT(_RAISE), KC_LBRC, KC_RBRC,
                                        KC_SPC,KC_ENT,                                        KC_ENT,
                                            CTL_ESC ,TT(_LOWER),                    KC_SPC, KC_RGUI

    ),
    [_LOWER] = LAYOUT_6x6(
        _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                       KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        _______,KC_EXLM,KC_AT  ,KC_LBRC,KC_RBRC,KC_PIPE,                                       KC_UP  ,KC_P7  ,KC_P8  ,KC_P9  ,KC_PAST,KC_F12 ,
        _______,KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_GRV ,                                       KC_DOWN,KC_P4  ,KC_P5  ,KC_P6  ,KC_PPLS,_______,
        _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,                                       KC_AMPR,KC_P1  ,KC_P2  ,KC_P3  ,KC_PSLS,_______,
                                  _______,_______,_______,_______,                                  _______,_______,_______,
                                                         _______,_______,          _______,
                                                     _______,_______,         _______, _______
    ),
    [_RAISE] = LAYOUT_6x6(
        _______,_______,_______,KC_MS_U,_______,_______,                                       _______,KC_MINUS,KC_EQUAL,KC_LBRC,KC_RBRC,_______,
        _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,_______,                                       KC_PGUP,KC_WH_U,KC_UP,KC_WH_D,KC_PGDOWN,_______,
        _______,KC_CPI_1,KC_CPI_2,KC_CPI_3,_______,_______,                                       KC_HOME,KC_BTN1, KC_BTN3,KC_BTN2,KC_END,_______,
        RESET  ,_______,_______,KC_BTN1,KC_BTN2,_______,                                       KC_WBAK,KC_MINUS,KC_EQUAL,KC_LBRC,KC_RBRC,_______,
                                 _______,_______,_______,_______,                              _______,_______,_______,
                                                         _______,_______,       _______,
                                                     _______,_______,         _______, _______
    )
};
