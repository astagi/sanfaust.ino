#include <LiquidCrystal.h>
#include "Heart.h"
#include "LoopAnimation.h"

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {

  setUpHearts(lcd);
  lcd.begin(16, 2);

}

int i = 0;

uint8_t HEART_BOOM[] = {
  0x20, HEART_BOOM_1_ID, HEART_BOOM_2_ID, HEART_EMPTY_ID, 
  HEART_FILLED_ID, HEART_EMPTY_ID, HEART_FILLED_ID,  HEART_EMPTY_ID, 
  HEART_BOOM_2_ID, HEART_BOOM_1_ID, 0x20
};

LoopAnimation anim = LoopAnimation(0, 0, HEART_BOOM, sizeof(HEART_BOOM));

void loop() {
  anim.draw(lcd);
  anim.nextFrame();
  delay(500);
}
