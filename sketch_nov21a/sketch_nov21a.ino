  
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop()
{
  int sensorvalue=analogRead(A0);
  Serial.print("value=");
  Serial.println(sensorvalue);
 
  int sensorvalue1=analogRead(A1);
  Serial.print("value 1=");
  Serial.println(sensorvalue1);
  
 if(sensorvalue>300)
{
   Serial.println("HIGH");
}


 if(sensorvalue1>200)
{
   Serial.println("1 HIGH");
}

delay (1000);
 
}
