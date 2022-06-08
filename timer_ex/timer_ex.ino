#include <Timer5.h>

String led_status="OFF";
const int yellow = 6;
const int red = 7;
int delay_t = 1000;
volatile int tick=0;

void setup() {
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  MyTimer5.begin(1000); // n_times/s
  MyTimer5.attachInterrupt(ClockTick); 
  Serial.begin(9600);  
}

void loop() {
  digitalWrite(yellow, HIGH);
  delay(delay_t);
  digitalWrite(yellow, LOW);
  delay(delay_t);
  Serial.println(tick);
}

void ClockTick(){
  tick++;
  if (tick % 500 == 0){
    BlinkLed();
  }
}

void BlinkLed(){
    if (led_status=="ON"){
    digitalWrite(red, LOW);
    led_status="OFF";
    return;
  }
  if (led_status=="OFF"){
    digitalWrite(red, HIGH);
    led_status="ON";
    return;
  }
}
