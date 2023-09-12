#include <DFRobot_DHT11.h>


#include <LiquidCrystal.h>

#define DHTPIN 2        // Pin where the DHT11 is connected
#define DHTTYPE DHT11   // DHT 11
int DHT;
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(2, 3, 5, 6, 7, 8);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  lcd.begin(16, 2);
  lcd.print("Humidity:");
  lcd.setCursor(0, 1);
  lcd.print("Temp:");
}

void loop() {
  delay(2000);  // Wait for 2 seconds between readings

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  lcd.setCursor(9, 0);
  lcd.print(humidity);
  lcd.print(" %");

  lcd.setCursor(6, 1);
  lcd.print(temperature);
  lcd.print(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}
