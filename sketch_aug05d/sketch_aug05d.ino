#include <HX711.h>
#include <LiquidCrystal_I2C.h>

const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;
const int SWITCH_PIN = 4;
const int LED_PIN = 5;
const int DISPLAY_ROWS = 2;
const int DISPLAY_COLUMNS = 16;

HX711 scale;

LiquidCrystal_I2C lcd(0x27, DISPLAY_COLUMNS, DISPLAY_ROWS);

void setup() {
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  lcd.begin(DISPLAY_COLUMNS, DISPLAY_ROWS);
  lcd.print("Weight:");
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(1.0); // Adjust this value for calibration
  scale.tare();
}

void loop() {
  if (digitalRead(SWITCH_PIN) == LOW) {
    digitalWrite(LED_PIN, HIGH);
    long rawWeight = scale.get_units(10);
    if (rawWeight < 0) rawWeight = 0;
    lcd.setCursor(7, 1);
    lcd.print("   "); // Clear previous weight value
    lcd.setCursor(7, 1);
    lcd.print(rawWeight, 1);
  } else {
    digitalWrite(LED_PIN, LOW);
    lcd.setCursor(7, 1);
    lcd.print("   ");
  }
}
