#include <HX711.h>

const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {
  // Replace 1.0 with your calibration factor for accurate measurements
  float calibration_factor = 1.0;

  scale.set_scale(calibration_factor); // Set calibration factor
  float weight = scale.get_units(); // Get the weight reading
  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" kg");

  delay(1000); // Wait for a second
}
