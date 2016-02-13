#include <LiquidCrystal.h>
#include "Heart.h"
#include "LoopAnimation.h"
#include "TextAnimation.h"
#include "Counter.h"


LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

uint8_t HEART_BOOM[] = {
  0x20, HEART_BOOM_1_ID, HEART_BOOM_2_ID, HEART_EMPTY_ID, 
  HEART_FILLED_ID, HEART_EMPTY_ID, HEART_FILLED_ID,  HEART_EMPTY_ID, 
  HEART_BOOM_2_ID, HEART_BOOM_1_ID, 0x20
};

LoopAnimation heart_boom_anim_1 = LoopAnimation(0, 13, HEART_BOOM, sizeof(HEART_BOOM));
LoopAnimation heart_boom_anim_2 = LoopAnimation(0, 2, HEART_BOOM, sizeof(HEART_BOOM));

TextAnimation single_anim = TextAnimation(0, 4, "  I'M", "SINGLE!!", true);
TextAnimation my_number_is_anim = TextAnimation(0, 3, "   MY", "NUMBER IS");
TextAnimation my_number_anim = TextAnimation(0, 4, "  322", "2222222");

Counter counter = Counter(20);

void setup() {
  setUpHearts(lcd);
  lcd.begin(16, 2);
}

void loop() {
  if (counter.isBelow(10)) {
    single_anim.render(lcd);
  }
  if (counter.isBetween(10, 15, true)) {
    my_number_is_anim.render(lcd);
  }
  if (counter.isBetween(15, 20, true)) {
    my_number_anim.render(lcd);
  }
  heart_boom_anim_1.render(lcd);
  heart_boom_anim_2.render(lcd);
  delay(500);
  lcd.clear();
  counter.next();
}

