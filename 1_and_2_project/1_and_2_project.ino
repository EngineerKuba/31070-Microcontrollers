/*
 * Program that controls 3 LEDs.
 * While button pressed red_1 and red_2 are blinking. And green is off.
 * If button not pressed red LEDs off and green one constantly on.
 */
const int green=6;
const int red_1=7;
const int red_2=8;
const int button=10;
int state=0;
int ON=200;
int OFF=200;

void setup() {
pinMode(green, OUTPUT);
pinMode(red_1, OUTPUT);
pinMode(red_2, OUTPUT);
pinMode(button, INPUT);
}

void loop() {
state = digitalRead(button);
if (state==0){
  digitalWrite(green,HIGH);
  digitalWrite(red_1,LOW);
  digitalWrite(red_2,LOW);
  }
else{
  digitalWrite(green,LOW);
  digitalWrite(red_1,HIGH);
  digitalWrite(red_2,LOW);
  delay(ON);
  digitalWrite(red_1,LOW);
  digitalWrite(red_2,HIGH);
  delay(OFF);
  }
}
