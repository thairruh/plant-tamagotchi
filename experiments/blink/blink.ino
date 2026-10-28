// Blink experiment. GPIO2 is commonly the onboard LED on ESP32 DevKit boards,
// but some boards use another pin or have no user LED.
const int LED_PIN = 2;
void setup() { pinMode(LED_PIN, OUTPUT); }
void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
