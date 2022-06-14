#include <Timer5.h>
volatile float x;
volatile float y;
volatile float y_prev;
volatile float y_prev_prev;
volatile float Frequency;
volatile int Z_cross;
volatile int Timer;
volatile int previous_ms = 0;

const float alpha = 0.0278; /* 50Hz = 0.02799, 10Hz = 0.00572, 100Hz = 0.05446*/
const int analog_read = A1;
const int analog_write = A0;
const int sample_rate_read = 10000;  // set to 100 us



void setup() { // put your setup code here, to run once:
  MyTimer5.begin(sample_rate_read); // 200=for toggle every 5msec
  MyTimer5.attachInterrupt(readsignal); //Digital Pins=3 with Interrupts
  analogReadResolution(10);   
  analogWriteResolution(10);
  Serial.begin(9600);
}

void readsignal()
{
  if (y >= 170.00 and y_prev_prev < 170.00){
    Z_cross++;}
  if (y_prev_prev >= 170.00 and y < 170.00){
    Z_cross++;
  }
  Timer++;
}
 
// Wiring.c : C:\Users\Simon\Documents\ArduinoData\packages\arduino\hardware\samd\1.8.12\cores\arduino

void loop() {  
  x = analogRead(analog_read);
  y = alpha*x + (1-alpha)*y_prev;
  
  if (y != y_prev){
    y_prev_prev = y_prev;
  }
  
  y_prev = y;
  
  if (Z_cross >= 100){
    //Frequency = ((Z_cross)/((millis()-previous_ms)/1000));
    Frequency = Z_cross/(Timer*0.00009158*1.0005);
    Timer = 0;
    Z_cross = 0;
    //previous_ms = millis();
    Serial.println(Frequency);
    }
    
  analogWrite(A0, x);
}
