#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN A0


void setup() {
  pinMode(A0,OUTPUT);
  lcd.begin(16,2);
  lcd.print("hi");
  lcd.setCursor(0, 2);
   lcd.print(" Temperature!");
  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 1);
 lcd.print(millis() / 1000);
}
 
