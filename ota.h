#ifndef OTA_H
#define OTA_H

#include "module.h"

class OTA : public Module
{
public:
  OTA();
  void moduleLoop();
};

#endif