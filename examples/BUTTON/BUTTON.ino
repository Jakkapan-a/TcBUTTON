#include <TcBUTTON.h>
#include <TcPINOUT.h>

TcPINOUT led(13);
// Use the function pointer to call the function

void isPressed(){
  led.on();
  Serial.println("Button Pressed");
}

void isReleased(){
  led.off();
  Serial.println("Button Released");
}

TcBUTTON button(2,isPressed,isReleased);
void func_callback_led(bool input){
  Serial.print("LED :");
  Serial.println(input);
}

void setup() {
  // put your setup code here, to run once:
  led.setCallback(func_callback_led);
}

void loop() {
  // put your main code here, to run repeatedly:
  button.update();
}
