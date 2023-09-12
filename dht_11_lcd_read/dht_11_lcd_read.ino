#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define DHT11_PIN 8


void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop(){
  delay(1000);
  DHT.read(DHT11_PIN);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("tem");
  lcd.println(DHT.temperature);
  
  lcd.setCursor(0,2);
  lcd.print("hum");
  lcd.println(DHT.humidity);
}
