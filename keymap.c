#include QMK_KEYBOARD_H
#include "keymap.h"
#include "accented_letters.h"
#include "keymap_fr_ch.h"
#include <stdio.h>

// Tap dance states
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;

// create a global instance of the tapdance state type
static td_state_t td_state;

// function to track the current tapdance state
int cur_dance (qk_tap_dance_state_t *state);

// `finished` function for each tapdance keycode
void CA_CC_CV_finished (qk_tap_dance_state_t *state, void *user_data);

// `finished` function for each tapdance keycode
void CA_CC_CV_finished (qk_tap_dance_state_t *state, void *user_data);

// track the tapdance state to return
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
        return SINGLE_TAP;
    } else {
        return SINGLE_HOLD;
    }
  }
  if (state->count == 2) {
      return DOUBLE_SINGLE_TAP;
  }
  else {
      return 3; // any number higher than the maximum state value you return above
  }
};

// handle the possible states for each tapdance keycode you define:

void CA_CC_CV_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      tap_code16(C(KC_C));
      break;
    case SINGLE_HOLD:
      tap_code16(C(KC_A));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(C(KC_V));
  }
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [CA_CC_CV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CA_CC_CV_finished, NULL),
};


/*
 * Per key tapping term settings
 */
/* uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) { */
    /* switch (keycode) { */
        /* case HOME_A: */
        /*     return TAPPING_TERM - 20; */
        /* case HOME_S: */
        /*     return TAPPING_TERM - 20; */
        /* case HOME_D: */
        /*     return TAPPING_TERM - 20; */
        /* case HOME_F: */
        /*     return TAPPING_TERM - 20; */
        /* case HOME_G: */
        /*     return TAPPING_TERM - 20; */
        /* case HOME_H: */
        /*     return TAPPING_TERM - 20; */
        /* case HOME_J: */
        /*     return TAPPING_TERM - 20; */
        /* case HOME_K: */
        /*     return TAPPING_TERM - 20; */
        /* case HOME_L: */
        /*     return TAPPING_TERM - 20; */
        /* case HOME_SCLN: */
        /*     return TAPPING_TERM - 20; */
        /* default: */
        /*     return TAPPING_TERM; */
    /* } */
/* }; */




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*  
 * Base Layer: New layout
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |k.layout|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  - _   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Super  |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ; :  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Options|   Z  |   X  |   C  |   V  |   B  | Alt  | Del  |  | - _  | ' "  |   N  |   M  | , <  | . >  | / ?  |  = +   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |shutd.|Symbol| Shift| Ctrl | Tab  |  | Super| Bspc | Space|Number| Mute |
 *                        |desks?| Esc  | CapsL|      |      |  |      |      |      | Enter| Vol  | 
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NEW] = LAYOUT(
      LGUI(KC_SPC), KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    UC_M_WC,
      KC_LGUI,    HOME_A, HOME_S, HOME_D, HOME_F, HOME_G,                                       HOME_H,  HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, UC_M_LN,
      MO(_OPTIONS), KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   CACCCV,_______, DED_CIR,    UC_MOD,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL ,
                               KC_CAPS, MO(_SYMBOLS), KC_LSFT,   UNDO, REDO, KC_DEL, KC_BSPC, KC_SPC, MO(_NUMBERS), KC_MUTE
    ),

/*  
 * Base Layer: Windows
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |k.layout|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  - _   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Super  |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ; :  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Options|   Z  |   X  |   C  |   V  |   B  | Alt  | Del  |  | - _  | ' "  |   N  |   M  | , <  | . >  | / ?  |  = +   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |shutd.|Symbol| Shift| Ctrl | Tab  |  | Super| Bspc | Space|Number| Mute |
 *                        |desks?| Esc  | CapsL|      |      |  |      |      |      | Enter| Vol  | 
 *                        `----------------------------------'  `----------------------------------'
 */
    [_WIN] = LAYOUT(
      LGUI(KC_SPC), KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
      KC_LGUI,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      MO(_OPTIONS), KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_LSFT,_______, KC_DEL, _______  ,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL ,
                               KC_CAPS, LT(_SYMBOLS, KC_ESC), KC_LSFT, KC_LCTL, KC_TAB , KC_BSPC, KC_LALT, KC_SPC, LT(_NUMBERS, KC_ENT), KC_MUTE
    ),

