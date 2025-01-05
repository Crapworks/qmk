#include QMK_KEYBOARD_H

enum layer {
    _QWERTY,
    _SPECIAL,
};

// German special characters
#define UML_AE RALT(KC_Q)
#define UML_OE RALT(KC_P)
#define UML_UE RALT(KC_Y)
#define GER_SZ RALT(KC_S)
#define EU_EUR RALT(KC_5)

// i3 Window navgation
#define WIN_LEFT LGUI(KC_LEFT)
#define WIN_RIGHT LGUI(KC_RIGHT)
#define WIN_MV_LEFT LSG(KC_LEFT)
#define WIN_MV_RIGHT LSG(KC_RIGHT)

// MOD TAP arrow keys
#define GUI_LEFT  MT(MOD_RGUI, KC_LEFT)
#define MOD_DOWN  LT(_SPECIAL, KC_DOWN)
#define SHFT_UP   MT(MOD_RSFT, KC_UP)
#define CTL_RIGHT MT(MOD_RCTL, KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_INS, KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,           KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,     KC_0,         KC_MINS, KC_EQL,  KC_DEL,
    KC_HOME,         KC_TAB,  KC_Q,    KC_W,    KC_E,           KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,         KC_LBRC, KC_RBRC, KC_BSPC,
    KC_PGUP,         KC_CAPS, KC_A,    KC_S,    KC_D,           KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,      KC_QUOT,          KC_ENT,
    KC_PGDN,         KC_LSFT, KC_Z,    KC_X,    KC_C,           KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,      SHFT_UP, KC_BSLS,
    KC_END,          KC_LCTL, KC_LGUI, KC_LALT, MO(_SPECIAL),   KC_SPC,  KC_SPC,      KC_SPC,  KC_SPC,  KC_RALT, GUI_LEFT, MOD_DOWN,     CTL_RIGHT
  ),
  [_SPECIAL] = LAYOUT(
    KC_MUTE, QK_BOOT, _______, KC_F1,   KC_F2,      KC_F3,      KC_F4,      KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,  KC_DEL,
    BL_STEP,          _______, _______, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), _______,      _______, KC_7,    KC_8,    KC_9,    _______, UML_UE, _______, _______,
    UG_NEXT,          _______, _______, LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), _______,      _______, KC_4,    KC_5,    KC_6,    UML_OE,  UML_AE,          _______,
    KC_VOLU,          _______, _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), _______,      _______, KC_1,    KC_2,    KC_3,    _______, _______, GER_SZ,
    KC_VOLD,          _______, _______, _______,    _______,    _______,    _______,      KC_0,    KC_0,    _______, _______, _______, _______
  ),
};
