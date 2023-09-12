#include <SoftwareSerial.h>

SoftwareSerial sim800aSerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600); // For serial monitor debugging
  sim800aSerial.begin(9600);

  delay(1000); // Give the module some time to initialize

  Serial.println("Initializing SIM800A...");
  sim800aSerial.println("AT"); // Check if the module is responding
  delay(1000);
  while (sim800aSerial.available()) {
    Serial.write(sim800aSerial.read());
  }

  Serial.println("Setting up SMS mode...");
  sim800aSerial.println("AT+CMGF=1"); // Set SMS mode to text
  delay(1000);
  while (sim800aSerial.available()) {
    Serial.write(sim800aSerial.read());
  }
}

void loop() {
  Serial.println("Sending SMS...");
  sim800aSerial.println("AT+CMGS=\"+8921630481\""); // Replace with the recipient's phone number
  delay(1000);
  sim800aSerial.println("Hello"); // Your message
  delay(1000);
  sim800aSerial.write(0x1A); // Send Ctrl+Z
  delay(1000);

  while (sim800aSerial.available()) {
    Serial.write(sim800aSerial.read());
  }

  delay(5000); // Wait for a while before sending the next message
}
