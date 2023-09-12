#include <LedControl.h>

// Create a LedControl object
LedControl lc = LedControl(11, 13, 10, 1);

// Delay between expressions
const int expressionDelay = 1000;

void setup() {
  // Initialize the MAX7219
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  // Simulate happiness (both eyes on)
  showExpression(B00000000, B00011000, B00011000, B00000000);
  delay(expressionDelay);

  // Simulate sadness (both eyes off)
  showExpression(B00000000, B00000000, B00000000, B00000000);
  delay(expressionDelay);

  // Simulate surprise (alternating blink)
  showExpression(B00001000, B00001000, B00001000, B00001000);
  delay(expressionDelay);
  showExpression(B00000100, B00000100, B00000100, B00000100);
  delay(expressionDelay);

  // ... (Add more expressions as needed)
}

// Display an expression on the 8x32 dot matrix
void showExpression(byte leftEyeTop, byte rightEyeTop, byte leftEyeBottom, byte rightEyeBottom) {
  for (int row = 0; row < 8; row++) {
    byte rowPattern = (leftEyeTop >> row) | (rightEyeTop >> row) | 
                     ((leftEyeBottom >> row) << 8) | ((rightEyeBottom >> row) << 8);
    lc.setRow(0, row, rowPattern);
  }
}
