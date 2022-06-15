volatile float voltage_read;
volatile float voltage_square;
volatile float sum_voltage_square;
volatile int RMS_count;
volatile float RMS_voltage;

float getRMS(float in_signal){ //in_signal must be before LowPassFilter
  voltage_read = (in_signal/1023)*3.3;
  voltage_square = pow(voltage_read, 2);
  sum_voltage_square = sum_voltage_square + voltage_square;
  RMS_count = RMS_count + 1;

  if (RMS_count > 1000){
    RMS_voltage = sqrt(sum_voltage_square/RMS_count)*240;
    RMS_count = 0;
    sum_voltage_square = 0;
  }
  return RMS_voltage;
}
