#include <SoftwareSerial.h>

SoftwareSerial gsmModule(7, 8);  // RX, TX pins for GSM module
String phoneNumber = "8921630481";

void setup() {
  Serial.begin(9600);
  gsmModule.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char key = Serial.read();
    if (key == '2') {
      // Send SMS when '2' is pressed
      sendSMS("8921630481", "Hello from your Arduino!");
    }
  }
  
  // Other parts of your loop code
}

void sendSMS(String recipient, String message) {
  gsmModule.println("AT+CMGF=1");  // Set SMS text mode
  delay(100);
  gsmModule.println("AT+CMGS=\"" + recipient + "\"");
  delay(100);
  gsmModule.print(message);
  delay(100);
  gsmModule.write(26);  // Ctrl+Z to send the SMS
}
