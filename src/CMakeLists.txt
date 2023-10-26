# Copyright (c) 2023 Filip Jagodzinski
# SPDX-License-Identifier: MIT

add_executable(pico-mute-button main.c)

target_link_libraries(pico-mute-button pico_stdlib)

pico_add_extra_outputs(pico-mute-button)
