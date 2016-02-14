#pragma once

typedef unsigned char uint8_t;

class LiquidCrystal;

enum AnimationStatus { start, stop, pause };

class Animation {
  
  protected: // Everything's protected for performances
    uint8_t _x;
    uint8_t _y;
    uint8_t _frame = 0;
    uint8_t _len = 0;
    uint8_t _delay = 0;
    uint8_t _amount_delay = 0;
    AnimationStatus _status = AnimationStatus::start;
    virtual void draw(LiquidCrystal &lcd) = 0;
    const uint8_t nextFrame();
    
  public:
    virtual bool isEnd();
    void restart();
    void pause();
    void stop();
    void setPosition(uint8_t x, uint8_t y);
    void setDelay(uint8_t _delay);
    const uint8_t getDelay();
    const uint8_t getLength();
    void render(LiquidCrystal &lcd);
    Animation(uint8_t x, uint8_t y, uint8_t len);
};
