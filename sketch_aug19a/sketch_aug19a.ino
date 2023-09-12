#include <SoftwareSerial.h>

SoftwareSerial gsmModule(7, 8);  // RX, TX pins for GSM module
String phoneNumber = "8921630481";

void setup() {
  Serial.begin(9600);
  gsmModule.begin(9600);
}

void loop() {
  if (gsmModule.available()) {
    char c = gsmModule.read();
    if (c == 'R') {
      delay(10);
      if (gsmModule.read() == 'I' && gsmModule.read() == 'N' && gsmModule.read() == 'G') {
        // Incoming call detected, read the phone number
        while (gsmModule.available()) {
          char numChar = gsmModule.read();
          if (isdigit(numChar)) {
            phoneNumber += numChar;
          }
        }
        
        // Send SMS to the detected phone number
        sendSMS(phoneNumber, "Hello from your Arduino!");
        
        // Clear the phone number for the next iteration
        phoneNumber = "8921630481";
      }
    }
  }
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
