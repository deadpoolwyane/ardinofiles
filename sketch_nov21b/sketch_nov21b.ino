int count = 0;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available())
  {
    count = 0; // Reset count to zero// Keep reading Byte by Byte from the Buffer till the Buffer is empty
    {
      char input = Serial.read();
      Serial.print(input);
      count++; //
      delay(1000); //
    }
    Serial.println();
    Serial.print("Tag Length : ");
    Serial.print(count);
    Serial.println(" Bytes");
  }
}
