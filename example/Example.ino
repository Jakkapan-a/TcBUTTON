#include <PINOUT.h>
#include <BUTTON.h>

// Set Digital Pin 2 is IO pin for pin 1 logic mode (false)
// Set Digital Pin 3 is IO pin for pin 2 reverse logic mode (true)
BUTTON b_1(2);
PINOUT LED(8);

void setup()
{
    Serial.begin(9600); // Start serial monitor
}

void loop()
{
   if(b_1.isPressed()) LED.on();
   else LED.off();
}
