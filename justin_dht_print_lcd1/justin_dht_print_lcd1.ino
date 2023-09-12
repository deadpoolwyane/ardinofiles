#include<LiquidCrystal.h>
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 10
const int rs = 2, en = 3, 4 = 5, 5 = 6, 6 = 7, 7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
  lcd.begin(16, 2);
  lcd.print( "gud mrng" );
  lcd.setCursor(0, 2);
  lcd.print("read temperature");
  delay(6000);
  lcd. clear();
  
}

void loop(){
 lcd.setCursor(0,1);
 lcd.print(millis()/ 1000);
}
