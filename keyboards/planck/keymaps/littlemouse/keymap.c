#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY, // 0
  _LOWER, // 1
  _RAISE, // 2
  _ADJUST, // 3
  _MOUSE, // 4
  _NUMPAD, // 5
  _MACROS, // 6
  _COPYPASTE // 7
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
  MC_CUT,
  MC_COPY,
  MC_PASTE,
  MC_ALL,
  XC_TOG_NAV,
  XC_TOG_INS,
  XC_NXT_EDT,
  XC_PRV_EDT,
  XC_NXT_EDR,
  XC_PRV_EDR,
  XC_NXT_TB,
  XC_PRV_TB
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |  S   |   D  |  F   |   G  |   H  |Cmd/J |   K  |  L   |Ctl/; | Ent  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|LT4/Z |LT5/X |   C  |LT6/V |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | MO7  | Ctrl | Opt  | Cmd  |Lower |    Space    |Raise | Left | Down | Up   |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,      KC_W,       KC_E,   KC_R,        KC_T,  KC_Y,  KC_U,        KC_I,    KC_O,    KC_P,           KC_BSPC,
    KC_ESC,         KC_A,      KC_S,       KC_D,   KC_F,        KC_G,  KC_H,  RGUI_T(KC_J),KC_K,    KC_L,    RCTL_T(KC_SCLN),KC_ENT,
    KC_LSFT,        LT(4,KC_Z),LT(5,KC_X), KC_C,   LT(6, KC_V), KC_B,  KC_N,  KC_M,        KC_COMM, KC_DOT,  KC_SLSH,        RSFT_T(KC_QUOT),
    KC_RGUI,        KC_LCTL,   KC_LALT,    KC_LGUI,LOWER,       KC_SPC,KC_SPC,RAISE,       KC_LEFT, KC_DOWN, KC_UP,          KC_RGHT
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
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,    KC_3,    KC_PGDN, _______,
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
    _______, QK_BOOT, DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, KC_BRMD, KC_BRMU, _______,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, KC_VOLD, KC_VOLU, KC_MUTE,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, KC_HOME,
    _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_END,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R
),

[_NUMPAD] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, KC_SLSH, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_4, KC_5, KC_6, KC_ASTR, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_MINS, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, KC_EQL, KC_PLUS, _______
),

[_MACROS] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, XC_TOG_NAV, XC_TOG_INS, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, XC_PRV_TB,  XC_NXT_TB,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, XC_PRV_EDR, XC_NXT_EDR, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    XC_PRV_EDT, _______, _______, XC_NXT_EDT
),

[_COPYPASTE] = LAYOUT_planck_grid(
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, MC_ALL,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _______, MC_CUT,  MC_COPY, MC_PASTE, _______, _______, _______, _______, _______, _______, _______,
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


#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MC_CUT:
      if (record->event.pressed) {
         SEND_STRING(SS_LGUI("x"));
      }
      break;
    case MC_COPY:
      if (record->event.pressed) {
         SEND_STRING(SS_LGUI("c"));
      }
      break;
    case MC_PASTE:
      if (record->event.pressed) {
         SEND_STRING(SS_LGUI("v"));
      }
      break;
    case MC_ALL:
      if (record->event.pressed) {
         SEND_STRING(SS_LGUI("a"));
      }
      break;
    case XC_TOG_NAV:
      if (record->event.pressed) {
         SEND_STRING(SS_LGUI("0"));
      }
      break;
    case XC_TOG_INS:
      if (record->event.pressed) {
         SEND_STRING(SS_LGUI(SS_LALT("0")));
      }
      break;
    case XC_NXT_EDT:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LCTL);
        tap_code(KC_RGHT);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
      }
      break;
    case XC_PRV_EDT:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LCTL);
        tap_code(KC_LEFT);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
      }
      break;
    case XC_NXT_EDR:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL("`"));
      }
      break;
    case XC_PRV_EDR:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL(SS_LSFT("`")));
      }
      break;
    case XC_NXT_TB:
      if (record->event.pressed) {
         SEND_STRING(SS_LGUI(SS_LSFT("]")));
      }
      break;
    case XC_PRV_TB:
      if (record->event.pressed) {
         SEND_STRING(SS_LGUI(SS_LSFT("[")));
      }
      break;
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
