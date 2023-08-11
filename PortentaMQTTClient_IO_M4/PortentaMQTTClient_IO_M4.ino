/***************************************************
  I/O client for the Portenta

  Version: 0.1
  Date: 11th Aug 2023
  Author: Peter Milne

  Copywrite 2022 Peter Milne
  Released under GNU GENERAL PUBLIC LICENSE
  Version 3, 29 June 2007

 ****************************************************/

#include <Arduino_MachineControl.h>

using namespace machinecontrol;

int ledState = LOW;
unsigned long previousMillis = 0;
const long INTERVAL = 500; // (unit: ms)

void setup() {
  digital_outputs.setLatch();
}

void loop() {
  unsigned long currentMillis = millis();          
  if ( currentMillis - previousMillis >= INTERVAL) 
  {
    previousMillis = currentMillis;                
    (ledState == LOW) ? (ledState = HIGH) : (ledState = LOW);
    digital_outputs.set( 0, ledState);
  }
}
