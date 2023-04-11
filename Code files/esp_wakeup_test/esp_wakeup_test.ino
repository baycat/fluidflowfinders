/*
 * ESP8266 Deep sleep mode example
 * Rui Santos 
 * Complete Project Details https://randomnerdtutorials.com
 */
 
void setup() {
  Serial.begin(115200);
  Serial.setTimeout(2000);

  // Wait for serial to initialize.
  while(!Serial) { }
  
  // Deep sleep mode until RESET pin is connected to a LOW signal (for example pushbutton or magnetic reed switch)
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println("im awake, but am going to sleep now");
  ESP.deepSleep(0); 
}

void loop() {
}