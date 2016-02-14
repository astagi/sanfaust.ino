#pragma once

#include "TextAnimation.h"

typedef unsigned char uint8_t;

class LiquidCrystal;

class ProgressTextAnimation : public TextAnimation {
  
  private:
    char *_text_aux;
    char _saved_char = '\0';
  protected:
    void draw(LiquidCrystal &lcd);
    
  public:
    ProgressTextAnimation(uint8_t x, uint8_t y, const char *_text);
};

