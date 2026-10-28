#include "MoistureSensor.h"
#include "Pet.h"
#include "Display.h"

void setup() {
  Serial.begin(115200);
  setupMoistureSensor();
  setupDisplay();
}
void loop() {
  int raw = readMoistureRaw();
  MoistureLevel moisture = classifyMoisture(raw);
  PetMood mood = moodFromMoisture(moisture);
  Serial.print("Raw moisture: ");
  Serial.println(raw);
  drawPet(mood); // Serial placeholder until TFT is implemented.
  delay(1000);
}
