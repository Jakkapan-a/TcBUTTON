#include <PINOUT.h>

PINOUT p_1(2); // Set Digital Pin 2 is IO pin for pin 1 logic mode (false)
PINOUT p_2(3,true); // Set Digital Pin 3 is IO pin for pin 2 reverse logic mode (true)

void setup()
{
    Serial.begin(9600); // Start serial monitor
    // Pin 1 Set pin 1
    p_1.on(); // Set pin 1 to high
    delay(1000); // Wait 1 second
    p_1.off(); // Set pin 1 to low
    delay(1000); // Wait 1 second
    
    // Pin 2 Set pin 2 
    p_2.on(); // Set pin 2 to low
    delay(1000); // Wait 1 second
    p_2.off(); // Set pin 2 to high
    delay(1000); // Wait 1 second
}

void loop()
{
    // Toggle pin 1,2
    p_1.Toggle(); // Toggle pin 1
    p_2.Toggle(); // Toggle pin 2
    delay(1000); // Wait 1 second
}