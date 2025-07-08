cmake_minimum_required(VERSION 3.10)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# Project name
project(TimerAppandLED_ARM C)


# Directories to include
include_directories(${CMAKE_SOURCE_DIR}/..
                    ${CMAKE_SOURCE_DIR}/../appTimer 
                    ${CMAKE_SOURCE_DIR}/../LedSimulation 
                    ${CMAKE_SOURCE_DIR}/../Libgpiod/usr/lib 
                    ${CMAKE_SOURCE_DIR}/../Libgpiod/usr/include)

# Cross compilation
add_executable(appTimerandLedOutput_RPI ${CMAKE_SOURCE_DIR}/../main.c
                    ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
                    ${CMAKE_SOURCE_DIR}/../LedSimulation/LedSimulation.c)
# Flags
target_compile_options(appTimerandLedOutput_RPI PRIVATE 
        -Wall -Werror -Wextra -fanalyzer -lgpiod -DRPICODE)

# Link required libraries
target_link_libraries(appTimerandLedOutput_RPI PRIVATE 
    ${CMAKE_SOURCE_DIR}/../Libgpiod/usr/lib/libgpiod.so)

# Set executable path
set_target_properties(appTimerandLedOutput_RPI PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../build/release)