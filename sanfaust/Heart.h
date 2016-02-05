#pragma once

#define HEART_BOOM_1_ID   0x0
#define HEART_BOOM_2_ID   0x1
#define HEART_EMPTY_ID    0x2
#define HEART_FILLED_ID   0x3
#define HEART_TOP_1_ID    0x4
#define HEART_TOP_2_ID    0x5
#define HEART_BOTTOM_1_ID 0x6
#define HEART_BOTTOM_2_ID 0x7

class LiquidCrystal;

typedef unsigned char byte;

extern byte HEART_BOOM_1[8];
extern byte HEART_BOOM_2[8];
extern byte HEART_EMPTY[8];
extern byte HEART_FILLED[8];
extern byte HEART_TOP_1[8];
extern byte HEART_TOP_2[8];
extern byte HEART_BOTTOM_1[8];
extern byte HEART_BOTTOM_2[8];

void setUpHearts(LiquidCrystal &lcd);

