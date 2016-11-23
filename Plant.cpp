#include "Arduino.h"
#include "Plant.h"

// soil moisture sensor
Plant::Plant(uint8_t moiPin)
{
	_moiPin = moiPin;
}

int Plant::readMoisture()
{
	return analogRead(_moiPin);
}


float Plant::MoiToPercentage(int moiValue)
{
	float moiPer = (float)(moiValue - 1032.418367) / (-941.8367) * 100;
	return moiPer;
}


// temperature and humidity sensor
DHT::DHT(uint8_t dhtPin)
{
	_dhtPin = dhtPin;
}

void DHT::init()
{
	pinMode(_dhtPin, OUTPUT);
}

byte DHT::read_data()
{
	byte data;
	for (int i = 0; i < 8; i++)
	{
		if (digitalRead(_dhtPin) == LOW)
		{

			while (digitalRead(_dhtPin) == LOW);
			delayMicroseconds(30);

			if (digitalRead(_dhtPin) == HIGH)
				data |= (1 << (7 - i));

			while (digitalRead(_dhtPin) == HIGH);
		}
	}
	return data;
}

void DHT::set()
{
	digitalWrite(_dhtPin, LOW);
	delay(30);
	digitalWrite(_dhtPin, HIGH);
	delayMicroseconds(40);
	pinMode(_dhtPin, INPUT);
	while (digitalRead(_dhtPin) == HIGH);
	delayMicroseconds(80);
	if (digitalRead(_dhtPin) == LOW);
	delayMicroseconds(80);

	for (int i = 0; i < 4; i++) 
		dat[i] = read_data();

	pinMode(_dhtPin, OUTPUT);
	digitalWrite(_dhtPin, HIGH);
}

float DHT::readHumidity()
{
	return dat[0] + dat[1];
}

float DHT::readTemperature()
{
	return dat[2] + dat[3];
}


// mini fan sensor
Fan::Fan(uint8_t fanPin)
{
	_fanPin = fanPin;
}

void Fan::init()
{
	pinMode(_fanPin, OUTPUT);
}

int Fan::fanControl(int fanspeed)
{
	analogWrite(_fanPin, fanspeed);
}

void Fan::fanning(float temperature)
{
	if (temperature >= 30) {
		fanControl(50);
	}
	else {
		fanControl(0);
	}
}
// END OF FILE

