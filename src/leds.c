/************************************************************************************************
Copyright (c) 2024, Leandro Soria <leandromsoria@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file leds.c
 ** @brief Capa de abstracción para controlar LEDs (implementación)
 **/

/* === Headers files inclusions =============================================================== */

#include "leds.h"

/* === Macros definitions ====================================================================== */

#define LED_TO_BIT(led) (1 << led - 1)

/* === Private data type declarations ========================================================== */

static uint16_t * led_port;

/* === Private variable declarations =========================================================== */
/* === Private function declarations =========================================================== */
/* === Public variable definitions ============================================================= */
/* === Private variable definitions ============================================================ */
/* === Private function implementation ========================================================= */
/* === Public function implementation ========================================================== */

void leds_init(uint16_t * port) {
    led_port = port;
    *led_port = 0x00;
}

void leds_turn_on_single(uint16_t led) {
    *led_port |= LED_TO_BIT(led);
}

void leds_turn_off_single(uint16_t led) {
    *led_port &= ~LED_TO_BIT(led);
}

bool leds_get_status_single(uint16_t led) {
    return (*led_port & LED_TO_BIT(led)) != 0;
}

/* === End of documentation ==================================================================== */
