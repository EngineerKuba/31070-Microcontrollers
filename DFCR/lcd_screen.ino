# include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 9, 8, 7, 6);

const int switch_pin = 14;
int switch_state = 0;
int prev_switch_state = 0;
int response = 0;
  
void lcdInit(){
  lcd.begin(16, 2);
  pinMode(switch_pin, INPUT);
  lcd.print("Press button");
  lcd.setCursor(0, 1);
  lcd.print("to refresh data.");
}

void lcdRefresh(float RMS_voltage, float Frequency){
  switch_state = digitalRead(switch_pin);
  if (switch_state != prev_switch_state){
    if (switch_state == LOW){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Vol[V]: ");
      lcd.print(RMS_voltage);
      lcd.setCursor(0, 1);
      lcd.print("Freq[Hz]: ");
      lcd.print(Frequency);      
    }
  }
  prev_switch_state = switch_state;
}
