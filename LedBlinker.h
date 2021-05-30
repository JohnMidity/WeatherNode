#ifndef LedBlinker_H
#define LedBlinker_H

#include "module.h"

class LedBlinker : public Module
{
private:
  int _ledPin, _ledState;
  unsigned long _previousMillis;
  long _interval, _onInterval, _offInterval;
  void setup(int ledPin, int onInterval, int offInterval);

public:
  LedBlinker(int ledPin);
  LedBlinker(int ledPin, int interval);
  LedBlinker(int ledPin, int onInterval, int offInterval);
  void moduleLoop();
};
#endif
