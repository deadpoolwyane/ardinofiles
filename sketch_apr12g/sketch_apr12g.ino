#define myled D1

void setup() {
      pinMode(myled,OUTPUT);
}

void loop() {
      digitalWrite(myled,HIGH);
      delay(1000);
      digitalWrite(myled,LOW);
      delay(1000);b

}
