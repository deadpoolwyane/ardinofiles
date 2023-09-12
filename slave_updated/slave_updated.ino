#include <Servo.h>
#define button 8

Servo myServo;
int state = 20;
int buttonState = 0;

void setup() {
  pinMode(button, INPUT);
  myServo.attach(9);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read();
    Serial.println(state); // Reads the data from the serial port
    if(state==0){
      Serial.println("Move Forward");
    }
   else if(state==1){
      Serial.println("Move backward");
    }
    else if(state== 4){
      Serial.println("Move Right");
    }
    else if(state==5){
      Serial.println("Move Left");
    
    }
 }
 // Controlling the servo motor
 
 
}
