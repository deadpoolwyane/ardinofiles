#include <ESP8266WiFi.h>
#include <ThingESP.h>
ThingESP8266 thing("kukku", "nodemcuwtatsapp", "978767");
int LED = D1;
int LED1= D3;
unsigned long previousMillis = 0;
const long INTERVAL = 6000;
void setup()
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(LED1,OUTPUT);
  thing.SetWiFi("Galaxy A02sfe67","jkig8296");
  thing.initDevice();
}
String HandleResponse(String query)
{
  if (query == "led on")
  {
    digitalWrite(LED, 1);
    return "Done: LED Turned ON";
  }
  if (query == "led off")
  {
    digitalWrite(LED, 0);
    return "Done: LED Turned OFF";
  }
  else if (query == "led status")
   {
    return digitalRead(LED) ? "LED is OFF" : "LED is ON";
    return "Your command invalid..";
   }
  if (query == "led1 on")
  {
    digitalWrite(LED1, 1);
    return "Done: LED1 Turned ON";
  }
  if (query == "led1 off")
  {
    digitalWrite(LED1, 0);
    return "Done: LED1 Turned OFF";
  }
  else if (query == "led1 status")
  {
    return digitalRead(LED1) ? "LED is OFF" : "LED is ON";
    return "Your command invalid..";
  }
}
void loop()
{
  thing.Handle();
  thing.Handle();
}
