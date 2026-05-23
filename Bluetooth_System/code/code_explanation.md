# 📖 Code Explanation – Smart Home Automation

This document provides a section-by-section explanation of `smart_home_automation.ino`.

---

## 1. Library Inclusion

```cpp
#include <SoftwareSerial.h>
```

The **SoftwareSerial** library is a built-in Arduino library that emulates a UART serial port on any two digital pins. This frees up the hardware UART (pins 0 and 1) for Serial Monitor debugging, while pins 10 and 11 handle HC-05 communication.

---

## 2. Pin Definitions

```cpp
#define BT_RX_PIN  10
#define BT_TX_PIN  11
#define RELAY_1    2
#define RELAY_2    3
#define RELAY_3    4
#define RELAY_4    5
```

Using `#define` constants instead of hard-coded numbers makes the code easier to maintain. If the pin assignments change, only the `#define` lines need to be updated.

---

## 3. Active-LOW Relay Logic

```cpp
#define RELAY_ON   LOW
#define RELAY_OFF  HIGH
```

Most 5V relay modules use **active-LOW** logic:
- Writing `LOW` (0V) to the IN pin **energises the relay coil** → contact closes → appliance turns ON.
- Writing `HIGH` (5V) to the IN pin **de-energises the relay coil** → contact opens → appliance turns OFF.

Naming these as `RELAY_ON` and `RELAY_OFF` improves code readability.

---

## 4. SoftwareSerial Object

```cpp
SoftwareSerial bluetooth(BT_RX_PIN, BT_TX_PIN);
```

Creates a SoftwareSerial object named `bluetooth`. All communication with HC-05 goes through this object using `bluetooth.read()`, `bluetooth.print()`, and `bluetooth.println()`.

---

## 5. setup() Function

```cpp
void setup() {
  Serial.begin(9600);        // Hardware UART for Serial Monitor
  bluetooth.begin(9600);     // SoftwareSerial for HC-05
  pinMode(RELAY_1, OUTPUT);  // Configure relay pins as outputs
  ...
  allAppliancesOFF();        // Safe initial state
}
```

- **Serial.begin(9600)** – Starts hardware UART for debugging on the PC's Serial Monitor.
- **bluetooth.begin(9600)** – Starts SoftwareSerial at 9600 baud, matching HC-05's factory default.
- **pinMode(..., OUTPUT)** – Sets relay pins as digital outputs so we can write HIGH/LOW.
- **allAppliancesOFF()** – Ensures all relays start in the OFF state, preventing accidental appliance activation on power-up.

---

## 6. loop() Function

```cpp
void loop() {
  if (bluetooth.available() > 0) {
    receivedCommand = bluetooth.read();
    processCommand(receivedCommand);
  }
}
```

- **bluetooth.available()** – Returns the number of bytes waiting in the SoftwareSerial receive buffer.
- **bluetooth.read()** – Reads one byte (character) from the buffer.
- The received character is passed to `processCommand()` for interpretation.

---

## 7. processCommand() – Switch-Case Logic

```cpp
void processCommand(char cmd) {
  switch (cmd) {
    case '1': digitalWrite(RELAY_1, RELAY_ON);  break;
    case '5': digitalWrite(RELAY_1, RELAY_OFF); break;
    case 'A': allAppliancesON();                break;
    case 'Z': allAppliancesOFF();               break;
    default:  bluetooth.println("Unknown command."); break;
  }
}
```

A **switch-case** structure efficiently handles multiple possible command characters. The `default` case handles any unrecognised input gracefully by sending an error message back to the phone.

---

## 8. Helper Functions

```cpp
void allAppliancesON() {
  digitalWrite(RELAY_1, RELAY_ON);
  digitalWrite(RELAY_2, RELAY_ON);
  digitalWrite(RELAY_3, RELAY_ON);
  digitalWrite(RELAY_4, RELAY_ON);
}
```

Encapsulating repeated actions in helper functions keeps the `processCommand()` and `loop()` functions clean and readable. This is good software engineering practice even in embedded systems.

---

## 9. Key Arduino Functions Used

| Function                   | Description                                        |
|----------------------------|----------------------------------------------------|
| `Serial.begin(baud)`       | Initialises hardware UART                          |
| `SoftwareSerial(rx, tx)`   | Creates software serial port on any digital pins   |
| `bluetooth.begin(baud)`    | Starts SoftwareSerial at specified baud rate       |
| `bluetooth.available()`    | Checks if data is waiting in receive buffer        |
| `bluetooth.read()`         | Reads one byte from SoftwareSerial buffer          |
| `bluetooth.println(str)`   | Sends a string + newline over SoftwareSerial       |
| `pinMode(pin, mode)`       | Sets a pin as INPUT or OUTPUT                      |
| `digitalWrite(pin, value)` | Writes HIGH or LOW to a digital output pin         |
| `switch / case`            | Multi-branch conditional control flow              |

---

## 10. Memory Usage (Approximate)

| Resource      | Used      | Available (UNO) |
|---------------|-----------|-----------------|
| Flash (Program)| ~2.4 KB  | 32 KB            |
| SRAM (RAM)    | ~200 bytes | 2 KB            |
| EEPROM        | 0 bytes   | 1 KB             |

The sketch uses very little of the Arduino UNO's resources, leaving ample space for future enhancements like LCD display, sensor readings, or scheduling logic.
