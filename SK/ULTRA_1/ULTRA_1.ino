#define echoPin D4
#define trigPin D2
 long duration;
 int distance;
void setup() 
{
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(D5,OUTPUT);
  Serial.begin(9600);
}
void loop() 
{
 digitalWrite(trigPin,LOW);
 delayMicroseconds(2); 
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
 duration=pulseIn(echoPin,HIGH);
 distance=duration*0.034/2;
 Serial.print("Distance:");
 Serial.print(distance);
 Serial.println("cm");
 delay(1000);
if(distance>60)
{
  digitalWrite(D5,HIGH);
}
if(distance<100)
{
  digitalWrite(D5,HIGH);
}
else
{
  digitalWrite(D5,LOW);
}
}
