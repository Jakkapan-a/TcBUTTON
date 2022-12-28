// 
// 
// 

#include "BUTTON.h"

void BUTTON::init()
{
	pinMode(this->pin, INPUT_PULLUP);
	update();
}
BUTTON::BUTTON(uint8_t pin) 
{
	this->pin = pin;
	init();
}

void BUTTON::update()
{
	bool reading = digitalRead(this->pin); // H
	if (reading != this->_lastState) { // L H!=L
		this->_lastDebounceTime = millis();
	}

	if ((millis() - this->_lastDebounceTime) > this->_debounceDelay) {
		if (reading != this->_state) {
			this->_state = reading;
		}
	}
 this->_lastState = reading;
}

bool BUTTON::getState() 
{
	update();
	return this->_state;
}


bool BUTTON::isPressed()
{
	return (getState() == LOW);
}
