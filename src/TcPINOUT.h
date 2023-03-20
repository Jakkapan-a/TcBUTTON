#ifndef TcPINOUT_h
#define TcPINOUT_h

#include "Arduino.h"
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