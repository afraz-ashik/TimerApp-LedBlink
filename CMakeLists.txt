cmake_minimum_required(VERSION 3.10)

# Project name
project(TimerAppandLed C)
include(ExternalProject)

# for Release and debug
Externalproject_add(build_gcc
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/build_x86_config
    CMAKE_ARGS -DCMAKE_C_COMPILER=gcc
    BUILD_COMMAND $(CMAKE_COMMAND) --build .
     INSTALL_COMMAND ""
)

# for Cross compilation
Externalproject_add(build_rpi
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/build_arm_config
    CMAKE_ARGS -DCMAKE_C_COMPILER=aarch64-linux-gnu-gcc
    BUILD_COMMAND $(CMAKE_COMMAND) --build .
     INSTALL_COMMAND ""
)