#include "TextAnimation.h"
#include <LiquidCrystal.h>

TextAnimation::TextAnimation(uint8_t x, uint8_t y, const char *_top_text, const char *_bottom_text, bool _blink) : Animation(0, y, 2){
  this-> _blink = _blink;
  this->_top_text = _top_text;
  this->_bottom_text = _bottom_text;
}

void TextAnimation::draw(LiquidCrystal &lcd) {
  if (this->_blink && this->_frame == 0) {
    return;
  }
  lcd.setCursor(this->_y, 0);
  lcd.print(this->_top_text);
  lcd.setCursor(this->_y, 1);
  lcd.print(this->_bottom_text);
}

