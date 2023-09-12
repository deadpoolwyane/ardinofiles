#include <SoftwareSerial.h>

SoftwareSerial gsmModule(2, 3);  // RX, TX

void setup() {
  Serial.begin(9600);           // Serial monitor
  gsmModule.begin(9600);        // GSM module
  
  delay(1000);
  
  Serial.println("Initializing GSM...");
  gsmModule.println("AT");      // Check if the GSM module is responsive
  delay(1000);
  while(gsmModule.available()) {
    Serial.write(gsmModule.read());
  }
  
  // Set the SMS format to text mode
  gsmModule.println("AT+CMGF=1");
  delay(1000);
  Serial.println("GSM initialized.");
}

void loop() {
  // Send SMS
  gsmModule.println("AT+CMGS=\"+1234567890\"");  // Replace with recipient's number
  delay(1000);
  gsmModule.print("Hello, this is a test message from Arduino!");  // SMS content
  delay(500);
  gsmModule.write(0x1A);  // Ctrl+Z to send the message
  delay(5000);  // Give some time for the message to be sent
  
  Serial.println("Message sent.");
  
  while(1);  // Endless loop
}
