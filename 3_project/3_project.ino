/* Using DS18B20 - digital thermometer
 * Thermometer - if your room temerature is in good range green LED will be on.
 * If it's too high red and green will be on if extreamly high red only.
 * If temp is too low yellow and green will turn on, extreamly low - yellow only.
 */
#include <OneWire.h> 
#include <DallasTemperature.h>

const int yellow = 6;
const int green = 7;
const int red = 8;
const int thermometer = A1;
float ok_up = 24.0;
float ok_low = 22.0;
float extreme_up = 25.0;
float extreme_low = 21.0;

OneWire oneWire(thermometer);
DallasTemperature sensors(&oneWire);

DeviceAddress thermometer_living_room = {0x28, 0xFF, 0x64, 0xCE, 0x6B, 0x18, 0x1, 0xCA};

void setup() {
  Serial.begin(9600);
  sensors.begin(); 
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
//  float temp_read = sensors.getTempCByIndex(0); In case we want to read by index
  float temp_read = sensors.getTempC(thermometer_living_room);
  sensors.requestTemperatures();
  Serial.print("Temp value: ");
  Serial.print(temp_read);
  Serial.print("\n");
  if (temp_read > extreme_up){
    ledOn(red);
    ledOff(green);
    ledOff(yellow);
  }
  else if (temp_read > ok_up){
    ledOn(red);
    ledOn(green);
    ledOff(yellow);
  }
  else if (temp_read > ok_low){
    ledOff(red);
    ledOn(green);
    ledOff(yellow);
  }
  else if (temp_read > extreme_low){
    ledOff(red);
    ledOn(green);
    ledOn(yellow);
  }
  else if (temp_read < extreme_low){
    ledOff(red);
    ledOff(green);
    ledOn(yellow);
  }
  delay(1000);
}
