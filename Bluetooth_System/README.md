# 📡 Bluetooth Based Smart Home Automation System

> A low-cost, wireless home automation system using Arduino UNO and HC-05 Bluetooth module to control household appliances via a smartphone.

---

![Arduino](https://img.shields.io/badge/Platform-Arduino%20UNO-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Bluetooth](https://img.shields.io/badge/Communication-Bluetooth%20HC--05-0082FC?style=for-the-badge&logo=bluetooth&logoColor=white)
![Language](https://img.shields.io/badge/Language-C%2FC%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

---

## 📋 Table of Contents

- [Project Overview](#-project-overview)
- [Block Diagram](#-block-diagram)
- [Components Used](#-components-used)
- [Circuit Connections](#-circuit-connections)
- [Working Principle](#-working-principle)
- [Features](#-features)
- [Arduino Code](#-arduino-code)
- [Bluetooth Commands](#-bluetooth-commands)
- [How to Use](#-how-to-use)
- [Project Structure](#-project-structure)
- [Future Scope](#-future-scope)
- [Applications](#-applications)
- [Resume Summary](#-resume-summary)
- [License](#-license)

---

## 📌 Project Overview

This mini project demonstrates **wireless control of home appliances** using the Bluetooth protocol. A smartphone communicates with an **HC-05 Bluetooth module** interfaced with an **Arduino UNO** microcontroller. Based on the received character commands, the Arduino toggles a **4-channel relay module** that switches connected electrical appliances (bulbs, fans, etc.) ON or OFF.

This project is designed to be **affordable, scalable, and easy to implement**, making it an ideal starting point for home automation using embedded systems.

| Parameter        | Details                        |
|------------------|--------------------------------|
| Microcontroller  | Arduino UNO (ATmega328P)       |
| Communication    | Bluetooth (HC-05 Module)       |
| Control Unit     | 4-Channel Relay Module (5V)    |
| Frequency        | 2.4 GHz ISM Band               |
| Range            | Up to 10 metres (Class 2)      |
| Power Supply     | 5V DC (via USB or adapter)     |
| IDE              | Arduino IDE 2.x                |
| Language         | C/C++ (Arduino Framework)      |

---

## 🔷 Block Diagram

```
+-------------+        Bluetooth         +------------------+
| Smartphone  |  ──────────────────────> |  HC-05 Module    |
| (Control    |       (2.4 GHz)          |  (Slave Mode)    |
|   App)      |                          +--------+---------+
+-------------+                                   |
                                              UART (RX/TX)
                                                   |
                                          +--------v---------+
                                          |   Arduino UNO    |
                                          |  (ATmega328P)    |
                                          +--------+---------+
                                                   |
                                          Digital Output Pins
                                    ______|_____|_____|______
                                   |      |     |     |      |
                                 Relay1 Relay2 Relay3 Relay4
                                   |      |     |     |      |
                                 Bulb1  Bulb2  Fan1  Fan2
```

---

## 🔩 Components Used

| S.No | Component                  | Quantity | Approximate Cost (INR) |
|------|----------------------------|----------|------------------------|
| 1    | Arduino UNO (ATmega328P)   | 1        | ₹450 – ₹600            |
| 2    | HC-05 Bluetooth Module     | 1        | ₹180 – ₹250            |
| 3    | 4-Channel Relay Module (5V)| 1        | ₹120 – ₹180            |
| 4    | Bulbs / CFLs / Fans        | 4        | ₹80 – ₹150 each        |
| 5    | Jumper Wires (M-M, M-F)    | 1 Set    | ₹50 – ₹80              |
| 6    | Breadboard                 | 1        | ₹60 – ₹100             |
| 7    | USB Cable (Type-B)         | 1        | ₹50 – ₹80              |
| 8    | 5V Power Supply / Adapter  | 1        | ₹100 – ₹200            |
|      | **Estimated Total**        |          | **₹1,090 – ₹1,640**    |

---

## 🔌 Circuit Connections

### HC-05 to Arduino UNO

| HC-05 Pin | Arduino Pin |
|-----------|-------------|
| VCC       | 5V          |
| GND       | GND         |
| TXD       | Pin 10 (RX) |
| RXD       | Pin 11 (TX) |

> ⚠️ **Note:** HC-05 RXD operates at 3.3V logic. Use a voltage divider (1kΩ + 2kΩ) on the Arduino TX → HC-05 RX line to prevent module damage.

### 4-Channel Relay to Arduino UNO

| Relay Pin | Arduino Pin |
|-----------|-------------|
| IN1       | Pin 2       |
| IN2       | Pin 3       |
| IN3       | Pin 4       |
| IN4       | Pin 5       |
| VCC       | 5V          |
| GND       | GND         |

> The relay module is **active-LOW**. Sending `LOW` (0V) to an IN pin energises the relay and closes the circuit.

---

## ⚙️ Working Principle

1. The smartphone runs a Bluetooth terminal application (e.g., **Serial Bluetooth Terminal** on Android).
2. The app pairs with the **HC-05 module** (default PIN: `1234` or `0000`).
3. Single-character commands are sent from the app to the HC-05 module over the 2.4 GHz ISM band.
4. HC-05 forwards these commands to the Arduino via the **UART** serial interface (SoftwareSerial on pins 10 & 11).
5. The Arduino reads the incoming character and toggles the corresponding **relay channel**.
6. The relay acts as an electrically controlled switch, connecting or disconnecting the AC supply to the appliance.

---

## ✨ Features

- ✅ Wireless control up to **10 metres** range
- ✅ Controls up to **4 independent appliances**
- ✅ Works with any **Android Bluetooth terminal app**
- ✅ **No internet or Wi-Fi** required
- ✅ **Low-cost** implementation (~₹1,200)
- ✅ **Status feedback** via Serial Monitor
- ✅ Easy to extend to 8-channel or 16-channel relay boards
- ✅ Safe for **220V AC mains** appliances through relay isolation

---

## 💻 Arduino Code

The main source code is located at [`code/smart_home_automation.ino`](code/smart_home_automation.ino).

**Command mapping:**

| Command Sent | Action               |
|--------------|----------------------|
| `1`          | Appliance 1 ON       |
| `2`          | Appliance 2 ON       |
| `3`          | Appliance 3 ON       |
| `4`          | Appliance 4 ON       |
| `5`          | Appliance 1 OFF      |
| `6`          | Appliance 2 OFF      |
| `7`          | Appliance 3 OFF      |
| `8`          | Appliance 4 OFF      |
| `A`          | ALL Appliances ON    |
| `Z`          | ALL Appliances OFF   |

---

## 📱 Bluetooth Commands

Full command reference is available in [`code/bluetooth_commands.md`](code/bluetooth_commands.md).

---

## 🚀 How to Use

### Step 1 – Hardware Setup
1. Assemble the circuit as per the wiring diagram in [`circuit-diagram/wiring_connections.md`](circuit-diagram/wiring_connections.md).
2. Connect the relay module outputs to AC appliances through proper insulated wiring.

### Step 2 – Upload the Code
1. Install [Arduino IDE](https://www.arduino.cc/en/software).
2. Open `code/smart_home_automation.ino` in Arduino IDE.
3. Connect Arduino UNO to your PC via USB.
4. Select **Board**: Arduino UNO and correct **COM Port**.
5. Click **Upload**.

### Step 3 – Pair the Bluetooth Module
1. Power on the circuit.
2. On your Android phone, go to **Settings → Bluetooth → Scan**.
3. Pair with **HC-05** (PIN: `1234`).

### Step 4 – Control Appliances
1. Open **Serial Bluetooth Terminal** (or any Bluetooth terminal app).
2. Connect to HC-05.
3. Send commands (`1`–`8`, `A`, `Z`) to control appliances.

---

## 📁 Project Structure

```
Bluetooth-Smart-Home-Automation/
│
├── README.md                        ← Project overview (this file)
├── LICENSE                          ← MIT License
│
├── circuit-diagram/
│   ├── circuit.png                  ← Schematic diagram
│   ├── block_diagram.png            ← System block diagram
│   └── wiring_connections.md        ← Detailed pin connections
│
├── code/
│   ├── smart_home_automation.ino    ← Main Arduino source code
│   ├── bluetooth_commands.md        ← Command reference sheet
│   └── code_explanation.md         ← Line-by-line code walkthrough
│
├── images/
│   ├── setup.jpg                    ← Hardware setup photo
│   ├── working.jpg                  ← Live working photo
│   ├── components.jpg               ← All components laid out
│   └── output_demo.jpg              ← Output demonstration
│
├── report/
│   └── mini_project_report.pdf      ← Full project report (B.Tech)
│
├── docs/
│   ├── abstract.md
│   ├── introduction.md
│   ├── objectives.md
│   ├── methodology.md
│   ├── working_principle.md
│   ├── experimental_procedure.md
│   ├── pin_configuration.md
│   ├── components.md
│   ├── advantages.md
│   ├── applications.md
│   ├── future_scope.md
│   └── conclusion.md
│
├── videos/
│   └── demo_link.txt                ← Link to demo video
│
└── requirements/
    └── required_components.txt      ← Bill of Materials
```

---

## 🔭 Future Scope

- 🌐 **Wi-Fi Integration** – Replace HC-05 with ESP8266/ESP32 for internet-based control
- 🗣️ **Voice Control** – Integrate Google Assistant or Amazon Alexa
- 📱 **Custom Android App** – Build a dedicated MIT App Inventor / Flutter control app
- 📊 **Energy Monitoring** – Add ACS712 current sensor to track power consumption
- 🔐 **Security** – Add PIN-based authentication for Bluetooth pairing
- ⏰ **Scheduling** – Add RTC module (DS3231) to automate appliance timers
- 🌡️ **Smart Sensing** – Integrate PIR / temperature sensors for automatic control

---

## 🏠 Applications

- Residential home automation
- Hostel and dormitory room control
- Office lighting automation
- Industrial equipment switching (low-voltage signalling)
- Prototype for larger IoT-based smart systems

---

## 📄 Resume Summary

> **Bluetooth Based Smart Home Automation System** | *B.Tech Mini Project – ECE*  
> Designed and implemented a wireless home automation system using Arduino UNO and HC-05 Bluetooth module. Interfaced a 4-channel relay module to control AC appliances via smartphone. Programmed in C/C++ using the Arduino framework with SoftwareSerial library. Demonstrated wireless communication over 2.4 GHz Bluetooth with a range of up to 10 metres.

**Skills demonstrated:** Embedded C, Arduino IDE, UART communication, relay interfacing, circuit design, hardware debugging

---

## 🏷️ GitHub Topics

```
arduino  bluetooth  hc-05  relay  home-automation  embedded-systems
arduino-uno  iot  smart-home  softwareserial  ece-project  btech-project
mini-project  wireless-control  uart  c-cpp  microcontroller
```

---

## 📜 License

This project is licensed under the **MIT License** – see the [LICENSE](LICENSE) file for details.

---

## 🙋 Author

**B.Tech ECE Student**  
Department of Electronics and Communication Engineering  

---

*⭐ If this project helped you, please give it a star on GitHub!*
