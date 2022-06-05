/*
 * Digital hourglass, every set interval next led turns on. 
 * Once all leds are on buzzer will start alarm.
 * In order to reset the hourglass press button. 
 */

const int button = 10;
const int alarm = 12;
unsigned long prev_t = 0;
int switch_state = 0;
int led = 6;
long interval = 60000; //time new led turns on
int alarm_duration = 30;

void setup() {
  Serial.begin(9600);
  for (int x=6; x<10; x++){
    pinMode(x, OUTPUT);
  }
  pinMode(alarm, OUTPUT);
  digitalWrite(alarm, HIGH);
  pinMode(button, INPUT);
}

void loop() {
  unsigned long current_t = millis();
  if (current_t - prev_t > interval){
    prev_t = current_t;
    digitalWrite(led, HIGH);
    Serial.print("\nTurned LED on: ");
    Serial.print(led);
    if(led>=9){
      Serial.print("\nAlarm Beep! \n");
      digitalWrite(alarm, LOW);
      delay(alarm_duration);
      digitalWrite(alarm, HIGH);
    }
    led++;
  }
  switch_state = digitalRead(button);
  if (switch_state == 1){
    for (int x=6; x<10; x++){
      digitalWrite(x, LOW);
    }

    led = 6;
    prev_t = current_t;
  }
}
