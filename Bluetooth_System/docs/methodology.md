# Methodology

## 3. Methodology

### 3.1 System Design Approach

The project follows a **bottom-up embedded system design methodology**:

```
Requirements Analysis
        ↓
Component Selection
        ↓
Circuit Design & Simulation
        ↓
Hardware Assembly
        ↓
Firmware Development
        ↓
Integration & Testing
        ↓
Documentation
```

### 3.2 Requirements Analysis

| Requirement             | Specification                          |
|-------------------------|----------------------------------------|
| Communication Protocol  | Bluetooth (Wireless, no internet)      |
| Number of Appliances    | 4 (expandable)                         |
| Control Interface       | Smartphone (Android)                  |
| Microcontroller         | Arduino UNO (ATmega328P)              |
| Operating Voltage       | 5V DC (logic), 220V AC (appliances)   |
| Communication Range     | Minimum 5 metres (target: 10 metres)  |
| Cost Constraint         | Under ₹1,500                          |

### 3.3 Component Selection Rationale

| Component        | Reason for Selection                                              |
|------------------|-------------------------------------------------------------------|
| Arduino UNO      | Widely available, easy to program, 5V GPIO, 14 digital pins      |
| HC-05            | Low cost, proven Bluetooth SPP (Serial Port Profile), 9600 baud  |
| 4-CH Relay Module| Optocoupler isolated, handles 220V/10A, active-LOW, plug-and-play|
| SoftwareSerial   | Reserves hardware UART for Serial Monitor debugging              |

### 3.4 Communication Protocol Design

The system uses a simple **single-character ASCII command protocol** over Bluetooth SPP (Serial Port Profile):

- Commands are **single printable ASCII characters** ('1'–'8', 'A', 'Z').
- Single-byte commands minimise transmission latency.
- The Arduino echoes a **text acknowledgement** back to the phone.
- No handshaking or error-correction protocol is implemented (suitable for short-range, low-noise environments).

### 3.5 Firmware Development Process

1. **Initialisation:** Configure serial ports and set all relay pins to output HIGH (OFF state).
2. **Polling Loop:** Continuously check the SoftwareSerial buffer for incoming bytes.
3. **Command Parsing:** Use a switch-case structure to map received characters to relay actions.
4. **Output Control:** Use `digitalWrite()` to toggle relay control pins.
5. **Feedback:** Send acknowledgement strings back over Bluetooth.

### 3.6 Testing Strategy

| Test Phase        | Test Description                                              | Pass Criteria             |
|-------------------|---------------------------------------------------------------|---------------------------|
| Bench Test        | Connect Arduino to PC, send commands via Serial Monitor       | Relay clicks audibly       |
| Bluetooth Test    | Pair phone with HC-05, send commands via app                  | Relay responds correctly   |
| Range Test        | Gradually increase distance between phone and HC-05           | Reliable at 10 metres      |
| AC Appliance Test | Connect 220V bulb via relay, verify ON/OFF switching          | Bulb responds to commands  |
| Stress Test       | Send rapid successive commands                                | No missed or latched relay |
