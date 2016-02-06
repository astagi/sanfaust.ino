#pragma once

typedef unsigned char uint8_t;

class LiquidCrystal;

class LoopAnimation {
  
  private:
    uint8_t _x;
    uint8_t _y;
    uint8_t _frame = 0;
    uint8_t _len = 0;
    const uint8_t *_frames;

    void draw(LiquidCrystal &lcd);
    const uint8_t nextFrame();

    
  public:
    LoopAnimation(uint8_t x, uint8_t y, const uint8_t *frames, uint8_t len);
    void setPosition(uint8_t x, uint8_t y);
    const uint8_t getLength();
    void render(LiquidCrystal &lcd);
};

