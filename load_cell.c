/*
    Project name : Load Cell
    Modified Date: 14-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-load-cell
*/

#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  Serial.println("HX711 calibration sketch");

  Serial.println("Remove all weight from scale");
  Serial.println("Place known weight on scale");
  delay(2000);

  scale.set_scale(); // Assume scale has no weight on it at start
  scale.tare(); // Reset the scale to 0

  Serial.println("Place known weight on scale");
  delay(5000); // Allow time to place weight on scale

  float calibration_factor = scale.get_units(10) / known_weight; // Calculate calibration factor

  Serial.print("Calibration factor: ");
  Serial.println(calibration_factor);

  scale.set_scale(calibration_factor); // Set the calibration factor
}

void loop() {
  // Read and print weight to Serial Monitor
  Serial.print("Weight: ");
  Serial.print(scale.get_units(), 1); // Get weight value and print it
  Serial.println(" kg");

  delay(1000);
}
