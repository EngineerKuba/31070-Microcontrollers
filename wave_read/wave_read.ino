#include <Timer5.h>
volatile float x;
volatile float y;
volatile float y_prev;
volatile float y_prev_prev;
volatile float Frequency;
volatile int Z_cross;
volatile int Timer;

boolean toggle = false;
const int pin4 = 4;
const int pin5 = 5;
volatile int state = LOW;

//const float alpha = 0.0278; /* 50Hz = 0.02799, 10Hz = 0.00572, 100Hz = 0.05446*/
const int analog_read = A1;
const int analog_write = A0;
const int sample_rate_read = 10000;  // set to 100 us

void setup() { // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin4, OUTPUT); 
  pinMode(pin5, OUTPUT);
  MyTimer5.begin(sample_rate_read); // 200=for toggle every 5msec
  MyTimer5.attachInterrupt(readsignal); //Digital Pins=3 with Interrupts
  analogReadResolution(10);   
  analogWriteResolution(10);
  
}

void readsignal()
{
  //digitalWrite(pin5,HIGH);
  
  x = analogRead(analog_read);
  y = 0.0278*x + (1-0.0278)*y_prev;

  if (y != y_prev){
    y_prev_prev = y_prev;
  }

  if (y >= 165.00 and y_prev_prev < 165.00){
    Z_cross++;}
    
  Timer++;
  
  y_prev = y;
  //digitalWrite(pin5,LOW);
}
 
// Wiring.c : C:\Users\Simon\Documents\ArduinoData\packages\arduino\hardware\samd\1.8.12\cores\arduino

void loop() {  
  //digitalWrite(pin4,HIGH);
  //digitalWrite(pin4,LOW);
  analogWrite(A0, x);
  
  if (Z_cross >= 150){
    //Frequency = ((Z_cross)/((millis()-previous_ms)/1000));
    Frequency = Z_cross/(Timer*0.00009158347);
    Timer = 0;
    Z_cross = 0;
    Serial.println(Frequency,3);
    
  
    //previous_ms = millis();
    /*if (Frequency > 52.00){
      digitalWrite(ledPin4, LOW);}
    else{
      digitalWrite(ledPin4, HIGH);}
      
    if (Frequency < 48.00){
      digitalWrite(ledPin5, LOW);}
    else{
      digitalWrite(ledPin5, HIGH);}
    */
    }
  //Serial.println(y-y_prev_prev);
  

}
