// First sensor experiment: read raw analog values.
// Sensor VCC -> ESP32 3V3, GND -> GND, AOUT -> GPIO36.
// GPIO36 is input-only and supports ADC1 on the classic ESP32.
const int MOISTURE_PIN = 36;
void setup() {
  Serial.begin(115200);
  analogReadResolution(12); // usually 0–4095
}
void loop() {
  int reading = analogRead(MOISTURE_PIN);
  Serial.print("Raw moisture reading: ");
  Serial.println(reading);
  delay(1000);
}
