#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX pins

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  delay(100);
}

void loop() {
  
  mySerial.println("AT+CMGF=1");
  delay(1000);
  mySerial.println("AT+CMGS=\"+918921630481\"x");
  delay(1000);
  mySerial.println("hello");
  delay(100);
  mySerial.write((char)26); 
  delay(1000);
}
