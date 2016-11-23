#ifndef Plant_h
#define Plant_h

#include "Arduino.h"

class Plant // soil moisture sensor
{
public:
	Plant(uint8_t dhtPin);
	int readMoisture();
	float MoiToPercentage(int moiValue);
  
private:
	uint8_t _moiPin;
};

class DHT // temperature and humidity sensor
{
public:
	DHT(uint8_t dhtPin);
	void init();
	byte read_data();
	void set();
	float readTemperature();
	float readHumidity();

private:
	uint8_t _dhtPin;
	byte dat[5];
};

class Fan // mini fan sensor
{
public:
	Fan(uint8_t fanPin);
	void init();
	int fanControl(int fanspeed);
	void fanning(float temperature);

private:
	uint8_t _fanPin;
};

#endif
// END OF FILE

