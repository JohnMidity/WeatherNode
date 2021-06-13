#include <DHT_U.h>
#include <DHT.h>

#include "settings.h"
#include "WiFiModule.h"
#include "module.h"
#include "LedBlinker.h"
#include "ota.h"
#include "WebServer.h"
#include "data.h"
#include "dhtModule.h"

#define DHTPIN D5
#define DHTTYPE DHT22

void setup()
{
    const char version[] = "build " __DATE__ " " __TIME__;
    Serial.begin(115200);
    Serial.println("");
    Serial.println(version);

    addModules();
}

void loop()
{
    Module::loopAll();
}

void addModules()
{
    Module::addModule(new WiFiModule(ssid, password));

    Module *dataModule = Module::addModule(new Data());
    Module::addModule(new LedBlinker(LED_BUILTIN, 15, 9985));
    Module::addModule(new OTA());
    Module::addModule(new dhtModule(DHTPIN, DHTTYPE, 5000));
    Module::addModule(new WebServer());
}
