#include <SoftwareSerial.h>

SoftwareSerial sim800aSerial(16, 17); // RX (ESP32 GPIO 16), TX (ESP32 GPIO 17)

void setup() {
  Serial.begin(9600);
  sim800aSerial.begin(9600);

  // Rest of the setup code remains the same
  // ...
}

void loop() {
  sendSMS("+8921630481", "Hello from ESP32!");

  delay(5000); // Wait before sending the next message
}

void sendSMS(const char* phoneNumber, const char* message) {
  // SMS sending code remains the same
  // ...
}
