/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

#define PIN_ROW_0 0
#define PIN_ROW_1 1
#define PIN_ROW_2 2
#define PIN_COL_0 3
#define PIN_COL_1 4
#define PIN_COL_2 5
#define PIN_COL_3 6

volatile uint16_t key_state = 0x0000;

void print_keystate()
{
    // No idea why but bits are 4 bits higher than they should be
    key_state = 0x0000;
    for (uint8_t row = 0; row < 4; row++)
    {
        // Drive current row low
        // Since the rows are on pins 0-2, recycle the row counter
        gpio_put(row, 0);

        // Read in the columns
        // Columns are on pins 3-6, so shift the result by 4
        uint16_t cols = (uint16_t)(gpio_get_all() & 0x00000078) >> 3;
        if (row >= 1)
            key_state |= (cols << ((row-1) * 4));

        // Drive current row high
        gpio_put(row, 1);
    }

    // Print the key state variable in binary
    // Print by column then row
    printf("Key state: %4.x\n", key_state);
    // Print matrix
    for (uint8_t row = 0; row < 3; row++)
    {
        for (uint8_t col = 0; col < 4; col++)
        {
            uint8_t key = (key_state >> (row * 4 + col)) & 0x01;
            printf("%d", key);
        }
        printf("\n");
    }
    printf("------\n");
}

int main()
{
    stdio_init_all();

    gpio_init(PIN_ROW_0);
    gpio_set_dir(PIN_ROW_0, GPIO_OUT);
    gpio_init(PIN_ROW_1);
    gpio_set_dir(PIN_ROW_1, GPIO_OUT);
    gpio_init(PIN_ROW_2);
    gpio_set_dir(PIN_ROW_2, GPIO_OUT);

    gpio_init(PIN_COL_0);
    gpio_set_dir(PIN_COL_0, GPIO_IN);
    gpio_pull_up(PIN_COL_0);
    gpio_init(PIN_COL_1);
    gpio_set_dir(PIN_COL_1, GPIO_IN);
    gpio_pull_up(PIN_COL_1);
    gpio_init(PIN_COL_2);
    gpio_set_dir(PIN_COL_2, GPIO_IN);
    gpio_pull_up(PIN_COL_2);
    gpio_init(PIN_COL_3);
    gpio_set_dir(PIN_COL_3, GPIO_IN);
    gpio_pull_up(PIN_COL_3);

    // Make sure all rows are high initially
    gpio_put(PIN_ROW_0, 1);
    gpio_put(PIN_ROW_1, 1);
    gpio_put(PIN_ROW_2, 1);

    while (true)
    {
        print_keystate();
        sleep_ms(500);
    }
    return 0;
}
