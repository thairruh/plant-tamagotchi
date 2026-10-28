#pragma once
// Moisture values are not calibrated yet.
enum class MoistureLevel { UNKNOWN, DRY, HEALTHY, TOO_WET };
void setupMoistureSensor();
int readMoistureRaw();
MoistureLevel classifyMoisture(int rawValue);
