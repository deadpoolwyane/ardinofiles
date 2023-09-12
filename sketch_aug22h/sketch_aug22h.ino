#include <LedControl.h>

// Define the pins for the LED matrix (CS, CLK, DIN)
LedControl lc = LedControl(12, 11, 10, 1);  // Adjust pins as needed

// Define different eye emotions as 8x8 patterns
byte happy[8] = {B00111100, B01000010, B10100101, B10000001, B10100101, B10011001, B01000010, B00111100};
byte sad[8] =   {B00111100, B01000010, B10100101, B10000001, B10000001, B10100101, B01000010, B00111100};
// Define more emotions as needed

void setup() {
  int ledControl;
  ledControl(0, 0);  // Initialize the LED matrix
  lc.setIntensity(0, 8);  // Set LED brightness (0-15)
  lc.clearDisplay(0);  // Clear the display
}

void loop() {
  displayEmotion(happy);  // Display the happy emotion
  delay(1000);  // Wait for a second
  displayEmotion(sad);  // Display the sad emotion
  delay(1000);  // Wait for a second
  // Display other emotions and add delay as needed
}

void displayEmotion(byte emotion[8]) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, emotion[row]);  // Display each row of the emotion pattern
  }
}
