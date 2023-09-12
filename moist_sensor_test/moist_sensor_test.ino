void setup() {
  pinMode(A2,INPUT);
  Serial.begin(9600);
}

void loop() {
int moist = analogRead(A2);
Serial.println("moist");
Serial.print(moist);

}
