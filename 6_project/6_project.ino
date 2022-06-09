/*
 * Time to make some noise! 
 * Regulate the tone of the buzzer based on light conditions.
 * Wave your hands around and create unique music.
 */
const int led_pin = 6;
const int light_sens = A1;

int sens_val = 0;
int sens_low = 1023;
int sens_high = 0;

void setup() {
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, HIGH);

  // calibrating the sensor max and min values
  while (millis() < 5000){
    sens_val = analogRead(light_sens);
    if (sens_val > sens_high) {
      sens_high = sens_val;
    }
    if (sens_val < sens_low) {
      sens_low = sens_val;
    }
  }
  digitalWrite(led_pin, LOW);
}

void loop() {
  sens_val = analogRead(light_sens);
  int pitch = map(sens_val, sens_low, sens_high, 50, 4000);
  tone(8, pitch, 20);
  delay(10);
}
