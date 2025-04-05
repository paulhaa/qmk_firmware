#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _COLEMAK,
    _NUM,
    _FNK,
    _NAV,
};

// Aliases for readability
#define NUM MO(_NUM)
#define NAV MO(_NAV)
#define FNK MO(_FNK)

#define NAV_ESC LT(NAV, KC_ESC)
#define NUM_SPC LT(NUM, KC_SPC)
#define NUM_ENT LT(NUM, KC_ENT)
#define FNK_BSPC LT(FNK, KC_BSPC)

#define CMK DF(_COLEMAK)
#define QWERTY DF(_QWERTY)

// Umlauts
#define AE RALT(KC_Q)
#define OE RALT(KC_P)
#define UE RALT(KC_Y)
#define SS RALT(KC_S)

// Modifiers at home row
// QWERTY
#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define CTL_D MT(MOD_LCTL, KC_D)
#define SFT_F MT(MOD_LSFT, KC_F)

#define SFT_J MT(MOD_RSFT, KC_J)
#define CTL_K MT(MOD_RCTL, KC_K)
#define ALT_L MT(MOD_RALT, KC_L)
#define GUI_SCLN MT(MOD_RGUI, KC_SCLN)

// COLEMAK
#define ALT_R MT(MOD_LALT, KC_R)
#define CTL_S MT(MOD_LCTL, KC_S)
#define _SFT_T MT(MOD_LSFT, KC_T)

#define SFT_N MT(MOD_RSFT, KC_N)
#define CTL_E MT(MOD_RCTL, KC_E)
#define ALT_I MT(MOD_RALT, KC_I)
#define GUI_O MT(MOD_RGUI, KC_O)

// Numbers
#define GUI_6 MT(MOD_LGUI, KC_6)
#define ALT_4 MT(MOD_LALT, KC_4)
#define CTL_0 MT(MOD_LCTL, KC_0)
#define SFT_2 MT(MOD_LSFT, KC_2)

#define SFT_3 MT(MOD_RSFT, KC_3)
#define CTL_1 MT(MOD_RCTL, KC_1)
#define ALT_5 MT(MOD_RALT, KC_5)
#define GUI_7 MT(MOD_RGUI, KC_7)

// Fn Keys
#define GUI_F6 MT(MOD_LGUI, KC_F6)
#define ALT_F4 MT(MOD_LALT, KC_F4)
#define CTL_F0 MT(MOD_LCTL, KC_0)
#define SFT_F2 MT(MOD_LSFT, KC_F2)

#define SFT_F3 MT(MOD_RSFT, KC_F3)
#define CTL_F1 MT(MOD_RCTL, KC_F1)
#define ALT_F5 MT(MOD_RALT, KC_F5)
#define GUI_F7 MT(MOD_RGUI, KC_F7)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ┌──────┬──────┬──────┬──────┬───────┐                  ┌────────┬──────┬──────┬──────┬──────┐
 * │   Q  │   W  │   E  │   R  │   T   │                  │    Y   │   U  │   I  │   O  │   P  │
 * ├──────┼──────┼──────┼──────┼───────┤                  ├────────┼──────┼──────┼──────┼──────┤
 * │LGUI/A│LAlt/S│LCtl/D│LSft/F│   G   │                  │    H   │RSft/J│RCtl/K│RAlt/L│RGUI/;│
 * ├──────┼──────┼──────┼──────┼───────┤                  ├────────┼──────┼──────┼──────┼──────┤
 * │   Z  │   X  │   C  │   V  │   B   │                  │    N   │   M  │   ,  │   .  │  /   │
 * └──────┴──────┴──────┼──────┼───────┼───────┐  ┌───────┼────────┼──────┼──────┴──────┴──────┘
 *                      │ Clmk │Nav/Esc│Num/Spc│  │Num/Ent│Fnk/Bspc│CW Tog│
 *                      └──────┴───────┴───────┘  └───────┴────────┴──────┘
 */
    [_QWERTY] = LAYOUT_split_3x5_3(
     KC_Q , KC_W , KC_E , KC_R , KC_T   ,                   KC_Y    , KC_U   , KC_I   , KC_O  , KC_P    ,
     GUI_A, ALT_S, CTL_D, SFT_F, KC_G   ,                   KC_H    , SFT_J  , CTL_K  , ALT_L , GUI_SCLN,
     KC_Z , KC_X , KC_C , KC_V , KC_B   ,                   KC_N    , KC_M   , KC_COMM, KC_DOT, KC_SLSH ,
                          CMK  , NAV_ESC, NUM_SPC, NUM_ENT, FNK_BSPC, CW_TOGG
    ),
