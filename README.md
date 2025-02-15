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
|   |-- PORT_Module Based on Autosar
|   |-- EXTI
|   |-- GIE
|   |-- ADC
|   |-- UART
|   |-- SPI
|   |-- I2C
|   |-- TIMERS
|   |-- WDT
|
|-- HAL
|   |-- LCD
|   |-- SWITCH
|   |-- SSD
|   |-- BUZZER
|   |-- LCD 16*2
|   |-- KEYPAD
|   |-- DC_MOTOR
|   |-- STEPPER_MOTOR
|   |-- SERVO_MOTOR
|   |-- DAC
|   |-- LM35_Sensor 
|   |-- LDR_Sensor
|   |-- ULTRASONIC
|   |-- EEPROM
|
|-- LIBS
|   |-- BIT_MATH.h
|   |-- STD_TYPES.h
|   |-- MAPPING
|
|-- RTOS
|   |-- Scheduler.c
|   |-- Scheduler.h
|
|-- README.md


## MCAL Drivers
### DIO (Digital Input/Output)
- Functions to set, clear, toggle, and read pin values.
- Supports port-wide operations.

### PORT_Module Based on Autosar
- Implements AUTOSAR-based port driver.
- Provides standardized APIs for pin configuration.

### EXTI (External Interrupts)
- Supports multiple interrupt sources.
- Configurable trigger modes (rising, falling, or both edges).

### GIE (Global Interrupt Enable)
- Provides functions to enable and disable global interrupts.

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

### TIMERS (Timer/Counter)
- Supports different timer modes (normal, CTC, PWM).
- Configurable prescalers and interrupts.

### WDT (Watchdog Timer)
- Provides system reset on timeout.
- Configurable timeout intervals.

## HAL Drivers
### LCD (Liquid Crystal Display)
- Supports 4-bit and 8-bit modes.
- Provides APIs for character and string display.

### SWITCH
- Handles push buttons and toggle switches.
- Supports software debouncing.

### SSD (Seven Segment Display)
- Supports common anode and cathode configurations.
- Provides number display functions.

### BUZZER
- Controls buzzer activation and deactivation.

### LCD 16*2
- Extended functionalities for 16x2 character LCDs.

### KEYPAD
- Handles matrix keypads with debouncing.
- Supports dynamic scanning.

### DC_MOTOR
- Functions for speed and direction control.
- Supports PWM-based speed regulation.

### STEPPER_MOTOR
- Provides step and direction control.
- Supports different stepping modes (full, half, micro-step).

### SERVO_MOTOR
- Uses PWM for position control.
- Configurable angle range.

### DAC (Digital-to-Analog Converter)
- Supports generating analog output from digital signals.

### LM35_Sensor (Temperature Sensor)
- Reads temperature values in Celsius.
- Provides API for conversion and calibration.

### LDR_Sensor (Light Dependent Resistor)
- Measures ambient light intensity.
- Outputs voltage proportional to light level.

### ULTRASONIC
- Measures distance using sound waves.
- Provides API for precise distance calculations.

### EEPROM
- Supports read and write operations.
- Non-volatile memory storage.

## LIBS
- **BIT_MATH.h**: Macros for bit manipulation.
- **STD_TYPES.h**: Standard data types for portability.
- **MAPPING**: Macros for mapping values from one range to another.

## RTOS Stack
- Implements a basic cooperative/preemptive scheduler.
- Supports task creation, scheduling, and delays.
- Includes task priority management.

## Getting Started
### Prerequisites
- AVR Toolchain (GCC for AVR, AVRDUDE, etc.)
- Atmel Studio / Arduino IDE (optional)
- AVR ISP Programmer

