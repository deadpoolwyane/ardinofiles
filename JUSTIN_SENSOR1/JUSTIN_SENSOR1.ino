#include<DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define  DHT11_PIN 8
#define echo 3
#define trig 4
const int MQ135_PIN=A1;

 int duration=0;
 int distance=0;
 int distance2=0;
  void setup()
  {
    Serial.begin(9600);
    pinMode(3,INPUT);//ultra
    pinMode(4,OUTPUT);//ultra
    pinMode(8,OUTPUT);//dht
    pinMode(A0,OUTPUT);//motion
    pinMode(5,OUTPUT);//LED
    pinMode(A1,OUTPUT);//ALCHO SENOR
  }

  void loop()
  {
  distance1();
  Serial.print(" distance :");
  Serial.println(distance);
     DHT.read(DHT11_PIN);
  Serial.print("temp:");
  Serial.print(DHT.temperature);
  Serial.print("  humi:");
  Serial.println(DHT.humidity);
//  delay(1000);
  
  int motionDetected= digitalRead(8);
  Serial.println(motionDetected);
   if(motionDetected==HIGH){
    Serial.println("MOTION DETECTED");
    digitalWrite(5,HIGH);
    delay(1000);
        digitalWrite(5,LOW);
        delay(1000);
   }
  }
    
  void distance1()
  {
    
    digitalWrite(4,LOW);
    delay(5);
    digitalWrite(4,HIGH);
    delay(10);
    digitalWrite(4,LOW);
    duration=pulseIn(3,HIGH);
    distance=duration*0.34/2;
    return distance;
    
    
    }
