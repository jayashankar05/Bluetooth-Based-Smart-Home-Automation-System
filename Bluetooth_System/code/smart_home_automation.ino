/*
 * ============================================================
 *   Bluetooth Based Smart Home Automation System
 * ============================================================
 *   Platform    : Arduino UNO (ATmega328P)
 *   Language    : C/C++ (Arduino Framework)
 *   Module      : HC-05 Bluetooth Module (Slave Mode)
 *   Relay       : 4-Channel Relay Module (Active-LOW, 5V)
 *   IDE Version : Arduino IDE 2.x
 *   Author      : B.Tech ECE Mini Project
 *   Date        : 2024
 * ============================================================
 *
 *   DESCRIPTION:
 *   This sketch receives single-character commands from a
 *   smartphone over Bluetooth (via HC-05) and toggles
 *   four relay channels to control AC appliances.
 *
 *   COMMAND TABLE:
 *   '1' → Appliance 1 ON    '5' → Appliance 1 OFF
 *   '2' → Appliance 2 ON    '6' → Appliance 2 OFF
 *   '3' → Appliance 3 ON    '7' → Appliance 3 OFF
 *   '4' → Appliance 4 ON    '8' → Appliance 4 OFF
 *   'A' → ALL ON            'Z' → ALL OFF
 *
 *   PIN CONNECTIONS:
 *   HC-05 TXD → Arduino Pin 10  (SoftwareSerial RX)
 *   HC-05 RXD → Arduino Pin 11  (SoftwareSerial TX) [via voltage divider]
 *   Relay IN1 → Arduino Pin 2
 *   Relay IN2 → Arduino Pin 3
 *   Relay IN3 → Arduino Pin 4
 *   Relay IN4 → Arduino Pin 5
 * ============================================================
 */

// -------------------------------------------------------
// Include Libraries
// -------------------------------------------------------
#include <SoftwareSerial.h>
// SoftwareSerial allows us to use digital pins 10 and 11
// as a secondary UART port for communicating with HC-05,
// keeping the hardware UART (pins 0 & 1) free for debugging.

// -------------------------------------------------------
// Pin Definitions
// -------------------------------------------------------

// SoftwareSerial pins for HC-05 communication
#define BT_RX_PIN  10   // Arduino receives data from HC-05 TXD
#define BT_TX_PIN  11   // Arduino sends data to HC-05 RXD

// Relay control pins (active-LOW relay module)
#define RELAY_1    2    // Controls Appliance 1 (e.g., Living Room Light)
#define RELAY_2    3    // Controls Appliance 2 (e.g., Bedroom Light)
#define RELAY_3    4    // Controls Appliance 3 (e.g., Fan)
#define RELAY_4    5    // Controls Appliance 4 (e.g., TV / Socket)

// -------------------------------------------------------
// Constants
// -------------------------------------------------------
#define RELAY_ON   LOW   // Active-LOW: LOW energises the relay
#define RELAY_OFF  HIGH  // HIGH de-energises the relay
#define BT_BAUD    9600  // HC-05 default baud rate

// -------------------------------------------------------
// Object Instantiation
// -------------------------------------------------------

// Create a SoftwareSerial object named 'bluetooth'
// Parameters: (RX pin, TX pin)
SoftwareSerial bluetooth(BT_RX_PIN, BT_TX_PIN);

// Variable to store the received Bluetooth command character
char receivedCommand;

// -------------------------------------------------------
// setup() – Runs once at power-on or reset
// -------------------------------------------------------
void setup() {

  // Initialise hardware Serial for debugging (Serial Monitor)
  Serial.begin(9600);
  Serial.println("=== Smart Home Automation System ===");
  Serial.println("Initialising...");

  // Initialise SoftwareSerial for HC-05 Bluetooth communication
  bluetooth.begin(BT_BAUD);
  Serial.println("Bluetooth module ready at 9600 baud.");

  // Configure relay pins as digital OUTPUT
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);

  // Set all relays to OFF state initially
  // (Active-LOW: HIGH = OFF)
  allAppliancesOFF();

  Serial.println("All relays initialised to OFF.");
  Serial.println("Waiting for Bluetooth commands...");
  Serial.println("-------------------------------------");
}

