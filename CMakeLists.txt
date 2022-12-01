# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(eps4400-pico C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(eps4400-pico

        # Library executables

        # Main executable
        src/main.cpp

        src/Hardware/Analog/Analog.cpp
        src/Hardware/DAC/MCP4922.cpp
        src/Hardware/Relay/Relay.cpp

        )

# Add libs
target_include_directories(eps4400-pico PUBLIC include/)

pico_set_program_name(eps4400-pico "eps4400-pico")
pico_set_program_version(eps4400-pico "0.1")

# Switch STDIO to USB
pico_enable_stdio_uart(eps4400-pico 0)
pico_enable_stdio_usb(eps4400-pico 1)

# Add any user requested libraries
target_link_libraries(eps4400-pico
        pico_stdlib
        hardware_spi
        hardware_adc
        hardware_pwm
        hardware_flash
        hardware_sync

        )

pico_add_extra_outputs(eps4400-pico)


