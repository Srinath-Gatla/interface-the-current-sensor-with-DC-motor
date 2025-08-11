# interface-the-current-sensor-with-DC-motor
This repository contains an Arduino sketch designed to control a DC motor and monitor its current consumption in real time using a Hall-effect current sensor like the ACS758. The system uses PWM for speed control, digital pins for direction control, and analog input for current sensing.

The project is useful for:

Motor load testing

Power consumption monitoring

Overcurrent protection systems

Educational demonstrations of motor control and sensor interfacing

Features
PWM speed control for DC motor

Direction control via H-bridge pins

Real-time current measurement using ACS758 or similar sensors

Configurable sensor sensitivity and calibration

Serial Monitor output for easy debugging and data logging

Hardware Requirements
Arduino UNO, Mega, or compatible board

ACS758 (or similar Hall-effect current sensor)

H-bridge motor driver (e.g., L298N, BTS7960)

DC motor

Power supply for motor and logic

Jumper wires and breadboard

Pin Configuration
Component	Arduino Pin
Current Sensor OUT	A0
Motor PWM	5
Motor IN1	6
Motor IN2	7

How It Works
Motor Control:
The motor runs in a set direction at 60% PWM duty cycle.

Current Measurement:
The ACS758 outputs a voltage proportional to current. The Arduino reads the voltage, subtracts the 0A offset (SENSOR_ZERO_CURRENT_VOLTAGE), and divides by sensitivity (SENSOR_SENSITIVITY) to calculate the actual current.

Data Output:
Real-time current values are printed to the Serial Monitor for monitoring or logging.

Applications
DC motor efficiency testing

Battery-powered system monitoring

Overcurrent detection and shutdown

Lab experiments in electronics and mechatronics
