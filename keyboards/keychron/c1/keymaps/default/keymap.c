/*
Copyright 2020 Dimitris Mantzouranis

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

/* Keychron Fn */

#define KC_TASK LGUI(KC_TAB)            // Task viewer
#define KC_FLXP LGUI(KC_E)              // Windows file explorer
#define KC_CORT LGUI(KC_C)              // Cortana
#define KC_SNIP LGUI(LSFT(KC_S))        // Windows snip tool
#define KC_W_FN MO(WIN_FN)              // Windows Fn

#define KC_MCTL LGUI(KC_UP)             // Mission Control
#define KC_SIRI LGUI(KC_SPC)            // Siri
#define KC_MSCR LSFT(LGUI(KC_3))        // Mac screenshot
#define KC_MSNP LSFT(LGUI(KC_4))        // Mac snip tool
#define KC_M_FN MO(MAC_FN)              // Mac Fn

/* Variant-tailored Defines */

#if defined(LED_MATRIX_ENABLE)
    #define LAYOUT_tkl_ansi LAYOUT_tkl_ansi_260
    #define LGT_VAD BL_DEC              // Decrease KB Brightness
    #define LGT_VAI BL_INC              // Increase KB Brightness
    #define XTR_AA BL_STEP              // Cycle LED Modes
    #define XTR_AB BL_TOGG              // Toggle BL
    #define XTR_BA BL_STEP              // Cycle LED Modes
    #define XTR_BB BL_TOGG              // Toggle BL
    #define LGT_HUI KC_TRNS             // None
    #define LGT_HUD KC_TRNS             // None
    #define LGT_SAI KC_TRNS             // None
    #define LGT_SAD KC_TRNS             // None
#elif defined(RGB_MATRIX_ENABLE)
    #define LAYOUT_tkl_ansi LAYOUT_tkl_ansi_240B
    #define LGT_VAD RGB_VAD             // Decrease KB Brightness
    #define LGT_VAI RGB_VAI             // Increase KB Brightness
    #define XTR_AA RGB_MOD              // Cycle RGB Modes
    #define XTR_AB RGB_TOG              // Toggle RGB
    #define XTR_BA RGB_MOD              // Cycle RGB Modes
    #define XTR_BB RGB_TOG              // Toggle RGB
    #define LGT_HUI RGB_HUI             // Increase RGB Hue
    #define LGT_HUD RGB_HUD             // Decrease RGB Hue
    #define LGT_SAI RGB_SAI             // Increase RGB Saturation
    #define LGT_SAD RGB_SAD             // Decrease RGB Saturation
#else
    #define LAYOUT_tkl_ansi LAYOUT_tkl_ansi_260
    #define LGT_VAD KC_TRNS             // None
    #define LGT_VAI KC_TRNS             // None
    #define XTR_AA LGUI(LCTL(KC_Q))     // Mac Lock
    #define XTR_AB KC_TRNS              // None
    #define XTR_BA LGUI(KC_L)           // Windows Lock
    #define XTR_BB KC_TRNS              // None
    #define LGT_HUI KC_TRNS             // None
    #define LGT_HUD KC_TRNS             // None
    #define LGT_SAI KC_TRNS             // None
    #define LGT_SAD KC_TRNS             // None
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*  Mac layout
    +-------------------------------------------------------------------------------------------+
    | ESC |  | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9| F10| F11| F12|  | |PSCR|SIRI| BL |
    +--------------------------------------------------------------------------+ +--------------+
    |  ~  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP | |INS |HOME|PGUP|
    +--------------------------------------------------------------------------+ +--------------+
    |  TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  | |DEL |END |PGDN|
    +--------------------------------------------------------------------------+ +--------------+
    | CAPSLCK  |  A |  S |  D |  F |  G |  H |  J |  K |  L | ; | ' |  RETURN  |                |
    +--------------------------------------------------------------------------+      +----+    |
    | LSHIFT     |  Z |  X |  C |  V |  B |  N |  M | , | . |  / |   RSHIFT    |      | UP |    |
    +--------------------------------------------------------------------------+ +--------------+
    |LCTRL| LALT| LGUI |            SPACE            | RGUI| RALT | FN | RCTRL | |LFT |DWN |RGT |
    +-------------------------------------------------------------------------------------------+
    */

    [MAC_BASE] = LAYOUT_tkl_ansi( \
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_MSCR,  KC_SIRI,  XTR_AA,  \
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP, \
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN, \
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,                                \
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,             \
        KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_RGUI,  KC_RALT,  KC_M_FN,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT  \
    ),

    [MAC_FN] = LAYOUT_tkl_ansi( \
        RESET,              KC_BRID,  KC_BRIU,  KC_MCTL,  _______,  LGT_VAD,  LGT_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MSNP,  _______,  XTR_AB,  \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,                               \
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            LGT_HUI,           \
        _______,  _______,  GUI_TOG,                                _______,                                GUI_TOG,  _______,  _______,  _______,  LGT_SAD,  LGT_HUD,  LGT_SAI  \
    ),

    /*  Windows layout
    +-------------------------------------------------------------------------------------------+
    | ESC |  | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9| F10| F11| F12|  | |PSCR|CORT| BL |
    +--------------------------------------------------------------------------+ +--------------+
    |  ~  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP | |INS |HOME|PGUP|
    +--------------------------------------------------------------------------+ +--------------+
    |  TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  | |DEL |END |PGDN|
    +--------------------------------------------------------------------------+ +--------------+
    | CAPSLCK  |  A |  S |  D |  F |  G |  H |  J |  K |  L | ; | ' |  RETURN  |                |
    +--------------------------------------------------------------------------+      +----+    |
    | LSHIFT     |  Z |  X |  C |  V |  B |  N |  M | , | . |  / |   RSHIFT    |      | UP |    |
    +--------------------------------------------------------------------------+ +--------------+
    |LCTRL| LGUI| LALT |            SPACE            | RALT| RGUI | FN | RCTRL | |LFT |DWN |RGT |
    +-------------------------------------------------------------------------------------------+
    */

    [WIN_BASE] = LAYOUT_tkl_ansi( \
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_CORT,  XTR_BA,  \
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP, \
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN, \
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,                                \
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,             \
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI,  KC_W_FN,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT  \
    ),

    [WIN_FN] = LAYOUT_tkl_ansi( \
        RESET,              KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  LGT_VAD,  LGT_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SNIP,  _______,  XTR_BB,  \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,                               \
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            LGT_HUI,           \
        _______,  GUI_TOG,  _______,                                _______,                                _______,  GUI_TOG,  _______,  _______,  LGT_SAD,  LGT_HUD,  LGT_SAI  \
    )
};

// Manage Windows and Mac LEDs
// - Show status of mode switch
// - Turn LEDs off durring USB suspend
static bool mode_leds_show = true;
static bool mode_leds_windows;

static void mode_leds_update(void){
    writePin(LED_WIN_PIN, mode_leds_show && mode_leds_windows);
    writePin(LED_MAC_PIN, mode_leds_show && !mode_leds_windows);
}

bool dip_switch_update_kb(uint8_t index, bool active){
    if(index == 0) {
        if(active) { // Mac mode
            layer_move(MAC_BASE);
        } else { // Windows mode
            layer_move(WIN_BASE);
        }

        // Update mode and update leds
        mode_leds_windows = !active;
        mode_leds_update();
    }

    dip_switch_update_user(index, active);
    return true;
}

void keyboard_pre_init_kb(void) {
    // Setup Win & Mac LED Pins as output
    setPinOutput(LED_WIN_PIN);
    setPinOutput(LED_MAC_PIN);

    keyboard_pre_init_user();
}
