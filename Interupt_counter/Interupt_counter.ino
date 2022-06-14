#include <Timer5.h>
#include <filters.h>

volatile float input_sig;
volatile float x = 0.0;
volatile float y = 0.0;
volatile float y_prev = 0.0;
volatile int count = 0;

const int analog_read = A1;
const float alpha = 0.0279; /* 50Hz = 0.03049, 10Hz = 0.00625, 100Hz = 0.05917*/
const int analog_write = A0;
const int sample_rate=10000;  // set to 100 us


void setup() { // put your setup code here, to run once:
  MyTimer5.begin(sample_rate); // 200=for toggle every 5msec
  MyTimer5.attachInterrupt(readsignal); //Digital Pins=3 with Interrupts
  Serial.begin(9600);
}

void readsignal()
{
  count = count+1;
}
// Wiring.c : C:\Users\Simon\Documents\ArduinoData\packages\arduino\hardware\samd\1.8.12\cores\arduino

void loop() {
  Serial.println(count);
  count = 0;
  delay(1000);

}
