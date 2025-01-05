#include QMK_KEYBOARD_H

enum layer {
    _QWERTY,
    _SPECIAL,
};

// Milliseconds the backlight is off (or on) when blinking to show
// caps lock is on. In other words, half the time of a full blink cycle.
#define CAPS_LOCK_BLINK_MS 350

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

// The backlight level shows which layer we are in:
// Special Layer = green, other (default) layer: blue
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _SPECIAL:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    }
  return state;
}

static uint16_t caps_lock_blink_timer = 0;

// This is called after every matrix scan. We make the backlight blink
// when caps lock is on here. To ensure the backlight is in the on state
// when caps lock is turned off, we also watch for the relase of the caps
// lock key in process_record_user().
void housekeeping_task_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        if (timer_elapsed(caps_lock_blink_timer) >= CAPS_LOCK_BLINK_MS) {
             backlight_toggle();
            caps_lock_blink_timer = timer_read();
        }
    }
}

// Set default color for backlight
void keyboard_post_init(void) {
    rgblight_setrgb (0x00,  0x00, 0xFF);
}
