#include <TcBUTTON.h>

void b_1Pressed(bool);
void b_2Pressed(bool)
TcBUTTON b_1(2,b_1Pressed,NULL); // Set Digital Pin 2 is IO pin for button 1 logic mode (false)
TcBUTTON b_2(3,b_2Pressed,NULL,true); // Set Digital Pin 3 is IO pin for button 2 reverse logic mode (true)
void void setup()
{
    Serial.begin(9600); // Start serial monitor
}
void void loop()
{
   b_1.update(); // Update button 1
   b_2.update(); // Update button 2
}

void b_1Pressed(bool state)
{
    Serial.println("Button 1 is pressed");
}

void b_2Pressed(bool state)
{
    Serial.println("Button 2 is pressed");
}