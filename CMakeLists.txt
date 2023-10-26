# Copyright (c) 2023 Filip Jagodzinski
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.13)

# Pre-initialize Raspberry Pi Pico SDK.
include(pico-sdk/pico_sdk_init.cmake)

project(pico-mute-button)

# Initialize the SDK.
pico_sdk_init()

add_subdirectory(src)
