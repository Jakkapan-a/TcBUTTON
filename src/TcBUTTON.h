// TcBUTTON.h

#ifndef Tc_BUTTON_h
#define Tc_BUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class TcBUTTON
{
 protected:
	uint8_t pin;
	bool _state = true;
	bool _lastState = false;
	bool _lowState = false;

	unsigned long _lastDebounceTime = 0;
	unsigned long _debounceDelay = 50;


	void (*onPress)();
    void (*onRelease)();

	void (*pressCallback)();
    void (*releaseCallback)();
	
 public:
	enum ButtonMode 
	{
		PULLUP,
		PULLDOWN
	};

	TcBUTTON(uint8_t pin, ButtonMode mode = PULLUP, int _invert = false);
	TcBUTTON(uint8_t pin, void (*press)(void), void (*release)(void),  ButtonMode mode = PULLUP, int _invert = false);
	bool invert = false;
	ButtonMode _mode;
	bool getState();
	void update();
	void init();
	bool isPressed();
};


#endif