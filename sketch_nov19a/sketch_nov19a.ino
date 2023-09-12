int D3;
int D4;
void setup() {
  // put your setup code here, to run once:
pinMode (A0,INPUT);
pinMode (A1,INPUT);
pinMode (D3,OUTPUT);
pinMode (D4,OUTPUT);
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorvalue=analogRead(A0);
Serial.print ("value");
Serial.println (sensorvalue);
if (sensorvalue >300)
{
  digitalWrite (D3,HIGH);
}
else
{
  digitalWrite (D3,LOW);
}


int sensorvalue1=analogRead(A1);
Serial.print ("value1");
Serial.println (sensorvalue1);
delay (1000);
if (sensorvalue1>200)
{
  digitalWrite (D4,HIGH);
  
}
else
{
  digitalWrite (D4,LOW);
}

if (sensorvalue>300 && sensorvalue1>200)
{
  digitalWrite (D3,HIGH);
  digitalWrite (D4,HIGH);
}
else
{
  digitalWrite (D3,LOW);
  digitalWrite (D4,LOW);
}
}
