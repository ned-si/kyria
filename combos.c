#include QMK_KEYBOARD_H
#include "keymap.h"
#include "action_tapping.h" // necessary for action_tapping_process

enum combo_events {
    SPCJ_PRN,
    SPCK_PRN,
    JK_ENT,
    MCOMMA_QUOT,
    COMMADOT_MINS,
    FD_ESC,
    CV_GRV,
    XC_TILD,
    COMBO_LENGTH
};


int COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM SPC_J_COMBO[] = {KC_SPC, HOME_J, COMBO_END};
const uint16_t PROGMEM SPC_K_COMBO[] = {KC_SPC, HOME_K, COMBO_END};
const uint16_t PROGMEM J_K_COMBO[] = {HOME_J, HOME_K, COMBO_END};
const uint16_t PROGMEM M_COMMA_COMBO[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM COMMA_DOT_COMBO[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM F_D_COMBO[] = {HOME_F, HOME_D, COMBO_END};
const uint16_t PROGMEM C_V_COMBO[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM X_C_COMBO[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [SPCJ_PRN] = COMBO_ACTION(SPC_J_COMBO),
    [SPCK_PRN] = COMBO_ACTION(SPC_K_COMBO),
    [JK_ENT] = COMBO_ACTION(J_K_COMBO),
    [MCOMMA_QUOT] = COMBO_ACTION(M_COMMA_COMBO),
    [COMMADOT_MINS] = COMBO_ACTION(COMMA_DOT_COMBO),
    [FD_ESC] = COMBO_ACTION(F_D_COMBO),
    [CV_GRV] = COMBO_ACTION(C_V_COMBO),
    [XC_TILD] = COMBO_ACTION(X_C_COMBO),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
    // Process mod-taps before the combo is fired,
    // this helps making modifier-aware combos, 
    // like UY_PRN or SPCN_NOT, more fluid
    // when I use them with home row mods.
    action_tapping_process((keyrecord_t){});
    mod_state = get_mods();
    switch(combo_index) {
        case SPCJ_PRN:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    // First canceling both shifts so that shift isn't applied
                    // to the KC_LBRC keycode since that would result in
                    // a "{" instead of a "[".            
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("[");
                    // "resuming" *the* shift so that you can hold shift 
                    // and the square brackets combo still works without
                    // having to re-press shift every time.
                    set_mods(mod_state);
                }
                else if (mod_state & MOD_MASK_CTRL) {
                    unregister_code(KC_LCTL);
                    unregister_code(KC_RCTL);
                    send_string("{");
                    set_mods(mod_state);
                }
                else {
                    send_string("(");
                }
            }
            break;

        case SPCK_PRN:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("]");
                    set_mods(mod_state);
                }
                else if (mod_state & MOD_MASK_CTRL) {
                    unregister_code(KC_LCTL);
                    unregister_code(KC_RCTL);
                    send_string("}");
                    set_mods(mod_state);
                }
                else {
                    send_string(")");
                }
        }
        break;

        case JK_ENT:
            if (pressed) {
                tap_code16(KC_ENT);
            }
        break;

        case MCOMMA_QUOT:
            if (pressed) {
                tap_code16(KC_QUOT);
            }
        break;

        case COMMADOT_MINS:
            if (pressed) {
                tap_code16(KC_MINS);
            }
        break;

        case FD_ESC:
            if (pressed) {
                tap_code16(KC_ESC);
            }
        break;

        case CV_GRV:
            if (pressed) {
                tap_code16(KC_GRV);
            }
        break;

        case XC_TILD:
            if (pressed) {
                tap_code16(KC_TILD);
            }
        break;
    }
};
