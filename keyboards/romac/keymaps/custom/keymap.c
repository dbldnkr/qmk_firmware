#include QMK_KEYBOARD_H

// create some custom keycodes for your keymap
enum custom_keycodes {
  PREV_DESKTOP = SAFE_RANGE,
  NEXT_DESKTOP,
  EZGAME
};

// define some useful send strings
// #define SS_PREV_DESKTOP SS_LCTRL(SS_LGUI(SS_TAP(X_LEFT)))
// #define SS_NEXT_DESKTOP SS_LCTRL(SS_LGUI(SS_TAP(X_RIGHT)))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
	case EZGAME:
		if (record->event.pressed) {
			// ez
			SEND_STRING("ez game, ez life")
		} else {
			// Release key
		}
		break;
	case PREV_DESKTOP:
		if (record->event.pressed) {
		// Back to previous desktop
		SEND_STRING(SS_LCTRL(SS_LGUI(SS_TAP(X_LEFT))));
		} else {
		// Release key
		}
		break;
	case NEXT_DESKTOP:
		if (record->event.pressed) {
		// To next desktop
		SEND_STRING(SS_LCTRL(SS_LGUI(SS_TAP(X_RIGHT))));
		} else {
		// Release key
		}
    	break;
  }
  return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_7, KC_8, KC_9, KC_4, KC_5, KC_6, KC_1, KC_2, KC_3, LT(3,KC_PDOT), KC_P0, KC_ENT),
	[1] = LAYOUT(KC_TRNS, KC_HOME, KC_PGUP, KC_TRNS, KC_END, KC_PGDN, LCTL(KC_Z), LCTL(KC_C), LCTL(KC_V), MO(3), KC_TRNS, KC_DOT),
	[2] = LAYOUT(KC_NO, KC_NO, KC_NO, PREV_DESKTOP, EZGAME, NEXT_DESKTOP, KC_NO, KC_NO, KC_NO, MO(3), KC_TRNS, KC_NO),
	[3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(1), TO(2), KC_NO, KC_TRNS, TO(0), KC_NO)
};
