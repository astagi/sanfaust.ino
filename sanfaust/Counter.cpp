#include "Counter.h"


Counter::Counter(int _size) {
  this->_size = _size;
  this->_current = 0;
}

bool Counter::isOver(int n, bool equal) {
  if (equal) {
    return (this->_current >= n);
  } else {
    return (this->_current > n);
  }
}

bool Counter::isBelow(int n, bool equal) {
  if (equal) {
    return (this->_current <= n);
  } else {
    return (this->_current < n);
  }
}

bool Counter::isBetween(int n1, int n2, bool equal1, bool equal2) {
  bool first = false;
  bool second = false;
  
  if (equal1) {
    first = (n1 <= this->_current);
  } else {
    first = (n1 < this->_current);
  }

  if (equal2) {
    second = (this->_current <= n2);
  } else {
    second = (this->_current < n2);
  }

  return (first && second);
}

int Counter::next() {
  this->_current = (this->_current + 1) % this->_size;
  return this->_current;
}

