#include <ESP8266WiFi.h>
#include "WifiModule.h"

WiFiModule::WiFiModule(char *ssid, char *password)
{
    _ssid = ssid;
    _password = password;

    connectWithWait();
}

void WiFiModule::moduleLoop()
{
}

void WiFiModule::connectWithWait()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(_ssid, _password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        delay(200);
    }
}