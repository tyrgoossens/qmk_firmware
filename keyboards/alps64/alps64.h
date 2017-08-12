/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef ALPS64_H
#define ALPS64_H

#include "quantum.h"

/* Alps64 keymap definition macro */
#define KEYMAP( \
    K36, K37, K46, K47, K56, K57, K66, K67, K76, K77, K06, K07, K17, K26, K27, \
    K34, K35, K44, K45, K54, K55, K64, K65, K75, K05, K15, K16, K25, K24, \
    K32, K33, K43, K52, K53, K63, K73, K74, K03, K04, K13, K14, K23, \
    K31, K41, K42, K51, K61, K62, K71, K72, K01, K02, K11, K12, K21, K22, \
    K30, K40, K50,           K60,                     K70, K00, K10, K20  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07 }, \
    { K10, K11, K12, K13, K14, K15, K16, K17 }, \
    { K20, K21, K22, K23, K24, K25, K26, K27 }, \
    { K30, K31, K32, K33, K34, K35, K36, K37 }, \
    { K40, K41, K42, K43, K44, K45, K46, K47 }, \
    { K50, K51, K52, K53, K54, K55, K56, K57 }, \
    { K60, K61, K62, K63, K64, K65, K66, K67 }, \
    { K70, K71, K72, K73, K74, K75, K76, K77 } \
}

#endif
