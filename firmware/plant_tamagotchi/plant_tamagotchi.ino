#include "MoistureSensor.h"
#include "Pet.h"
#include "Display.h"

void setup() {
  Serial.begin(115200);
  setupMoistureSensor();
  setupDisplay();
}

void loop() {
    static unsigned long lastSensorRead = 0;
    static PetMood currentMood;
    static bool firstRead = true;

    unsigned long now = millis();

    if (firstRead || now - lastSensorRead >= 1000) {
        int raw = readMoistureRaw();
        MoistureLevel moisture = classifyMoisture(raw);

        currentMood = moodFromMoisture(moisture);

        Serial.print("Raw moisture: ");
        Serial.println(raw);

        lastSensorRead = now;
        firstRead = false;
    }

    drawPet(currentMood);
}

