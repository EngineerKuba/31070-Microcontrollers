/*
 * Create unique colours based on exteral light conditions!
 * This program enables to regulate intensity of red, green, blue LED.
 * Intensity depends on the light conditions outside. 
 * The more light on respective sensor the stringer it's part in final color.
 */
const int r_led_pin = 6;
const int g_led_pin = 7;
const int b_led_pin = 8;

const int r_sens_pin = A1;
const int g_sens_pin = A2;
const int b_sens_pin = A3;

int r_val = 0;
int g_val = 0;
int b_val = 0;

int r_sens_val = 0;
int g_sens_val = 0;
int b_sens_val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(r_led_pin, OUTPUT);
  pinMode(g_led_pin, OUTPUT);
  pinMode(b_led_pin, OUTPUT);
}

void loop() {
  // Read values from light sensors
  r_sens_val = analogRead(r_sens_pin);
  delay(5);
  g_sens_val = analogRead(g_sens_pin);
  delay(5);
  b_sens_val = analogRead(b_sens_pin);
  
  // Direct print of read values
  Serial.println("Sens values: ");
  Serial.print("Red: ");
  Serial.println(r_sens_val);
  Serial.print("Green: ");
  Serial.println(g_sens_val);
  Serial.print("Blue: ");
  Serial.println(b_sens_val);

  // Range mapping, from 0-1023 to 0-254 approx
  r_val = r_sens_val/4;
  g_val = g_sens_val/4;
  b_val = b_sens_val/4;

  // Mapped values print
  Serial.println("Mapped values: ");
  Serial.print("Red: ");
  Serial.println(r_val);
  Serial.print("Green: ");
  Serial.println(g_val);
  Serial.print("Blue: ");
  Serial.println(b_val);

  // Writing mapped values to respective ligh
  analogWrite(r_led_pin, r_val);
  analogWrite(g_led_pin, g_val);
  analogWrite(b_led_pin, b_val);
}
