#include <Servo.h>

Servo myservo;  // Create a Servo object
int trigPin = 7; // Ultrasonic sensor trigger pin
int echoPin = 8; // Ultrasonic sensor echo pin
long duration, distance;

void setup() {
  myservo.attach(9); // Attaches the servo on pin 9
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Ultrasonic sensor distance measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Calculate distance in centimeters

  // Servo motor control based on distance
  if (distance <= 10) { // If an object is within 10cm, move the servo
    myservo.write(90); // Move the servo to 90 degrees (adjust as needed)
  } else {
    myservo.write(0); // Move the servo to 0 degrees (adjust as needed)
  }

  // Print distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500); // Delay for stability
}
