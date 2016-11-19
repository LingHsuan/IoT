#include <math.h>

int tempPin = A1; // temperature sensor
int tempVal = 0;
int soilPin = A2; // moisture sensor
int soilVal = 0;
float celsius, soil;

void setup() {
  Serial.begin(9600);
}

void loop() {
  tempVal = analogRead(tempPin);
  celsius = toCelsius(tempVal);

  soilVal = analogRead(soilPin);
  soil = toPercentage(soilVal);

  Serial.print(tempVal);
  Serial.print("\t");
  Serial.print(celsius, 1);
  Serial.print("'C\t\t");
  Serial.print(soilVal);
  Serial.print("\t");
  Serial.print(soil, 0);
  Serial.println("%");

  delay(2000);
}

// convert temperature to Celsius
float toCelsius(int value) {
  float resistance = (float)(1023 - value) * 10000 / value;
  double temperature = 1 / (log10(resistance / 10000) / 3975 + 1 / 298.15) - 273.15;
  return temperature;
}

// convert value to percentage
float toPercentage(int value) {
  float convert = (float)value / 650;
  return convert;
}

