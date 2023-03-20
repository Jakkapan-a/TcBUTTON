#include "TcPINOUT.h"

void TcPINOUT::init()
{
    pinMode(pin, OUTPUT);
    off();
}

TcPINOUT::TcPINOUT(uint8_t pin, bool _invert = false)
{
    this->pin = pin;
    this->invert = _invert;
    init();
}

TcPINOUT::TcPINOUT(uint8_t pin,void (*_callback)(bool), bool _invert = false)
{
    this->pin = pin;
    this->invert = _invert;
    this->callback = _callback;
    init();
}
void TcPINOUT::on()
{
    if (this->invert) {
        digitalWrite(pin, LOW);
    } else {
        digitalWrite(pin, HIGH);
    }
    // Set state to true
    this->statePin = true;
    // Check if callback is set and call it
    if(this->callback != NULL) 
    { 
      // Call the callback function
      this->callback(true);
    }
}

void TcPINOUT::off()
{
    if (this->invert) {
        digitalWrite(pin, HIGH);
    } else {
        digitalWrite(pin, LOW);
    }
    // Set the state to false
    this->statePin = false;
    // Check if callback is set and call it
    if(this->callback != NULL) 
    { 
      // Call the callback function
      this->callback(false);
    }
}

bool TcPINOUT::getState()
{
    return this->statePin;
}

void TcPINOUT::setOutput(bool _state)
{
    if (_state) {
        on();
    } else {
        off();
    }
}

void TcPINOUT::toggle()
{
    if (this->statePin) {
        off();
    } else {
        on();
    }
}

bool TcPINOUT::isOn()
{
    return this->statePin;
}

void TcPINOUT::setCallback(void (*_callback)(bool))
{
    this->callback = _callback;
}