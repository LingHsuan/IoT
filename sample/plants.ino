#include <Plant.h>
#include <ChainableLED.h>

#define moiPin A2
#define dhtPin 2
#define fanPin 3

float humidity, temperature, moisture, moiValue;

plant plant(moiPin);
dht dht(dhtPin);
fan fan(fanPin);
ChainableLED leds(7, 8, 1);

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
  ledLight();

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

void ledLight()
{
  if (moisture <= 50) {
    leds.setColorRGB(0, 255, 0, 0); //red
  } else if (moisture > 50 && moisture < 60) {
    leds.setColorRGB(0, 255, 255, 0); //yellow
  } else {
    leds.setColorRGB(0, 0, 255, 0); //green
  }
}
