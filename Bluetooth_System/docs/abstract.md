# Abstract

## Bluetooth Based Smart Home Automation System

### Abstract

This project presents the design and implementation of a **Bluetooth-based Smart Home Automation System** using an Arduino UNO microcontroller and an HC-05 Bluetooth module. The system enables wireless control of household electrical appliances through a smartphone application, eliminating the need for manual switches or internet connectivity.

A **4-channel relay module** serves as the switching interface between the low-voltage control circuit and the high-voltage AC appliances. The HC-05 module operates in slave mode and receives character-based commands from a paired smartphone over the 2.4 GHz ISM band. The Arduino processes these commands using the **SoftwareSerial** library and drives the relay channels accordingly.

The system supports independent control of up to four appliances and provides bidirectional communication by sending acknowledgement responses back to the smartphone. The prototype was successfully tested for a range of up to **10 metres**, demonstrating reliable wireless operation within a typical residential environment.

The total hardware cost is approximately **₹1,200**, making it a practical and affordable solution for entry-level home automation. This project demonstrates the fundamental concepts of **embedded systems, UART serial communication, relay interfacing, and wireless control**, and serves as a viable foundation for more advanced IoT-based automation systems.

**Keywords:** Arduino UNO, HC-05, Bluetooth, Home Automation, Relay Module, SoftwareSerial, UART, Embedded Systems, Wireless Control,UART Communication.
