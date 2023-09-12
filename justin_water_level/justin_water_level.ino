#define water_senor A0
#define green 5
#define red 6
#define multi 7
int value=0;
void setup() {
  pinMode(water_senor,INPUT);
  pinMode(green,OUTPUT);//1led 
  pinMode(red,OUTPUT);//2 led 
  pinMode(multi,OUTPUT);//3 led 
  Serial.begin(9600);

}

void loop() {
  int value=analogRead(water_senor);
  Serial.print("water level:     ");  Serial.println(value);

  delay(1000);
  if (value<=50)
    { 
       digitalWrite(red,HIGH);//redblink
       delay(100);
       digitalWrite(red,LOW);//red BLINK
       digitalWrite(green,LOW);//green OFF
       digitalWrite(multi,LOW);//MULITI OFF
       Serial.println("-water level  low");
    }
  else if(value>=50&&value<=100)
    { 
      digitalWrite(green,HIGH);// GREEN BLINK
      delay(100);
      digitalWrite(green,LOW);// BLINK GREEN
      digitalWrite(red,LOW);// RED OFF
      digitalWrite(multi,LOW);//MULIT OFF
      Serial.println("-water level is MID level");
     }
 else if(value!=100)//multi high
    {
      digitalWrite(red,LOW);//MULIT HIGH
      digitalWrite(green,LOW);// OFF RED
      digitalWrite(multi,HIGH);// OFF GREEN
      Serial.println("-water level very high");
    }
}
