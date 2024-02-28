#include "TcPINOUT.h"

void TcPINOUT::init()
{
    pinMode(pin, OUTPUT);
    off();
}

TcPINOUT::TcPINOUT(uint8_t pin, bool _invert)
{
    this->pin = pin;
    this->invert = _invert;
    init();
}

TcPINOUT::TcPINOUT(uint8_t pin,void (*_callback)(bool), bool _invert)
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
    if(this->callback != NULL && this->oldStatePin != this->statePin) 
    { 
       this->oldStatePin = this->statePin;
      // Call the callback function
      this->callback(this->statePin);
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
    if(this->callback != NULL && this->oldStatePin != this->statePin) 
    { 
        this->oldStatePin = this->statePin;
      // Call the callback function
    this->callback(this->statePin);
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
void TcPINOUT::on(int ms)
{
    on();
    this->_ms = ms;
    this->_lastDebounceTime = millis();
}
void TcPINOUT::update()
{
    if (this->_ms > 0) {
        if (millis() - this->_lastDebounceTime > this->_ms) {
            off();
            this->_ms = 0;
        }else if(millis() < this->_lastDebounceTime){
            this->_lastDebounceTime = millis();
        }
    }
}