#include "alps64.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _FN 1

enum macro_id {
  M_PASS = 0,
  M_PASS2,
  M_SRV,
  M_BREAK,
  M_VI,
  M_TERM,
  M_ITM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _QW: (QWerty) Default Layer
   * ,------------------------------------------------------------
   * |Esc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = | # |Bsp|
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shft| | |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Esc|
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |APP |ALT |GUI |CTRL |
   * `-----------------------------------------------------------'
   */
[_QW] = KEYMAP(
  KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_NUHS, KC_BSPC, \
  KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS, \
  KC_CAPS,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_ENT,  \
  KC_LSFT,KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,FUNC(3),MO(_FN), \
  KC_LCTL,KC_LGUI,KC_LALT,          FUNC(1),                     KC_APP, KC_RALT,KC_RGUI,KC_RCTL),

  /* Keymap _FN: (FuNction) Function Layer
   * ,------------------------------------------------------------
   * |Esc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = | # |Bsp|
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shft| | |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Esc|
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |APP |ALT |GUI |CTRL |
   * `-----------------------------------------------------------'
   */
[_FN] = KEYMAP(
  KC_GRV, KC_F1,        KC_F2,  KC_F3,  KC_F4,   KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_NUHS, KC_DEL, \
  KC_TAB, M(M_PASS),    KC_EXLM,KC_AT,  KC_HASH, M(M_VI),KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_P,   KC_LBRC,KC_RBRC,KC_BSLS, \
  KC_CAPS,LSFT(KC_QUOT),KC_S,   KC_D,    KC_F,   KC_G,   KC_H,   KC_MINS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE,KC_ENT,  \
  KC_LSFT,LSFT(KC_NUBS),KC_Z,   KC_X,   KC_C,    KC_V,   KC_B,   KC_N,   KC_M,   KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,MO(_FN), \
  KC_LCTL,KC_LGUI,KC_LALT,          KC_TRNS,                     KC_APP, KC_RALT,KC_RGUI,KC_RCTL),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_KEY(_FN, KC_SPC),       // Tap for space, hold for SpaceFN
    [2] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_CAPS),  //Shift on press, Caps on tap
    [3] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_CAPS),  //Shift on press, Caps on tap
};


void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case M_PASS:
          if (record->event.pressed) {
            return MACRO( I(1), D(LSFT), T(Z), T(X), T(C), T(V), U(LSFT), T(9), T(9), T(Z), T(X), END);
          }  else {
            return MACRO_NONE ;
          }
        break;
        case M_PASS2:
          if (record->event.pressed) {
            return MACRO( I(1), D(LSFT), T(C), T(V), T(B), T(N), U(LSFT), T(1), T(1), T(Q), T(W), END);
          }  else {
            return MACRO_NONE ;
          }
        break;
        case M_SRV:
          if (record->event.pressed) {
            return MACRO( I(1), T(DOT), T(S), T(R), T(V), T(DOT), T(B), T(E), T(DOT), T(E), T(U), T(R), T(O), T(P), T(E), T(DOT), T(I), T(N), T(T), T(R), T(A), T(N), T(E), T(T), END);
          }  else {
            return MACRO_NONE ;
          }
        break;
        case M_BREAK:
          if (record->event.pressed) {
            return MACRO( I(1), T(TILD), T(DOT), END);
          }  else {
            return MACRO_NONE ;
          }
        break;
        case M_VI:
          if (record->event.pressed) {
            return MACRO( I(1), T(S), T(E), T(T), T(SPC), T(MINS), T(O), T(SPC), T(V), T(I), T(ENT), END);
          }  else {
            return MACRO_NONE ;
          }
        break;
        case M_TERM:
          if (record->event.pressed) {
            return MACRO( I(1), T(E), T(X), T(P), T(O), T(R), T(T), T(SPC), D(LSFT), T(T), T(E), T(R), T(M), U(LSFT), T(EQL), T(X), T(T), T(E), T(R), T(M), T(SPC), T(SCLN), END);
          }  else {
            return MACRO_NONE ;
          }
        break;
        case M_ITM:
          if (record->event.pressed) {
            return MACRO( I(1), T(TILD), T(I), T(T), T(M), T(S), T(Y), D(S), T(0), T(2), T(SLSH), T(B), T(I), T(N), T(SLSH), END);
          }  else {
            return MACRO_NONE ;
          }
        break;
      }
    return MACRO_NONE;
};