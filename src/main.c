/*
 * Copyright (c) 2023 Filip Jagodzinski
 * SPDX-License-Identifier: MIT
 */

#include "tusb.h"
#include "pico/stdlib.h"

#define LED_GPIO_MASK (1U << PICO_DEFAULT_LED_PIN)

void mute_button_task(void) {
    if (tud_hid_ready() == false) {
        return;
    }

    static bool button_pressed_before = false;
    // Pushed button pulls the pin low.
    bool button_pressed_now = (get_bootsel_button() == false);

    if (!button_pressed_before && button_pressed_now) {
        uint8_t keycode[6] = { 0 };
        keycode[0] = HID_KEY_MUTE;
        tud_hid_keyboard_report(1, 0, keycode);
        gpio_set_mask(LED_GPIO_MASK);
        sleep_ms(20);
        gpio_clr_mask(LED_GPIO_MASK);
    } else if (button_pressed_before && !button_pressed_now) {
        tud_hid_keyboard_report(1, 0, NULL);
    }
    button_pressed_before = button_pressed_now;
}

int main() {
    gpio_init_mask(LED_GPIO_MASK);
    gpio_set_dir_out_masked(LED_GPIO_MASK);
    tusb_init();
    while (true) {
        tud_task();
        mute_button_task();
    }
}
