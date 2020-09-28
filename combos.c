#include QMK_KEYBOARD_H
#include "keymap.h"
#include "action_tapping.h" // necessary for action_tapping_process

enum combo_events {
    SPCJ_PRN,
    SPCK_PRN,
    JK_BSPC,
    KL_ENT,
    MCOMMA_MINS,
    COMMADOT_QUOT,
    FD_TAB,
    DS_ESC,
    CV_GRV,
    XC_AMPR,
    BSPCEV_EVERY,
    BSPCU_YOU,
    BSPCA_AND,
    BSPCN_NOT,
    BSPCW_WITH,
    BSPCF_FOR,
    BSPCH_HERE,
    BSPCT_THE,
    BSPCM_MENT,
    BSPCG_ING,
    BSPCO_OUGH,
    BSPCI_ION,
    BSPCIS_IONS,
    BSPCTA_THAT,
    BSPCQ_QUE,
    BSPCK_KEY,
    COMBO_LENGTH
};


int COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM SPC_J_COMBO[] = {KC_SPC, HOME_J, COMBO_END};
const uint16_t PROGMEM SPC_K_COMBO[] = {KC_SPC, HOME_K, COMBO_END};
const uint16_t PROGMEM J_K_COMBO[] = {HOME_J, HOME_K, COMBO_END};
const uint16_t PROGMEM K_L_COMBO[] = {HOME_K, HOME_L, COMBO_END};
const uint16_t PROGMEM M_COMMA_COMBO[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM COMMA_DOT_COMBO[] = {KC_COMMA, TD_DOT, COMBO_END};
const uint16_t PROGMEM F_D_COMBO[] = {HOME_F, HOME_D, COMBO_END};
const uint16_t PROGMEM D_S_COMBO[] = {HOME_D, HOME_S, COMBO_END};
const uint16_t PROGMEM C_V_COMBO[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM X_C_COMBO[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM BSPC_E_V_COMBO[] = {KC_BSPC, KC_E, KC_V, COMBO_END};
const uint16_t PROGMEM BSPC_U_COMBO[] = {KC_BSPC, KC_U, COMBO_END};
const uint16_t PROGMEM BSPC_A_COMBO[] = {KC_BSPC, HOME_A, COMBO_END};
const uint16_t PROGMEM BSPC_N_COMBO[] = {KC_BSPC, KC_N, COMBO_END};
const uint16_t PROGMEM BSPC_W_COMBO[] = {KC_BSPC, KC_W, COMBO_END};
const uint16_t PROGMEM BSPC_F_COMBO[] = {KC_BSPC, HOME_F, COMBO_END};
const uint16_t PROGMEM BSPC_H_COMBO[] = {KC_BSPC, HOME_H, COMBO_END};
const uint16_t PROGMEM BSPC_T_COMBO[] = {KC_BSPC, KC_T, COMBO_END};
const uint16_t PROGMEM BSPC_M_COMBO[] = {KC_BSPC, KC_M, COMBO_END};
const uint16_t PROGMEM BSPC_G_COMBO[] = {KC_BSPC, HOME_G, COMBO_END};
const uint16_t PROGMEM BSPC_O_COMBO[] = {KC_BSPC, KC_O, COMBO_END};
const uint16_t PROGMEM BSPC_I_COMBO[] = {KC_BSPC, KC_I, COMBO_END};
const uint16_t PROGMEM BSPC_I_S_COMBO[] = {KC_BSPC, KC_I, HOME_S, COMBO_END};
const uint16_t PROGMEM BSPC_T_A_COMBO[] = {KC_BSPC, KC_T, HOME_A, COMBO_END};
const uint16_t PROGMEM BSPC_Q_COMBO[] = {KC_BSPC, KC_Q, COMBO_END};
const uint16_t PROGMEM BSPC_K_COMBO[] = {KC_BSPC, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [SPCJ_PRN] = COMBO_ACTION(SPC_J_COMBO),
    [SPCK_PRN] = COMBO_ACTION(SPC_K_COMBO),
    [JK_BSPC] = COMBO_ACTION(J_K_COMBO),
    [KL_ENT] = COMBO_ACTION(K_L_COMBO),
    [MCOMMA_MINS] = COMBO_ACTION(M_COMMA_COMBO),
    [COMMADOT_QUOT] = COMBO_ACTION(COMMA_DOT_COMBO),
    [FD_TAB] = COMBO_ACTION(F_D_COMBO),
    [DS_ESC] = COMBO_ACTION(D_S_COMBO),
    [CV_GRV] = COMBO_ACTION(C_V_COMBO),
    [XC_AMPR] = COMBO_ACTION(X_C_COMBO),
    [BSPCEV_EVERY] = COMBO_ACTION(BSPC_E_V_COMBO),
    [BSPCU_YOU] = COMBO_ACTION(BSPC_U_COMBO),
    [BSPCA_AND] = COMBO_ACTION(BSPC_A_COMBO),
    [BSPCN_NOT] = COMBO_ACTION(BSPC_N_COMBO),
    [BSPCW_WITH] = COMBO_ACTION(BSPC_W_COMBO),
    [BSPCF_FOR] = COMBO_ACTION(BSPC_F_COMBO),
    [BSPCH_HERE] = COMBO_ACTION(BSPC_H_COMBO),
    [BSPCT_THE] = COMBO_ACTION(BSPC_T_COMBO),
    [BSPCM_MENT] = COMBO_ACTION(BSPC_M_COMBO),
    [BSPCG_ING] = COMBO_ACTION(BSPC_G_COMBO),
    [BSPCO_OUGH] = COMBO_ACTION(BSPC_O_COMBO),
    [BSPCI_ION] = COMBO_ACTION(BSPC_I_COMBO),
    [BSPCIS_IONS] = COMBO_ACTION(BSPC_I_S_COMBO),
    [BSPCTA_THAT] = COMBO_ACTION(BSPC_T_A_COMBO),
    [BSPCQ_QUE] = COMBO_ACTION(BSPC_Q_COMBO),
    [BSPCK_KEY] = COMBO_ACTION(BSPC_K_COMBO),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
    // Process mod-taps before the combo is fired,
    // this helps making modifier-aware combos, 
    // like UY_PRN or BSPCN_NOT, more fluid
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

        case BSPCEV_EVERY:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Every");
                    set_mods(mod_state);
                }
                else {
                    send_string("every");
                }
        }
        break;

        case BSPCU_YOU:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("You");
                    set_mods(mod_state);
                }
                else {
                    send_string("you");
                }
        }
        break;

        case BSPCA_AND:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("And");
                    set_mods(mod_state);
                }
                else {
                    send_string("and");
                }
        }
        break;
        
        case BSPCN_NOT:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Not");
                    set_mods(mod_state);
                }
                else if (mod_state & MOD_MASK_CTRL) {
                    unregister_code(KC_LCTL);
                    unregister_code(KC_RCTL);
                    send_string("n't");
                    set_mods(mod_state);
                }
                else {
                    send_string("not");
                }
        }
        break;

        case BSPCW_WITH:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("With");
                    set_mods(mod_state);
                }
                else {
                    send_string("with");
                }
        }
        break;

        case BSPCF_FOR:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("For");
                    set_mods(mod_state);
                }
                else {
                    send_string("for");
                }
        }
        break;

        case BSPCH_HERE:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Here");
                    set_mods(mod_state);
                }
                else {
                    send_string("here");
                }
        }
        break;

        case BSPCT_THE:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("The");
                    set_mods(mod_state);
                }
                else {
                    send_string("the");
                }
        }
        break;

        case BSPCM_MENT:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Ment");
                    set_mods(mod_state);
                }
                else {
                    send_string("ment");
                }
        }
        break;

        case BSPCG_ING:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Ing");
                    set_mods(mod_state);
                }
                else {
                    send_string("ing");
                }
        }
        break;

        case BSPCO_OUGH:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Ough");
                    set_mods(mod_state);
                }
                else {
                    send_string("ough");
                }
        }
        break;

        case BSPCI_ION:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Ion");
                    set_mods(mod_state);
                }
                else {
                    send_string("ion");
                }
        }
        break;

        case BSPCIS_IONS:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Ions");
                    set_mods(mod_state);
                }
                else {
                    send_string("ions");
                }
        }
        break;

        case BSPCTA_THAT:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("That");
                    set_mods(mod_state);
                }
                else {
                    send_string("that");
                }
        }
        break;

        case BSPCQ_QUE:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Que");
                    set_mods(mod_state);
                }
                else {
                    send_string("que");
                }
        }
        break;

        case BSPCK_KEY:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    send_string("Key");
                    set_mods(mod_state);
                }
                else {
                    send_string("key");
                }
        }   

        case JK_BSPC:
            if (pressed) {
                tap_code16(KC_BSPC);
            }
        break;

        case KL_ENT:
            if (pressed) {
                tap_code16(KC_ENT);
            }
        break;

        case MCOMMA_MINS:
            if (pressed) {
                tap_code16(KC_MINS);
            }
        break;

        case COMMADOT_QUOT:
            if (pressed) {
                tap_code16(KC_QUOT);
            }
        break;

        case FD_TAB:
            if (pressed) {
                tap_code16(KC_TAB);
            }
        break;

        case DS_ESC:
            if (pressed) {
                tap_code16(KC_ESC);
            }
        break;

        case CV_GRV:
            if (pressed) {
                tap_code16(KC_GRV);
            }
        break;

        case XC_AMPR:
            if (pressed) {
                tap_code16(KC_AMPR);
            }
        break;


    }
};
