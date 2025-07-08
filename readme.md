# TimerApp-LedBlink

A C project that supports cross-compilation to build a Timer app that display 
time and date in GMT, IST and PST timezone, and a Led blink program for both 
Linux and Raspberry Pi, using either __CMake__ or __Make__ for building.

## Features

Organized source code in multiple directories
Separate __release__ and __debug__ builds
Cross-compilation support for Raspberry Pi (aarch64)

## Prerequisites

__CMake__ ≥ 3.10
__Make__
__GCC__ (for Linux build)
__aarch64-linux-gnu-gcc__ (for Raspberry Pi cross-compilation)

## Building with Make

### 1. Build All

$ make all

Builds both Linux and Raspberry Pi release targets.

### 2. Linux (Release, Debug)

$ make linux

Output: release/appTimerOutput debug/appTimerOutput

### 3. Raspberry Pi (Release)

$ make rpi

Output: release/appTimerArm64

### 4. Clean Build Artifacts

$ make clean

Removes all files from release/ and debug/ folders.

## Building with CMake

### 1. Native and RPI Build

$ cmake -B build

$ cmake --build build