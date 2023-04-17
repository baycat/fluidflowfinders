#include "Arduino.h"

int i = 1;
 
//The setup function is called once at startup of the sketch
void setup() {
  Serial.begin(9600);
  while(!Serial) { }
  Serial.println();
  Serial.println("Start device in normal mode!");
 
  delay(5000);
  // Wait for serial to initialize.
  while(!Serial) { }
 
  // Deep sleep mode for 10 seconds, the ESP8266 wakes up by itself when GPIO 16 (D0 in NodeMCU board) is connected to the RESET pin
  Serial.println("I'm awake, but I'm going into deep sleep mode for 10 seconds");
  Serial.println(i);
  i++;
  
  ESP.deepSleep(10e5);
  
  
  
}
 
void loop() {
  Serial.println("Does this ever run?");
}
