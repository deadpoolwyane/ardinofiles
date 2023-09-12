#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 10
#define RAIN_SENSOR_PIN 11 // Change this to the appropriate pin for your rain sensor

// Alert thresholds
const float TEMPERATURE_THRESHOLD = 28.0; // in degrees Celsius
const int HUMIDITY_THRESHOLD = 40;       // in percentage
const int RAIN_ALERT_THRESHOLD = 1;      // 1 indicates rain detected

void setup() {
  Serial.begin(115200);
}

void loop() {
  DHT.read(DHT11_PIN);
  
  int rainSensorValue = digitalRead(RAIN_SENSOR_PIN);
  
  Serial.print("temp:");
  Serial.print(DHT.temperature);
  Serial.print("  humi:");
  Serial.print(DHT.humidity);
  Serial.print("  rain:");
  Serial.println(rainSensorValue);

  // Temperature alert
  if (DHT.temperature > TEMPERATURE_THRESHOLD) {
    Serial.println("Temperature Alert!");
    // Add code here to trigger an actual alert (e.g., sound a buzzer, send a notification, etc.)
  }

  // Humidity alert
  if (DHT.humidity < HUMIDITY_THRESHOLD) {
    Serial.println("Humidity Alert!");
    // Add code here to trigger an actual alert
  }

  // Rain alert
  if (rainSensorValue == RAIN_ALERT_THRESHOLD) {
    Serial.println("Rain Alert!");
    // Add code here to trigger an actual alert
  }

  delay(1000);
}
