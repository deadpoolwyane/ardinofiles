#include <SoftwareSerial.h>

SoftwareSerial gsmModule(7, 8);  // RX, TX pins for GSM module
String phoneNumber = "";

const int sendSMSPin = 2;  // Pin for the button to send SMS
boolean sendSMSFlag = false;

void setup() {
  Serial.begin(9600);
  gsmModule.begin(9600);
  pinMode(sendSMSPin, INPUT_PULLUP);  // Set the button pin as input with internal pull-up resistor
}

void loop() {
  // Check if the button is pressed to send SMS
  if (digitalRead(sendSMSPin) == LOW) {
    sendSMSFlag = true;
    while (digitalRead(sendSMSPin) == LOW) {
      // Wait for button release
    }
  }

  // If the flag is set, send SMS
  if (sendSMSFlag) {
    sendSMS("8921630481", "Hello from your Arduino!");
    sendSMSFlag = false;  // Reset the flag
  }

  // Other parts of your loop code
}

void sendSMS(String recipient, String message) {
  // The code to send SMS, same as before
}
