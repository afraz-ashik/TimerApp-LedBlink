cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Project name
project(TimerApp C)

# Directories to include
include_directories(${CMAKE_SOURCE_DIR} 
                    ${CMAKE_SOURCE_DIR}/appTimer 
                    ${CMAKE_SOURCE_DIR}/LedSimulation)

# Source files
set(SRCFILES main.c 
             appTimer/appTimer.c 
             LedSimulation/LedSimulation.c)

# For release folder
add_executable(appTimerOutput ${SRCFILES})

target_compile_options(appTimerOutput PRIVATE
                      -Wall -Werror -Wextra)

set_target_properties(appTimerOutput PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/release)

# For debug folder
add_executable(appTimerOutput_debug ${SRCFILES})

target_compile_options(appTimerOutput_debug PRIVATE
                      -Wall -Werror -Wextra -g -O0)

set_target_properties(appTimerOutput_debug PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/debug)
