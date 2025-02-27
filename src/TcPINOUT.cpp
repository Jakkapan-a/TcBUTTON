#include "TcPINOUT.h"

TcPINOUT::TcPINOUT(uint8_t pin, void (*callback)(bool), bool invert) {
    this->pin = pin;
    this->_callback = callback;
    this->_invert = invert;
    begin();
}

void TcPINOUT::begin() {
    pinMode(pin, OUTPUT);
    off(); // Default to OFF state
}

void TcPINOUT::on() {
    digitalWrite(pin, _invert ? LOW : HIGH);
    _state = true;
    if (_callback && _state != _previousState) {
        _previousState = _state;
        _callback(_state);
    }
}

void TcPINOUT::off() {
    digitalWrite(pin, _invert ? HIGH : LOW);
    _state = false;
    if (_callback && _state != _previousState) {
        _previousState = _state;
        _callback(_state);
    }
}

void TcPINOUT::toggle() {
    setState(!_state);
}

void TcPINOUT::setState(bool state) {
    if (state) on();
    else off();
}

bool TcPINOUT::getState() {
    return _state;
}

bool TcPINOUT::isOn() {
    return _state;
}

void TcPINOUT::onFor(uint16_t ms) {
    on();
    _duration = ms;
    _lastTime = millis();
    _toggleCount = 0; // Disable toggling
}

void TcPINOUT::toggleFor(uint8_t count, uint16_t ms) {
    _toggleCount = count;
    _duration = ms;
    on(); // Start with ON
    _lastTime = millis();
}

void TcPINOUT::stopToggle() {
    _toggleCount = 0;
    _duration = 0;
    off();
}

uint8_t TcPINOUT::getToggleCount() {
    return _toggleCount;
}

void TcPINOUT::update() {
    if (_duration == 0) return; // No timed operation active

    unsigned long currentTime = millis();
    if ((currentTime - _lastTime >= _duration) || (currentTime < _lastTime)) {
        if (_toggleCount > 0) {
            toggle();
            _lastTime = currentTime;
            if (_state) _toggleCount--; // Decrease count only after ON cycle
        } else {
            off();
            _duration = 0; // Stop timed operation
        }
    }
}

void TcPINOUT::setCallback(void (*callback)(bool)) {
    this->_callback = callback;
}