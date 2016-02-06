#include "LoopAnimation.h"
#include <LiquidCrystal.h>

LoopAnimation::LoopAnimation(uint8_t x, uint8_t y, const uint8_t *frames, uint8_t len) {
  this->_frames = frames;
  this->_len = len;
  this->setPosition(x, y);
}

const uint8_t LoopAnimation::nextFrame() {
  this->_frame = (this->_frame + 1) % this->_len;
  return this->_frame;
}

const uint8_t LoopAnimation::getLength() {
  return this->_len;
}

void LoopAnimation::setPosition(uint8_t x, uint8_t y) {
  this->_x = x;
  this->_y = y;
}

void LoopAnimation::draw(LiquidCrystal &lcd) {
  lcd.setCursor(this->_x, this->_y);
  lcd.write(this->_frames[this->_frame]);
}

void LoopAnimation::render(LiquidCrystal &lcd) {
  this->draw(lcd);
  this->nextFrame();
}
