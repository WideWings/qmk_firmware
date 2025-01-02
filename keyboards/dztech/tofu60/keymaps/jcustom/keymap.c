/* Copyright 2022 DZTECH <moyi4681@Live.cn>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#define SCREENSAVE_DELAY 120000

enum{
	M_JQUERY = SAFE_RANGE,
    NO_SLEEP,
	M_DIV,
	M_DIVEND,
	M_VDUMP,
	M_JSLOG,
	M_EMAIL_W,
	M_PW_W,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NUHS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(3),
        _______, KC_LCTL, KC_LALT,                                     KC_SPC,                    KC_RALT, MO(2),  MO(1), _______
    ),
    [1] = LAYOUT_all(
        QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, NO_SLEEP, KC_GRV, KC_DEL,
        KC_TAB,  KC_Q,    KC_UP,   KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, RGUI(KC_UP),
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          RGUI(KC_DOWN),
        KC_LSFT, LALT(KC_F4), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  RGUI(KC_LEFT), RGUI(KC_RGHT), RGUI(KC_E),
        _______, KC_LGUI, KC_LALT,                                     KC_UNDS,                    KC_RALT, KC_APP,  _______, _______
    ),
    [2] = LAYOUT_all(
        QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_F14,   KC_F15, KC_F16, KC_NUHS,
        KC_CAPS, M_JQUERY, M_DIV, M_DIVEND, KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_HOME, KC_Z,    KC_X,    M_JSLOG, M_VDUMP, KC_B,    KC_N,    KC_M,    LCTL(KC_Z), LCTL(KC_Y),  KC_MUTE, KC_VOLU, KC_END,
        _______, KC_LGUI, KC_LALT,                                     KC_UNDS,                    KC_RALT, _______,  KC_VOLD, _______
    ),
    [3] = LAYOUT_all(
        QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,  KC_TILDE, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_UP, KC_INS, KC_RGHT,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_LEFT, KC_DOWN,          KC_ENT,
        KC_LSFT, QK_BOOTLOADER, M_EMAIL_W, M_PW_W,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, _______,
        _______, KC_LGUI, KC_LALT,                                     KC_SPC,                    KC_RALT, C(S(KC_T)), C(KC_W), _______
    ),
};

bool stop_screensaver = false;     //screensaver mode status
uint32_t last_activity_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record){
	if (record->event.pressed) {
		switch(keycode){
			case M_JQUERY:
				SEND_STRING("$('')");
				return false; break;
			case M_DIV:
				SEND_STRING("<div>");
				return false; break;
			case M_DIVEND:
				SEND_STRING("</div>");
				return false; break;
			case M_VDUMP:
				SEND_STRING("var_dump();");
				return false; break;
			case M_JSLOG:
				SEND_STRING("console.log();");
				return false; break;
			case M_EMAIL_W:
				SEND_STRING("");	//DO NOT COMMIT THESE LINES !!!
				return false; break;
			case M_PW_W:
				SEND_STRING("");	//DO NOT COMMIT THESE LINES !!!
				return false; break;
            case NO_SLEEP:             //if NO_SLEEP is pressed
                if(stop_screensaver){
                    stop_screensaver = false;               //turn off screensaver mode
                }else{
                    stop_screensaver = true;               //turn on screensaver mode
                }
                last_activity_timer = timer_read32();  //reset timer
                return false; break;
		}
	}
	return true;
};

void matrix_scan_user(void) {
    if (stop_screensaver) {                                             //if screensaver mode is active
        if (timer_elapsed32(last_activity_timer) > SCREENSAVE_DELAY) {  //and no key has been pressed in more than SCREENSAVE_DELAY ms
            tap_code16(KC_F13);                                         //  tap F13
            last_activity_timer = timer_read32();                       //  reset last_activity_timer
        }
    }
}
