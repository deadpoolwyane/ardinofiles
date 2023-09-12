#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <HX711.h>
#include <DFRobotDFPlayerMini.h>
#define DEBUG_HX711
#define CALIBRATION_FACTOR 20780.0

LiquidCrystal_I2C lcd(0x3F, 16, 2);
byte pinData = 4;
byte pinClk = 5;

HX711 scale;

SoftwareSerial mySerial(10, 11); // RX, TX (connect to TX and RX of the DFPlayer Mini)
DFRobotDFPlayerMini dfplayer;

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

  mySerial.begin(9600);
  dfplayer.begin(mySerial);
  dfplayer.volume(20); // Set volume (0 to 30)
}

void loop() {
 #ifdef DEBUG_HX711
  float weight = scale.get_units(),2);

  lcd.setCursor(0, 1);
  lcd.print("Reading:");
  lcd.print(weight, 2);
  lcd.print(" Kgs");
  Serial.println();

  char weightStr[10];
  dtostrf(weight, 5, 2, weightStr);

  // Speak the weight using the DFPlayer Mini
  dfplayer.playMp3Folder(1); // Play the speech file with index 1 on the SD card

  delay(500); // Add a delay to allow time for the speech to complete before reading the next value
}
