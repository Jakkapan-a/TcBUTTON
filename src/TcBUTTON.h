// TcBUTTON.h

#ifndef Tc_BUTTON_h
#define Tc_BUTTON_h

#include "Arduino.h"

class TcBUTTON
{
 protected:
	uint8_t pin;
	bool _currentState = true;
	bool _previousState = false;
	uint32_t _lastDebounceTime = 0;
	uint16_t _debounceDelay = 50;

	void (*onEventChange)(bool);
	void (*pressCallback)();
	void (*releaseCallback)();

 public:
	enum ButtonMode { PULLUP, PULLDOWN };

	TcBUTTON(uint8_t pin, void (*onEventChange)(bool) = nullptr, 
			void (*press)(void) = nullptr, void (*release)(void) = nullptr, 
			bool invert = false);

			 
	bool isInvert = false;
	ButtonMode _mode = PULLUP;
	bool getState();
    void update();
    void begin();
    void setDebounceDelay(uint16_t delay);
    void useMicros(bool isMicros);
    bool isPressed();
    void setOnPress(void (*press)());
    void setOnRelease(void (*release)());
    void setOnEventChange(void (*onEventChange)(bool));
	
	bool _useMicros = false;
};
#endif
