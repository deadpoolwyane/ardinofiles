 int watervalueA0;

void setup() {
  Serial.begin(9600);
  pinMode(A0,OUTPUT);//WATER SENSOR
  pinMode(3,OUTPUT);//LED 1
  pinMode(4,OUTPUT);// LED 2
  pinMode(5,OUTPUT);// LED 3

}

void loop() {
     int watervalue; // put your main code here, to run repeatedly:
    int water_value=analogRead(A0);
    //Serial.println("water_value=");
    Serial.print("water_value=");
    Serial.println(water_value);
   // if (watervalue>=50)
    digitalRead(3)
    delay(1000);
    digitalRead(3)==LOW&& digitalRead(4)== LOW)&& 
    delay(1000);
    }
}
    //if (watervalue >=60)
    digitalWrite(4)==HIGH&&
    delay(500);
    digitalWrite(4)==LOW&&
    delay(500);
   // if(watervalue>=100)
   /// digitalWrite(5)==HIGH&&
    //delay(500);
}
