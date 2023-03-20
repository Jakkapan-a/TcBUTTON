#include "PINOUT.h"

void PINOUT::init()
{
  pinMode(pin, OUTPUT);
  off();
}

PINOUT::PINOUT(uint8_t pin, bool _state = false)
{
  this->pin = pin;
  if (_state) {
    this->reverse = _state;
  }
  init();
}

void PINOUT::on()
{
  if (this->reverse) {
    digitalWrite(pin, HIGH);
  }
  else {
    digitalWrite(pin, LOW);
  }
  this->statePin = true;
}
void PINOUT::off()
{
  if (this->reverse) {
    digitalWrite(pin, LOW);
  }
  else {
    digitalWrite(pin, HIGH);
  }
  this->statePin = false;
}

bool PINOUT::getState()
{
  return this->statePin;
}

void PINOUT::setOutput(bool _state)
{
  if (_state)
  {
    on();
  } else
  {
    off();
  }
}
void PINOUT::Toggle()
{
  if (this->statePin)
  {
    off();
  } else
  {
    on();
  }
}

bool PINOUT::isOn()
{
  return this->statePin;
}
