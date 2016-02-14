#pragma once

#include "Animation.h"

typedef unsigned char uint8_t;

class LiquidCrystal;

class LoopAnimation : public Animation {

  private:
    const uint8_t *_frames;

  protected:
    void draw(LiquidCrystal &lcd);

  public:
    bool isEnd();
    LoopAnimation(uint8_t x, uint8_t y, const uint8_t *frames, uint8_t len);
};

