#include <AFMotor.h>
#include <SoftwareSerial.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

SoftwareSerial bluetooth(10, 11);  // RX, TX

const int trigPin = 6; // Ultrasonic sensor trig pin
const int echoPin = 7; // Ultrasonic sensor echo pin

void setup() {
  bluetooth.begin(9600);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  if (bluetooth.available() >= 2) {
    char command = bluetooth.read();
    int speed = bluetooth.read();
    
    switch (command) {
      case 'F':
        if (!obstacleDetected()) {
          moveForward(speed);
        } else {
          stopAndAvoidObstacle(speed);
        }
        break;
      case 'B':
        moveBackward(speed);
        break;
      case 'L':
        turnLeft(speed);
        break;
      case 'R':
        turnRight(speed);
        break;
      case 'S':
        stopMotors();
        break;
    }
  }
}

bool obstacleDetected() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;

  if (distance < 15) { // Adjust the threshold distance as needed
    return true;
  } else {
    return false;
  }
}

void stopAndAvoidObstacle(int speed) {
  moveBackward(speed);
  delay(500);
  turnRight(speed);
  delay(1000);
}

void moveForward(int speed) {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
}

void moveBackward(int speed) {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
}

void turnLeft(int speed) {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
}

void turnRight(int speed) {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
}

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
