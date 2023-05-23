# TcBUTTON 1.0.7
> A library for arduino to use button and pinout with external function, reverse logic and callback function

<!-- Stipulation -->
## Stipulation
- Arduino IDE 1.8.5 or higher

<!-- Use -->
## How to use the library
1. Download the library
2. Unzip the library
3. Copy the folder to your Arduino libraries folder
4. Open the Arduino IDE
5. Open the example
6. run the example

## In version 1.0.0
- Add Callback function
- Add Reverse Logic
- Add External Function
- Add Mode Button PULLUP and PULLDOWN

## In version 1.0.6
- Add Callback function in TcPINOUT
- Add Invert Logic in TcPINOUT


```C++
BUTTON button(pin, callback, reverseLogic, mode,invertLogic);

pin is pin button
callback is callback function
reverseLogic is reverse logic button
mode is mode button PULLUP or PULLDOWN
invertLogic is invert logic button
```

<!-- Example -->
## Example
```c++
#include <TcPINOUT.h>
#include <TcBUTTON.h>
// Create pinout and button
TcPINOUT led(13); // Create pinout led on pin 13
TcBUTTON button(2); // Create button on pin 2
// If you want to use invert logic
TcPINOUT led(13,mode, true); // Create pinout led on pin 13 with invert logic
TcBUTTON button(2,mode, true); // Create button on pin 2 with invert logic
// Create button with callback function
TcBUTTON button(2,[]
{
  // This function will be called when button is pressed  
  Serial.println("Button Pressed");
},[]
{
  // This function will be called when button is released  
  Serial.println("Button Released");
});

// Create button with reverse logic
BUTTON button(2,[]
{
  // This function will be called when button is pressed  
  Serial.println("Button Pressed");
},[]
{
  // This function will be called when button is released  
  Serial.println("Button Released");
}, true);

// If want external function is used
void ButtonPressed()
{
  // This function will be called when button is pressed  
  Serial.println("Button Pressed");
}
void ButtonReleased()
{
  // This function will be called when button is released  
  Serial.println("Button Released");
}
// Create button with external function
TcBUTTON button(2, ButtonPressed, ButtonReleased);
// Create button with reverse logic and external function
TcBUTTON button(2, ButtonPressed, ButtonReleased, true);

```
# Use 
```c++
// Example 1
if(button.IsPressed())led.Toggle(); // Toggle led if button is pressed
// Example 2
if(button.IsPressed())led.On(); // Turn on led if button is pressed
else led.Off(); // Turn off led if button is not pressed

void ButtonPressed()
{
  led.Toggle(); 
  Serial.println("Button Pressed");
}

void loop(){
  button.update(); // Update button
}
```
<!-- Logic -->
## Logic Button
<!-- Image Size Small -->
![image](/images/02.png) 

<!-- Circuit -->
## Circuit
![image](/images/01.jpg)
## License
MIT License