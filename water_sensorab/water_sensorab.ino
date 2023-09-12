void setup() {
  Serial.begin(9600);
  pinMode(D8,INPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);

}

void loop() {
  int Sensorvalue=digitalRead(D8);
  Serial.print("value");
  Serial.println(Sensorvalue);
  delay(2000);
  if(Sensorvalue==0){
    digitalWrite(D3,HIGH);
    delay(1000);
    digitalWrite(D3,LOW);
    
  
}
   else if(Sensorvalue=1){
    digitalWrite(D4,HIGH);
    delay(1000);
    digitalWrite(D4,LOW);
   }
}
