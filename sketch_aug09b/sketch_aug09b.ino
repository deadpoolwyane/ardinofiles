int PWMpin = 10;
void setup() {
  Serial.begin(9600);

{
  void loop() {
   for (int i= 0; i<= 255; i++)
        analogWrite(PWMpin,i);
        delay(100);
   for (i=255; i>0; i--)
        Serial.println(i);
  }
}
 
  
