# Plant Tamagotchi 🌱
A beginner-friendly ESP32 project: a pixel pet that reacts to a real plant's soil moisture.

**Current progress:** We uploaded a Blink sketch to one ESP32. The sensor, display, and pet are **not yet tested**.

## Goal for November 13
1. Read moisture from a capacitive soil sensor.
2. Show a face on a 1.8-inch ST7735S TFT screen.
3. Change the face based on calibrated moisture readings.

Blinking and watering animations are stretch goals. Buttons, feeding, and other features come later, if time permits.

## Start here
1. Install [Arduino IDE](https://www.arduino.cc/en/software) and **esp32 by Espressif Systems** in Boards Manager. Add this URL in Arduino IDE Preferences → Additional Boards Manager URLs if needed: `https://espressif.github.io/arduino-esp32/package_esp32_index.json`.
2. Plug in your ESP32 using a **data-capable** Micro-USB cable. Choose **ESP32 Dev Module** and your serial port.
3. Open `experiments/blink/blink.ino` and upload it. If it doesn't blink, check your board's onboard LED pin (some boards have no user LED).
4. For sensor work, open `experiments/moisture_test/moisture_test.ino` (no extra libraries required).
5. For display work, install **Adafruit GFX Library** and **Adafruit ST7735 and ST7789 Library**, then open `experiments/display_test/display_test.ino`.
6. When each part works independently, open `firmware/plant_tamagotchi/plant_tamagotchi.ino` to begin integration.

## Who works on what?
- **Moisture:** `experiments/moisture_test/`, then `MoistureSensor.h/.cpp`; record readings in `docs/moisture-calibration.md`.
- **Display:** `experiments/display_test/`, then `Display.h/.cpp`; confirm pin labels and screen tab/init settings.
- **Art / pet logic:** `assets/sprites/`, then `Pet.h/.cpp`; draw simple faces and decide which mood corresponds to which reading.
- **Integration:** `firmware/plant_tamagotchi/plant_tamagotchi.ino` after individual tests succeed.

See [CONTRIBUTING.md](CONTRIBUTING.md) for a simple Git workflow and [docs/wiring.md](docs/wiring.md) before connecting hardware.

## Hardware
- ESP-WROOM-32 development board
- Capacitive soil moisture sensor v1.2
- 1.8-inch ST7735S 128×160 SPI TFT
- Jumper wires, breadboard, USB cable

**Safety:** ESP32 GPIO is **3.3V logic**. Power the sensor and compatible TFT from 3V3, not VIN/5V; disconnect USB before changing wiring. Keep exposed electronics dry.
