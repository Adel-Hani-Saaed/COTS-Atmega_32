# ATmega32 Drivers

## Overview
This repository contains a set of modular and reusable drivers for the ATmega32 microcontroller, structured into different abstraction layers:

- **MCAL (Microcontroller Abstraction Layer)**: Low-level drivers interfacing directly with hardware registers.
- **HAL (Hardware Abstraction Layer)**: Higher-level drivers providing easy-to-use APIs for peripherals.
- **LIBS (Utility Libraries)**: Helper functions and macros for efficiency and code clarity.
- **RTOS Stack**: Real-time operating system implementation for task scheduling.

## Repository Structure
```
|-- MCAL
|   |-- DIO
|   |-- ADC
|   |-- UART
|   |-- SPI
|   |-- I2C
|   |-- TIMER
|   |-- WDT
|
|-- HAL
|   |-- LCD
|   |-- KEYPAD
|   |-- MOTOR
|   |-- SENSORS
|
|-- LIBS
|   |-- BIT_MATH.h
|   |-- STD_TYPES.h
|
|-- RTOS
|   |-- Scheduler.c
|   |-- Scheduler.h
|
|-- README.md
|-- main.c
```

## MCAL Drivers
### DIO (Digital Input/Output)
- Functions to set, clear, toggle, and read pin values.
- Supports port-wide operations.

### ADC (Analog-to-Digital Converter)
- Supports single and continuous conversion modes.
- Interrupt and polling-based implementations.

### UART (Universal Asynchronous Receiver-Transmitter)
- Configurable baud rate, parity, and stop bits.
- Supports transmission and reception using interrupts or polling.

### SPI (Serial Peripheral Interface)
- Master/slave modes supported.
- Supports full-duplex communication.

### I2C (Inter-Integrated Circuit)
- Supports master and slave communication.
- Interrupt and polling-based data transmission.

### TIMER (Timer/Counter)
- Supports different timer modes (normal, CTC, PWM).
- Configurable prescalers and interrupts.

### WDT (Watchdog Timer)
- Provides system reset on timeout.
- Configurable timeout intervals.

## HAL Drivers
### LCD (Liquid Crystal Display)
- Supports 4-bit and 8-bit modes.
- Provides APIs for character and string display.

### KEYPAD
- Handles matrix keypads with debouncing.
- Supports dynamic scanning.

### MOTOR (DC Motor and Servo)
- Functions for speed and direction control.
- Supports PWM-based speed regulation.

### SENSORS
- Includes support for temperature, IR, and ultrasonic sensors.
- Provides simple APIs to retrieve sensor data.

## LIBS
- **BIT_MATH.h**: Macros for bit manipulation.
- **STD_TYPES.h**: Standard data types for portability.

## RTOS Stack
- Implements a basic cooperative/preemptive scheduler.
- Supports task creation, scheduling, and delays.
- Includes task priority management.

## Getting Started
### Prerequisites
- AVR Toolchain (GCC for AVR, AVRDUDE, etc.)
- Atmel Studio / Arduino IDE (optional)
- AVR ISP Programmer

### Compilation & Upload
1. Compile the code using `avr-gcc`:
   ```sh
   avr-gcc -mmcu=atmega32 -o main.elf main.c
   ```
2. Convert to HEX file:
   ```sh
   avr-objcopy -O ihex main.elf main.hex
   ```
3. Upload to ATmega32 using AVRDUDE:
   ```sh
   avrdude -c usbasp -p m32 -U flash:w:main.hex:i
   ```

## Contribution
Feel free to submit issues or pull requests to improve the drivers.

## License
This project is licensed under the MIT License.
