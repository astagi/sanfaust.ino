#include "BlinkTextAnimation.h"
#include <LiquidCrystal.h>

BlinkTextAnimation::BlinkTextAnimation(uint8_t x, uint8_t y, const char *_text) : TextAnimation(x, y, _text){
  this->_len = 2;
}

void BlinkTextAnimation::draw(LiquidCrystal &lcd) {
  if (this->_frame == 1) {
    return;
  }
  TextAnimation::draw(lcd);
}

