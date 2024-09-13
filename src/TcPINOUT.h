#ifndef TcPINOUT_h
#define TcPINOUT_h

#include "Arduino.h"
class TcPINOUT
{
protected:
    uint8_t pin;
    bool statePin = false;
    bool oldStatePin = false;

    bool invert;
 	void (*callback)(bool);
    uint32_t _lastDebounceTime = 0;
    uint16_t _ms = 0;

    uint8_t _toggleCount = 0;
public:
    TcPINOUT(uint8_t pin, bool invert = false);
	TcPINOUT(uint8_t pin,void (*_callback)(bool) , bool invert = false);
    void on();
    void on(int ms);
    void update();
    void off();
    void init();
    bool getState();
    void toggle();
    void onToggle(uint8_t toggleCount, int ms);
    void noToggle();
    uint8_t getToggleCount();
    bool isOn();
    void setOutput(bool _state);
	void setCallback(void (*callback)(bool));
};
#endif