#include "Animation.h"
#include <LiquidCrystal.h>


Animation::Animation(uint8_t x, uint8_t y, uint8_t len) {
  this->_len = len;
  this->setPosition(x, y);
}

void Animation::setDelay(uint8_t _delay) {
  this->_amount_delay = _delay;
  this->_delay = _delay;
}

const uint8_t Animation::getDelay() {
  return this->_delay;
}

const uint8_t Animation::nextFrame() {
  if (this->isEnd()) {
    return this->_frame;
  }
  this->_frame = (this->_frame + 1) % this->_len;
  return this->_frame;
}

const uint8_t Animation::getLength() {
  return this->_len;
}

void Animation::restart() {
  this->_status = AnimationStatus::start;
  this->_frame = 0;
  this->_amount_delay = this->_delay;
}

void Animation::stop() {
  this->_status = AnimationStatus::stop;
}

void Animation::pause() {
  this->_status = AnimationStatus::pause;
}

void Animation::setPosition(uint8_t x, uint8_t y) {
  this->_x = x;
  this->_y = y;
}

void Animation::render(LiquidCrystal &lcd) {
  if (this->_status != AnimationStatus::start) {
    if (this->_status == AnimationStatus::pause) {
      this->draw(lcd);
    }
    return;
  }
  if (this->_amount_delay > 0) {
    this->_amount_delay--;
    return;
  }
  if (this->isEnd()) {
    return;
  }
  this->draw(lcd);
  this->nextFrame();
}

bool Animation::isEnd() {
  return (this->_len -1 == this->_frame);
}
