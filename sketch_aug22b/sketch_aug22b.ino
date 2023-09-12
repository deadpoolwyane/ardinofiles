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

// Define the "love" expression pattern
byte lovePattern[8] = {
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000
};

// Define the "cry" expression pattern
byte cryPattern[8] = {
  B00000000,
  B01000100,
  B00101000,
  B10010001,
  B10010001,
  B00101000,
  B01000100,
  B00000000
};

// Define the "confusion" expression pattern
byte confusionPattern[8] = {
  B00111100,
  B01000010,
  B10001000,
  B00010100,
  B00101000,
  B01000010,
  B00111100,
  B00000000
};

// Define the "confidence" expression pattern
byte confidencePattern[8] = {
  B00111100,
  B01000010,
  B10000001,
  B10011001,
  B10011001,
  B10000001,
  B01000010,
  B00111100
};

// Define the "happy" expression pattern
byte happyPattern[8] = {
  B00000000,
  B00100100,
  B00100100,
  B00000000,
  B10000001,
  B01000010,
  B00111100,
  B00000000
};

// Define the "thundering" expression pattern
byte thunderingPattern[8] = {
  B00010000,
  B00111000,
  B00111000,
  B00111000,
  B01111100,
  B01111100,
  B01111100,
  B01111100
};

// Define the "slowly blinking" pattern
byte slowlyBlinkingPattern[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  // Display "slowly blinking" expression for both eyes
  for (int i = 0; i < 5; i++) {
    displayPattern(slowlyBlinkingPattern);
    delay(400); // Display blank for 400 milliseconds
    
    displayPattern(eyesOpenPattern);
    delay(400); // Display "eyes open" for 400 milliseconds
  }
  
  // Display "eyes closed" expression
  displayPattern(eyesClosedPattern);
  delay(1000); // Display "eyes closed" for 1 second

  // Display "love" expression
  displayPattern(lovePattern);
  delay(1000); // Display "love" for 1 second

  // Display "cry" expression
  displayPattern(cryPattern);
  delay(1000); // Display "cry" for 1 second

  // Display "confusion" expression
  displayPattern(confusionPattern);
  delay(1000); // Display "confusion" for 1 second

  // Display "confidence" expression
  displayPattern(confidencePattern);
  delay(1000); // Display "confidence" for 1 second

  // Display "happy" expression
  displayPattern(happyPattern);
  delay(1000); // Display "happy" for 1 second

  // Display "thundering" expression
  displayPattern(thunderingPattern);
  delay(1000); // Display "thundering" for 1 second
}

void displayPattern(byte pattern[8]) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, pattern[row]);
  }
}
