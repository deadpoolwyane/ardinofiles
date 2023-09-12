#include <Servo.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "MD_EyePair.h"

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 10
#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  // or SS

Servo leftHandServo;
Servo rightHandServo;
Servo headServo;

MD_MAX72XX M = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
MD_EyePair E[MAX_DEVICES/2];

#define DELAYTIME  500  // in milliseconds

void setup() {
  leftHandServo.attach(9);   // Attach left hand servo to digital pin 9
  rightHandServo.attach(10); // Attach right hand servo to digital pin 10
  headServo.attach(8);       // Attach head servo to digital pin 8

  M.begin();

  for (uint8_t i = 0; i < MAX_DEVICES/2; i++)
    E[i].begin(i * 2, &M, DELAYTIME);
}

void loop() {
  // Move left hand servo up and down
  leftHandServo.write(0);
  delay(1000);
  leftHandServo.write(90);
  delay(1000);

  // Move right hand servo left and right
  rightHandServo.write(0);
  delay(1000);
  rightHandServo.write(180);
  delay(1000);

  // Move head servo left and right
  headServo.write(0);
  delay(1000);
  headServo.write(180);
  delay(1000);

  // Move eyes up and down
  for (uint8_t i = 0; i < MAX_DEVICES/2; i++) {
    E[i].setEyePos(0, -2);
    E[i].animate();
    delay(1000);
    E[i].setEyePos(0, 2);
    E[i].animate();
    delay(1000);
  }
}
