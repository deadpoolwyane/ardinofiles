#include <DFRobot_DHT11.h>
#include <SoftwareSerial.h> // Include the DFRobot_DHT11 library

#define DHTPIN 4             // GPIO pin connected to the DHT11 sensor
#define RAIN_SENSOR_PIN 5    // GPIO pin connected to the rain sensor
#define HIGH_TEMP_THRESHOLD 30.0  // Set the high temperature threshold in °C

DFRobot_DHT dht(DHTPIN, DHT11);  // Initialize DFRobot_DHT object

// SoftwareSerial for GSM module
SoftwareSerial gsmSerial(2, 3);  // RX, TX for SIM800A module

void setup() {
  Serial.begin(115200);
  gsmSerial.begin(9600);  // Initialize GSM module
  dht.begin();  // Initialize DHT11 sensor
  pinMode(RAIN_SENSOR_PIN, INPUT);

  // Set GSM module to text mode
  gsmSerial.println("AT+CMGF=1");
  delay(100);
  gsmSerial.flush();
}

void loop() {
  delay(2000);  // Wait for 2 seconds between readings

  float humidity = dht.readHumidity();  // Use DFRobot_DHT11's readHumidity function
  float temperature = dht.readTemperature();  // Use DFRobot_DHT11's readTemperature function
  int rainSensorValue = digitalRead(RAIN_SENSOR_PIN);  // Read the rain sensor value

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read data from DHT sensor");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C\t");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  if (temperature > HIGH_TEMP_THRESHOLD) {
    sendSMSAlert("High temperature alert!", "Current temperature: " + String(temperature) + " °C");
    // playTemperatureSound(temperature);  // Add your audio play function if needed
  }

  if (rainSensorValue == LOW) {
    sendSMSAlert("Rain detected!", "Take necessary precautions.");
  }
}

void sendSMSAlert(const String &subject, const String &message) {
  // Replace with your own phone number
  String phoneNumber = "+1234567890";

  // Send the SMS
  gsmSerial.print("AT+CMGS=\"");
  gsmSerial.print(phoneNumber);
  gsmSerial.println("\"");
  delay(500);
  gsmSerial.print(subject);
  delay(500);
  gsmSerial.write(0x0D);  // Carriage return
  delay(500);
  gsmSerial.print(message);
  delay(500);
  gsmSerial.write(26);  // Send Ctrl+Z to indicate end of message
  delay(500);
}
