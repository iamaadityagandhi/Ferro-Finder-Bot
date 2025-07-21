# Ferro-Finder-Bot

This repository contains the code and project files for Ferro_Finder, a small mobile robot designed to detect and locate ferrous (iron-containing) metal objects. The project utilizes an Arduino microcontroller for hardware control and Unity for visualization and potential simulation/control interface development.

Overview
The Ferro_Finder robot uses a sensor (e.g., inductive proximity sensor, magnetometer) to detect the presence of ferrous metals. The Arduino code processes the sensor data and controls the robot's motors to navigate towards the detected metal object. This repository includes the Arduino code (.ino file) required to operate the robot's hardware.

Hardware
Microcontroller: ESP32
Sensor: Ultrasonic sensor
Motors: DC Motors
Motor Driver: L298N Motor Driver
Power Supply: 12V Battery
Chassis: Wooden Plank

Software
Arduino IDE:
The Arduino code is written in C++ and should be compiled and uploaded using the Arduino IDE.
Unity:
Used to visualize the robot’s sensor readings and potentially create a simulated environment for testing and development.

File Description
meta_over_wifi.ino:
Arduino sketch containing the code for controlling the robot’s hardware, including sensor reading, motor control, and logic for finding ferrous metals.
