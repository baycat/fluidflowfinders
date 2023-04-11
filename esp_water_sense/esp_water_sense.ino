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

bool lvl0 = 0;
bool lvl1 = 0;
bool lvl2 = 0;
bool lvl3 = 0;
bool lvl4 = 0;
bool lvl5 = 0;


void setup() {

  Serial.begin(115200);
  Serial.setTimeout(2000);
  
  //level 0
  pinMode(water_sensor_0,INPUT);

  //level 1
  pinMode(water_sensor_2,INPUT);

  //level 2
  pinMode(water_sensor_3,INPUT);

  //level 3
  pinMode(water_sensor_5,INPUT);

  //level 4
  pinMode(water_sensor_6,INPUT);
  
  //level 5
  pinMode(water_sensor_8,INPUT);


  while(!Serial) { }

  Serial.println("im awake, but am going to sleep now");
  ESP.deepSleep(0);

}

void loop() {

  //every X seconds, check the levels
  if time % X == Y ->

    //check each sensor and update level boolean
    // lvl 0 update
    if water_sensor_0
      lvl0 = 1;
    else 
      lvl0 = 0;

    // lvl 1 update
    if water_sensor_2
      lvl1 = 1;
    else 
      lvl1 = 0;

    // lvl 2
    if water_sensor_3
      lvl2 = 1;
    else 
      lvl2 = 0;

    // lvl 3 update
    if water_sensor_5
      lvl2 = 1;
    else 
      lvl2 = 0;

    // lvl 4 update
    if water_sensor_6
      lvl2 = 1;
    else 
      lvl2 = 0;

    // lvl 5 update
    if water_sensor_8
      lvl2 = 1;
    else 
      lvl2 = 0;




}
