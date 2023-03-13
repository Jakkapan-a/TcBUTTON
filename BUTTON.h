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
	bool _lastState = false;
	bool _lowState = false;
	bool _wait = false;

	unsigned long _lastDebounceTime = 0;
	unsigned long _debounceDelay = 50;
	void (*onPress)();
    void (*onRelease)();

	void (*pressCallback)();
    void (*releaseCallback)();
	
 public:
	BUTTON(uint8_t pin, bool invert = false);
	BUTTON(uint8_t pin, void (*press)(void), void (*release)(void));
	bool invert = false;
	bool getState();
	void update();
	void init();
	bool isPressed();
};


#endif
