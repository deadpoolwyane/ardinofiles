#include <SoftwareSerial.h>
#include <DFRobot_DHT11.h>
#include <DFRobotDFPlayerMini.h>  // Include the MP3 Player library

#define DHT11_PIN A0 // temperature and humidity
DFRobot_DHT11 DHT;
SoftwareSerial mySerial(9, 10);
#define moist 7 // moist sensor
#define water 8 // rain water detection sensor

SoftwareSerial mp3Serial(11, 12); // Mini MP3 Player module
DFRobotDFPlayerMini mp3Player;

void setup() {
  pinMode(moist, INPUT);
  pinMode(water, INPUT);
  mySerial.begin(9600);
  Serial.begin(9600);
  mp3Serial.begin(9600); // Initialize the MP3 Player's serial communication
  
  if (!mp3Player.begin(mp3Serial)) {
    Serial.println(F("Unable to begin DFPlayer"));
    while (true);
  }
  
  delay(100);
}

void loop() {
  DHT.read(DHT11_PIN);
  int a = analogRead(moist);
  int b = analogRead(water);
  
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature);
  Serial.println("C  ");
  
  if (a >= 200) {
    mySerial.println("AT+CMGF=1");
    delay(1000);
    mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r");
    mySerial.println("low soil moist");
    mySerial.println((char)26);
    delay(100);
    
    mp3Player.play(1); // Play alert audio
    delay(5000); // Wait for audio to finish
  }
  
  if (b <= 200) {
    mySerial.println("AT+CMGF=1");
    delay(1000);
    mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r");
    delay(1000);
    mySerial.println("raining");
    delay(100);
    mySerial.println((char)26);
    delay(1000);
    
    mp3Player.play(2); // Play alert audio
    delay(5000);
  }
  
  if (DHT.humidity <= 200) {
    mySerial.println("AT+CMGF=1");
    delay(1000);
    mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r");
    delay(1000);
    mySerial.println("high humidity");
    delay(100);
    mySerial.println((char)26);
    delay(1000);
    
    mp3Player.play(3); // Play alert audio
    delay(5000);
  }
  
  if (DHT.temperature <= 200) {
    mySerial.println("AT+CMGF=1");
    delay(1000);
    mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r");
    delay(1000);
    mySerial.println("very high temperature");
    delay(100);
    mySerial.println((char)26);
    delay(1000);
    
    mp3Player.play(4); // Play alert audio
    delay(5000);
  }
}
