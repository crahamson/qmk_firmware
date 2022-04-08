
#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "durken1.h"


// Left-hand home row mods colemak
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTRL_T LCTL_T(KC_T)

// Right-hand home row mods colemak
#define CTL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O LGUI_T(KC_O)

#define NUM_SPC LT(NUM, KC_SPC)
#define FN_ENT LT(FN, KC_ENT)
#define SYM_BSP LT(SYM, KC_BSPC)

const uint16_t PROGMEM arng_combo[] = {ALT_R, SFT_S, COMBO_END};
const uint16_t PROGMEM adia_combo[] = {SFT_E, ALT_I, COMBO_END};
const uint16_t PROGMEM odia_combo[] = {SE_U, SE_K, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
	[WF_ARNG] = COMBO(arng_combo, SE_ARNG),
	[UK_ADIA] = COMBO(adia_combo, SE_ADIA),
	[HC_ODIA] = COMBO(odia_combo, SE_ODIA)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
 // Colemak Mod-DH
  //,--------------------------------------------,                    ,--------------------------------------------.
         SE_Q,    SE_W,    SE_F,    SE_P,    SE_B,                         SE_Y,    SE_L,    SE_U,    SE_K, SE_QUOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        GUI_A,   ALT_R,   SFT_S,  CTRL_T,    SE_G,                         SE_M,   CTL_N,   SFT_E,   ALT_I,   GUI_O,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         SE_Z,    SE_X,    SE_C,    SE_D,    SE_V,                         SE_J,    SE_H, SE_COMM,  SE_DOT, SE_MINS,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_ESC, NUM_SPC,  KC_TAB,     FN_ENT, SYM_BSP,  KC_DEL
                             //`--------------------------'  '--------------------------'

  ),


  [MBO] = LAYOUT(
  // Mouse
  //,--------------------------------------------,                    ,--------------------------------------------.
      _______, _______, _______, _______, _______,                      KC_BTN1, KC_BTN2, _______, _______, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                      KC_BTN3, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 _______, _______, _______,    _______, KC_BSPC, _______
                             //`--------------------------'  '--------------------------'

  ),

  [SYM] = LAYOUT(
  // Symbols
  //,--------------------------------------------,                    ,--------------------------------------------.
      SE_SECT, SE_ACUT, SE_SLSH, SE_TILD, _______,                      _______, SE_PIPE, SE_BSLS, SE_DIAE, SE_CIRC,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      SE_EXLM,  SE_DLR, SE_LPRN, SE_LBRC, _______,                      _______, SE_RBRC, SE_RPRN, SE_HASH, SE_QUES,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, SE_PERC, SE_LCBR, SE_LABK, _______,                      _______, SE_RABK, SE_RCBR, SE_AMPR, _______,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                   SE_AT,  SE_EQL, SE_DQUO,    _______, _______, _______
                             //`--------------------------'  '--------------------------'
  ),

  [NUM] = LAYOUT(
  // Numbers
  //,--------------------------------------------,                    ,--------------------------------------------.
      _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,                      _______,    SE_7,    SE_8,    SE_9, SE_QUOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      SE_PLUS, SE_MINS, SE_ASTR, SE_SLSH, SE_CIRC,                      _______,    SE_4,    SE_5,    SE_6, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, KC_VOLD, KC_VOLU, _______,                       KC_SPC,    SE_1,    SE_2,    SE_3, _______,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 _______, _______, _______,    SE_COMM,   SE_0,  SE_DOT
                             //`--------------------------'  '--------------------------'
  ),

  [FN] = LAYOUT(
  // FN
  //,--------------------------------------------,                    ,--------------------------------------------.
      _______, _______, _______, _______, _______,                      _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,                      _______,   KC_F4,   KC_F5,   KC_F6,  KC_F11,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                      _______,   KC_F1,   KC_F2,   KC_F3,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 KC_PSCR, KC_CAPS, _______,    _______, _______, _______
                             //`--------------------------'  '--------------------------'
  )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
