# Arduino LED Sequencer (Inline Assembly Version)

This project demonstrates controlling a sequence of 6 LEDs on an Arduino UNO, but with a twist: the core LED control logic is implemented using **inline AVR assembly language** within the Arduino C++ environment.

This is an evolution of a previous project that accomplished the same LED sequencing task purely in C++. About a month or two ago, it was all `digitalWrite()`. Now? Now we're talking directly to the metal!

## Diagram 
![Screenshot 2025-05-23 220140](https://github.com/user-attachments/assets/c61b55a0-0cf9-4128-8769-b7caee27be10)

![1](https://github.com/user-attachments/assets/5a97b115-87be-4f7e-8cf7-aadfb4e5d200)

## Features

*   Sequentially lights up 6 LEDs.
*   Utilizes inline AVR assembly for the primary LED control logic.
*   Demonstrates bit-shifting (`lsl`) in assembly to select which LED to illuminate.
*   Directly manipulates hardware I/O ports (`PORTB`) from assembly.
*   Shows how to pass data (the `counter` variable) from C++ to assembly.
*   Properly preserves and restores register states (`push`/`pop`) used by the assembly block.

## Hardware Requirements

*   Arduino UNO (or compatible)
*   6 x LEDs (any color)
*   6 x Current-limiting resistors (e.g., 220Ω - 330Ω, appropriate for your LEDs and 5V)
*   Breadboard
*   Jumper wires

## Wiring

As seen in the image, the LEDs are connected to Arduino digital pins 8 through 13. These pins correspond to PORTB (PB0 to PB5) on the ATmega328P microcontroller.

1.  **LED 1 (controlled by PB0/D8):** Connect Anode to Digital Pin 8 via a resistor. Cathode to GND.
2.  **LED 2 (controlled by PB1/D9):** Connect Anode to Digital Pin 9 via a resistor. Cathode to GND.
3.  **LED 3 (controlled by PB2/D10):** Connect Anode to Digital Pin 10 via a resistor. Cathode to GND.
4.  **LED 4 (controlled by PB3/D11):** Connect Anode to Digital Pin 11 via a resistor. Cathode to GND.
5.  **LED 5 (controlled by PB4/D12):** Connect Anode to Digital Pin 12 via a resistor. Cathode to GND.
6.  **LED 6 (controlled by PB5/D13):** Connect Anode to Digital Pin 13 via a resistor. Cathode to GND.

*Ensure all LED cathodes share a common ground with the Arduino.*

## Software Requirements

*   Arduino IDE
*   The AVR-GCC toolchain (this is included with the Arduino IDE)



