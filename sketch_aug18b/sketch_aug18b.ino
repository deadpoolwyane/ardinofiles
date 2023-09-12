#include <SoftwareSerial.h>

SoftwareSerial gsmSerial(7, 8); // RX, TX

void setup() {
  Serial.begin(9600);
  gsmSerial.begin(9600);
  delay(1000);
  
  // Check for the event and send SMS if it occurs
  if (checkEvent()) {
    sendSMS();
  }
}

void loop() {
  // Your loop code here
}

bool checkEvent() {
  // Replace this with your own event-checking logic
  // For demonstration, let's simulate an event every 10 seconds
  static unsigned long lastEventTime = 0;
  if (millis() - lastEventTime >= 10000) {
    lastEventTime = millis();
    return true; // Simulate an event every 10 seconds
  }
  return false;
}

void sendSMS() {
  gsmSerial.println("AT");
  delay(1000);
  gsmSerial.println("AT+CMGF=1"); // Set SMS text mode
  delay(1000);
  
  gsmSerial.println("AT+CMGS=\"8921630481\""); // Replace with recipient's number
  delay(1000);
  gsmSerial.print("Hello mags");
  gsmSerial.write(26); // Ctrl+Z character to indicate end of message
  delay(1000);
}
