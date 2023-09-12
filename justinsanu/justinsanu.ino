#include <LiquidCrystal_I2C.h>
#include "HX711.h"
#include <Talkie.h> // Include the Talkie library

#define DEBUG_HX711

#define CALIBRATION_FACTOR 20780.0

LiquidCrystal_I2C lcd(0x3F, 16, 2);
byte pinData = 3;
byte pinClk = 2;

HX711 scale;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("WEIGHT SCALE");

#ifdef DEBUG_HX711
  Serial.begin(9600);
  Serial.println("[HX7] Sensor start HX711");
#endif

  scale.begin(pinData, pinClk);
  scale.set_scale(CALIBRATION_FACTOR);
  scale.tare();

  // Initialize the Talkie library
  Talkie tts;
  tts.setVoice('1'); // Select a voice from available options (1 to 8)
}

void loop() {
#ifdef DEBUG_HX711
  Serial.print("[HX7] Reading: ");
  Serial.print(scale.get_units(), 2);
  Serial.print(" Kgs");
  Serial.println();
#endif

  float weight = scale.get_units();
  lcd.setCursor(0, 1);
  lcd.print("Reading:");
  lcd.print(weight, 2);
  lcd.print(" Kgs");

  // Convert the weight to a character array (string) to be spoken
  char weightStr[10];
  dtostrf(weight, 5, 2, weightStr);

  // Speak the weight using the Talkie library
  Talkie.say(weightStr);

  delay(1000); // Add a delay to allow time for the speech to complete before reading the next value

}
