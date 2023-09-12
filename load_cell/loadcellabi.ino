#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <HX711.h>

// Define the HX711 circuit pins
#define DOUT_PIN 2
#define CLK_PIN 3

// Define the button switch pin and LEDs pins
#define BUTTON_PIN 4
#define LED_READING 5
#define LED_NON_READING 6

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

  // Set the button pin as input
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  // Set the LED pins as output
  pinMode(LED_READING, OUTPUT);
  pinMode(LED_NON_READING, OUTPUT);
}

void loop() {
  // Check if the button is pressed and reset the scale to zero
  if (digitalRead(BUTTON_PIN) == LOW) {
    scale.tare();
    lcd.setCursor(8, 0); // Move the cursor to the second line, 9th position
    lcd.print("       "); // Clear the previous weight value
  }

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

  // LED control based on reading time and non-reading time
  if (weight > 0.0) {
    // Turn on the reading time LED
    digitalWrite(LED_READING, HIGH);
    // Blink the non-reading time LED
    digitalWrite(LED_NON_READING, (millis() / 500) % 2);
  } else {
    // Turn off both LEDs when not reading
    digitalWrite(LED_READING, LOW);
    digitalWrite(LED_NON_READING, LOW);
  }

  delay(1000); // Wait for a second before reading again
}
