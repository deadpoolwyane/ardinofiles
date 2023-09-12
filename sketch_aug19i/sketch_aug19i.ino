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
  
  Serial.println("GSM initialized.");
}

void loop() {
  // Initiate a call
  gsmModule.println("8921630481;");  // Replace with the number you want to call
  delay(500);  // Call duration
  
  Serial.println("Call initiated.");
  
  while(1);  // Endless loop
}
