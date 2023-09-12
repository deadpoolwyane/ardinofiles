int echopin=2;
int trigpin=8;
int ledpin=4;
int disp=0;
int dist=0;
void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(trigpin,LOW);
  delay(5);
  digitalWrite(trigpin,HIGH);
  delay(10);
  digitalWrite(trigpin,LOW);
  int disp=pulseIn(echopin,HIGH);
  int dist=(disp/2)*0.034;
  if(dist>=50&&dist<=90)
  {
  digitalWrite(ledpin,HIGH);
  delay(10);
  }
   else 
  {
  digitalWrite(ledpin,LOW);
  delay(10);
  
  }
  Serial.println(dist);
  // put your main code here, to run repeatedly:

}
