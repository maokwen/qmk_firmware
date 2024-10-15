/* Copyright 2015-2023 Jack Humbert
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

enum planck_layers { _QWERTY, _LOWER, _RAISE, _FUNC, _ADJUST };

#define LOWER OSL(_LOWER)
#define RAISE MO(_RAISE)
#define FUNC MO(_FUNC)

#define KUC_CLQ UC(0x300C)
#define KUC_CRQ UC(0x300D)

enum virtual_desktop_keycodes {
    VD_NXT = SAFE_RANGE,
    VD_FWD,
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   \  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Func |  Alt | Lower|    Space    | Raise| Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
    KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_DQUO,
    KC_LSFT, KC_BSLS, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_ENT ,
    KC_LCTL, KC_LGUI, FUNC   , KC_LALT, LOWER  , KC_SPC          , RAISE  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

/* Lower: left hand - numbers, operators, punctuators
 * ,-----------------------------------------------------------------------------------.
 * |   +  |   7  |   8  |   9  |   ?  |   !  |   &  |   |  |   ^  |   %  |   $  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   -  |   4  |   5  |   6  |   {  |   (  |   )  |   }  |   `  |   ~  |   :  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   *  |   1  |   2  |   3  |   <  |   [  |   ]  |   >  |   @  | U([) | U(]) |   _  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   /  |   0  |   .  |   =  |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 * U([): `「`
 * U(]): `」`
 */

[_LOWER] = LAYOUT_planck_mit(
    KC_PLUS, KC_7,    KC_8   , KC_9   , KC_QUES, KC_EXLM, KC_AMPR, KC_PIPE, KC_CIRC, KC_PERC, KC_DLR , KC_HASH,
    KC_MINS, KC_4,    KC_5   , KC_6   , KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_GRV , KC_TILD, KC_COLN, KC_QUOT,
    KC_ASTR, KC_1,    KC_2   , KC_3   , KC_LT  , KC_LBRC, KC_RBRC, KC_GT  , KC_AT  , KUC_CLQ, KUC_CRQ, KC_UNDS,
    KC_SLSH, KC_0,    KC_DOT , KC_EQL , _______, KC_NO           , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO
),

/* Raise: right hand - movement, edit operators
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |CV(UP)|      |      |      | PgUp |  Up  | PgDn |      |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------|------+
 * |KC_CAP|      |CV(LT)|CV(DN)|CV(RT)|      |      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------|------+
 * |AShift|      |      |      |      |      | RAlt | Home |      |  End |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------|------+
 * |      |      |      |      |      |             |      |VD_FWD|      |      |VD_NXT|
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP  , KC_PGDN, _______, KC_DEL ,
    KC_CAPS, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    AS_TOGG, _______, _______, _______, _______, _______, KC_RALT, KC_HOME, _______, KC_END , _______, _______,
    _______, _______, _______, _______, _______, _______         , _______, VD_FWD , _______, _______, VD_NXT
),

/* Func: left hand - functions
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------|------+------+------+------+------+------+------+
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |      |      |      |      |      |
 * |------+------+------+------+------|------+------+------+------+------+------+------+
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------|------+
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_FUNC] = LAYOUT_planck_mit(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______, KC_F13 , KC_F14 , KC_F15 , KC_F16 , _______,
    _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______, _______, KC_F17 , KC_F18 , KC_F19 , KC_F20 , _______,
    _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, KC_F21 , KC_F22 , KC_F23 , KC_F24 , _______,
    _______, _______, _______, _______, _______, _______         , _______, _______ , _______, _______, _______
),

/* Adjust (Func + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | EEClr|MUSmod|Aud on|Audoff|      |      |      |UCwinc|UCmode|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |MIDItg|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, EE_CLR , MU_NEXT, AU_ON  , AU_OFF,  _______, _______, _______, UC_WINC, UC_NEXT, _______, _______,
    _______, AU_PREV, AU_NEXT, MU_ON  , MU_OFF,  MI_ON  , MI_OFF , _______, MI_TOGG, _______, _______, _______,
    _______, _______, _______, _______, _______, _______         , _______, _______, _______, _______, _______
)

/* layer_name: description
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------|------+
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------|------+
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------|------+
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
// [layer_name] = LAYOUT_planck_mit(
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______         , _______, _______, _______, _______, _______
// ),

};
/* clang-format on */

// Layer

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, _LOWER) &&
        (layer_state_cmp(state, _RAISE) || layer_state_cmp(state, _FUNC))) {
        reset_oneshot_layer();
    }

    return update_tri_layer_state(state, _FUNC, _RAISE, _ADJUST);
}

#ifdef AUDIO_ENABLE
float shot_timeout_song[][2] = SONG(Q__NOTE(_E4));
float layer1_shot_song[][2] = SONG(Q__NOTE(_E2));

void oneshot_layer_changed_user(uint8_t layer) {
    switch (layer)
    {
    case 0:
        PLAY_SONG(shot_timeout_song);
        break;
    case 1:
        PLAY_SONG(layer1_shot_song);
        break;
    default:
        break;
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case VD_NXT:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_LGUI);
            tap_code(KC_RGHT);
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case VD_FWD:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_LGUI);
            tap_code(KC_LEFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
        } else {
            // when keycode QMKBEST is released
        }
        break;
   }

    return true;
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case QWERTY:
//             if (record->event.pressed) {
//                 print("mode just switched to qwerty and this is a huge string\n");
//                 set_single_persistent_default_layer(_QWERTY);
//             }
//             return false;
//             break;
//         case COLEMAK:
//             if (record->event.pressed) {
//                 set_single_persistent_default_layer(_COLEMAK);
//             }
//             return false;
//             break;
//         case DVORAK:
//             if (record->event.pressed) {
//                 set_single_persistent_default_layer(_DVORAK);
//             }
//             return false;
//             break;
//         case BACKLIT:
//             if (record->event.pressed) {
//                 register_code(KC_RSFT);
//             } else {
//                 unregister_code(KC_RSFT);
//             }
//             return false;
//             break;
//         case PLOVER:
//             if (record->event.pressed) {
// #ifdef AUDIO_ENABLE
//                 stop_all_notes();
//                 PLAY_SONG(plover_song);
// #endif
//                 layer_off(_RAISE);
//                 layer_off(_LOWER);
//                 layer_off(_ADJUST);
//                 layer_on(_PLOVER);
//                 if (!eeconfig_is_enabled()) {
//                     eeconfig_init();
//                 }
//                 keymap_config.raw  = eeconfig_read_keymap();
//                 keymap_config.nkro = 1;
//                 eeconfig_update_keymap(keymap_config.raw);
//             }
//             return false;
//             break;
//         case EXT_PLV:
//             if (record->event.pressed) {
// #ifdef AUDIO_ENABLE
//                 PLAY_SONG(plover_gb_song);
// #endif
//                 layer_off(_PLOVER);
//             }
//             return false;
//             break;
//     }
//     return true;
// }
