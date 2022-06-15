/*
 * Program that displays randomly generated response on the screen.
 * There are 8 different options you can hear while making desision.
 * This program helps you to always pick the right one! 
 */

# include <LiquidCrystal.h>
// Display pin setup
LiquidCrystal lcd(12, 11, 9, 8, 7, 6);

const int switch_pin = 14;
int switch_state = 0;
int prev_switch_state = 0;
int response = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(switch_pin, INPUT);
  lcd.print("Ask the ");
  lcd.setCursor(0, 1);
  lcd.print("crystal ball!");
}

void loop() {
  switch_state = digitalRead(switch_pin);
  if (switch_state != prev_switch_state){
    if (switch_state == LOW){
      response = random(8); // Generate response randomly <0-8)
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The ball says: ");
      lcd.setCursor(0, 1);
      // Response sentence depending on the number generated
      switch(response){
        case 0:
          lcd.print("Yes");
          break;
        case 1:
          lcd.print("Most likely");
          break;
        case 2:
          lcd.print("Certainly");
          break;
        case 3:
          lcd.print("Outlook good");
          break;
        case 4:
          lcd.print("Unsure");
          break;
        case 5:
          lcd.print("Ask again");
          break;
        case 6:
          lcd.print("Doubtful");
          break;
        case 7:
          lcd.print("No :(");
          break;
      }
    }
  }
  prev_switch_state = switch_state;
}
