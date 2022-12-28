#ifndef _PINOUT_h
#define _PINOUT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class PINOUT
{
 protected:
	 uint8_t pin;
	 bool statePin;
	 bool reverse = false;
 public:
	 PINOUT(uint8_t pin, bool _state = false);
	 void on();
	 void off();
	 void init();
   bool getState();
   void Toggle();
   bool IsOn();
   void setOutput(bool _state);
};


#endif
