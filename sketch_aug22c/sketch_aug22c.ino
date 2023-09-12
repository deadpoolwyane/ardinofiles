#include <LedControl.h>

// Define the pins for your LED matrix
#define DIN_PIN 2
#define CLK_PIN 3
#define CS_PIN 4

LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);

// Define the "eyes open" expression pattern
byte eyesOpenPattern[8] = {
  B00111100,
  B01000010,
  B10000001,
  B10100101,
  B10100101,
  B10000001,
  B01000010,
  B00111100
};

// Define the "eyes closed" expression pattern
byte eyesClosedPattern[8] = {
  B00111100,
  B01000010,
  B10000001,
  B10111101,
  B10111101,
  B10000001,
  B01000010,
  B00111100
};

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  displayPattern(eyesOpenPattern);
  delay(1000); // Display "eyes open" for 1 second
  
  displayPattern(eyesClosedPattern);
  delay(1000); // Display "eyes closed" for 1 second
}

void displayPattern(byte pattern[8]) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, pattern[row]);
  }
}
