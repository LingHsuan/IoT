#include "Arduino.h"
#include "Plant.h"

// soil moisture sensor
plant::plant(uint8_t moiPin)
{
	_moiPin = moiPin;
}

int plant::readMoisture()
{
	return analogRead(_moiPin);
}


float plant::MoiToPercentage(int moiValue)
{
	float moiPer = (float)(moiValue - 1032.418367) / (-941.8367) * 100;
	return moiPer;
}


// temperature and humidity sensor
dht::dht(uint8_t dhtPin)
{
	_dhtPin = dhtPin;
}

void dht::init()
{
	pinMode(_dhtPin, OUTPUT);
}

byte dht::read_data()
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

void dht::set()
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

float dht::readHumidity()
{
	return dat[0] + dat[1];
}

float dht::readTemperature()
{
	return dat[2] + dat[3];
}


// mini fan sensor
fan::fan(uint8_t fanPin)
{
	_fanPin = fanPin;
}

void fan::init()
{
	pinMode(_fanPin, OUTPUT);
}

int fan::fanControl(int fanspeed)
{
	analogWrite(_fanPin, fanspeed);
}

void fan::fanning(float temperature)
{
	if (temperature >= 30) {
		fanControl(50);
	}
	else {
		fanControl(0);
	}
}
// END OF FILE

