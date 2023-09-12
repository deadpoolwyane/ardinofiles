#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#include <SoftwareSerial.h>
#define DHTPIN 14     // GPIO 14 (D5) for DHT11 sensor
#define DHTTYPE DHT11 // Change to DHT22 if using that sensor
//DHT dht(DHTPIN, DHTTYPE);
#define RX_PIN 3      // GPIO 3 (RX) for GSM module
#define TX_PIN 1      // GPIO 1 (TX) for GSM module
SoftwareSerial gsmSerial(RX_PIN, TX_PIN);

void setup() {
  Serial.begin(9600);
  gsmSerial.begin(9600);
   DFRobot_DHT11.begin(9600);
  
  delay(1000);
  
  gsmInit();
}

void loop() {
  float temperature = DHT.readTemperature();
  float humidity = DHT.readHumidity();
  
  if (!isnan(temperature) && !isnan(humidity)) {
    sendData(temperature, humidity);
  }
  
  delay(5000); // Wait for 5 seconds before reading and sending data again
}

void gsmInit() {
  gsmSerial.println("AT"); // Send AT command to check GSM module communication
  delay(1000);
  while (gsmSerial.available()) {
    Serial.write(gsmSerial.read());
  }
  gsmSerial.println("AT+CMGF=1"); // Set SMS mode to text
  delay(1000);
}

void sendData(float temperature, float humidity) {
  gsmSerial.print("AT+CMGS=\"91+8921630481\""); // Replace with your phone number
  gsmSerial.write(0x0D); // Carriage return
  delay(500);
  
  gsmSerial.print("Temperature: ");
  gsmSerial.print(temperature);
  gsmSerial.print("°C, Humidity: ");
  gsmSerial.print(humidity);
  
  gsmSerial.write(0x1A); // Ctrl+Z to end the SMS
  delay(5000);
}
