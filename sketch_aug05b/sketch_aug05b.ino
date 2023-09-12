#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <HX711.h>

// Define the HX711 circuit pins
#define DOUT_PIN 2
#define CLK_PIN 3

HX711 scale;

// Initialize the LCD object with the I2C address (use the actual address of your LCD)
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  Serial.begin(9600);
  scale.begin(DOUT_PIN, CLK_PIN);
  scale.set_scale(); // Calibrate the scale if needed
  scale.tare();      // Reset the scale to 0

  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.print("Weight: ");
}

void loop() {
  // Read the raw value from the load cell
  long rawValue = scale.read();

  // Convert the raw value to weight in grams or other units depending on calibration
  float weight = scale.get_units();

  // Display the weight on the serial monitor
  Serial.print("Weight (grams): ");
  Serial.println(weight);

  // Display the weight on the LCD
  lcd.setCursor(8, 0); // Move the cursor to the second line, 9th position
  lcd.print("       "); // Clear the previous weight value
  lcd.setCursor(8, 0); // Move the cursor back to the 9th position
  lcd.print(weight); // Print the current weight value

  delay(1000); // Wait for a second before reading again
}
