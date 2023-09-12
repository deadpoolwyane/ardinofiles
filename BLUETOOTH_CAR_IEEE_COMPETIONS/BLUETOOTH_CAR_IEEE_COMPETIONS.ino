
#include <AFMotor.h> // Library for controlling DC motors
#include <SoftwareSerial.h> // Library for software serial communication (Bluetooth)

// Motor Shield Configuration
AF_DCMotor motor1(1); // Motor 1 is connected to M1 on the motor shield
AF_DCMotor motor2(2); // Motor 2 is connected to M2 on the motor shield
AF_DCMotor motor3(3); // Motor 3 is connected to M3 on the motor shield
AF_DCMotor motor4(4); // Motor 4 is connected to M4 on the motor shield

// Bluetooth Module Configuration
SoftwareSerial bluetooth(10, 11); // RX, TX pins for Bluetooth (change as needed)

void setup() {
  // Set the motor speed (0-255)
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize Bluetooth communication
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available() > 0) {
    char command = bluetooth.read();

    // Check the command received from Bluetooth
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        backward();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'S':
        stopMotors();
        break;
    }
  }
}

void forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void left() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void right() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
