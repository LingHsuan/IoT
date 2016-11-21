#include "Arduino.h"
#include "Plant.h"

Plant::Plant(void)
{
  
}

int Plant::readMoisture(int pin)
{
	return analogRead(pin);
}

float Plant::MoiToPercentage(int value)
{
	float convert = (float)(value - 1032.418367) / (-941.8367) * 100;
	return convert;
}
