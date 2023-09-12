void setup() {
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);

}

void loop() {
  digitalWrite(D1,HIGH); 
  delay(1000);
  digitalWrite(D2,LOW);
  delay(1000);
  digitalWrite(D2,HIGH);
  delay(1000);
  digitalWrite(D1,LOW);
  delay(1000);

 

for(int i=0;i<255;i++)
{
  analogWrite(D3,i);
  delay(50); 
}
 for(int i=255;i>0;i--)
  {
  analogWrite(D3,i);
  delay(50);
  }
  
}
