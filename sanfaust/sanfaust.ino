#include <LiquidCrystal.h>
#include "Heart.h"
#include "LoopAnimation.h"

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

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

int i = 0;

uint8_t HEART_BOOM[] = {
  0x20, 0x0, 0x1, 0x2, 
  0x3, 0x2, 0x3,  0x2, 
  0x1, 0x0, 0x20
};

LoopAnimation anim = LoopAnimation(0, 0, HEART_BOOM, sizeof(HEART_BOOM));

void loop() {
  anim.draw(lcd);
  anim.nextFrame();
  delay(500);
}
