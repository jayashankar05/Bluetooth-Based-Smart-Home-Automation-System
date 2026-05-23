# Pin Configuration

## 6. Pin Configuration

### 6.1 Arduino UNO Pin Map (ATmega328P)

```
                    ┌──────────────────┐
               NC   │  [ ]  D13        │ ← (unused / onboard LED)
              3.3V  │  [ ]  3.3V       │
               Ref  │  [ ]  AREF       │
               GND  │  [ ]  GND        │
               A0   │  [ ]  D12        │ ← (unused)
               A1   │  [ ]  D11/PWM   ─┼──────────► HC-05 RXD (via divider)
               A2   │  [ ]  D10/PWM   ─┼──────────► HC-05 TXD (direct)
               A3   │  [ ]  D9/PWM    │ ← (unused)
               A4   │  [ ]  D8        │ ← (unused)
               A5   │  [ ]  D7        │ ← (unused)
                    │  [ ]  D6/PWM    │ ← (unused)
                    │  [ ]  D5/PWM   ─┼──────────► Relay IN4
                    │  [ ]  D4       ─┼──────────► Relay IN3
                    │  [ ]  D3/PWM   ─┼──────────► Relay IN2
                    │  [ ]  D2       ─┼──────────► Relay IN1
                    │  [ ]  GND      ─┼──────────► HC-05 GND / Relay GND
                    │  [ ]  D1/TX     │ → Serial Monitor (USB)
                    │  [ ]  D0/RX     │ ← Serial Monitor (USB)
                    │                 │
                    │  [ ]  RESET     │
                    │  [ ]  3.3V      │
                    │  [ ]  5V       ─┼──────────► HC-05 VCC / Relay VCC
                    │  [ ]  GND       │
                    │  [ ]  GND       │
                    │  [ ]  VIN       │
                    └──────────────────┘
```

---

### 6.2 Arduino UNO Pin Assignment Table

| Arduino Pin | Direction | Connected To        | Signal             |
|-------------|-----------|---------------------|--------------------|
| 5V          | Output    | HC-05 VCC           | Power              |
| 5V          | Output    | Relay Module VCC    | Power              |
| GND         | Output    | HC-05 GND           | Ground             |
| GND         | Output    | Relay Module GND    | Ground             |
| Pin 2       | Output    | Relay IN1           | Appliance 1 control|
| Pin 3       | Output    | Relay IN2           | Appliance 2 control|
| Pin 4       | Output    | Relay IN3           | Appliance 3 control|
| Pin 5       | Output    | Relay IN4           | Appliance 4 control|
| Pin 10      | Input     | HC-05 TXD           | UART RX (BT data) |
| Pin 11      | Output    | HC-05 RXD (divider) | UART TX (BT data) |
| Pin 0 (RX)  | Input     | USB (via CH340/16U2)| Serial Monitor     |
| Pin 1 (TX)  | Output    | USB (via CH340/16U2)| Serial Monitor     |

---

### 6.3 HC-05 Bluetooth Module Pin Description

| Pin   | Name   | Function                                              |
|-------|--------|-------------------------------------------------------|
| 1     | STATE  | Indicates Bluetooth connection status (HIGH = connected)|
| 2     | RXD    | UART Receive – accepts 3.3V logic                     |
| 3     | TXD    | UART Transmit – outputs 3.3V logic                    |
| 4     | GND    | Ground reference                                      |
| 5     | VCC    | Power supply – 3.3V to 5V                             |
| 6     | EN/KEY | Enable pin for AT command mode (leave floating for data mode)|

> ⚠️ HC-05 RXD maximum input voltage = **3.3V**. Never apply 5V directly from Arduino TX without a voltage divider.

---

### 6.4 4-Channel Relay Module Pin Description

| Pin  | Name | Function                                                    |
|------|------|-------------------------------------------------------------|
| VCC  | VCC  | Module power supply – 5V                                    |
| GND  | GND  | Ground                                                      |
| IN1  | IN1  | Control input for Relay 1 (active LOW)                      |
| IN2  | IN2  | Control input for Relay 2 (active LOW)                      |
| IN3  | IN3  | Control input for Relay 3 (active LOW)                      |
| IN4  | IN4  | Control input for Relay 4 (active LOW)                      |

Each relay channel has three screw terminal outputs on the AC side:

| Terminal | Name | Description                              |
|----------|------|------------------------------------------|
| COM      | Common   | Always connected to the relay switch  |
| NO       | Normally Open  | Open when relay OFF, closed when ON|
| NC       | Normally Closed| Closed when relay OFF, open when ON |

---

### 6.5 Voltage Divider Calculation (Arduino TX → HC-05 RXD)

```
Arduino Pin 11 (5V) ─────┬───── R1 = 1kΩ ─────┐
                          │                     ├──── HC-05 RXD
                         GND ◄──── R2 = 2kΩ ───┘

Vout = Vin × R2 / (R1 + R2)
     = 5V  × 2000 / (1000 + 2000)
     = 5V  × 0.667
     = 3.33V  ✅ (within HC-05 3.3V logic tolerance)
```
