/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 * Copyright (C) Peter Ivanov, 2022
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"

int cntr = 0;
const uint8_t led_pin = 25;


int main() 
{
    stdio_init_all();

    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);

    while (true) 
    {
        printf("Hello, world! cntr: %i\n", cntr);
        cntr++;
        gpio_put(led_pin, true);
        sleep_ms(500);
        gpio_put(led_pin, false);
        sleep_ms(500);
    }
    return 0;
}
