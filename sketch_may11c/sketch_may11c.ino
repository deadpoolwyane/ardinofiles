void setup() {
  pinMode (D4,OUTPUT);
  pinMode (D2,OUTPUT);
  

}

void loop() {
  digitalWrite (D4,HIGH);
  delay(1000);
  digitalWrite (D4,LOW);
  delay(1000);
  digitalWrite (D2,HIGH);
  delay(1000);
  digitalWrite (D2,LOW);
  delay(1000);

}
