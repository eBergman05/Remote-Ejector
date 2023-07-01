//Running Arduino Nano
//Using the gear chanel of an RC transmitter and receiver
//pulse ~1077us when low and ~1911us when high
//a pulse over 1500us will trigger the ejection system

#include <Arduino.h>

#define radio 10
#define solenoid 11

void setup() {
  pinMode(radio, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(solenoid, OUTPUT);
  digitalWrite(solenoid, LOW);
}

void loop() {
  if(pulseIn(radio, HIGH) > 1500) {
    digitalWrite(solenoid, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(solenoid, LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }
}