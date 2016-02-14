#include "TextAnimation.h"
#include <LiquidCrystal.h>

TextAnimation::TextAnimation(uint8_t x, uint8_t y, const char *_text, uint8_t len) : Animation(x, y, len){
  this->_text = _text;
}

void TextAnimation::draw(LiquidCrystal &lcd) {
  lcd.setCursor(this->_y, this->_x);
  lcd.print(this->_text);
}

