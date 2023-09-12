#define echoPin D2
#define trigPin D3
 long duration;
 int distance;
void setup() 
{
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
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
if(distance<50)
{
  digitalWrite(D5,HIGH);
  digitalWrite(D6,LOW);
}
if(distance>200)
{
  digitalWrite(D6,HIGH);
  digitalWrite(D5,LOW);
}
else
{
  digitalWrite(D6,LOW);
}
}
