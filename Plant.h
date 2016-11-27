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
	void fanning(float temperature);

private:
	uint8_t _fanPin;
	int fanControl(int fanspeed);
};

#define _CL_RED             0
#define _CL_GREEN           1
#define _CL_BLUE            2
#define _CLK_PULSE_DELAY    20

class LED // RGB LED sensor
{
public:
	LED(byte clk_pin, byte data_pin, byte number_of_leds);
	void init();
	void setColorRGB(byte led, byte red, byte green, byte blue);
	void lighting(float moisture);

private:
	byte _clk_pin;
	byte _data_pin;
	byte _num_leds;
	byte* _led_state;

	void clk(void);
	void sendByte(byte b);
	void sendColor(byte red, byte green, byte blue);
};

#endif
// END OF FILE

