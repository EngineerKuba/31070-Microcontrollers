//#include "thingProperties.h"
#include <Timer5.h>

volatile float y_prev;
volatile float y_prev_prev;
volatile int Z_cross;
volatile int Timer;
volatile float Frequency;
//const int analog_read = A1;
//const int analog_write = A0;
const int sample_rate_read = 10000;  // set to 100 us

void setup() { // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1500); 
  //initProperties();
  // Connect to Arduino IoT Cloud
  //ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  //setDebugMessageLevel(2);
  //ArduinoCloud.printDebugInfo();
  analogReadResolution(10);   
  analogWriteResolution(10);
  MyTimer5.begin(sample_rate_read); // 200=for toggle every 5msec
  MyTimer5.attachInterrupt(readsignal); //Digital Pins=3 with Interrupts
}

void readsignal()
{
  //ArduinoCloud.update();
  float x = analogRead(A1);
  float y = 0.0278*x + (1-0.0278)*y_prev;

  if (y != y_prev){
    y_prev_prev = y_prev;
  }

  if (y >= 165.00 and y_prev_prev < 165.00){
    Z_cross++;}
    
  Timer++;
  y_prev = y;
}
// Wiring.c : C:\Users\Simon\Documents\ArduinoData\packages\arduino\hardware\samd\1.8.12\cores\arduino

void loop() {  
  if (((millis()/1000) & 0x01) == 0){
      if (Z_cross >= 300){
        Frequency = Z_cross/(Timer*0.00009158347);
        Timer = 0;
        Z_cross = 0;
        Serial.println(Frequency,3);
      }
    }
    else{
      //Serial.println("ArduinoCloud.update();");
      //ArduinoCloud.update();
    }
}

  
