#include "BlinkTextAnimation.h"
#include <LiquidCrystal.h>

BlinkTextAnimation::BlinkTextAnimation(uint8_t x, uint8_t y, const char *_text, uint8_t len) : TextAnimation(x, y, _text, len){
}

void BlinkTextAnimation::draw(LiquidCrystal &lcd) {
  if (this->_frame % 2 != 0) {
    return;
  }
  TextAnimation::draw(lcd);
}

