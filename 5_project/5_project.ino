/*
 * Potentiometer is an input controlling the servo angle.
 */
#include <Servo.h>

Servo myServo;
const int pot_pin = A1;
const int servo_pin = 10;
int pot_val;
int angle;


void setup() {
  Serial.begin(9600);
  myServo.attach(servo_pin);
}

void loop() {
  pot_val = analogRead(pot_pin);
  
  Serial.print("Value: ");
  Serial.print(pot_val);
  
  angle = map(pot_val, 0, 1023, 0, 179);
  
  Serial.print(", Angle: ");
  Serial.print(angle);
  Serial.print("\n");

  myServo.write(angle);
  delay(20);
}
