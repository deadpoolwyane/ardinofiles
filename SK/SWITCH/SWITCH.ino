void setup() 
{
  pinMode(D5,OUTPUT);
 Serial.begin(9600); 
}
void loop() 
{
if(Serial.available()>0)
{
  int val=Serial.read();
switch(val)
{
case'0':
  digitalWrite(D5,HIGH);
break;
case'1':
  digitalWrite(D5,LOW);
break;
case'2':
  digitalWrite(D5,HIGH);
  delay(1000);  
  digitalWrite(D5,LOW);
  delay(1000);
  digitalWrite(D5,HIGH);
  delay(1000);
  digitalWrite(D5,LOW);
  delay(1000);
break;
}
}
}
