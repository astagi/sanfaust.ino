#include <LiquidCrystal.h>
#include "Heart.h"
#include "LoopAnimation.h"
#include "TextAnimation.h"
#include "BlinkTextAnimation.h"
#include "ProgressTextAnimation.h"
#include "cfg.h"


LiquidCrystal lcd(LCD_PINS);

uint8_t HEART_BOOM[] = {
  0x20, HEART_BOOM_1_ID, HEART_BOOM_2_ID, HEART_EMPTY_ID,
  HEART_FILLED_ID, HEART_EMPTY_ID, HEART_FILLED_ID,  HEART_EMPTY_ID,
  HEART_FILLED_ID,  HEART_EMPTY_ID, HEART_BOOM_2_ID, HEART_BOOM_1_ID, 0x20
};

uint8_t HEART_BOOM_FROM_BOTTOM[] = {
  0x20, HEART_BOTTOM_2_ID, HEART_BOTTOM_1_ID, HEART_EMPTY_ID,
  HEART_FILLED_ID, HEART_EMPTY_ID, HEART_FILLED_ID,  HEART_EMPTY_ID,
  HEART_FILLED_ID,  HEART_EMPTY_ID, HEART_BOTTOM_1_ID, HEART_BOTTOM_2_ID, 0x20
};

uint8_t HEART_BOOM_FROM_TOP[] = {
  0x20, HEART_TOP_1_ID, HEART_TOP_2_ID, HEART_EMPTY_ID,
  HEART_FILLED_ID, HEART_EMPTY_ID, HEART_FILLED_ID,  HEART_EMPTY_ID,
  HEART_FILLED_ID,  HEART_EMPTY_ID, HEART_TOP_2_ID, HEART_TOP_1_ID, 0x20
};

Animation *animations[] = {
  new LoopAnimation(0, 13, HEART_BOOM_FROM_TOP, sizeof(HEART_BOOM_FROM_TOP)),
  new LoopAnimation(0, 2, HEART_BOOM, sizeof(HEART_BOOM)),
  new LoopAnimation(1, 14, HEART_BOOM, sizeof(HEART_BOOM)),
  new LoopAnimation(1, 1, HEART_BOOM_FROM_BOTTOM, sizeof(HEART_BOOM_FROM_BOTTOM)),
  new LoopAnimation(0, 0, HEART_BOOM, sizeof(HEART_BOOM)),
  new LoopAnimation(0, 15, HEART_BOOM, sizeof(HEART_BOOM)),
  new BlinkTextAnimation(0, 6, "I'M", 4),
  new BlinkTextAnimation(1, 4, "SINGLE!!", 4),
  new TextAnimation(0, 6, "MY", 4),
  new TextAnimation(1, 3, "NUMBER IS:", 4),
  new ProgressTextAnimation(0, 6, "322"),
  new ProgressTextAnimation(1, 4, "2222222")
};

void setup() {
  setUpHearts(lcd);
  lcd.begin(16, 2);
  animations[1]->setDelay(5);
  animations[2]->setDelay(1);
  animations[3]->setDelay(4);
  animations[4]->setDelay(3);
  animations[5]->setDelay(5);

  animations[8]->setDelay(1);
  animations[9]->setDelay(1);
  animations[10]->setDelay(1);
  animations[11]->setDelay(1);
}

void end_loop() {
  delay(500);
  lcd.clear();
}

void loop() {

  animations[6]->render(lcd);
  animations[7]->render(lcd);

  if (animations[6]->isEnd()) {
    animations[8]->render(lcd);
    animations[9]->render(lcd);
  }
  if (animations[8]->isEnd()) {
    animations[10]->render(lcd);
  }
  if (animations[10]->isEnd()) {
    animations[10]->pause();
    animations[11]->render(lcd);
  }
  if (animations[11]->isEnd()) {
    animations[10]->stop();
    for (uint8_t i = 6; i < 12 ; i++) {
      animations[i]->restart();
    }
  }
  for (uint8_t i = 0; i < 6 ; i++) {
    animations[i]->render(lcd);
  }
  end_loop();
}

