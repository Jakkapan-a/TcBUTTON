# PINOUT-BUTTON 1.0.0
> A simple button and pinout class for Arduino IDE with reverse logic support and easy to use and understand for beginner.
<!-- Keyword PINOUT -->
## Keyword IPNOUT
- PINOUT - KEYWORD01
<!-- Method -->
## Method PINOUT
- PINOUT name(SET PIN NUMBER FOR PINOUT, SET REVERSE FOR PINOUT (Default = false)) METHOD01
- On - METHOD02 - set pinout logic 
- Off - METHOD03 - set pinout logic
- Toggle - METHOD04 - set pinout logic
- IsOn - METHOD05 - return true if pinout is on
<!-- Keyword BUTTON -->
## Keyword BUTTON
- BUTTON - KEYWORD02
<!-- Method -->
## Method BUTTON
- BUTTON name(SET PIN NUMBER FOR BUTTON, SET REVERSE FOR BUTTON (Default = false)) METHOD06
- IsPressed - METHOD07 return true if button is pressed
<!-- Stipulation -->
## Stipulation
- Use the library pinout and button for arduino digital pin only 
<!-- Use -->
## How to use the library
1. Download the library
2. Unzip the library
3. Copy the folder to your Arduino libraries folder
4. Open the Arduino IDE
5. Open the example
6. run the example
<!-- Example -->
## Example
```c++
#include <PINOUT.h>
#include <BUTTON.h>
// Create pinout and button
PINOUT led(13); // Create pinout led on pin 13
BUTTON button(2); // Create button on pin 2
// If you want to use reverse logic
PINOUT led(13, true); // Create pinout led on pin 13 with reverse logic
BUTTON button(2, true); // Create button on pin 2 with reverse logic
```
# Use 
```c++
// Example 1 In loop
if(button.IsPressed())led.Toggle(); // Toggle led if button is pressed
// Example 2 In loop
if(button.IsPressed())led.On(); // Turn on led if button is pressed
else led.Off(); // Turn off led if button is not pressed
```
## License
Free to use and modify