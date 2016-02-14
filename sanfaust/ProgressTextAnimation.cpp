#include "ProgressTextAnimation.h"
#include <LiquidCrystal.h>

ProgressTextAnimation::ProgressTextAnimation(uint8_t x, uint8_t y, const char *_text) : TextAnimation(x, y, _text, strlen(_text) + 2) {
  this->_text_aux = (char*)malloc((strlen(_text)) * sizeof(char));
  memcpy(this->_text_aux, this->_text, strlen(_text) * sizeof(char));
}

void ProgressTextAnimation::draw(LiquidCrystal &lcd) {
  lcd.setCursor(this->_y, this->_x);
  this->_saved_char = this->_text_aux[this->_frame];
  this->_text_aux[this->_frame] = '\0';
  lcd.print(this->_text_aux);
  this->_text_aux[this->_frame] = this->_saved_char;
}

