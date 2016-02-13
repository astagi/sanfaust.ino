#pragma once

#include "Animation.h"

typedef unsigned char uint8_t;

class LiquidCrystal;

class TextAnimation : public Animation {
  
  private:
    const char *_text;

  protected:
    void draw(LiquidCrystal &lcd);

  public:
    TextAnimation(uint8_t x, uint8_t y, const char *_text);
    
};

