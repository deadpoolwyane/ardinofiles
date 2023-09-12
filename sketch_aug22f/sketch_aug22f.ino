#include <LedControl.h>

const int dataPin = 11;
const int clockPin = 13;
const int csPin = 10;

LedControl lc = LedControl(dataPin, clockPin, csPin, 1);

const int matrixWidth = 8;
const int matrixHeight = 8;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  displayEyes();
  delay(1000);
}

void displayEyes() {
  lc.setRow(0, 2, B11000011); // Upper eyelid
  lc.setRow(0, 5, B11000011); // Lower eyelid
  delay(500);
  
  lc.setRow(0, 2, B11111111); // Open eyes
  lc.setRow(0, 5, B11111111);
  delay(1000);
  
  lc.setRow(0, 2, B11100000); // Squint eyes
  lc.setRow(0, 5, B11100000);
  delay(500);
  
  lc.setRow(0, 2, B11000011); // Return to normal
  lc.setRow(0, 5, B11000011);
  delay(1000);
}
