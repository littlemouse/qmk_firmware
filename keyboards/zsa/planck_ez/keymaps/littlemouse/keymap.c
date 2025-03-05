#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY, // 0
  _LOWER, // 1
  _RAISE, // 2
  _ADJUST, // 3
  _NUMPAD // 4
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |  S   |   D  |  F   |   G  |   H  |Cmd/J |   K  |  L   |Ctl/; |SFT/Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | MO7  | Ctrl | Opt  | Cmd  |Lower |  LT4/Space  |Raise | Left | Down | Up   |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,      KC_W,       KC_E,   KC_R,   KC_T,     KC_Y,    KC_U,        KC_I,    KC_O,    KC_P,           KC_BSPC,
    KC_ESC,         KC_A,      KC_S,       KC_D,   KC_F,   KC_G,     KC_H,    RGUI_T(KC_J),KC_K,    KC_L,    RCTL_T(KC_SCLN),KC_ENT,
    KC_LSFT,        KC_Z,      KC_X,       KC_C,   KC_V,   KC_B,     KC_N,    KC_M,        KC_COMM, KC_DOT,  KC_SLSH,        RSFT_T(KC_QUOT),
    KC_RGUI,        KC_LCTL,   KC_LALT,    KC_LGUI,LOWER,  KC_SPC,   KC_SPC,  RAISE,       KC_LEFT, KC_DOWN, KC_UP,          KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Mute   Mute | Play | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, KC_MUTE, KC_MUTE, KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Mute   Mute | Play | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_GRV,  KC_TILD, KC_3,    KC_PGDN, _______,
    _______, _______, _______, _______, _______, KC_MUTE, KC_MUTE, KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|      | Vol+ | Vol- | Mute |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    QK_BOOT, _______, LED_LEVEL, RGB_TOG,  _______, _______, _______, _______,  _______,  KC_BRMD, KC_BRMU, _______,
    _______, _______, RGB_MOD,   RGB_RMOD, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G,
    _______, _______, RGB_HUI,   RGB_HUD,  _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, RGB_VAI,   RGB_VAD,  _______, _______, _______, _______,  _______,  _______, _______, _______
),

[_NUMPAD] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_0,    _______, 
    _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)              
};

//[_MOUSE] = LAYOUT_planck_grid(
//    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//,
//)


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
