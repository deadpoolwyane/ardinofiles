void setup() {
  // put your setup code here, to run once:
  pinMode(D1,INPUT);
  Serial. begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int i=digitalRead(D1);
  Serial. print(i);
  delay(1000);

if(i==1)
{
 digitalWrite(D4,HIGH);
 
}
else
{
  digitalWrite(D4,LOW);
}
}
