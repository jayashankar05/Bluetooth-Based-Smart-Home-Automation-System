# 🔌 Wiring Connections – Bluetooth Smart Home Automation

This document provides a complete pin-by-pin connection guide for assembling the circuit.

---

## 1. HC-05 Bluetooth Module → Arduino UNO

| HC-05 Pin | Arduino UNO Pin | Wire Colour (Suggested) | Notes                                               |
|-----------|-----------------|-------------------------|-----------------------------------------------------|
| VCC       | 5V              | Red                     | Powers the module                                   |
| GND       | GND             | Black                   | Common ground                                       |
| TXD       | Pin 10 (RX)     | Green                   | HC-05 transmits → Arduino receives                  |
| RXD       | Pin 11 (TX)     | Yellow                  | Arduino transmits → HC-05 receives (use 3.3V divider)|
| EN/KEY    | Not connected   | —                       | Leave floating for normal operation                 |
| STATE     | Not connected   | —                       | Optional; HIGH when connected                       |

> ⚠️ **Voltage Divider Warning:**  
> The HC-05 RXD pin operates at **3.3V logic**. The Arduino TX (Pin 11) outputs **5V**.  
> Use a resistor voltage divider between Arduino Pin 11 and HC-05 RXD:  
> - R1 = 1 kΩ (Arduino TX → junction)  
> - R2 = 2 kΩ (junction → GND)  
> - Junction → HC-05 RXD  
> Output at junction = 5V × (2k / (1k+2k)) ≈ **3.33V** ✅

---

## 2. 4-Channel Relay Module → Arduino UNO

| Relay Module Pin | Arduino UNO Pin | Wire Colour (Suggested) | Notes                                    |
|------------------|-----------------|-------------------------|------------------------------------------|
| IN1              | Pin 2           | Blue                    | Controls Relay 1 (Appliance 1)           |
| IN2              | Pin 3           | Purple                  | Controls Relay 2 (Appliance 2)           |
| IN3              | Pin 4           | Orange                  | Controls Relay 3 (Appliance 3)           |
| IN4              | Pin 5           | Brown                   | Controls Relay 4 (Appliance 4)           |
| VCC              | 5V              | Red                     | Powers relay coil driver circuit         |
| GND              | GND             | Black                   | Common ground                            |

> ℹ️ **Active-LOW Relay:**  
> Most 5V relay modules are **active-LOW**, meaning:  
> - Writing `LOW` (0V) to an IN pin **energises** the relay → appliance turns **ON**  
> - Writing `HIGH` (5V) to an IN pin **de-energises** the relay → appliance turns **OFF**

---

## 3. Relay Module → AC Appliances

Each relay channel has three terminals on the AC side:

| Relay Terminal | Description                        |
|----------------|------------------------------------|
| COM            | Common terminal (connect Live wire) |
| NO             | Normally Open – open when relay OFF |
| NC             | Normally Closed – closed when relay OFF |

**Standard Connection for switching appliances ON/OFF:**

```
AC Mains Live Wire ──── COM
                         |
                        NO ──── Appliance Live In
                        
AC Mains Neutral ──────────────── Appliance Neutral In
```

> 🔴 **Safety Warning:**  
> Work with AC mains wiring only if you are qualified or under supervision.  
> Always use proper insulated wires and ensure the circuit is powered OFF before making AC connections.  
> For testing, use low-voltage DC loads (LEDs, 5V motors) in place of AC appliances.

---

## 4. Power Supply

| Component        | Supply Voltage | Source                      |
|------------------|----------------|-----------------------------|
| Arduino UNO      | 5V (USB) / 7–12V (barrel jack) | USB from PC or DC adapter |
| HC-05 Module     | 5V             | From Arduino 5V pin         |
| Relay Module     | 5V             | From Arduino 5V pin         |
| AC Appliances    | 220V AC        | Mains supply (via relay)    |

> ℹ️ If driving all 4 relays simultaneously, ensure your 5V supply can deliver at least **500mA**. A powered USB hub or external 5V adapter is recommended.

---

## 5. Full Connection Summary (Quick Reference)

```
HC-05 VCC  ──────────────────────────────►  Arduino 5V
HC-05 GND  ──────────────────────────────►  Arduino GND
HC-05 TXD  ──────────────────────────────►  Arduino Pin 10
HC-05 RXD  ──── [Voltage Divider 1k+2k] ──►  Arduino Pin 11

Relay VCC  ──────────────────────────────►  Arduino 5V
Relay GND  ──────────────────────────────►  Arduino GND
Relay IN1  ──────────────────────────────►  Arduino Pin 2
Relay IN2  ──────────────────────────────►  Arduino Pin 3
Relay IN3  ──────────────────────────────►  Arduino Pin 4
Relay IN4  ──────────────────────────────►  Arduino Pin 5
```

---

*Refer to `circuit.png` for the visual schematic diagram.*
