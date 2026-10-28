# Wiring notes (classic ESP32-WROOM-32 DevKit)

**Disconnect USB before changing connections. ESP32 GPIO pins are 3.3V logic.**

## Capacitive moisture sensor v1.2
| Sensor | ESP32 | Why |
|---|---|---|
| VCC | 3V3 | Safe 3.3V supply |
| GND | GND | Common ground |
| AOUT | GPIO36 | Analog input (ADC1) |

Do **not** use VIN/5V for this sensor setup. Keep the connector and exposed electronics dry. Test first with a slightly damp paper towel touching only the sensing section; calibrate later using actual soil.

## ST7735S TFT (verify module pin labels)
| TFT | ESP32 |
|---|---|
| VCC | 3V3 |
| GND | GND |
| CLK | GPIO18 |
| DIN | GPIO23 |
| CS | GPIO5 |
| D/C | GPIO27 |
| RST | GPIO26 |
| BL | Follow your module's backlight instructions (often 3V3) |

This is a proposed SPI pin map, not a verified wiring diagram for your exact module. Never apply 5V logic to ESP32 pins.
