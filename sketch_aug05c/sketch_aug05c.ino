#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <HX711.h>

const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;

HX711 scale;

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 to the I2C address of your LCD

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  lcd.begin(16, 2); // Initialize the LCD
  lcd.backlight();  // Turn on the backlight
}

void loop() {
  // Replace 1.0 with your calibration factor for accurate measurements
  float calibration_factor = 10000.0;

  scale.set_scale(calibration_factor); // Set calibration factor
  float weight = scale.get_units(); // Get the weight reading
  
  // Print the weight on the LCD
  lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
  lcd.print("Weight: ");
  lcd.print(weight);
  lcd.print(" kg");

  // Print the weight on the Serial Monitor
  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" kg");

  delay(1000); // Wait for a second
}