/*
 * Base Layer: Colemak Mod DH
 *
 * ┌──────┬──────┬──────┬──────┬───────┐                  ┌────────┬──────┬──────┬──────┬──────┐
 * │   Q  │   W  │   F  │   P  │   B   │                  │    J   │   L  │   U  │   Y  │   ;  │
 * ├──────┼──────┼──────┼──────┼───────┤                  ├────────┼──────┼──────┼──────┼──────┤
 * │LGUI/A│LAlt/R│LCtl/S│LSft/T│   G   │                  │    M   │RSft/N│RCtl/E│RAlt/I│RGUI/O│
 * ├──────┼──────┼──────┼──────┼───────┤                  ├────────┼──────┼──────┼──────┼──────┤
 * │   Z  │   X  │   C  │   D  │   V   │                  │    K   │   H  │   ,  │   .  │  /   │
 * └──────┴──────┴──────┼──────┼───────┼───────┐  ┌───────┼────────┼──────┼──────┴──────┴──────┘
 *                      │QWERTY│Nav/Esc│Num/Spc│  │Num/Ent│Fnk/Bspc│CW Tog│
 *                      └──────┴───────┴───────┘  └───────┴────────┴──────┘
 */
    [_COLEMAK] = LAYOUT_split_3x5_3(
     KC_Q , KC_W , KC_F , KC_P  , KC_B   ,                   KC_J    , KC_L   , KC_U   , KC_Y  , KC_SCLN,
     GUI_A, ALT_R, CTL_S, _SFT_T, KC_G   ,                   KC_M    , SFT_N  , CTL_E  , ALT_I , GUI_O  ,
     KC_Z , KC_X , KC_C , KC_D  , KC_V   ,                   KC_K    , KC_H   , KC_COMM, KC_DOT, KC_SLSH,
                          QWERTY, NAV_ESC, NUM_SPC, NUM_ENT, FNK_BSPC, CW_TOGG
    ),

/*
 * Num Layer: Numbers
 *
 * ┌──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┐
 * │      │  =   │  -   │      │      │                │      │  \   │  '   │  `   │      │
 * ├──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┤
 * │  6   │  4   │  0   │  2   │  AE  │                │  UE  │  3   │  1   │  5   │  7   │
 * ├──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┤
 * │      │  [   │  ]   │  8   │  OE  │                │  SS  │  9   │  )   │  (   │      │
 * └──────┴──────┴──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┴──────┴──────┘
 *                      │      │      │      │  │      │      │      │
 *                      └──────┴──────┴──────┘  └──────┴──────┴──────┘
 */
    [_NUM] = LAYOUT_split_3x5_3(
      _______, KC_EQL , KC_MINS, _______, _______,                   _______, KC_BSLS, KC_QUOT, KC_GRV , _______,
      GUI_6  , ALT_4  , CTL_0  , SFT_2  , AE     ,                   UE     , SFT_3  , CTL_1  , ALT_5  , GUI_7  ,
      _______, KC_LBRC, KC_RBRC, KC_8   , OE     ,                   SS     , KC_9   , KC_RPRN, KC_LPRN, _______,
                                 _______, _______, _______, _______, _______, _______
    ),

/*
 * Fn Layer: Fn Keys
 *
 * ┌──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │                │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┤
 * │  F6  │  F4  │ LCtl │  F2  │      │                │      │  F3  │  F1  │  F5  │  F7  │
 * ├──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┤
 * │      │  F12 │  F10 │  F8  │      │                │      │  F9  │ F11  │      │      │
 * └──────┴──────┴──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┴──────┴──────┘
 *                      │      │      │      │  │      │      │      │
 *                      └──────┴──────┴──────┘  └──────┴──────┴──────┘
 */
    [_FNK] = LAYOUT_split_3x5_3(
      _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
      GUI_F6 , ALT_F4 , KC_LCTL, SFT_F2 , _______,                   _______, SFT_F3 , CTL_F1 , ALT_F5 , GUI_F7 ,
      _______, KC_F12 , KC_F10 , KC_F8  , _______,                   _______, KC_F9  , KC_F11 , _______, _______,
                                 _______, _______, _______, _______, _______, _______
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ┌──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┐
 * │TT_DWN│TT_UP │TT_PNT│      │      │                │ Home │ PgDn │ PgUp │ End  │Insert│
 * ├──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┤
 * │ LGUI │ LAlt │ LCtl │ LSft │      │                │   ←  │   ↓  │   ↑  │   →  │      │
 * ├──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │                │VolMut│VolDn │VolDn │ Play │      │
 * └──────┴──────┴──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┴──────┴──────┘
 *                      │      │      │      │  │  Tab │  Del │      │
 *                      └──────┴──────┴──────┘  └──────┴──────┴──────┘
 */
    [_NAV] = LAYOUT_split_3x5_3(
      QK_DYNAMIC_TAPPING_TERM_DOWN, QK_DYNAMIC_TAPPING_TERM_UP, QK_DYNAMIC_TAPPING_TERM_PRINT, _______, _______,                  KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_INS ,
      KC_LGUI                     , KC_LALT                   , KC_LCTL                      , KC_LSFT, _______,                  KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
      _______                     , _______                   , _______                      , _______, _______,                  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, _______,
                                                                                               _______, _______, _______, KC_TAB, KC_DEL, _______
    ),

// /*
//  * Layer template
//  *
//  * ┌──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┐
//  * │      │      │      │      │      │                │      │      │      │      │      │
//  * ├──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┤
//  * │      │      │      │      │      │                │      │      │      │      │      │
//  * ├──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┤
//  * │      │      │      │      │      │                │      │      │      │      │      │
//  * └──────┴──────┴──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┴──────┴──────┘
//  *                      │      │      │      │  │      │      │      │
//  *                      └──────┴──────┴──────┘  └──────┴──────┴──────┘
//  */
//     [_LAYERINDEX] = LAYOUT_split_3x5_3(
//       _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______
//     ),
};

