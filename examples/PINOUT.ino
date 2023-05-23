#include <TcPINOUT.h>

TcPINOUT LED1(2); // Set Digital Pin 2 is IO pin for pin 1 logic mode (false)
TcPINOUT LED2(3,true); // Set Digital Pin 3 is IO pin for pin 2 reverse logic mode (true)

void setup()
{
    Serial.begin(9600); // Start serial monitor
    // Pin 1 Set pin 1
    LED1.on(); // Set pin 1 to high
    delay(1000); // Wait 1 second
    LED1.off(); // Set pin 1 to low
    delay(1000); // Wait 1 second
    
    // Pin 2 Set pin 2 
    LED2.on(); // Set pin 2 to low
    delay(1000); // Wait 1 second
    LED2.off(); // Set pin 2 to high
    delay(1000); // Wait 1 second
}

void loop()
{
    // Toggle pin 1,2
    LED1.Toggle(); // Toggle pin 1
    LED2.Toggle(); // Toggle pin 2
    delay(1000); // Wait 1 second
}