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

	uint32_t _lastDebounceTime = 0;
	uint16_t _debounceDelay = 50;

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
	TcBUTTON(uint8_t pin, void (*onEventChange)(bool),int _invert);

	bool isInvert = false;
	ButtonMode _mode = PULLUP;
	bool getState();
	void update();
	void init();
	bool isPressed();
	void OnPress(void (*press)(void));
	void OnRelease(void (*release)(void));
	void OnEventChange(void (*onEventChange)(bool));
	void DebounceDelay(unsigned long delay);
	void Micros(bool isMicros);
	bool isMicros = false;
};
#endif
