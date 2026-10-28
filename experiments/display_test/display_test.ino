// First display experiment. Requires Adafruit GFX and Adafruit ST7735 libraries.
// Confirm your module's labels and voltage requirements before wiring.
// TFT CLK -> GPIO18; DIN -> GPIO23; CS -> GPIO5;
// D/C -> GPIO27; RST -> GPIO26; VCC -> 3V3; GND -> GND.
// BL (backlight) connection depends on your module: check its documentation.
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

const int TFT_CS = 5;
const int TFT_DC = 27;
const int TFT_RST = 26;
Adafruit_ST7735 tft(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  SPI.begin(18, 19, 23, TFT_CS); // SCK, MISO (unused), MOSI, SS
  tft.initR(INITR_BLACKTAB); // Try other init options if colors/offsets are wrong.
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(2);
  tft.setCursor(8, 30);
  tft.println("Hello!");
  tft.setCursor(8, 60);
  tft.println("Plant :)");
}
void loop() {}