/*  
 * Base Layer: Linux
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  è (CH)|
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Alt   |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ; :  |  à (CH)|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Options|   Z  |   X  |   C  |   V  |   B  | Alt  | Del  |  | - _  | ' "  |   N  |   M  | , <  | . >  | / ?  |  é (CH)|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |shutd.|Symbol| Shift| Ctrl | Tab  |  | Super| Bspc | Space|Number| Mute |
 *                        |desks?| Esc  | CapsL|      |      |  |      |      |      | Enter| Vol  |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LINUX] = LAYOUT(
      LGUI(KC_SPC), KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
      KC_LGUI,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      MO(_OPTIONS), KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_LSFT,_______, KC_DEL, _______  ,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL ,
                               KC_CAPS, LT(_SYMBOLS, KC_ESC), KC_LSFT, KC_LCTL, KC_TAB , KC_BSPC, KC_LALT, KC_SPC, LT(_NUMBERS, KC_ENT), KC_MUTE
    ),
  
 /*  
 * Base Layer: Gaming
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  è (CH)|
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Alt   |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ; :  |  à (CH)|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Options|   Z  |   X  |   C  |   V  |   B  | Alt  | Del  |  | - _  | ' "  |   N  |   M  | , <  | . >  | / ?  |  é (CH)|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |shutd.|Symbol| Shift| Ctrl | Tab  |  | Super| Bspc | Space|Number| Mute |
 *                        |desks?| Esc  | CapsL|      |      |  |      |      |      | Enter| Vol  |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_GAMING] = LAYOUT(
      KC_TAB,       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
      KC_LCTL,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      MO(_OPTIONS), KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_LGUI,KC_PSCR, KC_DEL, LCTL(KC_LSFT),KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL ,
                               KC_CAPS, LT(_SYMBOLS, KC_ESC), KC_SPC, KC_LSFT, KC_TAB , KC_BSPC, KC_LALT, KC_SPC, LT(_NUMBERS, KC_ENT), KC_MUTE
    ),
  

/*
 * Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      | ^(CH)|      |      |                              |   %  |  {   |  }   |  #   |  ^   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | °(CH)| "(CH)| `(CH)| ç(CH)| €(CH)|                              |   *  |  [   |  ]   |  |   |  @   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |  &   |  =   |   !  |  (   |  )   |  \   |  ~   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |  $   |  `   |      | Nav  |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMBOLS] = LAYOUT(
      _______, _______, CH_DEG , CH_EURO, CH_EGRV, _______,                                     KC_PERC, KC_LCBR, KC_RCBR, KC_HASH, KC_CIRC, _______,
      _______, _______, CH_EGRV, CH_CIRC, CH_EGRV, _______,                                     KC_EXLM, KC_LBRC, KC_RBRC, KC_PIPE, KC_AT  , _______,
      _______, _______, CH_DIAE, CH_GRV , CH_CCED, _______, _______, _______, KC_AMPR, KC_EQL , KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, KC_TILD, _______,
                                 _______, _______, _______, _______, _______, KC_DLR , KC_GRV , _______,MO(_NAV), _______
    ),

/*
 * Accents
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      | ^(CH)|      |      |                              |   %  |  {   |  }   |  #   |  ^   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | °(CH)| "(CH)| `(CH)| ç(CH)| €(CH)|                              |   *  |  [   |  ]   |  |   |  @   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |  &   |  =   |   !  |  (   |  )   |  \   |  ~   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |  $   |  `   |      | Nav  |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ACCENTS] = LAYOUT(
       _______, A_CIRCU, _______, E_ACUTE, E_GRAVE, _______,                                     _______, U_CIRCU, I_CIRCU, O_CIRCU, _______, _______,
       _______, A_GRAVE, _______, E_CIRCU, _______, _______,                                     _______, _______, I_UMLAU, O_UMLAU, _______, _______,
       _______, _______, _______, C_CDILA, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Numbers and F keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.  
 * |        |  F9  | F10  | F11  | F12  |      |                              |  -   |  7   |  8   |  9   |  /   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  | Super|                              |  +   |  4   |  5   |  6   |  *   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |  0   |  1   |  2   |  3   |  .   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | Nav  |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUMBERS] = LAYOUT(
      _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,                                     KC_PMNS, KC_7,    KC_8,    KC_9,    KC_PSLS, _______,
      _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_LGUI,                                     KC_PPLS, KC_4   , KC_5   , KC_6   , KC_PAST, _______,
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______, _______, _______, _______, KC_0   , KC_1   , KC_2   , KC_3   ,  KC_DOT, _______,
                                 _______,MO(_NAV), _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Navigation + media
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      | Home | PgDn | PgUp | End  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      | Left | Down |  Up  | Right|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | Alt  | Shift| Ctrl | Super|      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______, 
      _______, _______, _______, _______, _______, _______,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
      _______, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*  Options 
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      | Prev | Play | Next |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_OPTIONS] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______,
                                 _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     return update_tri_layer_state(state, _SYMBOLS, _NUMBERS, _NAV); */
/* } */

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}


static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _NEW:
            oled_write_P(PSTR("new\n"), false);
            break;
        case _WIN:
            oled_write_P(PSTR("windows\n"), false);
            break;
        case _LINUX:
            oled_write_P(PSTR("linux\n"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("gaming\n"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("symbols\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("navigation\n"), false);
            break;
        case _OPTIONS:
            oled_write_P(PSTR("options\n"), false);
            break;
        default:
            oled_write_P(PSTR("undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("numlck ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("caplck ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("scrllck ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
				oled_set_cursor(0,6);
    }
}
#endif

#ifdef ENCODER_ENABLE
uint8_t selected_layer = 0;
void encoder_update_user(uint8_t index, bool clockwise) {
   if (index == 0) {
		switch (index) {
			case 0:
			if (!clockwise && selected_layer  < 4) {
				selected_layer ++;
			} else if (clockwise && selected_layer  > 0){
				selected_layer --;
			}
			layer_clear();
			layer_on(selected_layer);
		}
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
#endif
