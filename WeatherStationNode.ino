#include <ESP8266WiFi.h>
#include "settings.h"
#include "module.h"
#include "LedBlinker.h"
#include "ota.h"
#include "WebServer.h"
#include "data.h"

void setup() {
    const char version[] = "build "  __DATE__ " " __TIME__;
    Serial.begin(115200);
    Serial.println("");
    Serial.println(version);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        Serial.println("Waiting for WIFI connection...");
        delay(2000);
    }
    Serial.println("Connected.");

    addModules();
}

void loop() {
    Module::loopAll();
}

void addModules()
{
    Module *dataModule = Module::addModule(new Data());
    Module::addModule(new LedBlinker(LED_BUILTIN, 25, 9975));
    Module::addModule(new OTA());
    Module::addModule(new WebServer());
}
