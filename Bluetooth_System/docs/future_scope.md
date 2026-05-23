# Future Scope

## 10. Future Scope

This project serves as a foundational prototype. The following enhancements can be implemented to develop it into a more complete, practical home automation system.

---

### 10.1 Wi-Fi Based Control (Internet of Things)

**Upgrade:** Replace HC-05 with an **ESP8266** or **ESP32** Wi-Fi module.

- Control appliances from **anywhere in the world** via internet.
- Integrate with cloud platforms like **Blynk**, **MQTT (Mosquitto)**, or **Firebase**.
- Enables remote monitoring and control through a web browser or mobile app.

| Module  | Protocol | Range       | Approximate Cost |
|---------|----------|-------------|------------------|
| ESP8266 | Wi-Fi    | Router range| ₹200 – ₹350      |
| ESP32   | Wi-Fi + BT| Router range| ₹350 – ₹500     |

---

### 10.2 Voice Control Integration

**Upgrade:** Integrate with **Google Assistant** or **Amazon Alexa** using IFTTT or direct API.

- "Hey Google, turn on the living room light."
- Requires Wi-Fi connectivity (ESP8266/ESP32 upgrade needed first).
- Provides hands-free appliance control.

---

### 10.3 Custom Android Application

**Upgrade:** Develop a dedicated **Android app** using MIT App Inventor or **Flutter**.

- Replace plain-text terminal commands with graphical toggle switches.
- Add appliance labels, room names, and status indicators.
- Include a connection status bar and error handling UI.

---

### 10.4 Energy Monitoring

**Upgrade:** Add **ACS712 Hall-Effect Current Sensor** modules on each appliance line.

- Measure actual current drawn by each appliance.
- Calculate power consumption (Watts) and energy usage (kWh).
- Display energy data on an LCD or send it to a smartphone dashboard.

---

### 10.5 Scheduling and Timers

**Upgrade:** Add a **DS3231 Real-Time Clock (RTC)** module.

- Schedule appliances to turn ON/OFF at specific times (e.g., "Turn on fan at 10 PM").
- Implement daily or weekly repeating schedules.
- Eliminates the need for manual intervention for routine switching.

---

### 10.6 PIR Sensor-Based Automation

**Upgrade:** Interface a **PIR (Passive Infrared) Motion Sensor** (HC-SR501).

- Automatically turn lights ON when motion is detected in a room.
- Automatically turn lights OFF after a set idle period.
- Reduces manual control requirement and saves electricity.

---

### 10.7 LCD Status Display

**Upgrade:** Add a **16×2 LCD with I2C interface**.

- Display current ON/OFF status of all 4 appliances locally.
- Show time, last command received, and Bluetooth connection status.
- Useful when the phone is not nearby.

---

### 10.8 PIN-Based Security

**Upgrade:** Implement a **4-digit PIN authentication** system over Bluetooth.

- The user must enter a correct PIN before any relay commands are accepted.
- Prevents unauthorised control if someone pairs with the HC-05.

---

### 10.9 Multi-User Support with BLE (Bluetooth Low Energy)

**Upgrade:** Replace HC-05 with an **HM-10 BLE module** or ESP32's onboard BLE.

- Multiple users can connect simultaneously.
- Compatible with both Android and iOS (iPhones do not support Bluetooth Classic SPP).
- Lower power consumption compared to Bluetooth Classic.

---

### 10.10 Summary Upgrade Roadmap

```
Version 1 (Current)
└── Arduino UNO + HC-05 + 4-CH Relay + Android app

Version 2
└── + Custom Android App (Flutter/MIT App Inventor)
└── + LCD Display + RTC scheduling

Version 3
└── + ESP8266/ESP32 (Wi-Fi)
└── + MQTT cloud integration
└── + Google Assistant voice control

Version 4
└── + ACS712 energy monitoring
└── + PIR sensor automation
└── + Web dashboard
```
