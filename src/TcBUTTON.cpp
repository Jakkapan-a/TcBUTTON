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
	this->isInvert = _invert;
	this->_mode = mode;
	init();
}

TcBUTTON::TcBUTTON(uint8_t pin, void (*press)(void) = NULL, void (*release)(void) = NULL, ButtonMode mode = PULLUP,int _invert = false){
	this->pin = pin;
	this->pressCallback = press;
	this->releaseCallback = release;
	this->_mode = mode;
	this->isInvert = _invert;
	init();
}

TcBUTTON::TcBUTTON(uint8_t pin, void (*onEventChange)(bool), void (*press)(void), void (*release)(void),  ButtonMode mode = PULLUP, int _invert = false)
{
	this->pin = pin;
	this->onEventChange = onEventChange;
	this->pressCallback = press;
	this->releaseCallback = release;
	this->_mode = mode;
	this->isInvert = _invert;
	init();
}
void TcBUTTON::update()
{
	unsigned long currentTime = isMicros ? micros() : millis();
	bool reading = digitalRead(this->pin); // H
	if(this->isInvert)
		reading = !reading;

	if (reading != this->_lastState) { // L H!=L
		// this->_lastDebounceTime = millis();
		this->_lastDebounceTime = currentTime;
	}
	// Push button is pressed when LOW is read from the pin (active low)
	if (currentTime - this->_lastDebounceTime >= this->_debounceDelay) {
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

			if (this->onEventChange != NULL) {
				this->onEventChange(this->_state);
			}
		}
	}
	this->_lastState = reading;
}

bool TcBUTTON::getState() 
{
	update();
	return this->_state;
}


bool TcBUTTON::isPressed()
{
	return (getState() == LOW && this->_lastState == HIGH);
}

void TcBUTTON::setOnPress(void (*press)(void))
{
	this->pressCallback = press;
}

void TcBUTTON::setOnRelease(void (*release)(void))
{
	this->releaseCallback = release;
}

void TcBUTTON::setOnEventChange(void (*onEventChange)(bool))
{
	this->onEventChange = onEventChange;
}

void TcBUTTON::setDebounceDelay(unsigned long delay)
{
	this->_debounceDelay = delay;
}

