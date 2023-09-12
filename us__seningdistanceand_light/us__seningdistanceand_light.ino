int duration=0;
int distance=0;

void setup() {
Serial.begin (9600);
pinMode(2,INPUT);//ECHO PIN 
pinMode(3,OUTPUT);//TRIG PIN
pinMode(4,OUTPUT);//LED 1
pinMode(5,OUTPUT);//LED 2
pinMode(6,OUTPUT);//LED 3
}

void loop() {
digitalWrite(3,LOW);
delayMicroseconds(5);
digitalWrite(3,HIGH);
delayMicroseconds(10);
digitalWrite(3,LOW);
duration=pulseIn(2,HIGH);
distance=duration*0.34/2;
Serial.println(distance);
delay(2000);
int distance;
if (distance <=200)
Serial.println("you are safe line");
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
delay(2000);
int distance;
if  (distance <=150)
Serial.println("you are middle safe now ");
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
delay (2000);
int distance;
if (distance <=50)
Serial.println("da pattiy danger aera");
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
delay(2000);
int distance;
if  (distance <=50)
Serial.println("da moona ne sarakam kandu");
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
delay(2000);
}
    
  
   

   
