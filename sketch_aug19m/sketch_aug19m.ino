#include <SoftwareSerial.h>

SoftwareSerial sim800aSerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  sim800aSerial.begin(9600);

  delay(1000);

  Serial.println("Initializing SIM800A...");

  sim800aSerial.println("AT");
  delay(1000);
  while (sim800aSerial.available()) {
    Serial.write(sim800aSerial.read());
  }

  Serial.println("Setting up SMS mode...");
  sim800aSerial.println("AT+CMGF=1");
  delay(1000);
  while (sim800aSerial.available()) {
    Serial.write(sim800aSerial.read());
  }

  Serial.println("Setting preferred SMS storage...");
  sim800aSerial.println("AT+CPMS=\"SM\",\"SM\",\"SM\""); // Preferred storage: SIM card
  delay(1000);
  while (sim800aSerial.available()) {
    Serial.write(sim800aSerial.read());
  }
}

void loop() {
  sendSMS("+8921630481", "Hello from Arduino!");

  delay(5000); // Wait before sending the next message
}

void sendSMS(const char* phoneNumber, const char* message) {
  Serial.println("Sending SMS...");
  
  sim800aSerial.print("AT+CMGS=\"");
  sim800aSerial.print(phoneNumber);
  sim800aSerial.println("\"");
  delay(1000);

  sim800aSerial.print(message);
  delay(100);
  sim800aSerial.write(26); // Ctrl+Z
  delay(1000);

  while (sim800aSerial.available()) {
    Serial.write(sim800aSerial.read());
  }
}
