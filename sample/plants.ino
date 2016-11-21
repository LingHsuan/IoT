#include <Plant.h>
#include <math.h>
#include <Servo.h>
#include <DHT.h>

#define soilPin A2 // soil moisture sensor
#define dhtPin A3 // temperature and humidity sensor
#define dhtType DHT11

int soilVal = 0;
float soil, humidity, temperature;

Plant plant;
Servo myservo;  // create servo object to control a servo
DHT dht(dhtPin, dhtType);

void setup() {
  myservo.attach(9);
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  soilVal = plant.readMoisture(soilPin);
  soil = plant.MoiToPercentage(soilVal);

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.println("*C");
  Serial.print("Humidity: ");
  Serial.print(humidity, 0);
  Serial.println("%");
  Serial.print("Moisture: ");
  Serial.print(soil, 0);
  Serial.print("%\t");
  Serial.println(soilVal);
  Serial.println();

  watering(temperature, humidity, soil);

  delay(5000);
}

int watering(float temperature, float humidity, float moisture) {
  if (moisture < 55) {
    moving();
  }
}

void moving() {
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
