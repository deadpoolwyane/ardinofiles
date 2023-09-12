#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX


int in1 = 2;
int in2 = 3;
int in3 = 5;
int in4 = 6;

void setup() {
 Serial.begin(9600);
  Serial.println("Arduino is communicating at 9600 baud rate");

  BTserial.begin(38400);
  Serial.println("HC05 is communicating at 38400 baud rate");
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
   pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  
  /*if (BTserial.available()) {
    Serial.write(BTserial.read());
//    int Val=BTserial.read();
//    Serial.println(Val);//
   switch(Val){
    case 'F':
    digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("Val");
  break;
    case 'B':
    digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  break;
    case 'R':
    digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  break;
  case 'L':
    digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  break;

   case 's':
    digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
   Serial.println("S");
  break;
   
   }
    } */

    if (BTserial.available()) {
    Serial.write(BTserial.read());
    
  }
  if (Serial.available()) {
    BTserial.write(Serial.read());
  }
    
}
