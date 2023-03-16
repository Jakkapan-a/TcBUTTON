// BUTTON.cpp

#include "TcBUTTON.h"

void TcBUTTON::init()
{
	if(this->_mode == PULLUP){
		pinMode(this->pin, INPUT_PULLUP);
	}else{
		pinMode(this->pin, INPUT);
	}
	update();
}
TcBUTTON::TcBUTTON(uint8_t pin,ButtonMode mode = PULLUP, int _invert = false)
{
	this->pin = pin;
	this->invert = _invert;
	this->_mode = mode;
	init();
}

TcBUTTON::TcBUTTON(uint8_t pin, void (*press)(void) = NULL, void (*release)(void) = NULL, ButtonMode mode = PULLUP,int _invert = false){
	this->pin = pin;
	this->pressCallback = press;
	this->releaseCallback = release;
	this->_mode = mode;
	this->invert = _invert;
	init();
}

void TcBUTTON::update()
{
	bool reading = digitalRead(this->pin); // H
	if(this->invert)
		reading = !reading;

	if (reading != this->_lastState) { // L H!=L
		this->_lastDebounceTime = millis();
	}
	// Push button is pressed when LOW is read from the pin (active low)
	if (millis() - this->_lastDebounceTime >= this->_debounceDelay) {
		if (reading != this->_state) {
			this->_state = reading;

			if (this->_state == LOW) {
				if (this->pressCallback != NULL) {
					this->pressCallback(); // call the function button was pressed
				}
			}
			else {
				if (this->releaseCallback != NULL) {
					this->releaseCallback(); // call the function button was released
				}
			}
		}
	}
	this->_lastState = reading;
}

bool TcBUTTON::getState() 
{
	update();
	if(this->invert)
		return !this->_state;

	return this->_state;
}


bool TcBUTTON::isPressed()
{
	return (getState() == LOW && this->_lastState == HIGH);
}
