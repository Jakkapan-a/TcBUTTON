// 
// 
// 

#include "BUTTON.h"

void BUTTON::init()
{
	pinMode(this->pin, INPUT_PULLUP);
	update();
}
BUTTON::BUTTON(uint8_t pin, bool _invert = false)
{
	this->pin = pin;
	this->invert = _invert;
	init();
}

BUTTON::BUTTON(uint8_t pin, void (*press)(void) = NULL, void (*release)(void) = NULL, bool _invert = false){
	this->pin = pin;
	this->pressCallback = press;
	this->releaseCallback = release;
	this->invert = _invert;
	init();
}

void BUTTON::update()
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

bool BUTTON::getState() 
{
	update();
	if(this->invert)
		return !this->_state;

	return this->_state;
}


bool BUTTON::isPressed()
{
	return (getState() == LOW && this->_lastState == HIGH);
}
