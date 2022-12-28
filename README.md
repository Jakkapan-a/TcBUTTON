# PINOUT-BUTTON 1.0.0
> A simple button and pinout component for Arduino 
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
## Use
1. Download the library
2. Unzip the library
3. Copy the folder to your Arduino libraries folder
4. Open the Arduino IDE
5. Go to Sketch > Include Library > PintoutButton
6. Use the library
<!-- Example -->
## Example
```c++
#include <PINOUT.h>
#include <BUTTON.h>
