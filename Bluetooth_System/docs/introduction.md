# Introduction

## 1. Introduction

### 1.1 Background

The growing demand for convenience, energy efficiency, and security in residential and commercial spaces has driven significant interest in **home automation systems**. Traditional electrical control involves manual switching, which is often inconvenient and inefficient. Modern embedded systems combined with short-range wireless communication protocols offer a practical alternative for automating such control.

**Bluetooth** is one of the most widely adopted short-range wireless communication standards, operating in the **2.4 GHz ISM (Industrial, Scientific, and Medical)** frequency band. Its widespread availability in smartphones makes it a natural choice for building simple, cost-effective automation systems that do not require an internet connection or a dedicated network infrastructure.

### 1.2 Problem Statement

In conventional homes, each electrical appliance is controlled by an individual manual switch. Controlling multiple appliances from a single location is inconvenient, particularly for elderly or physically challenged individuals. There is a need for a simple, affordable, and reliable wireless control system that can retrofit into existing electrical installations without major modifications.

### 1.3 Proposed Solution

This project proposes a **Bluetooth-based Smart Home Automation System** using:
- **Arduino UNO** as the central microcontroller
- **HC-05 Bluetooth module** for wireless communication
- **4-Channel Relay Module** as the electro-mechanical switching interface
- A standard **Android smartphone** as the user control terminal

The smartphone sends predefined character commands over Bluetooth. The Arduino decodes these commands and switches the relay channels to control connected appliances independently.

### 1.4 Scope of the Project

This mini project covers:
- Hardware assembly and circuit interfacing
- Embedded C programming for Arduino
- Bluetooth serial communication
- Relay-based AC appliance switching
- Testing and validation of the complete system

The project is designed as a **proof-of-concept prototype** suitable for academic demonstration, and can be scaled or upgraded for practical deployment.
