#ifndef DHTMODULE_H
#define DHTMODULE_H

#include "module.h"

class dhtModule : public Module
{
private:
  DHT* _myDHT;

  unsigned int _DHTPin;
  unsigned int _DHTType;
  unsigned long _interval, _previousMillis;

public:
  dhtModule(unsigned int DHTPin, unsigned int DHTType, unsigned long interval);
  void moduleLoop();
};
#endif
