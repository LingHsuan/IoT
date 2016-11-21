#ifndef Plant_h
#define Plant_h

#include "Arduino.h"

class Plant
{
  public:
  Plant(void);
  int readMoisture(int pin);
  float MoiToPercentage(int value);
  
  private:
  int _pin;
  int _value;
};

#endif

