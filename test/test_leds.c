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

/** @file test_leds.c
 ** @brief Batería de Unit Tests para la API de manejo de LEDs.
 **/

/* === Headers files inclusions ================================================================ */

#include <unity.h>

#include "leds.h"

/* === Macros definitions ====================================================================== */
/* === Private data type declarations ========================================================== */
/* === Private variable declarations =========================================================== */
static uint16_t leds_port = 0xFF;
/* === Private function declarations =========================================================== */
/* === Public variable definitions ============================================================= */
/* === Private variable definitions ============================================================ */
/* === Private function implementation ========================================================= */

void setUp(void) {
    leds_init(&leds_port);
}

/// @brief Al iniciar el controlador todos los bits de los LEDs deben quedar en cero,
///        sin importar el estado anterior.
void test_initial_state(void) {
    uint16_t leds_port = 0xFF;
    leds_init(&leds_port);
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_port);
}

/// @brief Con todos los LEDs apagados prender el LED3, y verificar que el bit 3 está en alto
///        mientras el resto de bits está en bajo.
void test_single_led_on(void) {
    static const int LED = 3;

    leds_turn_on_single(LED);

    TEST_ASSERT_BIT_HIGH(LED - 1, leds_port);
    TEST_ASSERT_BITS_LOW(~(1 << (LED - 1)), leds_port);
}

/// @brief Apagar el LED3 (prendido previamente), y verificar que el bit 3 está en bajo
///        mientras el resto de bits no cambia.
void test_single_led_off(void) {
    static const int LED = 3;

    leds_turn_on_single(LED);
    leds_turn_off_single(LED);
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_port);
}

/* === Public function implementation ========================================================== */
/* === End of documentation ==================================================================== */
