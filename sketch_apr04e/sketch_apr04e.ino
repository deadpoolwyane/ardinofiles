#include <dht.h>
dht DHT;
#define out_pin D1

void setup() {
  Serial.begin(9600);
  pinMode(out_pin,INPUT);

}

void loop() {
   int val=DHT.read11(out_pin);
   

}
