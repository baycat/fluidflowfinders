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

float avgBottomVoltage = 0;
float avgMidVoltage = 0;
float avgTopVoltage = 0;


void setup() {

  Serial.begin(115200);
  Serial.setTimeout(2000);
  
  //top level sensors
  pinMode(water_sensor_0,INPUT);
  pinMode(water_sensor_1,INPUT);
  pinMode(water_sensor_2,INPUT);

  //mid level sensors
  pinMode(water_sensor_3,INPUT);
  pinMode(water_sensor_4,INPUT);
  pinMode(water_sensor_5,INPUT);

  //bottom level sensors
  pinMode(water_sensor_6,INPUT);
  pinMode(water_sensor_7,INPUT);
  pinMode(water_sensor_8,INPUT);


  while(!Serial) { }

  Serial.println("im awake, but am going to sleep now");
  ESP.deepSleep(0);

}

void loop() {
  
  static unsigned long analogSampleTimepoint = millis();
  if(millis()-analogSampleTimepoint > 40U){     //every 40 milliseconds,read the analog value from the ADC
    analogSampleTimepoint = millis();
    analogBuffer[analogBufferIndex] = analogRead(TdsSensorPin);    //read the analog value and store into the buffer
    analogBufferIndex++;
    if(analogBufferIndex == SCOUNT){ 
      analogBufferIndex = 0;
    }
  //check each sensor and update average voltage level
  avgBottomVoltage =
  avgMidVoltage =
  avgTopVoltage =

  //convert average voltage to a water level
  water_lvl = (133.42*compensationVoltage*compensationVoltage*compensationVoltage - 255.86*compensationVoltage*compensationVoltage + 857.39*compensationVoltage)*0.5;

}
