int i=0;

void setup() {
      Serial.begin(9600);

}

void loop() {
     while(i<=10)
     {
     Serial.println(i);
     delay(1000);
     i++;
     }
}  
