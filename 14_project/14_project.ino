/*
 * Control your PC with potentiometer and arduino.
 */

const int pot_pin = A1;

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.write(analogRead(pot_pin)/4);
  delay(1);
}
