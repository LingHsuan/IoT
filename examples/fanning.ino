#include <Plant.h>

#define moiPin A2
#define dhtPin 2
#define fanPin 3

float humidity, temperature, moisture;

Plant plant(moiPin);
DHT dht(dhtPin);
Fan fan(fanPin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  dht.set();
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  moisture = plant.readMoisture();
  fan.fanning(temperature);

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
