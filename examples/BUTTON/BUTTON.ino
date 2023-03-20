#include <BUTTON.h>
#include <PINOUT.h>

PINOUT led(13);
// Use the function pointer to call the function
BUTTON button(2,[]
{
  led.on();
  Serial.println("Button Pressed");
},[]
{
  led.off();
  Serial.println("Button Released");
});

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  button.update();
}
