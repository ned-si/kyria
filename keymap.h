#pragma once

#include QMK_KEYBOARD_H
#include "tapdance.h"

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;

enum layers {
    _NEW = 0,
    _WIN,
    _LINUX,
    _GAMING,
    _SYMBOLS,
    _ACCENTS,
    _NUMBERS,
    _NAV,
    _OPTIONS
};

// // Layer keys
// #define NAV_TAB LT(_NAV, KC_TAB)
// #define GNAV MO(_GNAV)
// #define SYM MO(_SYM)
#define ACCENTS OSL(_ACCENTS)
// #define MOUSE MO(_MOUSE)
// #define MS_CAPS LT(_MOUSE, KC_CAPS)
// #define ADJUST MO(_ADJUST)
// #define SYM_ENT LT(_SYM, KC_ENT)
// #define PLOVER TG(_PLOVER)
// #define NAV_UND LT(_NAV, KC_F24)

// Miscellaneous keyboard shortcuts in direct access
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define DED_CIR ALGR(KC_6)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)
#define HOME_G LT(_ACCENTS, KC_G)

// Right-hand home row mods
#define HOME_SCLN LGUI_T(KC_SCLN)
#define HOME_L LALT_T(KC_L)
#define HOME_K RSFT_T(KC_K)
#define HOME_J LCTL_T(KC_J)
#define HOME_H LT(_ACCENTS, KC_H)
