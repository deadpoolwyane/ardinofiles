#define echoPin 2 
#define trigPin 3 
#define motorpin1 4
#define motorpin2 8
#define motorpin3 10
#define motorpin4 7
#define rir 5
#define lir 6

long duration; 
int distance;
int right;
int left;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode (motorpin1,OUTPUT);
  pinMode (motorpin2,OUTPUT);
  pinMode (motorpin3,OUTPUT);
  pinMode (motorpin4,OUTPUT);
  pinMode (rir,INPUT);
  pinMode (lir,INPUT);
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");
}
void loop() {
  right = digitalRead(rir);
  //Serial.print ("right=");
  //Serial.println (right);
  left= digitalRead(lir);
  //Serial.print ("left=");
  //Serial.println (left);
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
 distance = duration * 0.034 / 2; 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  //delay (1000);
  
  if (distance<20 && distance>7)
  {
    digitalWrite (motorpin1,HIGH);
    digitalWrite (motorpin2,LOW);
    digitalWrite (motorpin3,LOW);
    digitalWrite (motorpin4,HIGH);
    Serial.println ("front");
  }
  else if (distance<7)
  {
    digitalWrite (motorpin1,HIGH);
    digitalWrite (motorpin2,LOW);
    digitalWrite (motorpin3,HIGH);
    digitalWrite (motorpin4,LOW);
    Serial.println ("back");
    delay(500);
    
  }
  else if (right  == 0)
  {
   // delay (1000);
    digitalWrite (motorpin1,HIGH);
    digitalWrite (motorpin2,LOW);
    digitalWrite (motorpin3,LOW);
    digitalWrite (motorpin4,LOW);
    Serial.println ("right");
    
  }
 else if (left == 0)
 {
  //delay (1000);
  digitalWrite (motorpin1,LOW);
  digitalWrite (motorpin2,LOW);
  digitalWrite (motorpin3,LOW);
  digitalWrite (motorpin4,HIGH);
  Serial.println ("left");
 }
  else
  {
    digitalWrite (motorpin1,LOW);
    digitalWrite (motorpin2,LOW);
    digitalWrite (motorpin3,LOW);
    digitalWrite (motorpin4,LOW);
    Serial.print ("stop");
  }
  
}
