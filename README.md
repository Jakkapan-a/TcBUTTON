# TcBUTTON 1.0.11
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
5. Go to File > Examples > TcBUTTON > Button
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
#include <TcBUTTON.h>

void buttonPressed() {
    Serial.println("Button Pressed!");
}

BUTTON myButton(2, buttonPressed, true, PULLUP, false); // reverseLogic = true

void setup() {
    Serial.begin(9600);
    myButton.begin();
}

void loop() {
    myButton.update();
}

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