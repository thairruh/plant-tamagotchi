#include <Arduino.h>
#include "Display.h"
// TODO: After display_test.ino works, move its initialization and drawing here.
// Temporary serial-only fallback lets the firmware compile without display libraries.
void setupDisplay() { Serial.println("Display not implemented yet"); }
void drawPet(PetMood mood) {
  Serial.print("Pet mood: ");
  Serial.println(moodLabel(mood));
}
