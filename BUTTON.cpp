// 
// 
// 

#include "BUTTON.h"

void BUTTON::init()
{
	pinMode(this->pin, INPUT_PULLUP);
	update();
}
BUTTON::BUTTON(uint8_t pin, bool reverse = false)
{
	this->pin = pin;
	this->_reverse = reverse;
	init();
}

void BUTTON::update()
{
	bool reading = digitalRead(this->pin); // H
	if (reading != this->_lastState) { // L H!=L
		this->_lastDebounceTime = millis();
	}
	// Push button is pressed when LOW is read from the pin (active low)
	if (millis() - this->_lastDebounceTime >= this->_debounceDelay) {
		if (reading != this->_state) {
			this->_state = reading;
		}
	}
this->_lastState = reading;
}

bool BUTTON::getState() 
{
	update();
	if(this->_reverse)
		return !this->_state;

	return this->_state;
}


bool BUTTON::isPressed()
{
	return (getState() == LOW && this->_lastState == HIGH);
}

bool BUTTON::isReleased()
{
	return (getState() == HIGH && this->_lastState == LOW);
}
