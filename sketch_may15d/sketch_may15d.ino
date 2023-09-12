void setup() {
 pinMode(D2,OUTPUT);
 pinMode(D6,OUTPUT);
}

void loop() {
  digitalWrite(D2,HIGH);
  digitalWrite(D6,LOW);
  delay(100);
  digitalWrite(D2,LOW);
  digitalWrite(D6,HIGH);
  delay(100);
  
  
  
  
}  
