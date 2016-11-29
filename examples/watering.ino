#include <Plant.h>

#define moiPin A2
#define dhtPin 2
#define pumpAnodePin 6
#define pumpCathodePin 7

float humidity, temperature, moisture;

Plant plant(moiPin);
DHT dht(dhtPin);
Pump pump(pumpAnodePin, pumpCathodePin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  dht.set();
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  moisture = plant.readMoisture();
  pump.watering(moisture, temperature, 7); //ms

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
