// low pass filtering function
// w0 - cut_off_freq [rad/s]
// fc - cut off freq [Hz]
// 50 Hz = 314.16 rad/s
// 10 Hz = 62.83 rad/s
// 100 Hz = 628.32rad/s

// fs = 10kHz
//
//float LowPassFilter(float input_sig, float dt, float fc){
//  float RC = 1/(2*pi*fc)
//  float a = dt/(RC+dt)
//
//  y = a*input_sig + (1-a)
//  return y;
//}


//  get_a(fc, sample_rate);
//void get_a(int fc, int sample_rate){
//  float RC = 1/(2*M_PI*fc);
//  float a = (1/sample_rate)/(RC+(1/sample_rate));
//}
//
//  float RC = 1/(2*M_PI*fc);
//  float a = (1/sample_rate)/(RC+(1/sample_rate));
//  float output_sig = a*input_sig + (1-a)*prev_output_sig;
