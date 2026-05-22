#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum layers {
    _LINUX,         // 0
    _MACOS,         // 1
    _LEFT_MOD,      // 2
    _RIGHT_MOD,     // 3
    _BOTH_MOD,      // 4
    _BOTH_LEFT,     // 5
    _GAMING,        // 6
    _SWAP_HAND,     // 7
};

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    ALT_TAB_MACRO,
    EXIT_VIM_TERMINAL,
    TOGGLE_COMBOS,
};

/// If disabled, combos will not fire on any layer
bool cwest_combos_enabled = true;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LINUX] = LAYOUT_moonlander(
        KC_0,               KC_1,                   KC_2,               KC_3,               KC_4,               KC_5,           KC_6,                                                           KC_TRANSPARENT, KC_6,           KC_7,               KC_8,                   KC_9,                   KC_0,                   KC_BSPC,
        KC_TAB,             KC_Q,                   KC_W,               KC_E,               KC_R,               KC_T,           KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_Y,           KC_U,               KC_I,                   KC_O,                   KC_P,                   KC_BSLS,
        KC_SPACE,           KC_A,                   KC_S,               KC_D,               KC_F,               KC_G,           KC_ESCAPE,                                                      KC_QUOTE,       KC_H,           KC_J,               KC_K,                   KC_L,                   KC_SCLN,                KC_ENTER,
        CW_TOGG,            MT(MOD_LSFT, KC_Z),     MT(MOD_LGUI, KC_X), MT(MOD_LALT, KC_C), MT(MOD_LCTL, KC_V), KC_B,                                                                                           KC_N,           MT(MOD_RCTL, KC_M), MT(MOD_RALT, KC_COMMA), MT(MOD_RGUI, KC_DOT),   MT(MOD_RSFT, KC_SLASH), KC_RIGHT_SHIFT,
        KC_MS_BTN1,         KC_TAB,                 KC_TRANSPARENT,     KC_LEFT_GUI,        MO(_SWAP_HAND),                     MO(_BOTH_LEFT),                                                 KC_NO,                          MO(_SWAP_HAND),     KC_LEFT,                KC_DOWN,                KC_UP,                  KC_RIGHT,
                                                                                                                MO(_LEFT_MOD),  KC_SPACE,           KC_LEFT_CTRL,       KC_RIGHT_CTRL,          KC_SPACE,       MO(_RIGHT_MOD)
    ),
    [_MACOS] = LAYOUT_moonlander(
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         MT(MOD_LCTL, KC_X), KC_TRANSPARENT,     MT(MOD_LGUI, KC_V), KC_TRANSPARENT,                                                                                 KC_TRANSPARENT, MT(MOD_RGUI, KC_M), KC_TRANSPARENT,         MT(MOD_RCTL, KC_DOT),   KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         ALT_TAB_MACRO,      KC_TRANSPARENT,     KC_TRANSPARENT,                     KC_TRANSPARENT,                                                 KC_RIGHT_GUI,                   KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
                                                                                                                KC_TRANSPARENT, KC_TRANSPARENT,     KC_LEFT_GUI,        KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [_LEFT_MOD] = LAYOUT_moonlander(
        KC_ESCAPE,          KC_F1,                  KC_F2,              KC_F3,              KC_F4,              KC_F5,          KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_F6,          KC_F7,              KC_F8,                  KC_F9,                  KC_F10,             KC_F11,
        KC_TRANSPARENT,     KC_TILD,                KC_GRAVE,           KC_HASH,            KC_DLR,             KC_PERC,        KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_AMPR,            KC_LCBR,                KC_RCBR,                KC_TRANSPARENT,     KC_F12,
        KC_MINUS,     KC_EXLM,                KC_AT,              KC_TAB,             KC_MINUS,           KC_BSLS,        KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_CIRC,        KC_ASTR,            KC_LPRN,                KC_RPRN,                KC_MINUS,           KC_PAGE_UP,
        KC_MEDIA_PREV_TRACK,KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_ENTER,                                                                                       KC_TRANSPARENT, KC_QUOTE,           KC_LBRC,                KC_RBRC,                KC_TRANSPARENT,     KC_PGDN,
        KC_MEDIA_PLAY_PAUSE,KC_AUDIO_VOL_DOWN,      KC_AUDIO_VOL_UP,    KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,                     MO(_BOTH_LEFT),                                                 KC_TRANSPARENT,                 KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
                                                                                                                KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [_RIGHT_MOD] = LAYOUT_moonlander(
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     QK_BOOT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_PLUS,        KC_4,               KC_5,                   KC_6,                   KC_MINUS,           KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     EXIT_VIM_TERMINAL,   KC_GRAVE,           KC_TRANSPARENT, KC_TRANSPARENT,                                                KC_TRANSPARENT, KC_EQUAL,       KC_1,               KC_2,                   KC_3,                   KC_DOT,             KC_TAB,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                                                                                 KC_0,           KC_7,               KC_8,                   KC_9,                   KC_TRANSPARENT,     KC_MEDIA_PREV_TRACK,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                     KC_TRANSPARENT,                                                 MO(_BOTH_MOD),                  KC_TRANSPARENT,     KC_MEDIA_NEXT_TRACK,    KC_AUDIO_VOL_DOWN,      KC_AUDIO_VOL_UP,    KC_MEDIA_PLAY_PAUSE,
                                                                                                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [_BOTH_MOD] = LAYOUT_moonlander(
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, TOGGLE_COMBOS,                                                  TG(_GAMING),    TG(_MACOS),     KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, RGB_TOG,                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,         KC_MS_DOWN,             KC_MS_UP,               KC_MS_RIGHT,        KC_PSCR,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_MS_BTN2,         KC_MS_BTN1,         KC_TRANSPARENT, RGB_SLD,                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,            KC_DOWN,                KC_UP,                  KC_RIGHT,           KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                                                                                 KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_RIGHT_SHIFT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                         KC_TRANSPARENT,                                             KC_TRANSPARENT,                 KC_TRANSPARENT,     KC_TRANSPARENT,         KC_PGDN,                KC_PAGE_UP,         KC_TRANSPARENT,
                                                                                                                KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [_BOTH_LEFT] = LAYOUT_moonlander(
        KC_F10,             KC_F11,                 KC_F12,             KC_MS_DOWN,         KC_MS_RIGHT,        KC_MS_BTN1,     KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_KP_DOT,              KC_UP,              KC_DOWN,            KC_RIGHT,           KC_MS_BTN2,     KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_LEFT,                KC_UP,              KC_DOWN,            KC_RIGHT,           KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_9,               KC_8,               KC_TRANSPARENT,     KC_0,                                                                                           KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_LEFT,                KC_UP,              KC_DOWN,            KC_RIGHT,                           KC_TRANSPARENT,                                                 KC_TRANSPARENT,                 KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
                                                                                                                KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [_GAMING] = LAYOUT_moonlander(
        KC_TAB,             KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_KP_PLUS,                                                     TG(_GAMING),    KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_KP_MINUS,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_LSFT,            KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_ESC,                                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_LEFT_CTRL,       KC_Z,                   KC_X,               KC_C,               KC_V,               KC_TRANSPARENT,                                                                                 KC_TRANSPARENT, KC_M,               KC_COMMA,               KC_DOT,                 KC_SLASH,           KC_TRANSPARENT,
        KC_9,               KC_4,                   KC_3,               KC_2,               MO(_SWAP_HAND),                     KC_ENTER,                                                       KC_TRANSPARENT,                 KC_TRANSPARENT,     KC_TRANSPARENT,         KC_PGDN,                KC_TRANSPARENT,     KC_TRANSPARENT,
                                                                                                                KC_SPACE,       KC_LEFT_ALT,        KC_LEFT_CTRL,               KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [_SWAP_HAND] = LAYOUT_moonlander(
        KC_BSPC,            KC_0,                   KC_9,               KC_8,               KC_7,               KC_6,           KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_BSLS,            KC_P,                   KC_O,               KC_I,               KC_U,               KC_Y,           KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_T,           KC_R,               KC_E,                   KC_W,                   KC_Q,               KC_TAB,
        KC_ENTER,           KC_SCLN,                KC_L,               KC_K,               KC_J,               KC_H,           KC_QUOTE,                                                       KC_ESC,         KC_G,           KC_F,               KC_D,                   KC_S,                   KC_A,               KC_SPACE,
        KC_TRANSPARENT,     MT(MOD_RSFT, KC_SLASH), KC_DOT,             KC_COMMA,           KC_M,               KC_N,                                                                                           KC_B,           KC_V,               KC_C,                   KC_X,                   KC_Z,               CW_TOGG,
        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                     KC_TRANSPARENT,                                                 KC_TRANSPARENT,                 KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
                                                                                                                KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    )
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
            return TAPPING_TERM - 35;
        case MT(MOD_RCTL, KC_M):
            return TAPPING_TERM - 35;
        default:
            return TAPPING_TERM;
    }
}

// #define MY_SOUND E__NOTE(_GS6), E__NOTE(_A6), S__NOTE(_REST), Q__NOTE(_E7)
// float toggle_song[][2] = SONG(MY_SOUND);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALT_TAB_MACRO:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_TAP(X_TAB) ));
        }
        break;
    case EXIT_VIM_TERMINAL:
        if (record->event.pressed) {
            register_code(KC_LEFT_CTRL);
            tap_code(KC_BSLS);
        } else {
            tap_code(KC_N);
            unregister_code(KC_LEFT_CTRL);
        }
        break;
    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(63,245,75);
        }
        return false;
    case TOGGLE_COMBOS:
        if (!record->event.pressed) {  // On not pressed means on release
            cwest_combos_enabled = !cwest_combos_enabled;
        }
        return false;
  }
  return true;
}

