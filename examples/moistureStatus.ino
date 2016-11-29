#include <Plant.h>

#define moiPin A2
#define dhtPin 2
#define clkPin 4
#define dataPin 5

float humidity, temperature, moisture;

Plant plant(moiPin);
DHT dht(dhtPin);
LED leds(clkPin, dataPin, 1);

void setup() {
  leds.init();
  Serial.begin(9600);
}

void loop() {
  dht.set();
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  moisture = plant.readMoisture();
  leds.lighting(moisture);

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.println("*C");
  Serial.print("Humidity: ");
  Serial.print(humidity, 0);
  Serial.println("%");
  Serial.print("Moisture: ");
  Serial.print(moisture, 0);
  Serial.println("%");
  Serial.println();

  delay(5000);
}
