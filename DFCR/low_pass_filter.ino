
float getAlpha (int sample_rate, int cut_off_freq){
  float alpha = (1.0/sample_rate)/((1.0/(2.0*M_PI*cut_off_freq))+(1.0/sample_rate));
  return alpha;
}

float lowPassFilter(float in_signal, float alpha){
  y = alpha*in_signal + (1-alpha)*y_prev; // LowPassFilter
  return y;
}
