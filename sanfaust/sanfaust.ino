#include <LiquidCrystal.h>
#include "Heart.h"
#include "LoopAnimation.h"
#include "TextAnimation.h"
#include "BlinkTextAnimation.h"
#include "ProgressTextAnimation.h"
#include "Counter.h"


LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

uint8_t HEART_BOOM[] = {
  0x20, HEART_BOOM_1_ID, HEART_BOOM_2_ID, HEART_EMPTY_ID, 
  HEART_FILLED_ID, HEART_EMPTY_ID, HEART_FILLED_ID,  HEART_EMPTY_ID, 
  HEART_BOOM_2_ID, HEART_BOOM_1_ID, 0x20
};

Animation *heart_boom_anim_1 = new LoopAnimation(0, 13, HEART_BOOM, sizeof(HEART_BOOM));
Animation *heart_boom_anim_2 = new LoopAnimation(0, 2, HEART_BOOM, sizeof(HEART_BOOM));

Animation *single_anim_1 = new BlinkTextAnimation(0, 6, "I'M", 4);
Animation *single_anim_2 = new BlinkTextAnimation(1, 4, "SINGLE!!", 4);

Animation *my_number_is_anim_1 = new TextAnimation(0, 6, "MY", 4);
Animation *my_number_is_anim_2 = new TextAnimation(1, 3, "NUMBER IS", 4);

Animation *my_number_anim_1 = new ProgressTextAnimation(0, 6, "339");
Animation *my_number_anim_2 = new ProgressTextAnimation(1, 4, "2625610");

Counter counter = Counter(20);

void setup() {
  setUpHearts(lcd);
  lcd.begin(16, 2);
  my_number_is_anim_1->setDelay(1);
  my_number_is_anim_2->setDelay(1);
  my_number_anim_1->setDelay(1);
  my_number_anim_2->setDelay(1);
}

void loop() {
  
  single_anim_1->render(lcd);
  single_anim_2->render(lcd);

  if (single_anim_1->isEnd()) {
    my_number_is_anim_1->render(lcd);
    my_number_is_anim_2->render(lcd);
  }
  if (my_number_is_anim_1->isEnd()) {
    my_number_anim_1->render(lcd);
  }
  if (my_number_anim_1->isEnd()) {
    my_number_anim_2->render(lcd);
  }
  heart_boom_anim_1->render(lcd);
  heart_boom_anim_2->render(lcd);
  delay(500);
  lcd.clear();
  counter.next();
}

