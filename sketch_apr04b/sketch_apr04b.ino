#define red_pin D1
#define green_pin D2
#define echo_pin D4
#define trigg_pin D5
void setup() {
  Serial.begin(9600);
  pinMode(red_pin,OUTPUT);//red
  pinMode(green_pin,OUTPUT);//green
  pinMode(echo_pin,INPUT);
  pinMode(trigg_pin,OUTPUT);
}

void loop() { 
    digitalWrite(trigg_pin,LOW);
    delay(5);
    digitalWrite(trigg_pin,HIGH);
    delay(10);
    digitalWrite(trigg_pin,LOW);
    int uss=pulseIn(echo_pin,HIGH);
    int i=(uss/2)*0.034;
    Serial.print(i);
    if (i>15&&i<45)
      {
        digitalWrite(red_pin,HIGH);
        digitalWrite(green_pin,LOW);
      }
   
}
