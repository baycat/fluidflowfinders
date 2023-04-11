// esp8266 based water level sensing and reporting


#define water_sensor_0 A0
#define water_sensor_1 A1
#define water_sensor_2 A2
#define water_sensor_3 A3
#define water_sensor_4 A4
#define water_sensor_5 A5
#define water_sensor_6 A6
#define water_sensor_7 A7
#define water_sensor_8 A8

float averageVoltage = 0;


void setup() {

  Serial.begin(115200);
  Serial.setTimeout(2000);
  
  pinMode(water_sensor_0,INPUT);
  pinMode(water_sensor_1,INPUT);
  pinMode(water_sensor_2,INPUT);
  pinMode(water_sensor_3,INPUT);
  pinMode(water_sensor_4,INPUT);
  pinMode(water_sensor_5,INPUT);
  pinMode(water_sensor_6,INPUT);
  pinMode(water_sensor_7,INPUT);
  pinMode(water_sensor_8,INPUT);


  while(!Serial) { }

  Serial.println("im awake, but am going to sleep now");
  ESP.deepSleep(0);

}

void loop() {

  //check each sensor and update average voltage level


  //convert average voltage to a water level
   

}
