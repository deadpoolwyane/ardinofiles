#include <LedControl.h>  // Include the LedControl library

// Define the connections to the LED dot matrix
const int dataPin = 11;
const int clockPin = 13;
const int csPin = 10;
LedControl lc = LedControl(dataPin, clockPin, csPin, 1); // Adjust the last parameter if using multiple matrices

// Define the LED matrix dimensions
const int matrixWidth = 8;
const int matrixHeight = 8;

// Define patterns for different emotions
byte happyPattern[matrixHeight] = {
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100
};

byte sadPattern[matrixHeight] = {
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10000001,
  B10100101,
  B01011010,
  B00111100
};

byte surprisedPattern[matrixHeight] = {
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10111101,
  B10000001,
  B01000010,
  B00111100
};

byte angryPattern[matrixHeight] = {
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10011001,
  B10100101,
  B01000010,
  B00111100
};

void setup() {
  // Initialize the LED matrix
  lc.shutdown(0, false); // Wake up the matrix
  lc.setIntensity(0, 8); // Set the brightness (0-15)
  lc.clearDisplay(0); // Clear the display
}

void loop() {
  // Display different emotion patterns
  displayPattern(happyPattern);
  delay(30000);

  displayPattern(sadPattern);
  delay(30000);

  displayPattern(surprisedPattern);
  delay(30000);

  displayPattern(angryPattern);
  delay(30000);
}

void displayPattern(const byte* pattern) {
  for (int row = 0; row < matrixHeight; row++) {
    lc.setRow(0, row, pattern[row]); // Set the LEDs for each row
  }
}
