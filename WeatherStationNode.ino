#include <ESP8266WiFi.h>
#include <DHT_U.h>
#include <DHT.h>

#include "settings.h"
#include "module.h"
#include "LedBlinker.h"
#include "ota.h"
#include "WebServer.h"
#include "data.h"
#include "dhtModule.h"

#define DHTPIN D5
#define DHTTYPE DHT22

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
    Module::addModule(new LedBlinker(LED_BUILTIN, 15, 9985));
    Module::addModule(new OTA());
    Module::addModule(new dhtModule(DHTPIN, DHTTYPE, 5000));
    Module::addModule(new WebServer());
}
