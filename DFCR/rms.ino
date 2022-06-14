volatile float voltageRead;
volatile float voltageSquare;
volatile float sumVoltageSquare;
volatile int RMS_count;
volatile float RMSVoltage;

float getRMS(float inSignal){ //inSignal must be before LowPassFilter
  voltageRead = (inSignal/1023)*3.3;
  voltageSquare = pow(voltageRead, 2);
  sumVoltageSquare = sumVoltageSquare + voltageSquare;
  RMS_count = RMS_count + 1;

  if (RMS_count > 1000){
    RMSVoltage = sqrt(sumVoltageSquare/RMS_count)*240;
//    Serial.print("RMS_V: ");
//    Serial.println(RMSVoltage);
    RMS_count = 0;
    sumVoltageSquare = 0;
  }
  return RMSVoltage;
}
