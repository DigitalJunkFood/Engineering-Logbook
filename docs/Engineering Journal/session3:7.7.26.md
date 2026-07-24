# Session 003

**Date:** July 7, 2026

## Objective

Verify the greenhouse power distribution system and integrate the motor driver.

## Hardware Progress

Successfully completed the initial setup of the motor driver IC and breadboard power module.

Each component was tested independently before integrating the complete system.

## Problem 1

The DC motor failed to operate.

### Root Cause

The motor driver's control pins were interpreted backwards, preventing power from reaching the IC from Arduino Vin.

### Resolution

Corrected the pin orientation after tracing the circuit.

## Problem 2

The DHT11 initialized correctly but failed to return sensor readings.

### Root Cause

The sensor ground was connected to the incorrect ground rail.

### Resolution

Connected the sensor to the proper common ground.

## Software Testing

Compared two software implementations:

- Gemini-generated program
- Lafvin Arduino reference implementation

Studied the libraries, keywords, syntax, and communication methods used by both.

## Engineering Notes

Confirmed that every device within the system must share a common electrical ground.

Question for future investigation:
Can opposite breadboard ground rails be connected together using jumper wires?

## Lessons Learned

- Verify wiring before debugging software.
- Test every component independently.
- Common ground is essential for reliable operation.
