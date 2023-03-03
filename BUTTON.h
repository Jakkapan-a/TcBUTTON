// BUTTON.h

#ifndef _BUTTON_h
#define _BUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class BUTTON
{
 protected:
	 uint8_t pin;
	 bool _state = true;
	 bool _lastState = true;
	 bool _lowState = false;
	 bool _wait = true;
	 bool _reverse = false;
	 unsigned long _lastDebounceTime = 0;
	 unsigned long _debounceDelay = 50;
	
 public:
	BUTTON(uint8_t pin, bool reverse = false);
	bool getState();
	void update();
	void init();
	bool isPressed();
	bool isReleased();
	bool isLongPressed();
};


#endif
