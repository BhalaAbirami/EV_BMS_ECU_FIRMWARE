# EV Battery Management System (BMS) ECU Firmware

## Overview
Automotive-style Battery Management System (BMS) ECU firmware developed on STM32 using Embedded C. The project implements battery monitoring, safety diagnostics, state management, SOC/SOH estimation, contactor control, precharge logic, watchdog supervision, and CAN-based communication.

## Features

* Scheduler-driven firmware architecture
* Finite State Machine (FSM)
  * IDLE
  * PRECHARGE
  * CHARGING
  * DISCHARGING
  * FAULT
  * SHUTDOWN
* Bootstrap initialization framework
* Watchdog supervision
* ADC abstraction layer
* Sensor monitoring
* Fault handling
* SOC estimation
* SOH estimation
* CAN communication
* Precharge control
* Shutdown Handling
* Contactor control and feedback diagnostics
* Fault debouncing and fault latching


## Implemented Diagnostics

* Overvoltage
* Undervoltage
* Overtemperature
* Sensor Invalid
* Sensor Stuck
* CAN Timeout

## Software Architecture

* Application Layer
* Service Layer
* Driver Layer

## STM32 Board
* STM32F407VGT7

## VALIDATION OF CODE
* Using WOKWI
