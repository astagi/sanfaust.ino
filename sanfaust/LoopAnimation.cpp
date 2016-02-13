#include "LoopAnimation.h"
#include <LiquidCrystal.h>

LoopAnimation::LoopAnimation(uint8_t x, uint8_t y, const uint8_t *frames, uint8_t len) : Animation(x, y, len) {
  this->_frames = frames;
}

void LoopAnimation::draw(LiquidCrystal &lcd) {
  lcd.setCursor(this->_y, this->_x);
  lcd.write(this->_frames[this->_frame]);
}
