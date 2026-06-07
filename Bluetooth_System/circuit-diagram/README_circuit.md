# Circuit Diagrams – Placeholder Guide

This folder contains circuit schematics and diagrams for the project.

## Files in This Folder

| Filename                 | Description                                                        | Status    |
|--------------------------|--------------------------------------------------------------------|-----------|
| `circuit.png`            | Full schematic diagram showing all component connections           | See below |
| `block_diagram.png`      | High-level system block diagram                                    | See below |
| `wiring_connections.md`  | Detailed text-based pin connection table                           | ✅ Done    |

---

## How to Create circuit.png

Use any of the following free tools:

### Option 1 – Fritzing (Recommended for Arduino projects)
- Download: https://fritzing.org/
- Create a breadboard view showing Arduino, HC-05, and relay module.
- Export as PNG at 150+ DPI.
- Save as `circuit.png` in this folder.

### Option 2 – Tinkercad Circuits (Online, Free)
- Visit: https://www.tinkercad.com/circuits
- Search for Arduino UNO, HC-05, and relay components.
- Wire them up and take a screenshot.
- Save as `circuit.png`.

### Option 3 – KiCad (Professional Schematic)
- Download: https://www.kicad.org/
- Draw a proper schematic with component symbols.
- Export as PNG or PDF.

---

## Schematic Description (Text Reference)

Until images are added, the circuit follows this connection scheme:

```
                    ARDUINO UNO
                   ┌────────────┐
         5V ───────┤ 5V         │
        GND ───────┤ GND        │
                   │            │
  HC-05 TXD ───────┤ D10 (RX)   │
  HC-05 RXD ──┬────┤ D11 (TX)   │
              │    │            │
            [1kΩ]  │ D2 ────────┼──── Relay IN1
              │    │ D3 ────────┼──── Relay IN2
            [2kΩ]  │ D4 ────────┼──── Relay IN3
              │    │ D5 ────────┼──── Relay IN4
             GND   └────────────┘
```

---

## block_diagram.png Description

The block diagram shows:

```
[Smartphone] ──BT──► [HC-05] ──UART──► [Arduino UNO] ──GPIO──► [Relay Module] ──AC──► [Appliances]
                                              │
                                         [Power Supply]
```

Draw this in **draw.io** (https://draw.io), **Canva**, **PowerPoint**, or **Google Slides** and export as PNG.
