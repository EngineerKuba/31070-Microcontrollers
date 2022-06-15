/*
 * Create your own touch button using conductive material.
 * Take piece of aluminium foil.
 * Change in capacitance will allow you to read touches.
 */
#include <CapacitiveSensor.h>

// Create capacitive sensor instance
CapacitiveSensor cap_sens = CapacitiveSensor (6, 8);

const int led_pin = 10;
int threshold = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  long sens_val = cap_sens.capacitiveSensor(30);
  Serial.println(sens_val);

  if (sens_val > threshold){
    digitalWrite(led_pin, HIGH);
  }
  else {
    digitalWrite(led_pin, LOW);
  }
  delay(10);
}
