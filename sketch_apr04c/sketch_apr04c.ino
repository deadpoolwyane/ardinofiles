void setup() {
  pinMode(D1,OUTPUT);
  

}

void loop() {
       red_blinker();

}

void red_blinker() {
       digitalWrite(D1,HIGH);
       delay(500);
       digitalWrite(D1,LOW);
       delay(500);
}
