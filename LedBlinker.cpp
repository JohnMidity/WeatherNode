#include "LedBlinker.h"

LedBlinker::LedBlinker(int ledPin)
{
  setup(ledPin, 1000, 1000);
}

LedBlinker::LedBlinker(int ledPin, int interval)
{
  setup(ledPin, interval, interval);
}

LedBlinker::LedBlinker(int ledPin, int onInterval, int offInterval)
{
  setup(ledPin, onInterval, offInterval);
}

void LedBlinker::setup(int ledPin, int onInterval, int offInterval)
{
  _ledPin = ledPin;
  _onInterval = onInterval;
  _offInterval = offInterval;

  _ledState = LOW;
  _previousMillis = 0;

  pinMode(_ledPin, OUTPUT);

}

void LedBlinker::moduleLoop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - _previousMillis >= _interval)
  {
    _previousMillis = currentMillis;
    if (_ledState == LOW)
    {
      _ledState = HIGH;
      _interval = _onInterval;
    }
    else
    {
      _ledState = LOW;
      _interval = _offInterval;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(_ledPin, _ledState);
  }
}
