int i;
void setup()
{
  pinMode(D6,OUTPUT);
}
void loop() 
{
 for(i=0;i<255;i++)
{
 analogWrite(D6,i);
 delay(20);
}
for(i=255;i>0;i--)
{
  analogWrite(D6,i);
  delay(20);
}
}
