#include "LedControl.h"

LedControl lc=LedControl(12, 11, 10, 1);

unsigned long delaytime = 250;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void writeArduinoOn7Segment() {
  lc.setChar(0, 0, 'a', false);
  delay(delaytime);
  lc.setRow(0, 0, 0x05);
  delay(delaytime);
  lc.setChar(0, 0, 'd', false);
  delay(delaytime);
  lc.setRow(0, 0, 0x1c);
  delay(delaytime);
  lc.setRow(0, 0, B00010000);
  delay(delaytime);
  lc.setRow(0, 0, 0x15);
  delay(delaytime);
  lc.setRow(0, 0, 0x1D);
  delay(delaytime);
  lc.clearDisplay(0);
  delay(delaytime);
}

void scrollDigits() {
  for (int i = 0; i < 13; i++) {
    lc.setDigit(0, 3, i, false);
    lc.setDigit(0, 2, i + 1, false);
    lc.setDigit(0, 1, i + 2, false);
    lc.setDigit(0, 0, i + 3, false);
    delay(delaytime);
  }
  lc.clearDisplay(0);
  delay(delaytime);
}

void loop() {
  writeArduinoOn7Segment();
  scrollDigits();
}
