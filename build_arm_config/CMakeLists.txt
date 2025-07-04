cmake_minimum_required(VERSION 3.10)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# Project name
project(TimerAppandLED_ARM C)


# Directories to include
include_directories(${CMAKE_SOURCE_DIR}/..
                    ${CMAKE_SOURCE_DIR}/../appTimer 
                    ${CMAKE_SOURCE_DIR}/../LedSimulation)

# Cross compilation
add_executable(appTimerOutput_RPI ${CMAKE_SOURCE_DIR}/../main.c
                    ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
                    ${CMAKE_SOURCE_DIR}/../LedSimulation/LedSimulation.c)

target_compile_options(appTimerOutput_RPI PRIVATE
                      -Wall -Werror -Wextra)
set_target_properties(appTimerOutput_RPI PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../build/release)