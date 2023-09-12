void setup() {
  // put your setup code here, to run once:
Serial.begin (115200);
pinMode ( A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorvalue = analogRead (A0);
Serial.print ("value");
Serial.println (sensorvalue);
delay (1000);
}
