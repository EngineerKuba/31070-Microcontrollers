#include <Timer5.h>
#include <filters.h>

const int analog_read = A1;
float prev_output_sig = 0;
float prev_input_sig = 0;
const int sample_rate = 1000;
volatile float input_sig;
volatile float output_sig;
float cutoff_freq = 50;
float sampling_time = 0.0001;
IIR::ORDER  order  = IIR::ORDER::OD2; // Order (OD1 to OD4)

//Filter f(cutoff_freq, sampling_time, order);

void setup() { // put your setup code here, to run once:
  //MyTimer5.begin(sample_rate); // 200=for toggle every 5msec
  //MyTimer5.attachInterrupt(readsignal); //Digital Pins=3 with Interrupts
  Serial.begin(9600);
  AdcBooster();
}

//void readsignal()
//{            
//     input_sig = analogRead(analog_read);
//     float output_sig = f.filterIn(input_sig);
//     Serial.println(output_sig);
//}

void loop() {
//  float output_sig = 0.969*prev_output_sig + 0.015*input_sig;// + 0.015*prev_input_sig;
    input_sig = analogRead(analog_read);
//  prev_input_sig = input_sig;
//  prev_output_sig = output_sig;
    analogWrite(A0, input_sig);
//  analogWrite(A0, input_sig);
}
