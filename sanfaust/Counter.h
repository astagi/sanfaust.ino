#pragma once

class Counter {
  
  protected: // Everything's protected for performances
    int _size;
    int _current;
    
  public:
    Counter(int _size);
    bool isOver(int n, bool equal=false);
    bool isBelow(int n, bool equal=false);
    bool isBetween(int n1, int n2, bool equal1=false, bool equal2=false);
    int next();
    int getCurrentValue();
};
