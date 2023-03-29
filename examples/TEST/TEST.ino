#include <TcBUTTON.h>
#include <TcPINOUT.h>

#define ledPin 3
void isLED(bool);
TcPINOUT led(ledPin, isLED);
void setup() {
    Serial.begin(9600);
}

void loop() {
  led.toggle();
  delay(500);
}
void isLED(bool state){
  Serial.print("LED is ");
  Serial.println(state ? "On" : "Off");
}

