#include <LedControl.h>

// Create LedControl objects for left and right eyes
LedControl leftEyeLC = LedControl(11, 9, 10, 1);
LedControl rightEyeLC = LedControl(5, 7, 6, 1); // Adjust the pin numbers as needed

// Delay between expressions
const int expressionDelay = 100;

void setup() {
  // Initialize the MAX7219 for both eyes
  leftEyeLC.shutdown(0, false);
  leftEyeLC.setIntensity(0, 8);
  leftEyeLC.clearDisplay(0);

  rightEyeLC.shutdown(0, false);
  rightEyeLC.setIntensity(0, 8);
  rightEyeLC.clearDisplay(0);
}

void loop() {
  // Simulate happiness (both eyes on)
  showExpression(leftEyeLC, B00011000, B00011000);
  showExpression(rightEyeLC, B00011000, B00011000);
  delay(expressionDelay);

  // Simulate sadness (both eyes off)
  showExpression(leftEyeLC, B00000000, B00000000);
  showExpression(rightEyeLC, B00000000, B00000000);
  delay(expressionDelay);

  // Simulate surprise (alternating blink)
  showExpression(leftEyeLC, B00001000, B00001000);
  showExpression(rightEyeLC, B00001000, B00001000);
  delay(expressionDelay);
  showExpression(leftEyeLC, B00000100, B00000100);
  showExpression(rightEyeLC, B00000100, B00000100);
  delay(expressionDelay);

  // Simulate curiosity (one eye raised)
  showExpression(leftEyeLC, B00111000, B00011000);
  showExpression(rightEyeLC, B00011000, B00111000);
  delay(expressionDelay);

  // Simulate confusion (crossed eyes)
  showExpression(leftEyeLC, B00100100, B00100100);
  showExpression(rightEyeLC, B00100100, B00100100);
  delay(expressionDelay);

  // Simulate anger (angry eyebrows)
  showExpression(leftEyeLC, B00011000, B00111100);
  showExpression(rightEyeLC, B00111100, B00011000);
  delay(expressionDelay);

  // Simulate love (heart-shaped eyes)
  showExpression(leftEyeLC, B01000100, B10000001);
  showExpression(rightEyeLC, B10000001, B01000100);
  delay(expressionDelay);

  // Simulate mischief (winking)
  showExpression(leftEyeLC, B00001000, B00000000);
  showExpression(rightEyeLC, B00000000, B00001000);
  delay(expressionDelay);

  // Simulate eyes looking up
  showExpression(leftEyeLC, B00011000, B00000000);
  showExpression(rightEyeLC, B00000000, B00011000);
  delay(expressionDelay);

  // Simulate eyes looking down
  showExpression(leftEyeLC, B00000000, B00011000);
  showExpression(rightEyeLC, B00011000, B00000000);
  delay(expressionDelay);

  // Simulate eyes looking right
  showExpression(leftEyeLC, B00000000, B00011000);
  showExpression(rightEyeLC, B00000000, B00000001);
  delay(expressionDelay);

  // Simulate eyes looking left
  showExpression(leftEyeLC, B00011000, B00000000);
  showExpression(rightEyeLC, B00000001, B00000000);
  delay(expressionDelay);

  // ... (Add more expressions as needed)
}

// Display an expression on the dot matrix for each eye
void showExpression(LedControl lc, byte leftEye, byte rightEye) {
  for (int row = 0; row < 8; row++) {
    byte rowPattern = (leftEye >> row) | (rightEye >> row);
    lc.setRow(0, row, rowPattern);
  }
}
