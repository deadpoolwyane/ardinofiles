#include <LedControl.h>

LedControl lc = LedControl(12, 11, 10, 1);  // Pins: DIN, CLK, CS, Number of MAX7219 modules

void setup() {
  lc.shutdown(0, false);  // Turn on the display
  lc.setIntensity(0, 8);  // Set brightness (0-15)
  lc.clearDisplay(0);     // Clear the display
}

void loop() {
  // Create expressions
  displayExpression("happyExpression");
  delay(1000);
  
  displayExpression("sadExpression");
  delay(1000);
  
  displayExpression("surprisedExpression");
  delay(1000);
  
  // Add more expressions as needed
}

void displayExpression(byte expression[]) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, expression[row]);
  }
}
