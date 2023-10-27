# pico-mute-button

The simplest possible USB device project for Raspberry Pi Pico.

Use the `BOOTSEL` button to toggle mute on any machine connected to Pico.

## Build instructions

This project is based on the Raspberry Pi Pico SDK. No build configuration has to be provided (e.g. toolchain files, CMake cache variables); the default SDK settings are sufficient for an off the shelf Raspberry Pi Pico.

### Fetching sources

1. Clone this respository.

    ```shell
    git clone https://github.com/fkjagodzinski/pico-mute-button.git
    ```

1. Change the working directory.

    ```shell
    cd pico-mute-button
    ```

1. Update submodules.

    ```shell
    git submodule update --recursive --init
    ```

### Building

1. Generate project buildsystem using defaults from Raspberry Pi Pico SDK.

    ```shell
    cmake -B build
    ```

1. Build the project.

    ```shell
    cmake --build ./build --parallel
    ```

Build artifacts `pico-mute-button.elf` and `pico-mute-button.uf2` are located in `build/src/` directory. Flash the Raspberry Pi Pico via a debugger or drag-and-drop the `.uf2` file to `RPI-RP2` volume.
