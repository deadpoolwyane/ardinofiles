#define analogPin A0
void setup()
{
  pinMode(A0,INPUT);
  Serial.begin(9600);
}
void loop()
{
  int sensor=analogRead(A0);
  Serial.print("SENSOR:");
  Serial.println(sensor);
  delay(1000);
}
