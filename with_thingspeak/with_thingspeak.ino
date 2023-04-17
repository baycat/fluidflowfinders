//  https://circuitdigest.com/microcontroller-projects/esp8266-deep-sleep-mode-programming-explanation
// https://thingspeak.com/channels/2109180/private_show

// esp8266 deepsleep

#include <ESP8266WiFi.h>

String apiWritekey = "YBXF584WEOE32Z5N"; 

char ssid[] = "XXXXXXXXXX"; // enter your wifi home router ssid

char password[] = "XXXXXXXXXX" ;   // enter your wifi home router ssid

char server[] = "api.thingspeak.com";

double tempF;

double tempC;

WiFiClient client;

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

  Serial.print("NodeMcu connected to wifi...");

}

 

void data() {

  if (client.connect(server,80))

  {  

    String Data = apiWritekey;

           Data +="&field1=";

           Data += String(tempF);

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

void setup() {

  Serial.begin(115200);

  Serial.println("device is in Wake up mode");

  while (!Serial) { }

  connect1();

  int value = analogRead(A0);

  float volts=(value/1024.0)*5.0;      //conversion to volts

  tempC = volts*100.0;             //conversion to temp Celsius

  Serial.print("Temperature C: ");

  Serial.println(tempC);

  data();

  Serial.println("deep sleep for 15 seconds");

  ESP.deepSleep(15e6); 

}

void loop() {

}
