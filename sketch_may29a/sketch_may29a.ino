int i;
void setup() {
  // put your setup code here, to run once:
pinMode(D3,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
for(i=0;i<=255;i++)
{
analogWrite(D3,i); 
delay(700);


for(i=255;i>=0;i--)

  analogWrite(D3,i);
  delay(700);

}}
