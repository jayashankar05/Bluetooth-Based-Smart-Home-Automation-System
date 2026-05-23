# Experimental Procedure

## 5. Experimental Procedure

### 5.1 Tools and Software Required

| Tool / Software         | Purpose                                      |
|-------------------------|----------------------------------------------|
| Arduino IDE 2.x         | Code writing, compilation, and upload        |
| Serial Monitor          | Debugging Arduino over USB                  |
| Serial Bluetooth Terminal (Android) | Sending commands to HC-05        |
| Multimeter              | Verifying voltages and continuity            |
| Soldering Iron (optional)| Permanent connections                       |
| Breadboard              | Temporary prototyping                        |

---

### 5.2 Step 1 – Gather Components

Verify availability of all components listed in `requirements/required_components.txt` before beginning assembly.

---

### 5.3 Step 2 – Assemble the Circuit on Breadboard

1. Place the Arduino UNO on the workbench.
2. Connect the **HC-05 module**:
   - HC-05 VCC → Arduino 5V
   - HC-05 GND → Arduino GND
   - HC-05 TXD → Arduino Pin 10 (direct wire)
   - HC-05 RXD → Arduino Pin 11 (via 1kΩ + 2kΩ voltage divider)
3. Connect the **4-Channel Relay Module**:
   - Relay VCC → Arduino 5V
   - Relay GND → Arduino GND
   - Relay IN1 → Arduino Pin 2
   - Relay IN2 → Arduino Pin 3
   - Relay IN3 → Arduino Pin 4
   - Relay IN4 → Arduino Pin 5
4. For initial testing, connect **LEDs with 220Ω resistors** to the relay NO terminals instead of AC appliances.

> ✅ Refer to `circuit-diagram/wiring_connections.md` for the complete pin table.

---

### 5.4 Step 3 – Install Arduino IDE and Upload Code

1. Download and install [Arduino IDE 2.x](https://www.arduino.cc/en/software).
2. Open `code/smart_home_automation.ino`.
3. **Disconnect HC-05 RX/TX wires** from Arduino pins 10 and 11 temporarily.
4. Connect Arduino UNO to PC via USB.
5. In Arduino IDE:
   - Tools → Board → **Arduino UNO**
   - Tools → Port → Select the correct **COM port**
6. Click the **Upload (→)** button.
7. Wait for "Done uploading" message.
8. **Reconnect HC-05** wires to pins 10 and 11.

---

### 5.5 Step 4 – Verify Initial State

1. Open **Serial Monitor** (Tools → Serial Monitor, Baud: 9600).
2. Power up the circuit.
3. Expected Serial Monitor output:
   ```
   === Smart Home Automation System ===
   Initialising...
   Bluetooth module ready at 9600 baud.
   All relays initialised to OFF.
   Waiting for Bluetooth commands...
   ```
4. Verify that all relay LEDs on the module are **OFF** (no coils energised).

---

### 5.6 Step 5 – Pair Smartphone with HC-05

1. Power on the circuit; the HC-05 LED should blink rapidly (searching mode).
2. On Android phone: **Settings → Bluetooth → Scan for devices**.
3. Select **HC-05** from the list.
4. Enter pairing PIN: **`1234`** (or `0000` if `1234` fails).
5. HC-05 LED changes to **slow blink** (paired, not yet connected).

---

### 5.7 Step 6 – Send Commands and Observe Results

1. Open **Serial Bluetooth Terminal** app.
2. Tap ☰ → **Devices** → select **HC-05** → Connect.
3. HC-05 LED becomes steady or blinks very slowly (connected).
4. Send the following test commands one at a time:

| Command Sent | Expected Relay Action    | Expected Serial Monitor Output  |
|--------------|--------------------------|---------------------------------|
| `1`          | Relay 1 clicks ON        | `>> Appliance 1 turned ON`      |
| `5`          | Relay 1 clicks OFF       | `>> Appliance 1 turned OFF`     |
| `A`          | All 4 relays click ON    | `>> ALL Appliances turned ON`   |
| `Z`          | All 4 relays click OFF   | `>> ALL Appliances turned OFF`  |
| `9`          | No relay changes         | `>> Unknown command: 9`         |

---

### 5.8 Step 7 – AC Appliance Testing

> ⚠️ **Perform this step only under supervision. Mains voltage (220V AC) is dangerous.**

1. Replace LED test loads with 220V bulbs.
2. Wire relay NO terminal → appliance Live wire.
3. Wire relay COM terminal → Mains Live wire.
4. Wire Mains Neutral directly to appliance Neutral.
5. Repeat the command tests from Step 6.
6. Verify each bulb lights up and extinguishes correctly.

---

### 5.9 Step 8 – Range Test

1. Keep the circuit powered at a fixed location.
2. Walk away with the paired smartphone, sending command `A` every metre.
3. Record the maximum distance at which commands are reliably executed.
4. Expected reliable range: **8–10 metres** in open space (may reduce through walls).

---

### 5.10 Observations Table

| Test No. | Command | Distance (m) | Relay Response | Response Time (approx.) |
|----------|---------|--------------|----------------|--------------------------|
| 1        | `1`     | 1            | ✅ ON           | < 200 ms                 |
| 2        | `5`     | 1            | ✅ OFF          | < 200 ms                 |
| 3        | `A`     | 5            | ✅ All ON       | < 300 ms                 |
| 4        | `Z`     | 5            | ✅ All OFF      | < 300 ms                 |
| 5        | `1`     | 10           | ✅ ON           | < 500 ms                 |
| 6        | `1`     | 12           | ❌ No response  | Timeout                  |
