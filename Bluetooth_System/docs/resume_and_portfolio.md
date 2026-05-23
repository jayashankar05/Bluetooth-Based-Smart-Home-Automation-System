# Resume Summary & GitHub Portfolio Guide

## ATS-Friendly Resume Entry

Use the following text in your **Projects** section on your resume:

---

### Projects Section (Resume Format)

**Bluetooth Based Smart Home Automation System** | *B.Tech Mini Project – ECE* | *2024*

- Designed and implemented a wireless home appliance control system using **Arduino UNO** and **HC-05 Bluetooth module**.
- Interfaced a **4-channel relay module** (10A/250V AC) to independently switch four AC appliances via GPIO digital outputs.
- Programmed the Arduino in **Embedded C** using the **SoftwareSerial** library for secondary UART communication on digital pins 10 and 11.
- Implemented a single-character ASCII command protocol transmitted over **Bluetooth SPP (Serial Port Profile)** at 2.4 GHz.
- Designed a resistor voltage divider (1kΩ + 2kΩ) to step down 5V Arduino TX logic to 3.3V for HC-05 RXD compatibility.
- Achieved reliable wireless control up to **10 metres** range with acknowledgement feedback to the smartphone.
- Documented the project on **GitHub** with circuit diagrams, source code, and full technical documentation.

**Technologies:** Arduino IDE, C/C++, SoftwareSerial, UART, Bluetooth, Relay Interfacing, Embedded Systems

---

## GitHub Portfolio Description

Use this as your GitHub repository description:

```
Wireless home appliance control system using Arduino UNO and HC-05 Bluetooth module.
Controls 4 AC appliances via relay module using smartphone Bluetooth commands. 
Built with Arduino IDE (C/C++), SoftwareSerial library. No internet required.
```

---

## GitHub Repository Topics / Tags

Add these tags to your GitHub repository (Settings → Topics):

```
arduino
bluetooth
hc-05
relay
home-automation
embedded-systems
arduino-uno
smart-home
softwareserial
uart
ece-project
btech-project
mini-project
wireless-control
c-cpp
microcontroller
4-channel-relay
android-bluetooth
iot-prototype
```

---

## LinkedIn Project Post Template

> **Just completed my B.Tech ECE Mini Project! 🎉**
>
> **Bluetooth Smart Home Automation System** – built using Arduino UNO + HC-05 + 4-Channel Relay.
>
> 🔧 Controls 4 home appliances wirelessly via smartphone
> 📡 Bluetooth SPP communication at 2.4 GHz
> 💡 No internet required – works completely offline
> 💰 Total cost: ~₹1,200
>
> The full source code, circuit diagrams, and documentation are available on my GitHub:
> [GitHub Link]
>
> #Arduino #Bluetooth #HomeAutomation #EmbeddedSystems #ECE #BTech #MiniProject #IoT

---

## Interview / Viva Q&A Preparation

| Question                                          | Answer Summary                                                                                     |
|---------------------------------------------------|-----------------------------------------------------------------------------------------------------|
| What microcontroller did you use?                 | Arduino UNO based on ATmega328P (8-bit, 16 MHz, 32KB Flash)                                       |
| What is the role of HC-05?                        | Acts as a Bluetooth-to-UART bridge; receives commands wirelessly and forwards to Arduino via UART   |
| Why SoftwareSerial instead of Hardware Serial?    | To keep hardware UART (pins 0,1) free for Serial Monitor debugging; SoftwareSerial uses pins 10,11  |
| Why is a voltage divider needed?                  | HC-05 RXD is 3.3V logic; Arduino TX outputs 5V; divider steps it down to ~3.33V to protect HC-05  |
| What is active-LOW relay logic?                   | Writing LOW (0V) energises the relay; most relay modules use this to provide optocoupler isolation  |
| What is the Bluetooth range?                      | HC-05 is Class 2 Bluetooth; typical range ~10 metres in open space                                 |
| What is the Bluetooth profile used?               | SPP – Serial Port Profile – emulates a wired serial connection over wireless Bluetooth              |
| Can multiple phones control simultaneously?       | No; HC-05 (Classic Bluetooth) supports only one master connection at a time                         |
| How many appliances can be controlled?            | 4 independently (using 4-channel relay); can extend to 8 or 16 with a larger relay board           |
| What are the limitations?                         | 10m range, single user, no internet, no scheduling, no energy monitoring, no iOS support            |
| What is the future scope?                         | ESP8266 Wi-Fi, Google Assistant, custom Android app, RTC scheduling, energy monitoring              |
| What safety measures did you implement?           | Relay optocoupler isolation between 5V control and 220V AC; initial state = all relays OFF          |
