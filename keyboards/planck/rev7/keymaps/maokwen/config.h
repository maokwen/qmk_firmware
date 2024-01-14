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

#pragma once

#ifdef AUDIO_ENABLE
#define TEMPO_DEFAULT 120
#define ZELDA_PUZZLE \
   Q__NOTE(_G5),     \
   Q__NOTE(_FS5),    \
   Q__NOTE(_F5),     \
   Q__NOTE(_CS5),    \
   Q__NOTE(_C5),     \
   Q__NOTE(_E5),     \
   Q__NOTE(_G5),     \
   HD_NOTE(_B5),
#define STARTUP_SONG SONG(ZELDA_PUZZLE)
#define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
// #define MIDI_ADVANCED

/*
 * One Shot Keys options
 */
#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 3000  /* Time (in ms) before the one shot key is released */

/*
 * Unicode options
 */
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE, UNICODE_MODE_LINUX, UNICODE_MODE_MACOS
#define UNICODE_KEY_WINC KC_RIGHT_ALT

/*
 * MIDI options
 */
#define MIDI_BASIC
