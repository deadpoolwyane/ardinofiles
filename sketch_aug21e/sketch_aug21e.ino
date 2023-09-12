#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN            6
#define MATRIX_WIDTH   32
#define MATRIX_HEIGHT  8

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(MATRIX_WIDTH, MATRIX_HEIGHT, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(50);
}

void loop() {
  // Clear the matrix
  matrix.fillScreen(0);

  // Draw different expressions
  drawPattern(happyPattern, 255, 255, 0);
  delay(2000);

  clearMatrix();

  drawPattern(sadPattern, 0, 0, 255);
  delay(2000);
}

void drawPattern(const uint8_t pattern[][MATRIX_WIDTH], uint8_t r, uint8_t g, uint8_t b) {
  for (int y = 0; y < MATRIX_HEIGHT; y++) {
    for (int x = 0; x < MATRIX_WIDTH; x++) {
      if (pattern[y][x] == 1) {
        matrix.drawPixel(x, y, matrix.Color(r, g, b));
      }
    }
  }
  matrix.show();
}

void clearMatrix() {
  matrix.fillScreen(0);
  matrix.show();
}

// List of example patterns
const uint8_t happyPattern[MATRIX_HEIGHT][MATRIX_WIDTH] = {
  // Your 32x8 pattern for happy expression here
};

const uint8_t sadPattern[MATRIX_HEIGHT][MATRIX_WIDTH] = {
  // Your 32x8 pattern for sad expression here
};
