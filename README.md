# Bluetooth-Based-Smart-Home-Automation-System

This project controls home appliances wirelessly using Bluetooth communication. An Arduino UNO and HC-05 Bluetooth module are used to receive commands from a smartphone application. A relay module controls electrical devices such as bulbs and fans.

The system works without internet connectivity and provides a simple method for appliance control.

## Features

- Wireless appliance control using Bluetooth
- Supports multiple devices
- Individual ON/OFF control
- No internet connection required
- Simple hardware setup

## Components Used

- Arduino UNO
- HC-05 Bluetooth Module
- 4-Channel Relay Module
- Bulbs/Fans
- Jumper Wires
- Power Supply

## Hardware Connections

| Component | Pin |
|------------|-----|
| Relay 1 | 12 |
| Relay 2 | 11 |
| Relay 3 | 10 |
| Relay 4 | 9 |
| HC-05 RX | 6 |
| HC-05 TX | 7 |

## Working Procedure

1. Power ON Arduino and HC-05 module.
2. Pair smartphone with HC-05.
3. Open Bluetooth control application.
4. Send command through app.
5. Arduino receives command and controls relays.
6. Connected appliances turn ON/OFF.

## Commands

| Command | Action |
|----------|---------|
| A | Relay 1 ON |
| B | Relay 1 OFF |
| C | Relay 2 ON |
| D | Relay 2 OFF |
| E | Relay 3 ON |
| F | Relay 3 OFF |
| G | Relay 4 ON |
| H | Relay 4 OFF |

## Project Images

Add project setup images in the images folder.

Example:

![Setup](images/project_setup.jpg)

## Project Report

Detailed report available in:

docs/Final_Report.pdf

## Future Improvements

- IoT based remote access
- Voice assistant integration
- Improved mobile application
- Energy monitoring support

## Author

K. Jaya Shankar  
B.Tech Electronics and Communication Engineering
