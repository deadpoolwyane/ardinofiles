void setup()  {
  Serial.begin(9600);
  Serial.begin(115200);
}
void loop()  {
   if (Serial.available()) {
      int inByte = Serial.read();
      Serial.write(inByte);
   }
 
  if (Serial.available()) {
     int inByte = Serial.read();
     Serial.write(inByte);
  }
}
