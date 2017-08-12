#include "preonic.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _MACRO,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

enum macro_id {
  M_LED = 0,
  M_PASS,
  M_PASS2,
  M_SRV,
  M_BREAK,
  M_VI,
  M_TERM,
  M_ITM
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL},
  {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT},
  {FUNC(2), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, FUNC(3)},
  {MO(_MACRO), KC_LCTL, KC_LALT, KC_LGUI, RAISE,   FUNC(1),  KC_SPC,  LOWER,   KC_LEFT, KC_UP, KC_DOWN,  KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   @  |   '  |      |      |      |      |   -  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |      |   |  |      |      |      |      |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM,    KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,  KC_AMPR,   KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL},
  {KC_TILD, KC_EXLM,    KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,  KC_AMPR,   KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_TAB,  S(KC_QUOT), KC_QUOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_MINS,   KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {KC_CAPS, S(KC_NUBS), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,S(KC_NUHS),S(KC_NUBS),_______, _______, _______},
  {_______, _______,    _______, _______, _______, _______, _______,  _______,   KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   6  |   7  |   8  |   9  |   0  |      |   _  |   =  |   [  |   ]  |  #   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |   \  |      |      |      |      |      |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL},
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_UNDS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {KC_CAPS, KC_NUBS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUHS, KC_NUBS, XXXXXXX, XXXXXXX, XXXXXXX},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END}
},

/* Macro
 * ,-----------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  | Pass | Pass2|      |      |  VI  | TERM |      | Break|      |  SRV | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |Qwerty|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |lbrite|    Macro    |ubrite|      |      |      |C-A-D |
 * `-----------------------------------------------------------------------------------'
 */
[_MACRO] = {
  {KC_F11,  KC_F1,     KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_F7,       KC_F8,      KC_F9,   KC_F10,   KC_F12},
  {KC_GRV,  M(M_PASS), M(M_PASS2), KC_TRNS, KC_TRNS, M(M_VI), M(M_TERM), KC_TRNS,     M(M_BREAK), KC_TRNS, M(M_SRV), KC_DEL },
  {KC_TAB,  KC_F1,     KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_MINS,     KC_EQL,     KC_LBRC, KC_RBRC,  KC_BSLS},
  {_______, KC_F7,     KC_F8,      KC_F9,   KC_F10,  KC_F11,  KC_F12,    DF(_QWERTY), XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX},
  {_______, _______,   _______,    _______, FUNC(4), _______, _______,   M(M_LED),    _______,    _______, _______,  LALT(LCTL(KC_DEL))}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12},
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE

float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_qwerty[][2]     = SONG(CLOSE_ENCOUNTERS_5_NOTE); // SONG(QWERTY_SOUND);

float tone_goodbye[][2]    = SONG(GOODBYE_SOUND);

float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_caps_on[][2]    = SONG(CAPS_LOCK_ON_SOUND);
float tone_caps_off[][2]   = SONG(CAPS_LOCK_OFF_SOUND);
float tone_numlk_on[][2]   = SONG(NUM_LOCK_ON_SOUND);
float tone_numlk_off[][2]  = SONG(NUM_LOCK_OFF_SOUND);
float tone_scroll_on[][2]  = SONG(SCROLL_LOCK_ON_SOUND);
float tone_scroll_off[][2] = SONG(SCROLL_LOCK_OFF_SOUND);

#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
            #endif
            persistant_default_layer_set(1UL<<_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
          return false;
          break;
      }
    return true;
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_KEY(_MACRO, KC_SPC),      // Tap for space, hold for SpaceFN
    [2] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_CAPS),  //Shift on press, Caps on tap
    [3] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_CAPS),  //Shift on press, Caps on tap
    [4] = ACTION_BACKLIGHT_DECREASE(),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_increase();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
        case M_PASS:
          if (record->event.pressed) {
            return MACRO( I(1), D(LSFT), T(Z), T(X), T(C), T(V), U(LSFT), T(9), T(9), T(Z), T(X), END);
          }  else {
            return MACRO_NONE ;
          }
        break;
        case M_PASS2:
          if (record->event.pressed) {
            return MACRO( I(1), D(LSFT), T(L), T(W), T(W), U(LSFT), T(R), T(M), T(A), T(4), T(8), END);
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
            return MACRO( I(1), T(DOT), END);
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
            return MACRO( I(1), T(GRV), T(I), T(T), T(M), T(S), T(Y), D(S), T(0), T(2), T(SLSH), T(B), T(I), T(N), T(SLSH), END);
          }  else {
            return MACRO_NONE ;
          }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

void led_set_user(uint8_t usb_led)
{
    static uint8_t old_usb_led = 0;

    _delay_ms(10); // gets rid of tick

    if (!is_playing_notes())
    {
        if ((usb_led & (1<<USB_LED_CAPS_LOCK)) && !(old_usb_led & (1<<USB_LED_CAPS_LOCK)))
        {
                // If CAPS LK LED is turning on...
                PLAY_NOTE_ARRAY(tone_caps_on,  false, LEGATO);
        }
        else if ((usb_led & (1<<USB_LED_NUM_LOCK)) && !(old_usb_led & (1<<USB_LED_NUM_LOCK)))
        {
                // If NUM LK LED is turning on...
                PLAY_NOTE_ARRAY(tone_numlk_on,  false, LEGATO);
        }
        else if (!(usb_led & (1<<USB_LED_NUM_LOCK)) && (old_usb_led & (1<<USB_LED_NUM_LOCK)))
        {
                // If NUM LED is turning off...
                PLAY_NOTE_ARRAY(tone_numlk_off, false, LEGATO);
        }
        else if ((usb_led & (1<<USB_LED_SCROLL_LOCK)) && !(old_usb_led & (1<<USB_LED_SCROLL_LOCK)))
        {
                // If SCROLL LK LED is turning on...
                PLAY_NOTE_ARRAY(tone_scroll_on,  false, LEGATO);
        }
        else if (!(usb_led & (1<<USB_LED_SCROLL_LOCK)) && (old_usb_led & (1<<USB_LED_SCROLL_LOCK)))
        {
                // If SCROLL LED is turning off...
                PLAY_NOTE_ARRAY(tone_scroll_off, false, LEGATO);
        }
    }

    old_usb_led = usb_led;
}

#endif
