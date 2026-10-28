#include <Arduino.h>
#include "config.h"
#include "MoistureSensor.h"
void setupMoistureSensor() { analogReadResolution(12); }
int readMoistureRaw() { return analogRead(MOISTURE_PIN); }
MoistureLevel classifyMoisture(int rawValue) {
  // outputs plant state based on current moisture reading
  // thresholds decided using paper towels, can change once we get a plant
  
  if (rawValue >= 2400) {
    return MoistureLevel::DRY;
  }
  
  else if (rawValue < 1500 ) {
    return MoistureLevel::TOO_WET;
  }

  else {
    return MoistureLevel::HEALTHY;
    }

}
