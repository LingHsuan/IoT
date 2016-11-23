#ifndef Plant_h
#define Plant_h

#include "Arduino.h"

class plant // soil moisture sensor
{
public:
	plant(uint8_t dhtPin);
	int readMoisture();
	float MoiToPercentage(int moiValue);
  
private:
	uint8_t _moiPin;
};

class dht // temperature and humidity sensor
{
public:
	dht(uint8_t dhtPin);
	void init();
	byte read_data();
	void set();
	float readTemperature();
	float readHumidity();

private:
	uint8_t _dhtPin;
	byte dat[5];
};

class fan // mini fan sensor
{
public:
	fan(uint8_t fanPin);
	void init();
	int fanControl(int fanspeed);
	void fanning(float temperature);

private:
	uint8_t _fanPin;
};

#endif
// END OF FILE

