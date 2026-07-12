# Minor Project: USB and UART Serial Communication

This repository contains the complete implementation and documentation for the minor project assignment at the end of my first year, demonstrating serial communication over USB/UART using a microcontroller and a terminal emulator.

## Core Project Requirements Completed

### 1. Connect Hardware
- Connected the Raspberry Pi Pico development board directly to the host computer using a high-quality USB cable.

### 2. Install MiniCom
- Configured and deployed **MiniCom 2.9** inside the Ubuntu WSL2 environment to monitor the active serial port client.

### 3. Write Code
- Developed an embedded C++ program (`led_blink.ino`) that initializes serial communication on boot and handles asynchronous data packets.

### 4. Test Verification
- Successfully uploaded the executable binary to the microcontroller flash memory.
- Configured MiniCom to listen to the active system port (`/dev/ttyACM0`) at a baud rate of `115200`.
- Verified that the system transmits the initialization string **"Hello World"** immediately upon device startup/power-on.

---

## Optional Enhancements Met
- **Bidirectional Data Streams:** Expanded the core program to actively listen for, capture, and process incoming serial command data transmitted directly from the host computer's keyboard via MiniCom.
- **Robust Buffer Clearing:** Integrated a dedicated clearing loop (`while(Serial.available() > 0)`) to flush trailing carriage returns (`\r`) and hidden whitespace lines from the hardware UART stack, preventing command prompt loop duplication.

---

## Environment & Toolchain Details
- **Microcontroller:** Raspberry Pi Pico (RP2040)
- **Host Link:** Windows 11 `usbipd` network bridging layer attached to Ubuntu 22.04 LTS (WSL2)
- **Terminal Settings:** 115200 Baud, 8N1 Frame configuration
