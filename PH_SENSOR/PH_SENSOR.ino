#define BLYNK_TEMPLATE_ID   "TMPL3Z-mW8c1-"
#define BLYNK_TEMPLATE_NAME "DHT11"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define DHTPIN D2         // Define the GPIO pin to which the DHT sensor is connected
#define DHTTYPE DHT11    // Define the type of DHT sensor (DHT11, DHT21, or DHT22)

char auth[] = "a2NnOoSYLi5H_sqcEDjQoRztZsGf5W10";  // Replace with your Blynk authentication token
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, "Redmipr", "gokul123"); // Replace with your Wi-Fi credentials
  dht.begin();
}

void loop() {
  Blynk.run();
  readDHT();
}

void readDHT() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.println(temperature);

  Blynk.virtualWrite(V2, humidity);     // Send humidity data to Blynk app's V5 widget
  Blynk.virtualWrite(V1, temperature);  // Send temperature data to Blynk app's V6 widget
  delay(2000);  // Update every 2 seconds
}
