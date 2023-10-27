# Copyright (c) 2023 Filip Jagodzinski
# SPDX-License-Identifier: MIT

add_executable(pico-mute-button main.c usb_descriptors.c)

target_link_libraries(pico-mute-button pico_stdlib pico_unique_id tinyusb_device tinyusb_bsp)

target_include_directories(tinyusb_device INTERFACE ${CMAKE_CURRENT_LIST_DIR})

pico_add_extra_outputs(pico-mute-button)
