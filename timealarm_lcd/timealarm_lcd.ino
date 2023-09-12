#include <Time.h>
#include <TimeAlarms.h>
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define RELAY1  2                       
#define RELAY2  3

void setup() {
 
 // Start Serial & set pin to output 
 Serial.begin(9600);
  lcd.begin(16, 2);
 pinMode(RELAY1, OUTPUT);       
 pinMode(RELAY2, OUTPUT);

// start clock
 setTime(18,00,00,7,1,17); // set time to 18:00 July 1 2017 

// create the alarms 
 Alarm.alarmRepeat(22,00,00, RelayOff);  // 22:00:00 every day
 
 Alarm.alarmRepeat(05,30,00, LightsON);  // 05:30:00 every day
 Alarm.alarmRepeat(22,00,00, LightsOFF);  // 22:00:30 every day  
 
 Alarm.alarmRepeat(06,00,00, AirPumpON);  // 06:00:00 every day 
 Alarm.alarmRepeat(22,00,00, AirPumpOFF);  // 22:00:00 every day
 

}

void loop() {

 digitalClockDisplay();
 Alarm.delay(1000); 

 
}

//Relays OFF
void RelayOff(){
 Serial.println("All Off"); 
digitalWrite(RELAY1,HIGH);           
digitalWrite(RELAY2,HIGH);
lcd.setCursor(0,0);             
 }
 
void LightsON(){
 Serial.println("Lights are ON"); 
 digitalWrite(RELAY1,LOW);           

  }

                                   
 void LightsOFF(){
 Serial.println("Lights are OFF");
 digitalWrite(RELAY1,HIGH);          

 }
  void AirPumpON(){
 Serial.println("AirPump is ON");
 digitalWrite(RELAY2,LOW);           

 }


 void AirPumpOFF(){
 Serial.println("AirPump is OFF");
 digitalWrite(RELAY2,HIGH);          

 }


void digitalClockDisplay()
{
 // digital clock display of the time
 Serial.print(hour());
 printDigits(minute());
 printDigits(second());
 Serial.println(); 
}

void printDigits(int digits)
{
 Serial.print(":");
 if(digits < 10)
   Serial.print('0');
 Serial.print(digits);
}
