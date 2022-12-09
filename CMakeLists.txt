cmake_minimum_required(VERSION 3.12)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

pico_sdk_init()

#project(hello_usb C CXX ASM)
project(flash_program C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (TARGET tinyusb_device)
    add_executable(${PROJECT_NAME}
            ${PROJECT_NAME}.c
            )

    # create map/bin/hex file etc.
    pico_add_extra_outputs(${PROJECT_NAME})

    target_link_libraries(${PROJECT_NAME}
            pico_stdlib
            hardware_flash
            )

    # add url via pico_set_program_url
    ##example_auto_set_url(flash_program)

    pico_enable_stdio_usb(${PROJECT_NAME} 0)
    pico_enable_stdio_uart(${PROJECT_NAME} 1)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building because TinyUSB submodule is not initialized in the SDK")
endif()