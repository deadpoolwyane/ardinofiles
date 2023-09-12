#include <LiquidCrystal.h>

// Pin configuration
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // Print a message to the LCD
  lcd.print("Hello, World!");
}

void loop() {
  // Do nothing here
}          
