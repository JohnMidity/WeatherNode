#ifndef WIFIMODULE_H
#define WIFIMODULE_H

#include "module.h"

class WiFiModule : public Module
{
private:
    char *_ssid, *_password;
    unsigned long _previousMillis, _interval, _onInterval, _offInterval;
    void connectWithWait();

public:
    WiFiModule(char *ssid, char *password);
    void moduleLoop();
};
#endif
