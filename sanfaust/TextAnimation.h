#pragma once

#include "Animation.h"

typedef unsigned char uint8_t;

class LiquidCrystal;

class TextAnimation : public Animation {

  protected:
    const char *_text;
    void draw(LiquidCrystal &lcd);

  public:
    TextAnimation(uint8_t x, uint8_t y, const char *_text, uint8_t len);

};

