#include <PINOUT.h>
#include <BUTTON.h>

BUTTON button(2); // Set Digital Pin 2 is IO pin for button 1 logic mode (false)
PINOUT LED(13); // Set Digital Pin 13 is IO pin for LED 1 logic mode (false)
void setup()
{
    Serial.begin(9600); // Start serial monitor
}

void loop()
{
   if(button.isPressed()) LED.on(); // If button is pressed, turn on LED
   else LED.off(); // If button is not pressed, turn off LED
}
