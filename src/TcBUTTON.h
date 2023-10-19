// TcBUTTON.h

#ifndef Tc_BUTTON_h
#define Tc_BUTTON_h

#include "Arduino.h"

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
	void (*onEventChange)(bool);
	void (*pressCallback)();
    void (*releaseCallback)();

 public:
	enum ButtonMode 
	{
		PULLUP,
		PULLDOWN
	};
	TcBUTTON(uint8_t pin, int invert = false);
	TcBUTTON(uint8_t pin, void (*press)(void), void (*release)(void), int _invert);
	TcBUTTON(uint8_t pin, void (*onEventChange)(bool), void (*press)(void), void (*release)(void), int _invert);
	TcBUTTON(uint8_t pin, void (*onEventChange)(bool), int _invert);

	bool isInvert = false;
	ButtonMode _mode = PULLUP;
	bool getState();
	void update();
	void init();
	bool isPressed();
	void setOnPress(void (*press)(void));
	void setOnRelease(void (*release)(void));
	void setOnEventChange(void (*onEventChange)(bool));
	void setDebounceDelay(unsigned long delay);
	void setMicros(bool isMicros);
	bool isMicros = false;
};
#endif
