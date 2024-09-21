#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum layers {
    _MACOS,         // 0
    _LINUX,         // 1
    _LEFT_MOD,      // 2
    _RIGHT_MOD,     // 3
    _SWAP_HAND,     // 4
    _BOTH_MOD,      // 5
    _BOTH_LEFT,     // 6
    _GAMING,        // 7
};

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MACOS] = LAYOUT_moonlander(
        KC_0,               KC_1,                   KC_2,               KC_3,               KC_4,               KC_5,           KC_6,                                                           TG(_LINUX),     KC_6,           KC_7,               KC_8,                   KC_9,                   KC_0,                   KC_BSPC,
        KC_TRANSPARENT,     KC_Q,                   KC_W,               KC_E,               KC_R,               KC_T,           KC_TRANSPARENT,                                                 TG(_GAMING),    KC_Y,           KC_U,               KC_I,                   KC_O,                   KC_P,                   KC_BSLS,
        KC_SPACE,           KC_A,                   KC_S,               KC_D,               KC_F,               KC_G,           KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_H,           KC_J,               KC_K,                   KC_L,                   KC_SCLN,                KC_ENTER,
        CW_TOGG,            MT(MOD_LSFT, KC_Z),     MT(MOD_LCTL, KC_X), MT(MOD_LALT, KC_C), MT(MOD_LGUI, KC_V), KC_B,                                                                                           KC_N,           MT(MOD_RGUI, KC_M), MT(MOD_RALT, KC_COMMA), MT(MOD_RCTL, KC_DOT),   MT(MOD_RSFT, KC_SLASH), KC_RIGHT_SHIFT,
        KC_MS_BTN1,         KC_TAB,                 KC_TRANSPARENT,     KC_LEFT_GUI,        MO(_SWAP_HAND),                     MO(_BOTH_LEFT),                                                 KC_NO,                          MO(3),              KC_LEFT,                KC_DOWN,                KC_UP,                  KC_RIGHT,
                                                                                                                MO(_LEFT_MOD),  KC_SPACE,           KC_LEFT_GUI,        KC_LEFT_ALT,            KC_SPACE,       MO(_RIGHT_MOD)
    ),
    [_LINUX] = LAYOUT_moonlander(
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         MT(MOD_LGUI, KC_X), KC_TRANSPARENT,     MT(MOD_LCTL, KC_V), KC_TRANSPARENT,                                                                                 KC_TRANSPARENT, MT(MOD_RCTL, KC_M), KC_TRANSPARENT,         MT(MOD_RGUI, KC_DOT),   KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         ST_MACRO_0,         KC_TRANSPARENT,     KC_TRANSPARENT,                     KC_TRANSPARENT,                                                 KC_RIGHT_GUI,                   KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
                                                                                                                KC_TRANSPARENT, KC_TRANSPARENT,     KC_LEFT_CTRL,               KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [_LEFT_MOD] = LAYOUT_moonlander(
        KC_ESCAPE,          KC_F1,                  KC_F2,              KC_F3,              KC_F4,              KC_F5,          KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_F6,          KC_F7,              KC_F8,                  KC_F9,                  KC_F10,             KC_F11,
        KC_TRANSPARENT,     KC_TILD,                KC_GRAVE,           KC_HASH,            KC_DLR,             KC_PERC,        KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_AMPR,            KC_LCBR,                KC_RCBR,                KC_TRANSPARENT,     KC_F12,
        KC_TRANSPARENT,     KC_EXLM,                KC_AT,              KC_TAB,             KC_MINUS,           KC_BSLS,        KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_CIRC,        KC_ASTR,            KC_LPRN,                KC_RPRN,                KC_MINUS,           KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_ENTER,                                                                                       KC_TRANSPARENT, KC_QUOTE,           KC_LBRC,                KC_RBRC,                KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_MEDIA_PLAY_PAUSE,KC_AUDIO_VOL_DOWN,      KC_AUDIO_VOL_UP,    KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,                     MO(_BOTH_LEFT),                                                 KC_TRANSPARENT,                 KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
                                                                                                                KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [_RIGHT_MOD] = LAYOUT_moonlander(
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     QK_BOOT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_PLUS,        KC_4,               KC_5,                   KC_6,                   KC_MINUS,           KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_GRAVE,           KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_EQUAL,       KC_1,               KC_2,                   KC_3,                   KC_DOT,             KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                                                                                 KC_0,           KC_7,               KC_8,                   KC_9,                   KC_TRANSPARENT,     KC_MEDIA_PREV_TRACK,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                     KC_TRANSPARENT,                                                 MO(_BOTH_MOD),                  KC_TRANSPARENT,     KC_MEDIA_NEXT_TRACK,    KC_AUDIO_VOL_DOWN,      KC_AUDIO_VOL_UP,    KC_MEDIA_PLAY_PAUSE,
                                                                                                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [_SWAP_HAND] = LAYOUT_moonlander(
        KC_TRANSPARENT,     KC_0,                   KC_9,               KC_8,               KC_7,               KC_6,           KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_P,                   KC_O,               KC_I,               KC_U,               KC_Y,           KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_MINUS,           KC_SCLN,                KC_L,               KC_K,               KC_J,               KC_H,           KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     MT(MOD_RSFT, KC_SLASH), KC_DOT,             KC_COMMA,           KC_M,               KC_N,                                                                                           KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                     KC_TRANSPARENT,                                                 KC_TRANSPARENT,                 KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
                                                                                                                KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [_BOTH_MOD] = LAYOUT_moonlander(
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,         KC_MS_DOWN,             KC_MS_UP,               KC_MS_RIGHT,        KC_PSCR,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_MS_BTN2,         KC_MS_BTN1,         KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,            KC_DOWN,                KC_UP,                  KC_RIGHT,           KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                                                                                 KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_RIGHT_SHIFT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                         KC_TRANSPARENT,                                             KC_TRANSPARENT,                 KC_TRANSPARENT,     KC_TRANSPARENT,         KC_PGDN,                KC_PAGE_UP,         KC_TRANSPARENT,
                                                                                                                KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [_BOTH_LEFT] = LAYOUT_moonlander(
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_MS_LEFT,             KC_MS_UP,           KC_MS_DOWN,         KC_MS_RIGHT,        KC_MS_BTN1,     KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_LEFT,                KC_UP,              KC_DOWN,            KC_RIGHT,           KC_MS_BTN2,     KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                                                                                 KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                     KC_TRANSPARENT,                                                 KC_TRANSPARENT,                 KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
                                                                                                                KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [_GAMING] = LAYOUT_moonlander(
        KC_TAB,             KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_KP_PLUS,                                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_KP_MINUS,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_LSFT,            KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_ESC,                                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_LEFT_CTRL,       KC_Z,                   KC_X,               KC_C,               KC_V,               KC_TRANSPARENT,                                                                                 KC_TRANSPARENT, KC_M,               KC_COMMA,               KC_DOT,                 KC_SLASH,           KC_TRANSPARENT,
        KC_9,               KC_4,                   KC_3,               KC_2,               KC_1,                               KC_TRANSPARENT,                                                 KC_TRANSPARENT,                 KC_TRANSPARENT,     KC_TRANSPARENT,         KC_PGDN,                KC_TRANSPARENT,     KC_TRANSPARENT,
                                                                                                                KC_SPACE,       KC_LEFT_ALT,        KC_LEFT_CTRL,               KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
};
const uint16_t PROGMEM r_bspc[] = { KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM r_delete[] = { KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM r_enter[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM r_esc[] = { KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM l_esc[] = { KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM l_enter[] = { KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM l_bspc[] = { KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM l_delete[] = { KC_S, KC_D, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(r_bspc, KC_BSPC),
    COMBO(r_delete, KC_DELETE),
    COMBO(r_enter, KC_ENTER),
    COMBO(r_esc, KC_ESCAPE),
    COMBO(l_esc, KC_ESCAPE),
    COMBO(l_enter, KC_ENTER),
    COMBO(l_bspc, KC_BSPC),
    COMBO(l_delete, KC_DELETE),
};
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_Z):
            return TAPPING_TERM -39;
        case MT(MOD_LGUI, KC_V):
            return TAPPING_TERM -37;
        case MT(MOD_RGUI, KC_M):
            return TAPPING_TERM -38;
        case MT(MOD_RSFT, KC_SLASH):
            return TAPPING_TERM -41;
        case MT(MOD_LGUI, KC_X):
            return TAPPING_TERM -31;
        case MT(MOD_LCTL, KC_V):
            return TAPPING_TERM -37;
        case MT(MOD_RCTL, KC_M):
            return TAPPING_TERM -39;
        default:
            return TAPPING_TERM;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_TAB) ));
    }
    break;

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LEFT_MOD, _RIGHT_MOD, _BOTH_MOD);
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return !layer_state_is(_GAMING);
}
