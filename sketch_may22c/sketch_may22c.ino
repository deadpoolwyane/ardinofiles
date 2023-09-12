void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(D3,INPUT);
pinMode(D4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Sensorvalue=digitalRead(D3);
  Serial.print("value");
  Serial.println(Sensorvalue);
  delay(1000);
  if(Sensorvalue==1)
  {
    digitalWrite(D4,HIGH);
  }
  else
  {
    digitalWrite(D4,LOW);
  }
    delay(1000);
}
