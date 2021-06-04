/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "keymap_french.h"
#include "french_keymap_osx.h"

enum preonic_layers {
  _WIN_LINUX,
  MO_1,
  MO_2,
  FN,
  _MAC_KEYBOARD,
};

enum preonic_keycodes {
  WIN_LINUX = SAFE_RANGE,
  MAC_KEYBOARD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* _WIN_LINUX
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  '   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |MO(Fn)|  Os  | Alt  | MO(1)|    Space    |MO(2) | Left |  Up  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_WIN_LINUX] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_BSPC,
  KC_ESC,  KC_A,  KC_Z,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_QUOT,
  KC_TAB,  KC_Q,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_M,  KC_ENT,
  KC_LSFT, KC_W,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N, KC_COMM, KC_DOT, KC_SLSH, KC_SCLN, KC_RSFT,
  KC_LCTL, MO(FN), KC_LGUI, KC_LALT, MO(MO_1), KC_SPC, MO(MO_2), KC_LEFT, KC_UP, KC_DOWN, KC_RGHT
),

/* MO(1)
 * ,-----------------------------------------------------------------------------------.
 * |      |   à  |   è  |   é  |      |      |  ^   |      |      |   [  |   ]  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   ù  |      |   -  |   +  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |  ç   |      |      |      |      |      |   \  |      |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |      | MO() |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[MO_1] = LAYOUT_preonic_grid(
  KC_NO,  FR_AGRV,  FR_EGRV,  FR_EACU,  KC_NO,  KC_NO,  FR_CIRC,  KC_NO,  KC_NO,  KC_LBRC,  KC_RBRC,  KC_DEL,
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  FR_UGRV,  KC_NO,  KC_MINS,  KC_EQL,  KC_NO,
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_ENT,
  KC_LSFT, KC_NO, KC_NO,  FR_CCED,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_BSLS,  KC_NO,  KC_RSFT,
  KC_LCTL, KC_NO, KC_NO,  KC_NO,  KC_TRNS,  KC_SPC,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
),

/* MO(2)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  End | Pdown|      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Home | Pup  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |    Space    | MO(2)|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[MO_2] = LAYOUT_preonic_grid(
   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
   KC_NO,  KC_NO,  KC_NO,  KC_END, KC_PGDN, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
   KC_NO,  KC_NO,  KC_HOME, KC_PGUP, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
   KC_LSFT, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_RSFT,
   KC_LCTL, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_SPC, KC_TRNS, KC_NO, KC_NO, KC_NO,  KC_NO
),

/* MO(FN)
 * ,-----------------------------------------------------------------------------------.
 * |   F1 |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |RGBtg |RGBm+ | HUE+ | SAT+ | Bri+ | EFF+ |      |      | Prev | Play | Next |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |RGBm- | HUE- | SAT- | Bri- | EFF- |      |      |      | Vol+ | Mute |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Ligh- |Ligh+ | Vol- | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MO() |      |      |      |             |      |      |      | WiLi | Mac  |
 * `-----------------------------------------------------------------------------------'
 */
[FN] = LAYOUT_preonic_grid(
   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12,
   RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,
   KC_NO, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_VOLU, KC_MUTE, KC_NO,
   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_BRID,  KC_BRIU,  KC_VOLD,  KC_NO,  KC_NO,
   KC_NO,  KC_TRNS, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  WIN_LINUX,  MAC_KEYBOARD
),

/* _MAC_KEYBOARD
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  '   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |MO(Fn)|  Os  | Alt  | MO(1)|    Space    |Raise | MO(2) |  Up  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_MAC_KEYBOARD] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_BSPC,
  KC_ESC,  KC_A,  KC_Z,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_QUOT,
  KC_TAB,  KC_Q,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_M,  KC_ENT,
  KC_LSFT, KC_W,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N, KC_COMM, KC_DOT, KC_SLSH, KC_SCLN, KC_RSFT,
  KC_LCTL, MO(FN), KC_LGUI, KC_LALT, MO(MO_1), KC_SPC, MO(MO_2), KC_LEFT, KC_UP, KC_DOWN, KC_RGHT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
// [_ADJUST] = LAYOUT_preonic_grid(
//   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
//   _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
//   _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______,
//   _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// )


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case WIN_LINUX:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_WIN_LINUX);
          }
          return false;
          break;
        case MAC_KEYBOARD:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_MAC_KEYBOARD);
          }
          return false;
          break;
        // case LOWER:
        //   if (record->event.pressed) {
        //     layer_on(FN);
        //     update_tri_layer(FN, _MAC_KEYBOARD, _ADJUST);
        //   } else {
        //     layer_off(FN);
        //     update_tri_layer(FN, _MAC_KEYBOARD, _ADJUST);
        //   }
        //   return false;
        //   break;
        // case RAISE:
        //   if (record->event.pressed) {
        //     layer_on(_MAC_KEYBOARD);
        //     update_tri_layer(FN, _MAC_KEYBOARD, _ADJUST);
        //   } else {
        //     layer_off(_MAC_KEYBOARD);
        //     update_tri_layer(FN, _MAC_KEYBOARD, _ADJUST);
        //   }
        //   return false;
        //   break;
        // case BACKLIT:
        //   if (record->event.pressed) {
        //     register_code(KC_RSFT);
        //     #ifdef BACKLIGHT_ENABLE
        //       backlight_step();
        //     #endif
        //     #ifdef __AVR__
        //     writePinLow(E6);
        //     #endif
        //   } else {
        //     unregister_code(KC_RSFT);
        //     #ifdef __AVR__
        //     writePinHigh(E6);
        //     #endif
        //   }
        //   return false;
        //   break;
      }
    return true;
};

// bool muse_mode = false;
// uint8_t last_muse_note = 0;
// uint16_t muse_counter = 0;
// uint8_t muse_offset = 70;
// uint16_t muse_tempo = 50;
//
// void encoder_update_user(uint8_t index, bool clockwise) {
//   if (muse_mode) {
//     if (IS_LAYER_ON(_MAC_KEYBOARD)) {
//       if (clockwise) {
//         muse_offset++;
//       } else {
//         muse_offset--;
//       }
//     } else {
//       if (clockwise) {
//         muse_tempo+=1;
//       } else {
//         muse_tempo-=1;
//       }
//     }
//   } else {
//     if (clockwise) {
//       register_code(KC_PGDN);
//       unregister_code(KC_PGDN);
//     } else {
//       register_code(KC_PGUP);
//       unregister_code(KC_PGUP);
//     }
//   }
// }
//
// void dip_switch_update_user(uint8_t index, bool active) {
//     switch (index) {
//         case 0:
//             if (active) {
//                 layer_on(_ADJUST);
//             } else {
//                 layer_off(_ADJUST);
//             }
//             break;
//         case 1:
//             if (active) {
//                 muse_mode = true;
//             } else {
//                 muse_mode = false;
//             }
//     }
// }
//
//
// void matrix_scan_user(void) {
// #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//         if (muse_counter == 0) {
//             uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//             if (muse_note != last_muse_note) {
//                 stop_note(compute_freq_for_midi_note(last_muse_note));
//                 play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                 last_muse_note = muse_note;
//             }
//         }
//         muse_counter = (muse_counter + 1) % muse_tempo;
//     } else {
//         if (muse_counter) {
//             stop_all_notes();
//             muse_counter = 0;
//         }
//     }
// #endif
// }
//
// bool music_mask_user(uint16_t keycode) {
//   switch (keycode) {
//     case RAISE:
//     case LOWER:
//       return false;
//     default:
//       return true;
//   }
// }