// -------------------------------------------------------
// loop() – Runs continuously after setup()
// -------------------------------------------------------
void loop() {

  // Check if any data has arrived from the Bluetooth module
  if (bluetooth.available() > 0) {

    // Read one character from the Bluetooth serial buffer
    receivedCommand = bluetooth.read();

    // Echo the received command to Serial Monitor for debugging
    Serial.print("Command received: ");
    Serial.println(receivedCommand);

    // Process the received command
    processCommand(receivedCommand);
  }
}

// -------------------------------------------------------
// processCommand() – Interprets and acts on a command
// -------------------------------------------------------
void processCommand(char cmd) {

  switch (cmd) {

    // --- Individual Appliance ON Commands ---
    case '1':
      digitalWrite(RELAY_1, RELAY_ON);
      Serial.println(">> Appliance 1 turned ON");
      bluetooth.println("Appliance 1 ON");
      break;

    case '2':
      digitalWrite(RELAY_2, RELAY_ON);
      Serial.println(">> Appliance 2 turned ON");
      bluetooth.println("Appliance 2 ON");
      break;

    case '3':
      digitalWrite(RELAY_3, RELAY_ON);
      Serial.println(">> Appliance 3 turned ON");
      bluetooth.println("Appliance 3 ON");
      break;

    case '4':
      digitalWrite(RELAY_4, RELAY_ON);
      Serial.println(">> Appliance 4 turned ON");
      bluetooth.println("Appliance 4 ON");
      break;

    // --- Individual Appliance OFF Commands ---
    case '5':
      digitalWrite(RELAY_1, RELAY_OFF);
      Serial.println(">> Appliance 1 turned OFF");
      bluetooth.println("Appliance 1 OFF");
      break;

    case '6':
      digitalWrite(RELAY_2, RELAY_OFF);
      Serial.println(">> Appliance 2 turned OFF");
      bluetooth.println("Appliance 2 OFF");
      break;

    case '7':
      digitalWrite(RELAY_3, RELAY_OFF);
      Serial.println(">> Appliance 3 turned OFF");
      bluetooth.println("Appliance 3 OFF");
      break;

    case '8':
      digitalWrite(RELAY_4, RELAY_OFF);
      Serial.println(">> Appliance 4 turned OFF");
      bluetooth.println("Appliance 4 OFF");
      break;

    // --- All Appliances ON ---
    case 'A':
    case 'a':
      allAppliancesON();
      Serial.println(">> ALL Appliances turned ON");
      bluetooth.println("ALL Appliances ON");
      break;

    // --- All Appliances OFF ---
    case 'Z':
    case 'z':
      allAppliancesOFF();
      Serial.println(">> ALL Appliances turned OFF");
      bluetooth.println("ALL Appliances OFF");
      break;

    // --- Unknown Command ---
    default:
      Serial.print(">> Unknown command: ");
      Serial.println(cmd);
      bluetooth.println("Unknown command. Use 1-8, A, or Z.");
      break;
  }
}

// -------------------------------------------------------
// allAppliancesON() – Turns all 4 relays ON
// -------------------------------------------------------
void allAppliancesON() {
  digitalWrite(RELAY_1, RELAY_ON);
  digitalWrite(RELAY_2, RELAY_ON);
  digitalWrite(RELAY_3, RELAY_ON);
  digitalWrite(RELAY_4, RELAY_ON);
}

// -------------------------------------------------------
// allAppliancesOFF() – Turns all 4 relays OFF
// -------------------------------------------------------
void allAppliancesOFF() {
  digitalWrite(RELAY_1, RELAY_OFF);
  digitalWrite(RELAY_2, RELAY_OFF);
  digitalWrite(RELAY_3, RELAY_OFF);
  digitalWrite(RELAY_4, RELAY_OFF);
}

/*
 * ============================================================
 *   END OF CODE
 * ============================================================
 *   Notes:
 *   - Disconnect HC-05 TX/RX wires before uploading code,
 *     as SoftwareSerial may conflict with upload process.
 *   - Re-connect after successful upload.
 *   - Open Serial Monitor at 9600 baud to view debug output.
 *   - Use "Serial Bluetooth Terminal" app on Android for testing.
 * ============================================================
 */
