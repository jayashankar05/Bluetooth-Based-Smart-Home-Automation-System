# Working Principle

## 4. Working Principle

### 4.1 System Overview

The Bluetooth Smart Home Automation System operates on the principle of **wireless serial communication** between a smartphone and an Arduino UNO microcontroller. The system uses the HC-05 Bluetooth module as a wireless UART bridge — it receives data over Bluetooth and passes it to the Arduino as regular serial bytes, and vice versa.

### 4.2 Step-by-Step Working

```
Step 1: Power ON
   └─► Arduino initialises → All relays set to OFF (HIGH)
   └─► HC-05 enters discoverable/slave mode (LED blinks fast)

Step 2: Bluetooth Pairing
   └─► User opens Bluetooth settings on smartphone
   └─► Scans and pairs with "HC-05" (PIN: 1234)
   └─► HC-05 LED blinks slowly → paired and connected

Step 3: Command Transmission
   └─► User opens Bluetooth terminal app on phone
   └─► Connects to HC-05
   └─► Types a command character (e.g., '1') and sends

Step 4: Wireless Data Transfer
   └─► Smartphone transmits ASCII character '1' over Bluetooth SPP
   └─► HC-05 receives the byte and forwards it to Arduino via UART (TXD → Pin 10)

Step 5: Arduino Command Processing
   └─► SoftwareSerial detects byte in receive buffer
   └─► bluetooth.read() extracts the character '1'
   └─► processCommand('1') is called
   └─► switch-case matches case '1'
   └─► digitalWrite(RELAY_1, LOW) is executed

Step 6: Relay Switching
   └─► Pin 2 goes LOW → Relay 1 coil energised
   └─► Relay contact closes (NO → COM)
   └─► 220V AC circuit completed → Appliance 1 turns ON

Step 7: Acknowledgement
   └─► Arduino sends "Appliance 1 ON" back over SoftwareSerial
   └─► HC-05 transmits response to smartphone
   └─► User sees confirmation in the Bluetooth terminal app
```

### 4.3 Bluetooth Communication (SPP Profile)

The HC-05 module uses the **Bluetooth Serial Port Profile (SPP)**, which emulates a wired RS-232 serial connection over a wireless Bluetooth link. From the Arduino's perspective, reading from or writing to the HC-05 is identical to reading from or writing to a wired serial port. This abstraction is what makes the HC-05 straightforward to use with Arduino's SoftwareSerial library.

| Parameter         | Value                     |
|-------------------|---------------------------|
| Bluetooth Version | 2.0 + EDR                 |
| Profile Used      | SPP (Serial Port Profile) |
| Frequency Band    | 2.4 GHz ISM               |
| Max Data Rate     | 3 Mbps (EDR)              |
| Effective Range   | ~10 m (Class 2)           |
| UART Baud Rate    | 9600 bps (default)        |

### 4.4 Relay Operation

A relay is an **electro-mechanical switch** controlled by a low-power signal:

```
Control Signal (5V DC)         AC Load Side
        │                           │
   Relay Coil                   COM ──── Live In
   (Energised)        ──────►   NO  ──── Appliance
        │                       NC  (unused)
       GND
```

- When the coil is energised (IN pin = LOW), the armature is attracted magnetically, closing the **NO (Normally Open)** contact.
- This connects the Live wire to the appliance, completing the AC circuit.
- The relay provides **electrical isolation** between the 5V Arduino circuit and the 220V AC load, ensuring safety.

### 4.5 SoftwareSerial vs Hardware Serial

| Feature            | Hardware Serial (UART) | SoftwareSerial          |
|--------------------|------------------------|-------------------------|
| Pins               | 0 (RX), 1 (TX)         | Any digital pins        |
| In this project    | Used for Serial Monitor| Used for HC-05          |
| Interrupt-driven   | Yes                    | Partial                 |
| Max reliable baud  | 115200+                | ~57600 (9600 used here) |
| Simultaneous use   | No (conflicts upload)  | Yes (while debug UART active) |
