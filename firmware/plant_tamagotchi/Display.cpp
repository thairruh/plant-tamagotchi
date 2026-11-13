
#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#include "Display.h"
#include "config.h"
#include "plant_animations.h"

Adafruit_ST7735 tft = Adafruit_ST7735(
    TFT_CS_PIN,
    TFT_DC_PIN,
    TFT_RST_PIN
);

void setupDisplay() {
    tft.initR(INITR_BLACKTAB);
    tft.setRotation(0);  // Portrait

    tft.fillScreen(ST77XX_WHITE);

    Serial.println("Display initialized!");
}


void drawPet(PetMood mood) {
    static PetMood previousMood = PetMood::UNKNOWN;
    static int currentFrame = 0;
    static unsigned long lastFrameTime = 0;

    const uint16_t* const* frames;
    unsigned long frameDelay;

    // Select animation based on moisture
    switch (mood) {
        case PetMood::HAPPY:
            frames = plant_happy_frames;
            frameDelay = plant_happy_frame_ms;
            break;

        case PetMood::THIRSTY:
            frames = plant_thirsty_frames;
            frameDelay = plant_thirsty_frame_ms;
            break;

        case PetMood::TOO_WET:
            frames = plant_too_wet_frames;
            frameDelay = plant_too_wet_frame_ms;
            break;

        default:
            tft.fillScreen(ST77XX_WHITE);
            tft.setTextColor(ST77XX_BLACK);
            tft.setTextSize(2);
            tft.setCursor(10, 60);
            tft.print("Unknown");
            previousMood = PetMood::UNKNOWN;
            return;
    }

    unsigned long now = millis();

    // Reset animation when mood changes
    if (mood != previousMood) {
        currentFrame = 0;
        lastFrameTime = now;
        previousMood = mood;

        tft.drawRGBBitmap(
            0, 0,
            frames[currentFrame],
            PLANT_SPRITE_WIDTH,
            PLANT_SPRITE_HEIGHT
        );

        return;
    }

    // Advance animation when enough time passes
    if (now - lastFrameTime >= frameDelay) {
        currentFrame = (currentFrame + 1) % 2;

        tft.drawRGBBitmap(
            0, 0,
            frames[currentFrame],
            PLANT_SPRITE_WIDTH,
            PLANT_SPRITE_HEIGHT
        );

        lastFrameTime = now;
    }
}