/// A list of light indexes for lights that are modified by some layer so that we know which lights need to be reset on the main layers
# define NUM_LAYER_LIGHTS 10
const short layer_lights[NUM_LAYER_LIGHTS] = {7, 11, 12, 17, 22, 24, 58, 60, 61, 65};

# define HOME_ROW_PURPLE 159, 110, 195
# define ACTIVE_GREEN 50, 238, 50
# define DISABLED_RED 199, 24, 22
# define OFF 0, 0, 0

void homing_lights(const bool leds_enabled) {
    if (leds_enabled) {
        rgb_matrix_set_color(22, HOME_ROW_PURPLE);
        rgb_matrix_set_color(58, HOME_ROW_PURPLE);
    }
}

bool rgb_matrix_indicators_user(void) {
    bool leds_enabled = rgb_matrix_get_flags() != LED_FLAG_NONE;

    if (!leds_enabled) {
        // If leds are not enabled, then we have to manually disable layer lights.
        // We just turn them all off and then if a layer wants to ignore the leds_enabled flag, then it can set it again below.
        for (short i = 0; i < NUM_LAYER_LIGHTS; ++i) {
            rgb_matrix_set_color(layer_lights[i], OFF);
        }
    }

    switch (biton32(layer_state)) {
        case _GAMING:
            rgb_matrix_set_color(65, ACTIVE_GREEN);
            if (layer_state_is(_SWAP_HAND)) {
                break;  // If swap hands is pressed, don't keep wasd lights active
            }
            rgb_matrix_set_color(7, HOME_ROW_PURPLE);
            rgb_matrix_set_color(11, HOME_ROW_PURPLE);
            rgb_matrix_set_color(12, HOME_ROW_PURPLE);
            rgb_matrix_set_color(17, HOME_ROW_PURPLE);
            break;
        case _MACOS:
            rgb_matrix_set_color(61, ACTIVE_GREEN);
            homing_lights(leds_enabled);
            break;
        case _LINUX:
        case _RIGHT_MOD:
        case _LEFT_MOD:
            homing_lights(leds_enabled);
            break;
    }

    if (layer_state_is(_SWAP_HAND)) {
        homing_lights(leds_enabled);
        rgb_matrix_set_color(24, ACTIVE_GREEN);
        rgb_matrix_set_color(60, ACTIVE_GREEN);
    }

    if (cwest_combos_enabled) {
        if (leds_enabled) {
            rgb_matrix_set_color(29, ACTIVE_GREEN);  // 29 is the key that switches combos on and off
        } else {
            rgb_matrix_set_color(29, OFF);
        }
    } else {
        rgb_matrix_set_color(29, DISABLED_RED);  // Shines even if leds are disabled so that it's obvious
    }

    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LEFT_MOD, _RIGHT_MOD, _BOTH_MOD);
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return cwest_combos_enabled && !layer_state_is(_GAMING);
}

