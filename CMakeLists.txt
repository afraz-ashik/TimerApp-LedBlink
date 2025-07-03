cmake_minimum_required(VERSION 3.10)
project(TimerApp C)

include_directories(${CMAKE_SOURCE_DIR}
                    ${CMAKE_SOURCE_DIR}/appTimer
                    ${CMAKE_SOURCE_DIR}/LedSimulation)

set(CMAKE_C_FLAGS"${CMAKE_C_FLAGS} -Wall -Werror -Wextra -g -O0")

set(SRC ${CMAKE_SOURCE_DIR}/main.c 
        ${CMAKE_SOURCE_DIR}/appTimer/appTimer.c 
        ${CMAKE_SOURCE_DIR}/LedSimulation/LedSimulation.c)

add_executable(appTimerOutput ${SRC})