#include "settings.h"
#include "module.h"
#include "LedBlinker.h"
#include "ota.h"
#include <ESP8266WiFi.h>

void setup() {
    Serial.begin(115200);
    Serial.println("Starting...");

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        Serial.println("Waiting for WIFI connection...");
        delay(2000);
    }
    Serial.println("Connected.");

    Module::addModule(new LedBlinker(LED_BUILTIN));
    Module::addModule(new OTA());
}

void loop() {
    Module::loopAll();
}
