int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
int led9 = 10; 
int led10 = 11;
int led11 = 12;
int led12 = 13;
int sensor1 = 1+1;
int sensor2 = 2+1;
int sensor3 = 3+1;
int sensor4 = 4+1;
int sensor5 = 5+1;
int sensor6 = 6+1;
int sensor7 = 7+1;
int sensor8 = 8+1;
int sensor9 = 9+1;
int sensor10 = 10+1;
int sensor11 = 11+1;
int sensor12 = 12+1;
int data1 = 0;
int data2 = 0;
int data3 = 0;
int data4 = 0;
int data5 = 0;
int data6 = 0;
int data7 = 0;
int data8 = 0;
int data9 = 0;
int data10 = 0;
int data11 = 0;
int data12 = 0;
int d = 0;
//bool message_available = false;
//String incomingByte;

int sensors;

//#include <EMailSender.h>
//#include <ESP8266WiFi.h>
//EMailSender emailSend("intradrainalertnetwork@gmail.com", "wbhltndtuzidoijh");  
//bool sent = false;

void setup() {
Serial.begin(9600);
//computer
delay(10);
/*
Serial.println('\n');
 
WiFi.begin("Rice Visitor");             // Connect to the network
Serial.print("Connecting to ");
Serial.print("Rice Visitor"); Serial.println(" ...");
*/
/*
for (int i=sensor1; i<=sensor2; i++) {
  pinMode(i, INPUT);
}
// set buttin pin to INPUT
for (int o=led1; o<=led4; o++) {
  pinMode(o, OUTPUT);
}
*/

}
/*if (data1 == 1) {
digitalWrite(led1,HIGH);
}
if (data1 == 0) {
digitalWrite(led1,LOW);
}*/

void loop() {
/*
data1=analogRead(A0);
if(data1>900){
  d=1;
}else{
  d=0;
}
*/
//Serial.print("data1= ");
//uncomment below
//Serial.println(d);

data1=digitalRead(sensor1);
//Serial.print(",");
//Serial.print("data2= ");
Serial.print(data1,DEC);

data2=digitalRead(sensor2);
Serial.print(",");
//Serial.print("data2= ");
Serial.print(data2,DEC);

data3=digitalRead(sensor3);
Serial.print(",");
Serial.print(data3,DEC);

data4=digitalRead(sensor4);
Serial.print(",");
Serial.print(data4,DEC);

data5=digitalRead(sensor5);
Serial.print(",");
Serial.print(data5,DEC);

data6=digitalRead(sensor6);
Serial.print(",");
Serial.print(data6,DEC);

data7=digitalRead(sensor7);
Serial.print(",");
Serial.print(data7,DEC);

data8=digitalRead(sensor8);
Serial.print(",");
Serial.print(data8,DEC);

data9=digitalRead(sensor9);
Serial.print(",");
Serial.print(data9,DEC);

data10=digitalRead(sensor10);
Serial.print(",");
Serial.print(data10,DEC);

data11=digitalRead(sensor11);
Serial.print(",");
Serial.println(data11,DEC);

//Serial.println("-------");)
delay(1000);
//EMailSender::EMailMessage message;
/*
if(d>0){
  if(Serial.available()) {
    incomingByte = Serial.readString();
    message_available = true;
    //digitalWrite(LED_BUILTIN, HIGH);
    delay(10);
    //Serial.println(incomingByte);
  }

  if(message_available == true) {
    message.subject = "LEAK";
    message.message = incomingByte;
  
    EMailSender::Response resp = emailSend.send("intradrainalertnetwork@gmail.com", message);
    //Serial.println("Sending status: ");
    //Serial.println(resp.code);
    //Serial.println(resp.desc);
    message_available = false;
  }
}
*/
}
/* 
data5=digitalRead(sensor5);
Serial.print(",");
Serial.print(data5,DEC);

data6=digitalRead(sensor6);
Serial.print(",");
Serial.print(data6,DEC);

data7=digitalRead(sensor7);
Serial.print(",");
Serial.print(data7,DEC);

data8=digitalRead(sensor8);
Serial.print(",");
Serial.print(data8,DEC);

data9=digitalRead(sensor9);
Serial.print(",");
Serial.print(data9,DEC);

data10=digitalRead(sensor10);
Serial.print(",");
Serial.print(data10,DEC);

data11=digitalRead(sensor11);
Serial.print(",");
Serial.print(data11,DEC);

data12=digitalRead(sensor12);
Serial.print(",");
Serial.println(data12,DEC);

*/
