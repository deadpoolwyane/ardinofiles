int PWMpin= 10;
void setup() {
 // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  int i;
  for (int i= 0; i<=255; i++){
  analogWrite(PWMpin,i);
  Serial.println(i);
  delay(1);
  }
  
  for (int i=255; i>=0; i--){
  analogWrite(PWMpin,i);
  delay(1);
  }
}
 
