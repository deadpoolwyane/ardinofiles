#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <HX711.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

const int LOAD_CELL_DOUT_PIN = 2;
const int LOAD_CELL_SCK_PIN = 3;
const int BUTTON_PIN = 4; // Connect the button to this digital pin
const int READING_LED_PIN = 5; // LED to blink during reading time
const int NON_READING_LED_PIN = 6; // LED to stay lit during non-reading time

bool isReadingEnabled = true; // Flag to control load cell readings

HX711 scale;
LiquidCrystal_I2C lcd(0x3F, 16, 2); // Adjust the address (0x27) according to your I2C module
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX for DFPlayer Mini
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); // Initialize the LCD
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("Load Cell Test");
  delay(3000);
  lcd.clear();

  pinMode(BUTTON_PIN, INPUT_PULLUP); // Set the button pin as input with internal pull-up resistor
  pinMode(READING_LED_PIN, OUTPUT);
  pinMode(NON_READING_LED_PIN, OUTPUT);

  scale.begin(LOAD_CELL_DOUT_PIN, LOAD_CELL_SCK_PIN);
  scale.set_scale(); // This should be adjusted according to your specific load cell calibration
  scale.tare();      // Set the scale to 0 (assuming no load on the load cell during startup)

  mySoftwareSerial.begin(9600);
  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println("Unable to begin DFPlayer");
    while (true); // Halt the program if DFPlayer initialization fails
  }
  myDFPlayer.setTimeOut(500);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) { // Button is pressed
    isReadingEnabled = !isReadingEnabled; // Toggle the reading state
    delay(200); // Debounce delay to avoid multiple toggles with one press
  }

  if (isReadingEnabled) {
    digitalWrite(READING_LED_PIN, HIGH); // Turn on the LED during reading time
    digitalWrite(NON_READING_LED_PIN, LOW);
    if (scale.is_ready()) {
      float weight = scale.get_units();
      lcd.clear();
      lcd.print("Weight: ");
      lcd.print(weight);
      lcd.print(" kg");
      Serial.print("Weight: ");
      Serial.print(weight);
      Serial.println(" kg");
      speakWeight(weight); // Speak the weight using the TTS module
    }
    delay(1000); // Read every second, adjust as needed
    digitalWrite(READING_LED_PIN, LOW); // Turn off the LED after reading time
  } else {
    digitalWrite(NON_READING_LED_PIN, HIGH); // Keep the LED on during non-reading time
  }
}

void speakWeight(float weight) {
  int fileNumber = map(weight, 0, 5, 1, 5); // Map the weight to the corresponding file number
  myDFPlayer.volume(20); // Adjust volume (0-30)
  myDFPlayer.play(fileNumber); // Play the audio file corresponding to the weight
  while (myDFPlayer.available()) {
    myDFPlayer.readType();
  }
  delay(3000); // Wait for the audio to finish playing before continuing
}
