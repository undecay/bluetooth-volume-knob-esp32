ESP32 Wireless BLE Volume Knob for iOS and Windows
This project turns a standard mechanical rotary encoder into a Bluetooth Low Energy (BLE) volume knob. It functions as a native wireless keyboard to control media across iOS, Android, Windows, and macOS.

//Features
  - Works natively as a Bluetooth HID device.
  - Optimized for iOS using explicit press and release states to ensure no dropped signals.
  - Software debouncing prevents double-triggering from noisy mechanical switches.
  - Uses the ESP32 internal pull-up resistors to minimize the physical wiring circuit.

//Hardware Required
  - ESP32 Development Board
  - EC11 Rotary Encoder with push switch
  - Breadboard and jumper wires
  - Micro-USB or USB-C cable for power
  - Breadboard

//Wiring Diagram (.kicad file included in repository)
  Rotary Encoder
  - CLK --> D22
  - DT --> D21
  - SW --> D19
  - GND --> - Power Rail
  - +/VCC --> + Power Rail
  ESP32
  - 3.3V --> + Power Rail
  - GND --> - Power Rail

//Software Setup
  - Open the Arduino IDE.
  - Install the ESP32 platform core via the Boards Manager if you haven't already.
  - Open the Library Manager, search for HijelHID_BLEKeyboard, and install it.
  - Open the project sketch file, select your ESP32 board and COM port under the Tools menu, and click Upload.

//Usage
  - Pair with your iPhone/Device using bluetooth  
