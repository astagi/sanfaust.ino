#pragma once

typedef unsigned char uint8_t;

class LiquidCrystal;

class Animation {
  
  protected: // Everything's protected for performances
    uint8_t _x;
    uint8_t _y;
    uint8_t _frame = 0;
    uint8_t _len = 0;
    virtual void draw(LiquidCrystal &lcd) = 0;
    const uint8_t nextFrame();
    
  public:
    void setPosition(uint8_t x, uint8_t y);
    const uint8_t getLength();
    void render(LiquidCrystal &lcd);
    Animation(uint8_t x, uint8_t y, uint8_t len);
};
