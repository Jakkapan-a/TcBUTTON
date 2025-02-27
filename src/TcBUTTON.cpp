// BUTTON.cpp

#include "TcBUTTON.h"

TcBUTTON::TcBUTTON(uint8_t pin, void (*onEventChange)(bool), 
void (*press)(void), void (*release)(void), 
bool invert) {  // ลบ default argument ออก
    this->pin = pin;
    this->onEventChange = onEventChange;
    this->pressCallback = press;
    this->releaseCallback = release;
    this->isInvert = invert;
    begin();
}

void TcBUTTON::begin()
{
	pinMode(pin, (_mode == PULLUP) ? INPUT_PULLUP : INPUT);
	update();
}

void TcBUTTON::update()
{
	unsigned long currentTime = _useMicros ? micros() : millis();
    bool reading = digitalRead(pin);
    if (_mode == PULLDOWN) reading = !reading;
    if (isInvert) reading = !reading;

    if (reading != _previousState) {
        _lastDebounceTime = currentTime;
    }

    if ((currentTime - _lastDebounceTime) >= _debounceDelay || currentTime < _lastDebounceTime) {
        if (reading != _currentState) {
            _currentState = reading;
            if (_currentState == LOW && pressCallback) pressCallback();
            else if (_currentState == HIGH && releaseCallback) releaseCallback();
            if (onEventChange) onEventChange(_currentState);
        }
    }
    _previousState = reading;
}

bool TcBUTTON::getState() 
{
    update();
    return _currentState;
}

bool TcBUTTON::isPressed() 
{
    update();
    return (_currentState == LOW && _previousState == HIGH);
}
void TcBUTTON::setOnPress(void (*press)()) { pressCallback = press; }
void TcBUTTON::setOnRelease(void (*release)()) { releaseCallback = release; }
void TcBUTTON::setOnEventChange(void (*onEventChange)(bool)) { this->onEventChange = onEventChange; }
void TcBUTTON::setDebounceDelay(uint16_t delay) { _debounceDelay = delay; }
void TcBUTTON::useMicros(bool isMicros) { _useMicros = isMicros; }