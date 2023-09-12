#include <DFRobot_DHT11.h>
#include <SoftwareSerial.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 8
#define RAIN_SENSOR_PIN A1
#define moist_PIN A2 
// Alert thresholds
const float TEMPERATURE_THRESHOLD = 39;
const int HUMIDITY_THRESHOLD = 70;//change accordance to the atmost: there
const int RAIN_ALERT_THRESHOLD = 90;// indicate where the rain begins
const int MOIST_THRESHOLD = 700;
// GSM module configuration
SoftwareSerial gsmSerial(2,3);  // RX, TX for GSM module
const char* phone_number = "8111828664";  // Replace with your phone number

// MP3 module configuration
SoftwareSerial mp3Serial(8, 7);  // RX, TX for DFPlayer Mini

void setup() {
  Serial.begin(9600);
  gsmSerial.begin(9600);
//  mp3Serial.begin(9600);
  delay(100);  // Allow time for GSM and MP3 modules to initialize
  sendSMS("GSM and MP3 modules initialized.");
}

void loop() {
  DHT.read(DHT11_PIN);
  
  int rainSensorValue = analogRead(RAIN_SENSOR_PIN);
  int moist =analogRead(moist_PIN);
  //Serial.print("temp:");
 Serial.print(DHT.temperature);
  Serial.print("  humi:");
  //Serial.print(DHT.humidity);
  //Serial.print("  rain:");
  //Serial.println(rainSensorValue);
  //Serial.print("  moist:");
  //Serial.println(moist_PIN);
  // Temperature alert
  if (DHT.temperature > TEMPERATURE_THRESHOLD) {
    
    sendSMS("Temperature Alert: High temperature !");
    playMP3("01.mp3"); // Play the corresponding alert message
      Serial.println("the temperature is higher than normal");
      
      }

  // Humidity alert
  if (DHT.humidity < HUMIDITY_THRESHOLD) {
    sendSMS("Humidity Alert: high humidity !");
    playMP3("02.mp3"); // Play the corresponding alert message
      Serial.println("humidity is higher than expected");
  
  }
  //soil moist
  if(moist>=MOIST_THRESHOLD){
    
    sendSMS("soil moist Alert: low soil moist !");
    playMP3("03.mp3"); // Play the corresponding alert message
    Serial.println("soil moist is low");
    
      }
    
 // Rain alert
  if (rainSensorValue <= RAIN_ALERT_THRESHOLD) {
    sendSMS("Rain Alert: Rain detected!");
    playMP3("04.mp3"); // Play the corresponding alert message
      Serial.println("it's raining");
  }


  
}

void sendSMS(const char* message) {
  gsmSerial.println("AT+CMGF=1");
  delay(100);
  gsmSerial.println("AT+CMGS=\"" + String("8921630481") + "\"");
  delay(100);
  gsmSerial.println(message);
  delay(100);
  gsmSerial.println((char)26);  
  delay(100);
}

void playMP3(const char* filename) {
    mp3Serial.write(0x7E); // Start code
    mp3Serial.write(0xFF); // Version
    mp3Serial.write(0x06); // Command length
    mp3Serial.write(0x03); // Command
    mp3Serial.write((byte)0x00); // Feedback
    mp3Serial.write((byte)0x00); // Parameter - no checksum
    mp3Serial.write((byte)0x00); // Parameter - high byte (folder)
    mp3Serial.write(0x01); // Parameter - low byte (file)
    mp3Serial.write(0xEF); // End code
    delay(100); // Allow time for the MP3 module to process the command
}
