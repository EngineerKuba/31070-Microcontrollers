#include <Timer5.h>

volatile float x;
volatile float y;
volatile float y_prev;
volatile float y_prev_prev;
volatile float Frequency;
volatile int Z_cross;
volatile int ISR_count;
volatile int previous_ms = 0;

float alpha;

const int analog_read = A1;
const int analog_write = A0;
const int sample_rate = 10000;  // set to 100 us
const int sample_rate_real = 10927; // myTimer in reality makes 10927 not 10000
const int cut_off_freq = 50;

void setup() {
  MyTimer5.begin(sample_rate);
  MyTimer5.attachInterrupt(readsignal); //Digital Pins=3 with Interrupts
  analogReadResolution(10);   
  analogWriteResolution(10);
  Serial.begin(115200);
  lcdInit(); // set pins for the screen
  alpha = getAlpha(sample_rate_real, cut_off_freq); // for low pass filter 
}

void readsignal()
{
  if (y >= 170.00 and y_prev_prev < 170.00){
    Z_cross++;}

  ISR_count++;
}

void loop() {  
  x = analogRead(analog_read); 
  y = lowPassFilter(x, alpha);
  
  if (y != y_prev){
    y_prev_prev = y_prev;
  }
  
  y_prev = y;
  
  if (Z_cross >= 150){
    Frequency = Z_cross/(ISR_count*0.00009158*1.0005);
    ISR_count = 0;
    Z_cross = 0;
    }
    
  analogWrite(A0, x);
  lcdRefresh(getRMS(x), Frequency);
}
