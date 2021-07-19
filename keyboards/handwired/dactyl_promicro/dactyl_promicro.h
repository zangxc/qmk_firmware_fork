#pragma once

#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
    #include <avr/io.h>
    #include <avr/interrupt.h>
#endif
#endif


#define LAYOUT_6x6(\
    L10, L11, L12, L13, L14, L15,                       R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,                       R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35,                       R30, R31, R32, R33, R34, R35, \
    L40, L41, L42, L43, L44, L45,                       R40, R41, R42, R43, R44, R45, \
               L50, L51,                              R55, R52, R53,                  \
                         L52, L53,                    R54,                            \
                                L54,L55,      R50, R51                   \
    )\
    {\
        { L10, L11, L12, L13, L14, L15 },     \
        { L20, L21, L22, L23, L24, L25 },     \
        { L30, L31, L32, L33, L34, L35 },     \
        { L40, L41, L42, L43, L44, L45 },     \
        { L50, L51, L52, L53, L54, L55 },   \
\
        { R10, R11, R12, R13, R14, R15 },    \
        { R20, R21, R22, R23, R24, R25 },    \
        { R30, R31, R32, R33, R34, R35 },    \
        { R40, R41, R42, R43, R44, R45 },    \
        { R50, R51, R52, R53, R54, R55 }   \
}

enum custom_keycodes {
    KC_SCROLL = SAFE_RANGE,
    KC_CPI_1,
    KC_CPI_2,
    KC_CPI_3
};

typedef union {
  uint32_t raw;
  struct {
    uint16_t cpi;
  };
} config_oddball_t;
