#include <Servo.h>

Servo headServo;
Servo leftHandServo;
Servo rightHandServo;

void setup() {
  headServo.attach(9);     // Attach head servo to pin 9
  leftHandServo.attach(10); // Attach left hand servo to pin 10
  rightHandServo.attach(11);// Attach right hand servo to pin 11
}

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
}
