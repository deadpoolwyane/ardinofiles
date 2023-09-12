#include <LedControl.h>

// Define the pins for the LED matrix
const int dataPin = 11;
const int clockPin = 13;
const int csPin = 10;

// Create an instance of the LedControl library
LedControl lc = LedControl(dataPin, clockPin, csPin, 1);

// Define the LED matrix dimensions
const int matrixWidth = 8;
const int matrixHeight = 8;

// Eye expressions (patterns for eyes)
byte neutralEyes[matrixHeight] = {
  B00000000,
  B01000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B01000000,
  B00000000
};

byte happyEyes[matrixHeight] = {
  B00000000,
  B01000000,
  B00000000,
  B00000000,
  B10000001,
  B00011000,
  B01000000,
  B00000000
};

byte sadEyes[matrixHeight] = {
  B00000000,
  B01000000,
  B00000000,
  B00000000,
  B00011000,
  B10000001,
  B01000000,
  B00000000
};

void setup() {
  lc.shutdown(0, false); // Wake up the matrix
  lc.setIntensity(0, 8); // Set brightness (0-15)
  lc.clearDisplay(0);    // Clear the display
}

void loop() {
  displayEyeExpression(neutralEyes);
  delay(1000);
  
  displayEyeExpression(happyEyes);
  delay(1000);
  
  displayEyeExpression(sadEyes);
  delay(1000);
}

void displayEyeExpression(const byte* eyePattern) {
  for (int row = 0; row < matrixHeight; row++) {
    lc.setRow(0, row, eyePattern[row]);
  }
}
