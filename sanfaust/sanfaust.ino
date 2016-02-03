#include <LiquidCrystal.h>
#include "Heart.h"

LiquidCrystal lcd(13, 11, 5, 4, 3, 2);

void setup() {

  lcd.createChar(0, HEART_BOOM_1);
  lcd.createChar(1, HEART_BOOM_2);
  lcd.createChar(2, HEART_EMPTY);
  lcd.createChar(3, HEART_FILLED);

  lcd.createChar(4, HEART_TOP_1);
  lcd.createChar(5, HEART_TOP_2);
  lcd.createChar(6, HEART_BOTTOM_1);
  lcd.createChar(7, HEART_BOTTOM_2);

  lcd.begin(16, 2);

}

void loop() {
  for (uint8_t i = 0 ; i < 7 ; i++) {
    lcd.write(i);
  }
  delay(1000);
}
