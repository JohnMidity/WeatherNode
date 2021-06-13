#include <HardwareSerial.h>
#include <DHT_U.h>
#include <DHT.h>
#include "Arduino.h"
#include "dhtModule.h"

dhtModule::dhtModule(unsigned int DHTPin, unsigned int DHTType, unsigned long interval)
{
  _DHTPin = DHTPin;
  _interval = interval;
  _previousMillis = 0;

  _myDHT = new DHT(DHTPin, DHTType);
  _myDHT->begin();
}

void dhtModule::moduleLoop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - _previousMillis >= _interval)
  {
    _previousMillis = currentMillis;

    float temp = _myDHT->readTemperature();
    float hum = _myDHT->readHumidity();
    Serial.println("DHT22 Temperature:" + String(temp));
    Serial.println("DHT22 Humidity:" + String(hum));
  }
}
