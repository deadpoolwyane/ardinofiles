void setup() {
       pinMode(D7,OUTPUT);
       pinMode(D1,OUTPUT);
}

void loop() {
       digitalWrite(D7,HIGH);
       digitalWrite(D1,HIGH);
        delay(1000);
        digitalWrite(D7,LOW);
        digitalWrite(D1,LOW);
        delay(1000);
}
       
