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
TcBUTTON::TcBUTTON(uint8_t pin, int invert)
{
	this->pin = pin;
	this->isInvert = invert;
	init();
}

TcBUTTON::TcBUTTON(uint8_t pin, void (*press)(void), void (*release)(void), int _invert){
	this->pin = pin;
	this->pressCallback = press;
	this->releaseCallback = release;
	this->isInvert = _invert;
	init();
}

TcBUTTON::TcBUTTON(uint8_t pin, void (*onEventChange)(bool), void (*press)(void), void (*release)(void), int _invert)
{
	this->pin = pin;
	this->onEventChange = onEventChange;
	this->pressCallback = press;
	this->releaseCallback = release;
	this->isInvert = _invert;
	init();
}
TcBUTTON::TcBUTTON(uint8_t pin, void (*onEventChange)(bool),int _invert)
{
	this->pin = pin;
	this->onEventChange = onEventChange;
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
	}else if(currentTime < this->_lastDebounceTime){ // overflow
		this->_lastDebounceTime = currentTime;
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

void TcBUTTON::OnPress(void (*press)(void))
{
	this->pressCallback = press;
}

void TcBUTTON::OnRelease(void (*release)(void))
{
	this->releaseCallback = release;
}

void TcBUTTON::OnEventChange(void (*onEventChange)(bool))
{
	this->onEventChange = onEventChange;
}

void TcBUTTON::DebounceDelay(unsigned long delay)
{
	this->_debounceDelay = delay;
}

void TcBUTTON::Micros(bool isMicros)
{
	this->isMicros = isMicros;
}

