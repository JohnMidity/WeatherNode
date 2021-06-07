#include <ESP8266WiFi.h>
#include "settings.h"
#include "module.h"
#include "LedBlinker.h"
#include "ota.h"

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

    Module* m = Module::addModule(new LedBlinker(LED_BUILTIN, 500, 250));
    Module::addModule(new LedBlinker(LED_BUILTIN_AUX, 1000, 100));
    Module::addModule(new OTA());
}

void loop() {
    Module::loopAll();
}
