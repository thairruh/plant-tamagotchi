#include "Pet.h"
PetMood moodFromMoisture(MoistureLevel level) {
  switch (level) {
    case MoistureLevel::DRY: return PetMood::THIRSTY;
    case MoistureLevel::HEALTHY: return PetMood::HAPPY;
    case MoistureLevel::TOO_WET: return PetMood::TOO_WET;
    default: return PetMood::UNKNOWN;
  }
}
const char* moodLabel(PetMood mood) {
  switch (mood) {
    case PetMood::THIRSTY: return "Thirsty";
    case PetMood::HAPPY: return "Happy";
    case PetMood::TOO_WET: return "Too wet";
    default: return "Not calibrated";
  }
}
