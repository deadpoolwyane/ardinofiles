// Define the pins for the ultrasonic sensor
const int trigPin = 2;  // Trig pin
const int echoPin = 3;  // Echo pin

// Variables to store the duration and distance
long duration;
int distance_cm;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Define the trigger and echo pins as OUTPUT and INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10us pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance_cm = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(200-distance_cm);
  Serial.println(" cm");

  // Add a delay before the next measurement
  delay(1000);  // You can adjust the delay to change the measurement rate
}
