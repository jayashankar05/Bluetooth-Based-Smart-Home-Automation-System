# Components

## 7. Component Details

### 7.1 Arduino UNO (ATmega328P)

The **Arduino UNO** is an open-source microcontroller development board based on the 8-bit **ATmega328P** microcontroller from Microchip Technology.

| Specification          | Value                            |
|------------------------|----------------------------------|
| Microcontroller        | ATmega328P                       |
| Operating Voltage      | 5V                               |
| Input Voltage (Jack)   | 7–12V                            |
| Digital I/O Pins       | 14 (6 with PWM output)           |
| Analog Input Pins      | 6 (10-bit ADC)                   |
| Flash Memory           | 32 KB (0.5 KB used by bootloader)|
| SRAM                   | 2 KB                             |
| EEPROM                 | 1 KB                             |
| Clock Speed            | 16 MHz                           |
| UART Ports             | 1 (hardware) + software emulation|
| USB Interface          | CH340G or ATmega16U2             |

**Role in this project:** Acts as the central processing unit. Receives serial commands from HC-05, executes the command logic, and drives relay control pins.

---

### 7.2 HC-05 Bluetooth Module

The **HC-05** is a serial Bluetooth module designed for transparent wireless serial communication. It supports the **Bluetooth SPP (Serial Port Profile)** which makes it appear as a virtual COM port to both the microcontroller and the smartphone.

| Specification          | Value                            |
|------------------------|----------------------------------|
| Bluetooth Version      | 2.0 + EDR                        |
| Operating Voltage      | 3.3V – 5V (VCC pin)              |
| UART Logic Level       | 3.3V                             |
| Default Baud Rate      | 9600 bps                         |
| Default PIN            | 1234                             |
| Operating Mode         | Master / Slave (configurable)    |
| Communication Range    | ~10 m (Class 2)                  |
| Frequency              | 2.4 GHz ISM Band                 |
| AT Command Mode        | Yes (via KEY/EN pin or at boot)  |

**Role in this project:** Receives character commands from the paired smartphone over Bluetooth and forwards them to Arduino via UART. Also sends acknowledgements back to the phone.

---

### 7.3 4-Channel Relay Module (5V)

A **relay** is an electrically operated mechanical switch. The module contains four individual relays, each controlled by an optocoupler-isolated transistor driver circuit.

| Specification           | Value                      |
|-------------------------|----------------------------|
| Number of Channels      | 4                          |
| Control Voltage         | 5V DC (active-LOW input)   |
| Coil Current per Relay  | ~70–80 mA                  |
| Contact Rating          | 10A / 250V AC, 10A / 30V DC|
| Trigger Logic           | Active LOW                 |
| Isolation               | Optocoupler (EL817/PC817)  |
| Status Indicators       | 4 LEDs (one per channel)   |

**Role in this project:** Acts as the power switching interface between the 5V Arduino control signal and the 220V AC mains appliances, providing both control and electrical isolation.

---

### 7.4 Jumper Wires

- **Male-to-Male (M-M):** Used for breadboard connections.
- **Male-to-Female (M-F):** Used to connect module pins to breadboard rows.
- Standard 2.54mm pitch, 22–26 AWG, 10–20 cm length.

---

### 7.5 Power Supply

- **5V / 1A USB Power Adapter** or Arduino connected to PC via USB.
- For all 4 relays active simultaneously, the relay module draws up to 320 mA; the Arduino 5V pin can supply up to 500 mA when powered by a 1A adapter.
- A **separate 5V / 2A adapter** is recommended for stable operation in a permanent installation.

---

### 7.6 Electrical Appliances (Loads)

- **Incandescent Bulbs / CFLs:** Simple resistive/capacitive loads; easy to switch.
- **Ceiling Fans:** Inductive loads; may cause slight relay contact sparking. Use relay-rated for inductive loads if possible.
- **Maximum per relay:** 10A / 250V AC. Do not exceed this rating.
