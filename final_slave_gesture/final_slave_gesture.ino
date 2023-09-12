#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
int in1 = 8;
int in2 = 9;
int in3 = 6;
int in4 = 7;
char c = ' ';
const int samples = 10;
void setup()
{
  Serial.begin(9600);
  Serial.println("Arduino is communicating at 9600 baud rate");

  BTserial.begin(38400);
  Serial.println("HC05 is communicating at 38400 baud rate");
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
   pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop()
{
  // Keep reading from HC-05 and send to Arduino Serial Monitor

  if (BTserial.available()>0) {
//    /

     int Val=BTserial.read();
//    Serial.println(Val);/
   switch(Val){
    
    case 'F':
    Serial.println("forward");
    digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  break;
    case 'B':
    digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("backward");
  break;
    case 'R':
    digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("R");
  break;
  case 'L':
    digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("L");
  break;

   case 'S':
    digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
   Serial.println("S");
  break;
   
   }
  }
  
  
}
