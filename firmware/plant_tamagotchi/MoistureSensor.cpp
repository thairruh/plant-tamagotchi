#include <Arduino.h>
#include "config.h"
#include "MoistureSensor.h"
void setupMoistureSensor() { analogReadResolution(12); }
int readMoistureRaw() { return analogRead(MOISTURE_PIN); }
MoistureLevel classifyMoisture(int rawValue) {
  // TODO: Replace after measuring dry/healthy/wet SOIL readings.
  // Don't guess thresholds or assume the reading direction.
  (void)rawValue;
  return MoistureLevel::UNKNOWN;
}
