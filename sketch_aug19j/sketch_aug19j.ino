void setup() {
  Serial.begin(9600); // Initialize serial communication
  Serial.println("Initializing GSM...");

  // Initialize the GSM module (use appropriate AT commands)
  delay(1000);
  Serial.println("GSM initialized.");
}

void loop() {
  // Initiate a call
  Serial.println("Initiating call...");
  delay(500);
  
  // Send AT command to initiate the call
  Serial.println("ATD+8921630481");// Example: Serial.println("ATD+1234567890;");
  
  delay(30000);  // Call duration (30 seconds)
  
  // Send AT command to hang up the call
  Serial.println("ATH");// Example: Serial.println("ATH");
  
  Serial.println("Call initiated and hung up.");
  delay(5000); // Wait for a while before attempting the next call
}
