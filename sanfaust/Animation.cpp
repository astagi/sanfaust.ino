#include "Animation.h"
#include <LiquidCrystal.h>


Animation::Animation(uint8_t x, uint8_t y, uint8_t len) {
  this->_len = len;
  this->setPosition(x, y);
}

const uint8_t Animation::nextFrame() {
  this->_frame = (this->_frame + 1) % this->_len;
  return this->_frame;
}

const uint8_t Animation::getLength() {
  return this->_len;
}

void Animation::setPosition(uint8_t x, uint8_t y) {
  this->_x = x;
  this->_y = y;
}

void Animation::render(LiquidCrystal &lcd) {
  this->draw(lcd);
  this->nextFrame();
}
