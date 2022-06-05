void ledOn(int LED){
  digitalWrite(LED, HIGH);
}

void ledOff(int LED){
  digitalWrite(LED, LOW);
}

void ledBlink(int LED, int blink_speed){
  ledOn(LED);
  delay(blink_speed);
  ledOff(LED);
  delay(blink_speed);
}
