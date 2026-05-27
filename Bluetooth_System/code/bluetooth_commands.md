# 📡 Bluetooth Command Reference Sheet

## HC-05 Module Default Settings

| Parameter        | Value          |
|------------------|----------------|
| Default Name     | HC-05          |
| Default PIN/Code | 1234 (or 0000) |
| Baud Rate        | 9600           |
| Mode             | Slave          |
| Frequency        | 2.4 GHz ISM    |

---

## Command Table

| Command | Action              | Relay Pin | Status LED (if added) |
|---------|---------------------|-----------|-----------------------|
| `1`     | Appliance 1 ON      | Pin 2 LOW | ON                    |
| `2`     | Appliance 2 ON      | Pin 3 LOW | ON                    |
| `3`     | Appliance 3 ON      | Pin 4 LOW | ON                    |
| `4`     | Appliance 4 ON      | Pin 5 LOW | ON                    |
| `5`     | Appliance 1 OFF     | Pin 2 HIGH| OFF                   |
| `6`     | Appliance 2 OFF     | Pin 3 HIGH| OFF                   |
| `7`     | Appliance 3 OFF     | Pin 4 HIGH| OFF                   |
| `8`     | Appliance 4 OFF     | Pin 5 HIGH| OFF                   |
| `A`     | ALL Appliances ON   | All LOW   | All ON                |
| `Z`     | ALL Appliances OFF  | All HIGH  | All OFF               |

> Commands are **case-insensitive** for `A` and `Z` (both `a`/`A` and `z`/`Z` are accepted).

---

## Recommended Android Apps

| App Name                   | Play Store | Notes                             |
|----------------------------|------------|-----------------------------------|
| Serial Bluetooth Terminal  | Free       | Best for raw character commands   |
| Bluetooth Terminal HC-05   | Free       | Simple and lightweight            |
| MIT App Inventor App       | Custom     | Build your own button-based UI    |
| Arduino Bluetooth Control  | Free       | Pre-built relay/switch interface  |

---

## How to Send Commands (Serial Bluetooth Terminal)

1. Install **Serial Bluetooth Terminal** from Google Play Store.
2. Open app → tap the **menu icon (☰)** → **Devices**.
3. Select **HC-05** from paired devices list.
4. In the terminal, type a command (e.g., `1`) and press **Send**.
5. The Arduino will respond with a confirmation message.

---

## Serial Monitor Debug Output (Arduino IDE)code dummping

When a command is received, the Serial Monitor (9600 baud) displays:

```
=== Smart Home Automation System ===
Initialising...
Bluetooth module ready at 9600 baud.
All relays initialised to OFF.
Waiting for Bluetooth commands...
-------------------------------------
Command received: 1
>> Appliance 1 turned ON
Command received: A
>> ALL Appliances turned ON
Command received: Z
>> ALL Appliances turned OFF
```

---

## Troubleshooting

| Problem                          | Possible Cause                    | Solution                                      |
|----------------------------------|-----------------------------------|-----------------------------------------------|
| HC-05 not visible during scan    | Module not powered                | Check VCC and GND connections                 |
| Paired but no command response   | Baud rate mismatch                | Ensure both Arduino & app use 9600 baud       |
| Relay clicks but appliance off   | NO/NC terminal wrong              | Use NO (Normally Open) terminal               |
| Upload fails with HC-05 connected| SoftwareSerial conflict           | Disconnect HC-05 RX/TX before uploading       |
| All relays ON at power-up        | Active-LOW default state issue    | Check `allAppliancesOFF()` in `setup()`       |
| Commands sent but relay no response | Wrong relay IN pin number      | Verify pin numbers in `#define` section       |
