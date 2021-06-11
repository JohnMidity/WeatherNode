#ifndef DATA_H
#define DATA_H

#include "../module.h"

class Data : public Module
{
private:
    struct
    {
        char WifiSSID[20] = "";
        char WifiPW[20] = "";
    } data;

public:
  Data();
  void moduleLoop();
};
#endif
