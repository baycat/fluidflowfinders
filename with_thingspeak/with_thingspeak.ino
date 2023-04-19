//  https://circuitdigest.com/microcontroller-projects/esp8266-deep-sleep-mode-programming-explanation
// https://thingspeak.com/channels/2109180/private_show

// esp8266 deepsleep

#include <ESP8266WiFi.h>
String apiWritekey = "YBXF584WEOE32Z5N"; 
char ssid[] = "Rice Visitor"; // enter your wifi home router ssid
char password[] = "xxxxxxxx" ;   // enter your wifi home router ssid
char server[] = "api.thingspeak.com";
WiFiClient client;

// GPIO Pins on WEMOS D1
#define water_sensor_1 D1 // D1
#define water_sensor_3 4 // D2
#define water_sensor_5 14 // D5
#define water_sensor_7 12 // D6
#define water_sensor_9 13 // D7
#define water_sensor_11 A0 // D8


bool lvl1 = 0;
bool lvl2 = 0;
bool lvl3 = 0;
bool lvl4 = 0;
bool lvl5 = 0;
bool lvl6 = 0;

void connect1() {

  WiFi.disconnect();
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("NodeMcu connected to wifi...");

}

void initialize_sensors() {
  //level 0
  pinMode(water_sensor_1,INPUT_PULLUP);

  //level 1
  pinMode(water_sensor_3,INPUT_PULLUP);

  //level 2
  pinMode(water_sensor_5,INPUT_PULLUP);

  //level 3
  pinMode(water_sensor_7,INPUT_PULLUP);

  //level 4
  pinMode(water_sensor_9,INPUT_PULLUP);
  
  //level 5
  pinMode(water_sensor_11,INPUT_PULLUP);
}

 

void postdata(int data) {

  if (client.connect(server,80)) {  
     String Data = apiWritekey;
           Data +="&field1=";
           Data += String(data);
           Data += "\r\n\r\n";

     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiWritekey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(Data.length());
     client.print("\n\n");  
     client.print(Data);
     
     Serial.println("uploaded to Thingspeak server....");
  }

  client.stop();

}

int getWaterLevel() {
   lvl1 = digitalRead(water_sensor_1);
   lvl2 = digitalRead(water_sensor_3);
   lvl3 = digitalRead(water_sensor_5);
   lvl4 = digitalRead(water_sensor_7);
   lvl5 = digitalRead(water_sensor_9);
   lvl6 = (analogRead(water_sensor_11) > 512); // | digitalRead(water_sensor_12);

   Serial.print(lvl1);
   Serial.print(", ");
   Serial.print(lvl2);
   Serial.print(", ");
   Serial.print(lvl3);
   Serial.print(", ");
   Serial.print(lvl4);
   Serial.print(", ");
   Serial.print(lvl5);
   Serial.print(", ");
   Serial.print(lvl6);
   Serial.print(", ");

   if (lvl6){
      return 6;
   } else if (lvl5){
      return 5;
   } else if (lvl4){
      return 4;
   } else if (lvl3){
      return 3;
   } else if (lvl2){
      return 2;
   } else if (lvl1){
      return 1;
   } else {
      // No sensors activated
      return 0;
   }
  
}


void setup() {

  Serial.begin(115200);
  Serial.println("device is in Wake up mode");

  
  while (!Serial) { }

  
  initialize_sensors();
  connect1();

  int level = getWaterLevel();
  Serial.print("Current level: ");
  Serial.println(level);
  postdata(level);

  Serial.println("deep sleep for 5 seconds");
  ESP.deepSleep(5e6); 

}

void loop() {
  // Intentionally empty. With deepsleep, this code is never run
}
