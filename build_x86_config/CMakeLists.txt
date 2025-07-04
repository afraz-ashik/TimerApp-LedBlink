cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 17)
# Project name
project(TimerAppandLED_x86 C)

# Directories to include
include_directories(${CMAKE_SOURCE_DIR}/..
                    ${CMAKE_SOURCE_DIR}/../appTimer 
                    ${CMAKE_SOURCE_DIR}/../LedSimulation)


# For release folder
add_executable(appTimerOutput ${CMAKE_SOURCE_DIR}/../main.c
                    ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
                    ${CMAKE_SOURCE_DIR}/../LedSimulation/LedSimulation.c)

target_compile_options(appTimerOutput PRIVATE
                      -Wall -Werror -Wextra)

set_target_properties(appTimerOutput PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../build/release)

# For debug folder
add_executable(appTimerOutput_debug ${CMAKE_SOURCE_DIR}/../main.c
                    ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
                    ${CMAKE_SOURCE_DIR}/../LedSimulation/LedSimulation.c)

target_compile_options(appTimerOutput_debug PRIVATE
                      -Wall -Werror -Wextra -g -O0)

set_target_properties(appTimerOutput_debug PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../build/debug)