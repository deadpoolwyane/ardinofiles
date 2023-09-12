void setup() {
 pinMode(D2,OUTPUT);//trig
 pinMode(D7,INPUT);//echo
 pinMode(D3,OUTPUT);
 pinMode(D4,OUTPUT);
 Serial.begin(9600);
}
void loop() {
 
 digitalWrite(D2,LOW);
 delay(5);
 
 digitalWrite(D2,HIGH);
 delay(10);

digitalWrite(D2,LOW);
 
int Sen=pulseIn(D7,HIGH);
//Serial.println(Sen);

int distance=(Sen/2)*0.034 ;

Serial.println(distance);

if (distance<20)
 {
  digitalWrite(D3,HIGH);
  digitalWrite(D4,LOW); 
 }
 else if (distance>50)
 {
   digitalWrite(D3,LOW);
   digitalWrite(D4,HIGH);
 }
 else
 {
   digitalWrite(D3,LOW);
   digitalWrite(D4,LOW);
 }
}





  
 
