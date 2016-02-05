#include "Heart.h"
#include <LiquidCrystal.h>


byte HEART_BOOM_1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00100,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte HEART_BOOM_2[8] = {
  0b00000,
  0b00000,
  0b00100,
  0b01010,
  0b00100,
  0b00000,
  0b00000,
  0b00000
};

byte HEART_EMPTY[8] = {
  0b00000,
  0b01010,
  0b10101,
  0b10001,
  0b01010,
  0b00100,
  0b00000,
  0b00000
};

byte HEART_FILLED[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};

byte HEART_TOP_1[8] = {
  0b01010,
  0b00100,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};


byte HEART_TOP_2[8] = {
  0b10101,
  0b10001,
  0b01010,
  0b00100,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};


byte HEART_BOTTOM_1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b01010,
  0b10101,
  0b10001,
  0b01010
};


byte HEART_BOTTOM_2[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b01010,
  0b10101
};


void setUpHearts(LiquidCrystal &lcd) {
  lcd.createChar(HEART_BOOM_1_ID, HEART_BOOM_1);
  lcd.createChar(HEART_BOOM_2_ID, HEART_BOOM_2);
  lcd.createChar(HEART_EMPTY_ID, HEART_EMPTY);
  lcd.createChar(HEART_FILLED_ID, HEART_FILLED);
  lcd.createChar(HEART_TOP_1_ID, HEART_TOP_1);
  lcd.createChar(HEART_TOP_2_ID, HEART_TOP_2);
  lcd.createChar(HEART_BOTTOM_1_ID, HEART_BOTTOM_1);
  lcd.createChar(HEART_BOTTOM_2_ID, HEART_BOTTOM_2);
}

