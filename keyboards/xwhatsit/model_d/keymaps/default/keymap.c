#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#define NUM_SPC LT(NUM, KC_SPC)
#define FN_ENT LT(FN, KC_ENT)
#define SYM_BSP LT(SYM, KC_BSPC)
#define CTL_DEL MT(MOD_LCTL, KC_DEL)


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

enum layer {
  COLEMAK,
  NUM,
  SYM,
  FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * .-----------------------------------------------------------------------------------.
 * | Ctrl |   Q  |   W  |   F  |   P  |   B  |   Y  |   L  |   U  |   K  |   Å  |  Ä   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | GUI  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  Ö   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   J  |   H  |   ,  |   .  |   -  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | ESC  |Num_SP|  Tab |FN_Ent|Sym_BS|  Del |      |      |Right |
 * `-----------------------------------------------------------------------------------'
 */
[COLEMAK] = LAYOUT_all(
  KC_LCTL, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_Y,    KC_L,    KC_U,    KC_K,    SE_ODIA, XXXXXXX,
  SE_ARNG, GUI_A,   ALT_R,   SFT_S,   CTRL_T,  KC_G,    KC_M,    CTL_N,   SFT_E,   ALT_I,   GUI_O,   SE_ADIA,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_J,    KC_H,    KC_COMM, KC_DOT,  SE_MINS, KC_LALT,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,  NUM_SPC, KC_TAB,  FN_ENT,  SYM_BSP, CTL_DEL, XXXXXXX, XXXXXXX, XXXXXXX
),

/* SYM
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   Y  |   L  |   U  |   K  |   Å  |  Ä   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  Ö   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   J  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[SYM] = LAYOUT_all(
  _______, SE_SECT, SE_ACUT, SE_SLSH, SE_TILD, _______, SE_CIRC, SE_PIPE, SE_BSLS, SE_DIAE, SE_ODIA, _______,
  _______, SE_EXLM, SE_DLR,  SE_LPRN, SE_LBRC, _______, _______, SE_RBRC, SE_RPRN, SE_HASH, SE_QUES, _______,
  _______, SE_QUOT, SE_PERC, SE_LCBR, SE_LABK, _______, _______, SE_RABK, SE_RCBR, SE_AMPR, _______, _______,
  _______, _______, _______, SE_AT,   SE_EQL,  SE_DQUO, _______, _______, _______, _______, _______, _______
),

/* NUM
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   Y  |   L  |   U  |   K  |   Å  |  Ä   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  Ö   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   J  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[NUM] = LAYOUT_all(
  _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, SE_7,    SE_8,    SE_9,    SE_ADIA, _______,
  _______, SE_PLUS, SE_MINS, SE_ASTR, SE_SLSH, SE_CIRC, _______, SE_4,    SE_5,    SE_6,    _______, _______,
  _______, _______, _______, KC_VOLD, KC_VOLU, _______, KC_SPC,  SE_1,    SE_2,    SE_3,    _______, _______,
  _______, _______, _______, _______, _______, _______, SE_COMM, SE_0,    SE_DOT,  _______, _______, _______ 
),

/* FN
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   Y  |   L  |   U  |   K  |   Å  |  Ä   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  Ö   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   J  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[FN] = LAYOUT_all(
  _______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
  _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
  _______, _______, _______, KC_PSCR, KC_CAPS, _______, _______, _______, _______, _______, _______, _______ 
)
};

