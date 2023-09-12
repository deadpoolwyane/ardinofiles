void setup() {
  pinMode(D2,OUTPUT);
  pinMode(D3,INPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  Serial.begin(9600);

}

void loop() {
   digitalWrite(D2,LOW);
   delay(5);
   digitalWrite(D2,HIGH);
   delay(10);
   digitalWrite(D2,LOW);
   int uss=pulseIn(D3,HIGH);
   int distance=(uss/2)*0.034;
   Serial.println(distance);
   if (distance<20)
    {digitalWrite(D4,HIGH);
     digitalWrite(D5,LOW);
    }
   else if (distance>50)
    {digitalWrite(D4,LOW);
     digitalWrite(D5,HIGH);
    }
   else
    {digitalWrite(D4,LOW);
     digitalWrite(D5,LOW);
    }
     

}
