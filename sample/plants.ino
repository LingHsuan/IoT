#include <Plant.h>

#define moiPin A2
#define dhtPin 2
#define fanPin 3

float humidity, temperature, moisture, moiValue;

Plant plant(moiPin);
DHT dht(dhtPin);
Fan fan(fanPin);
LED leds(7, 8, 1);

void setup() {
  dht.init();
  fan.init();
  leds.init();
  Serial.begin(9600);
}

void loop() {
  dht.set();
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  moiValue = plant.readMoisture();
  moisture = plant.MoiToPercentage(moiValue);
  fan.fanning(temperature);
  leds.lighting(moisture);

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.println("*C");
  Serial.print("Humidity: ");
  Serial.print(humidity, 0);
  Serial.println("%");
  Serial.print("Moisture: ");
  Serial.print(moiValue, 0);
  Serial.print("\t");
  Serial.print(moisture, 0);
  Serial.println("%");
  Serial.println();

  delay(5000);
}
