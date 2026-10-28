#pragma once
#include "MoistureSensor.h"
enum class PetMood { UNKNOWN, THIRSTY, HAPPY, TOO_WET };
PetMood moodFromMoisture(MoistureLevel level);
const char* moodLabel(PetMood mood);
