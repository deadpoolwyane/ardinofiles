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
  Serial.println("ATD+91 8921630481;");  // Replace with the actual number
  delay(500); // Allow time for the command to be sent
  
  delay(30000);  // Call duration (30 seconds)
  
  // Send AT command to hang up the call
  Serial.println("ATH");
  delay(500); // Allow time for the command to be sent
  
  Serial.println("Call initiated and hung up.");
  delay(5000); // Wait for a while before attempting the next call
  
  // Send a message
  Serial.println("Sending message...");
  delay(500);
  
  // Send AT command to set SMS text mode
  Serial.println("AT+CMGF=1");
  delay(500); // Allow time for the command to be sent
  
  // Send AT command to specify the recipient's number and message
  Serial.println("AT+CMGS=\"+91 8921630481\""); // Replace with the actual number
  delay(500); // Allow time for the command to be sent
  
  // Send the message content
  Serial.println("Hello, this is a test message from Arduino!");
  delay(500); // Allow time for the message to be sent
  
  // Send Ctrl+Z character to indicate the end of the message
  Serial.write(0x1A);
  delay(500); // Allow time for the command to be sent
  
  Serial.println("Message sent.");
  delay(5000); // Wait for a while before attempting the next message
  
  while (1); // Endless loop
}
