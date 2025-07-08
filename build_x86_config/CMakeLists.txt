cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 17)
# Project name
project(TimerAppandLED_x86 C)

# Directories to include
include_directories(${CMAKE_SOURCE_DIR}/..
                    ${CMAKE_SOURCE_DIR}/../appTimer 
                    ${CMAKE_SOURCE_DIR}/../LedSimulation
                    ${CMAKE_SOURCE_DIR}/../gpiodWrapper)


# For release folder
add_executable(appTimerandLedOutput ${CMAKE_SOURCE_DIR}/../main.c
                    ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
                    ${CMAKE_SOURCE_DIR}/../LedSimulation/LedSimulation.c)
# Flags
target_compile_options(appTimerandLedOutput PRIVATE
                      -Wall -Wextra -fanalyzer)

# Set executable path
set_target_properties(appTimerandLedOutput PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../build/release)

# For debug folder
add_executable(appTimerandLedOutput_debug ${CMAKE_SOURCE_DIR}/../main.c
                    ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
                    ${CMAKE_SOURCE_DIR}/../LedSimulation/LedSimulation.c)

# Flag
target_compile_options(appTimerandLedOutput_debug PRIVATE
                      -Wall -Werror -Wextra -g -fanalyzer -O0)

# Set executable path
set_target_properties(appTimerandLedOutput_debug PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../build/debug)