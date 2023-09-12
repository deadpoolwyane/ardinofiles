#include <DFRobot_DHT11.h>;
DFRobot_DHT11 DHT;
#define DHT11_PIN D8

#define PIR_SENOR D6

int duration=0;
int distance=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(D4,OUTPUT);//trig ultra pin
  pinMode(D2,INPUT);//output ultra pin
  pinMode(D8,OUTPUT);//dth pin
}
  


void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(D4,LOW);//ultrassonic
   delayMicroseconds(2);
   digitalWrite(D4,HIGH);
   delayMicroseconds(10);
   digitalWrite(D4,LOW);
   duration=pulseIn(D2,HIGH);
   distance=duration*0.34/2;
   Serial.print(" ULRASONIC Distance:");
   Serial.println(distance);
   delay(500);
   DHT.read(DHT11_PIN);// dht tem
   Serial.print("TEMPERATURE:");
   Serial.print(DHT.temperature);
   Serial.print(" HUMIDITY ");
   Serial.println(DHT.humidity);
   delay(1000);

   int motiondetected=
   digitalRead(PIR_SENOR);// pir senor

    if(motiondetected==HIGH)
   {
    Serial.print("MOTION DETECTED ");
    delay(1000);
   }
}
  
    
    


   
