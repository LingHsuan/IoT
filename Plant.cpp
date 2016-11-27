#include "Arduino.h"
#include "Plant.h"

// soil moisture sensor
Plant::Plant(uint8_t moiPin)
{
	_moiPin = moiPin;
}

int Plant::readMoisture()
{
	int moistureSum = 0;
	for (int i = 0; i < 30; i++)
	{
		moistureSum = moistureSum + analogRead(_moiPin);
		delay(100);
	}
	return (moistureSum / 30);
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

// RGB LED sensor
LED::LED(byte clk_pin, byte data_pin, byte number_of_leds) :
_clk_pin(clk_pin), _data_pin(data_pin), _num_leds(number_of_leds)
{
	_led_state = (byte*)calloc(_num_leds * 3, sizeof(byte));
}

void LED::init()
{
	pinMode(_clk_pin, OUTPUT);
	pinMode(_data_pin, OUTPUT);

	for (byte i = 0; i<_num_leds; i++)
		setColorRGB(i, 0, 0, 0);
}

void LED::clk(void)
{
	digitalWrite(_clk_pin, LOW);
	delayMicroseconds(_CLK_PULSE_DELAY);
	digitalWrite(_clk_pin, HIGH);
	delayMicroseconds(_CLK_PULSE_DELAY);
}

void LED::sendByte(byte b)
{
	// Send one bit at a time, starting with the MSB
	for (byte i = 0; i<8; i++)
	{
		// If MSB is 1, write one and clock it, else write 0 and clock
		if ((b & 0x80) != 0)
			digitalWrite(_data_pin, HIGH);
		else
			digitalWrite(_data_pin, LOW);
		clk();

		// Advance to the next bit to send
		b <<= 1;
	}
}

void LED::sendColor(byte red, byte green, byte blue)
{
	// Start by sending a byte with the format "1 1 /B7 /B6 /G7 /G6 /R7 /R6"
	byte prefix = 0b11000000;
	if ((blue & 0x80) == 0)     prefix |= 0b00100000;
	if ((blue & 0x40) == 0)     prefix |= 0b00010000;
	if ((green & 0x80) == 0)    prefix |= 0b00001000;
	if ((green & 0x40) == 0)    prefix |= 0b00000100;
	if ((red & 0x80) == 0)      prefix |= 0b00000010;
	if ((red & 0x40) == 0)      prefix |= 0b00000001;
	sendByte(prefix);

	// Now must send the 3 colors
	sendByte(blue);
	sendByte(green);
	sendByte(red);
}

void LED::setColorRGB(byte led, byte red, byte green, byte blue)
{
	// Send data frame prefix (32x "0")
	sendByte(0x00);
	sendByte(0x00);
	sendByte(0x00);
	sendByte(0x00);

	// Send color data for each one of the leds
	for (byte i = 0; i<_num_leds; i++)
	{
		if (i == led)
		{
			_led_state[i * 3 + _CL_RED] = red;
			_led_state[i * 3 + _CL_GREEN] = green;
			_led_state[i * 3 + _CL_BLUE] = blue;
		}

		sendColor(_led_state[i * 3 + _CL_RED],
			_led_state[i * 3 + _CL_GREEN],
			_led_state[i * 3 + _CL_BLUE]);
	}

	// Terminate data frame (32x "0")
	sendByte(0x00);
	sendByte(0x00);
	sendByte(0x00);
	sendByte(0x00);
}

void LED::lighting(float moisture)
{
	if (moisture <= 50) {
		setColorRGB(0, 255, 0, 0); //red
	}
	else if (moisture > 50 && moisture < 60) {
		setColorRGB(0, 255, 255, 0); //yellow
	}
	else {
		setColorRGB(0, 0, 255, 0); //green
	}
}
// END OF FILE

