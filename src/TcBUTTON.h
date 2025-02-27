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
	uint32_t _pressStartTime = 0;
	bool _holdTriggered = false;

	void (*onEventChange)(bool);
	void (*pressCallback)();
	void (*releaseCallback)();
	void (*holdCallback)(); // 

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
	bool isHeld();
    void setOnPress(void (*press)());
    void setOnRelease(void (*release)());
    void setOnEventChange(void (*onEventChange)(bool));
	void setOnHold(void (*hold)(), uint16_t holdTime = 1000);
	
private:
	bool _useMicros = false;
	uint16_t _holdTime = 1000;
};
#endif
