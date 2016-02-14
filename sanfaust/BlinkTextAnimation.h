#pragma once

#include "TextAnimation.h"

typedef unsigned char uint8_t;

class LiquidCrystal;

class BlinkTextAnimation : public TextAnimation {
  
  protected:
    void draw(LiquidCrystal &lcd);
    
  public:
    BlinkTextAnimation(uint8_t x, uint8_t y, const char *_text, uint8_t len);
};

