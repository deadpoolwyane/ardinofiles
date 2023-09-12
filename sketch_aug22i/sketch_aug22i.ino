#include <Servo.h>
Servo headServo;
Servo leftHandServo;
Servo rightHandServo;
#include <Arduino.h>
#include <LedControl.h>  // Include the LedControl library
const uint8_t IMAGES[][8] = {
{
  0b00111100,
  0b01111110,
  0b11111111,
  0b11100111,
  0b11100111,
  0b11111111,
  0b01111110,
  0b00111100
},{
  0b00111100,
  0b01111110,
  0b11111111,
  0b11100111,
  0b11100111,
  0b11111111,
  0b01111110,
  0b00111100
},{
  0b00000000,
  0b00111100,
  0b01000010,
  0b01011010,
  0b01011010,
  0b01000010,
  0b00111100,
  0b00000000
},{
  0b00000000,
  0b00111100,
  0b01000010,
  0b01011010,
  0b01011010,
  0b01000010,
  0b00111100,
  0b00000000
},{
  0b00000000,
  0b00111100,
  0b01110010,
  0b01110010,
  0b01111110,
  0b01111110,
  0b00111100,
  0b00000000
},{
  0b00000000,
  0b00111100,
  0b01110010,
  0b01110010,
  0b01111110,
  0b01111110,
  0b00111100,
  0b00000000
},{
  0b00000000,
  0b00111100,
  0b01001110,
  0b01001110,
  0b01111110,
  0b01111110,
  0b00111100,
  0b00000000
},{
  0b00000000,
  0b00111100,
  0b01001110,
  0b01001110,
  0b01111110,
  0b01111110,
  0b00111100,
  0b00000000
},{
  0b00000000,
  0b00111100,
  0b01111110,
  0b01111110,
  0b01001110,
  0b01001110,
  0b00111100,
  0b00000000
},{
  0b00000000,
  0b00111100,
  0b01111110,
  0b01111110,
  0b01001110,
  0b01001110,
  0b00111100,
  0b00000000
},{
  0b00000000,
  0b00111100,
  0b01111110,
  0b01111110,
  0b01110010,
  0b01110010,
  0b00111100,
  0b00000000
},{
  0b00000000,
  0b00111100,
  0b01111110,
  0b01111110,
  0b01110010,
  0b01110010,
  0b00111100,
  0b00000000
},{
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111
},{
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111
},{
  0b00000000,
  0b01111110,
  0b01000010,
  0b01000010,
  0b01000010,
  0b01000010,
  0b01111110,
  0b00000000
},{
  0b00000000,
  0b01111110,
  0b01000010,
  0b01000010,
  0b01000010,
  0b01000010,
  0b01111110,
  0b00000000
},{
  0b00000000,
  0b00000000,
  0b00111100,
  0b00100100,
  0b00100100,
  0b00111100,
  0b00000000,
  0b00000000
},{
  0b00000000,
  0b00000000,
  0b00111100,
  0b00100100,
  0b00100100,
  0b00111100,
  0b00000000,
  0b00000000
},{
  0b11111111,
  0b11111111,
  0b11111111,
  0b10000011,
  0b10000011,
  0b10000011,
  0b10000011,
  0b10000011
},{
  0b11111111,
  0b11111111,
  0b11111111,
  0b10000011,
  0b10000011,
  0b10000011,
  0b10000011,
  0b10000011
}};
const int IMAGES_LEN = sizeof(IMAGES)/8;

// Define the pin connections for the LED matrix
const int DIN_PIN = 2;   // Data In
const int CLK_PIN = 3;   // Clock
const int CS_PIN = 4;    // Chip Select

LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);  // Create a LedControl instance

// Set up function
void setup() {

  headServo.attach(9);     // Attach head servo to pin 9
  leftHandServo.attach(10); // Attach left hand servo to pin 10
  rightHandServo.attach(11);// Attach right hand servo to pin 11
  // Initialize the LED matrix
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);   // Adjust intensity (0-15)
  lc.clearDisplay(0);      // Clear the display
}

// Display a single image on the LED matrix
void displayImage(const uint8_t *image) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, image[row]);  // Set the row data on the LED matrix
  }
  delay(1000);  // Display each image for 1 second
  lc.clearDisplay(0);  // Clear the display
}

// Loop function
void loop() {
  
   // Move head to different positions
  headServo.write(90);    // Center position
  delay(1000);
  headServo.write(0);     // One extreme
  delay(1000);
  headServo.write(180);   // Other extreme
  delay(1000);
  
  // Move left hand to different positions
  leftHandServo.write(0);    // One extreme
  delay(1000);
  leftHandServo.write(90);   // Center position
  delay(1000);
  leftHandServo.write(180);  // Other extreme
  delay(1000);
  
  // Move right hand to different positions
  rightHandServo.write(0);   // One extreme
  delay(1000);
  rightHandServo.write(90);  // Center position
  delay(1000);
  rightHandServo.write(180); // Other extreme
  delay(1000);
  // Display each image in sequence
  for (int i = 0; i < IMAGES_LEN; i++) {
    displayImage(IMAGES[i]);
  }
}
