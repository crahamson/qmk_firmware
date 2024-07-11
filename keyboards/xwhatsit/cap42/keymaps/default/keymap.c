#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "sendstring_swedish.h"

#define NUM_SPC LT(NUM, KC_SPC)
#define FN_ENT LT(FN, KC_ENT)
#define SYM_BSP LT(SYM, KC_BSPC)
#define CTL_TAB MT(MOD_LCTL, KC_TAB)
#define ALT_DEL MT(MOD_LALT, KC_DEL)
#define SFT_INS LSFT(KC_INS)

enum custom_keycodes {
    rarrow = SAFE_RANGE,
    larrow,
    others0,
};

// Combos
//enum combos {
//  ST_CTL,
//  RS_SFT,
//  AR_GUI,
//  RT_ALT,
//  NE_CTL,
//  EI_SFT,
//  IO_GUI,
//  NI_ALT
//};
//
//const uint16_t PROGMEM st_combo[] = {KC_S, KC_T, COMBO_END};
//const uint16_t PROGMEM rs_combo[] = {KC_R, KC_S, COMBO_END};
//const uint16_t PROGMEM ar_combo[] = {KC_A, KC_R, COMBO_END};
//const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
//const uint16_t PROGMEM ne_combo[] = {KC_N, KC_E, COMBO_END};
//const uint16_t PROGMEM ei_combo[] = {KC_E, KC_I, COMBO_END};
//const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
//const uint16_t PROGMEM ni_combo[] = {KC_N, KC_I, COMBO_END};
//
//combo_t key_combos[] = {
//  [ST_CTL] = COMBO(st_combo, KC_LCTL),
//  [RS_SFT] = COMBO(rs_combo, KC_LSFT),
//  [AR_GUI] = COMBO(ar_combo, KC_LGUI),
//  [RT_ALT] = COMBO(rt_combo, KC_LALT),
//  [NE_CTL] = COMBO(ne_combo, KC_LCTL),
//  [EI_SFT] = COMBO(ei_combo, KC_LSFT),
//  [IO_GUI] = COMBO(io_combo, KC_LGUI),
//  [NI_ALT] = COMBO(ni_combo, KC_LALT),
//};

// Left-hand home row mods colemak
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTRL_T LCTL_T(KC_T)

// Right-hand home row mods colemak
#define CTRL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O LGUI_T(KC_O)

enum layer {
  COLEMAK,
  GAME,
  NUM,
  SYM,
  FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * .-----------------------------------------------------------------------------------.
 * | Alt  |   Q  |   W  |   F  |   P  |   B  |   Y  |   L  |   U  |   K  |   Å  |  Ö   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CTRL |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  Ä   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   J  |   H  |   ,  |   .  |   -  |GUI   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 *                      | ESC  |Num_SP|  Tab |FN_Ent|Sym_BS|  Del |
 *                      `-----------------------------------------'
 */

[COLEMAK] = LAYOUT(
  KC_LALT, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_Y,    KC_L,    KC_U,    KC_K,    SE_ARNG, SE_ODIA,
  KC_LCTL, GUI_A,   ALT_R,   SFT_S,   CTRL_T,  KC_G,    KC_M,    CTRL_N,  SFT_E,   ALT_I,   GUI_O,   SE_ADIA,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_J,    KC_H,    KC_COMM, KC_DOT,  SE_MINS, KC_LGUI,
                             KC_ESC,  NUM_SPC, CTL_TAB, FN_ENT,  SYM_BSP, ALT_DEL
),

[GAME] = LAYOUT(
  KC_LALT, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_Y,    KC_L,    KC_U,    KC_K,    SE_ARNG, SE_ODIA,
  KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    SE_ADIA,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_J,    KC_H,    KC_COMM, KC_DOT,  SE_MINS, KC_LGUI,
                             KC_ESC,  NUM_SPC, CTL_TAB, FN_ENT,  SYM_BSP, ALT_DEL
),

/* SYM
 * ,-----------------------------------------------------------------------------------.
 * | RST  |   §  |   '  |   /  |   ~  |      |      |   |  |   \  |   ¨  |   €  | GAME |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | <=   |   !  |   $  |   (  |   [  | paste|      |   ]  |   )  |   #  |   ?  |  =>  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  ^   |   '  |   %  |   {  |   <  |      |      |   >  |   }  |   &  |o=>'0'|  µ   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 *                      |  @   |  =   |  "   |      |      |      |
 *                      `-----------------------------------------'
 */
[SYM] = LAYOUT(
  QK_BOOT, SE_SECT, SE_ACUT, SE_SLSH, SE_TILD, _______, _______, SE_PIPE, SE_BSLS, SE_DIAE, SE_EURO, TG(GAME),
  larrow,  SE_EXLM, SE_DLR,  SE_LPRN, SE_LBRC, SFT_INS, _______, SE_RBRC, SE_RPRN, SE_HASH, SE_QUES, rarrow,
  SE_CIRC, SE_QUOT, SE_PERC, SE_LCBR, SE_LABK, KC_SPC,  _______, SE_RABK, SE_RCBR, SE_AMPR, others0, SE_MICR,
                             SE_AT,   SE_EQL,  SE_DQUO, _______, _______, _______
),
 
/* NUM
 * ,-----------------------------------------------------------------------------------.
 * |      |      | prev | play | next |      |      |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   +  |   -  |   *  |   /  |   ^  |      |   4  |   5  |   6  |   '  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | mute | vol_d| vol_u|      | bkspc|   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 *                      |      |      |      |  ,   |   0  |   .  |
 *                      `-----------------------------------------'
 */
[NUM] = LAYOUT(
  _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, SE_7,    SE_8,    SE_9,    _______, _______,
  _______, SE_PLUS, SE_MINS, SE_ASTR, SE_SLSH, SE_CIRC, KC_SPC,  SE_4,    SE_5,    SE_6,    SE_QUOT, _______,
  _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_BSPC, SE_1,    SE_2,    SE_3,    _______, _______,
                             _______, _______, _______, SE_COMM, SE_0,    SE_DOT
),

/* FN
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | left | down |  up  | right|      |      |  F4  |  F5  |  F6  |  F11 |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F12 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 *                      | prsc | caps |      |      |      |      |
 *                      `-----------------------------------------'
 */
[FN] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
  _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
                             KC_PSCR, KC_CAPS, _______, _______, _______, _______
)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case rarrow :
        if (record->event.pressed) {
            // when keycode rarrow is pressed
            SEND_STRING(" => ");
        } else {
            // when keycode rarrow is released
        }
        break;

    case larrow :
        if (record->event.pressed) {
            // when keycode rarrow is pressed
            SEND_STRING(" <= ");
        } else {
            // when keycode rarrow is released
        }
        break;

    case others0 :
        if (record->event.pressed) {
            // when keycode rarrow is pressed
            SEND_STRING("(others => '0');");
        } else {
            // when keycode rarrow is released
        }
        break;
    }
    return true;
};
