void setup() {
  // put your setup code here, to run once:
  pinMode(D1,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int m=0;m<255;m++)
  {
    analogWrite(D1,m);
    delay(10);
   
    
    
  }
  for(int m=255;m>0;m--)
  {
    analogWrite(D1,m);
    delay(10);
  }

}
