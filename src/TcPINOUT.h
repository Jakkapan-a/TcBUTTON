#ifndef TcPINOUT_h
#define TcPINOUT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
class TcPINOUT
{
protected:
    uint8_t pin;
    bool statePin;
    bool invert;
 	void (*callback)(bool);
public:

    TcPINOUT(uint8_t pin, bool invert = false);
	TcPINOUT(uint8_t pin,void (*_callback)(bool) , bool invert = false);
    void on();
    void off();
    void init();
    bool getState();
    void toggle();
    bool isOn();
    void setOutput(bool _state);
	void setCallback(void (*callback)(bool) );
};
#endif