#include <ESP8266WiFi.h>
#include <ThingESP.h>
ThingESP8266 thing("kukku", "nodemcuwhatsapp", "978767");
//int LED = D1;
//int LED1= D3;
//int LED3=D4;
unsigned long previousMillis = 0;
const long INTERVAL = 6000;
String sensorvalue;
void setup()
{
  Serial.begin(115200);
  pinMode (A0, INPUT);
  thing.SetWiFi("Galaxy A02sfe67", "jkig8296");
  thing.initDevice();
}
String HandleResponse(String query)
{
  if (query == "mq3")
  {

    sensorvalue = String(analogRead(A0));
    Serial.print ("value");
    Serial.println (sensorvalue);
    return  sensorvalue;
  }
}

void loop()
{

  thing.Handle();

}
