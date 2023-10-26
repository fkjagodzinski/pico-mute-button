/*
 * Copyright (c) 2023 Filip Jagodzinski
 * SPDX-License-Identifier: MIT
 */

#include "pico/stdlib.h"

#define LED_GPIO_MASK (1U << PICO_DEFAULT_LED_PIN)

void status_led_task(void) {
    gpio_xor_mask(LED_GPIO_MASK);
}

int main() {
    gpio_init_mask(LED_GPIO_MASK);
    gpio_set_dir_out_masked(LED_GPIO_MASK);
    while (true) {
        sleep_ms(1000);
        status_led_task();
    }
}
