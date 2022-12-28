#include <BUTTON.h>
BUTTON b_1(2); // Set Digital Pin 2 is IO pin for button 1 logic mode (false)
BUTTON b_2(3,true); // Set Digital Pin 3 is IO pin for button 2 reverse logic mode (true)
void void setup()
{
    
}
void void loop()
{
    if(b_1.isPressed()) Serial.println("Button 1 is pressed"); // Print to serial monitor if button 1 is pressed to low    
    if(b_2.isPressed()) Serial.println("Button 2 is pressed"); // Print to serial monitor if button 2 is pressed to high
}