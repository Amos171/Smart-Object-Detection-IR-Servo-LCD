# Smart-Object-Detection-IR-Servo-LCD

Project Overview
This project uses an Arduino Uno with an IR obstacle sensor to detect objects.
When an object is detected, the LCD displays the status and a servo motor rotates.
When no object is present, the LCD shows “No Object” and the servo returns to its home position.

Components Used
	1.	Arduino Uno
	2.	IR Obstacle Sensor
	3.	SG90 Servo Motor
	4.	16x2 LCD with I2C Module (PCF8574)
	5.	Jumper Wires
	6.	Breadboard

Working Principle
	1.	IR Sensor Working
The IR sensor has an IR LED and photodiode.
When no object is in front of the sensor, IR light does NOT reflect, so the output is HIGH (1).
When an object is present, IR light reflects, causing output LOW (0).
Arduino reads this value on digital pin D2.
	2.	System Response
If IR value is LOW → “Object Detected” and servo rotates to 90 degrees.
If IR value is HIGH → “No Object” and servo returns to 0 degrees.
	3.	LCD Display
The LCD uses I2C communication.
Only four wires are needed: VCC, GND, SDA (A4), SCL (A5).
The LCD shows real-time status of object detection.

Circuit Connections
IR Sensor:
VCC → 5V
GND → GND
OUT → D2

Servo Motor:
Red (VCC) → 5V
Brown/Black (GND) → GND
Orange/Yellow (Signal) → D10

LCD with I2C:
VCC → 5V
GND → GND
SDA → A4
SCL → A5
