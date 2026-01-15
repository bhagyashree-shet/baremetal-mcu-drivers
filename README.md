# Bare-Metal MCU Drivers (STM32) ----  IN PROGRESS

This repository contains bare-metal peripheral drivers written from scratch
for STM32 microcontrollers.

## Implemented Drivers
- Clock (RCC)
- GPIO (input/output, pull-up/down)

## Goals
- No HAL
- Register-level control
- Hardware-verified on STM32F103
## Repository Structure
- drivers/ : reusable peripheral drivers
- examples/: application code using the drivers

## How to Build
1. Create a new STM32CubeIDE project for your target MCU
2. Copy required example `main.c` into the project
3. Add `drivers/inc` to include paths
4. Add `drivers/src/*.c` to the build
5. Build and flash

## Tools
- ARM GCC
- STM32CubeIDE
- ST-Link
