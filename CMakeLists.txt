cmake_minimum_required(VERSION 3.10)
project(TimerApp C)

include_directories(${CMAKE_SOURCE_DIR}
                    ${CMAKE_SOURCE_DIR}/appTimer
                    ${CMAKE_SOURCE_DIR}/LedSimulation)

set(CMAKE_C_FLAGS"${CMAKE_C_FLAGS} -Wall -Werror -Wextra -g -O0")

set(SRC main.c 
        appTimer/appTimer.c 
        LedSimulation/LedSimulation.c)

add_executable(appTimerOutput ${SRC})