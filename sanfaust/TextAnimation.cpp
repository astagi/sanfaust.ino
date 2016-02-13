#include "TextAnimation.h"
#include <LiquidCrystal.h>

TextAnimation::TextAnimation(uint8_t x, uint8_t y, const char *_text, bool _blink) : Animation(x, y, 2){
  this-> _blink = _blink;
  this->_text = _text;
}

void TextAnimation::draw(LiquidCrystal &lcd) {
  if (this->_blink && this->_frame == 1) {
    return;
  }
  lcd.setCursor(this->_y, this->_x);
  lcd.print(this->_text);
}

