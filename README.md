# Plant Itself

## Overview
Plant is an Arduino Library for getting datas from each sensors that you may want to know while planting flowers or plants.

## Motivation
Most of us have plants in our house and place them by the window sill or on the balcony.<br>
Potted plants and flowers can improve your idea generation, mood, which make your brain work better.<br>
You may also feel joy while watering the plants!<br>
Want to get more interactive with those lovely flowers and plants?<br>
All you need to do is to prepare some materials, combine with the sample code.<br>
Then you'll get a "Plant Itself" to understand the plant's status, take a good care of it!<br>

## Preparation
- Plant
- Arduino Board
- Breadboard
- Soil Moisture Sensor
- Temperature and Humidity Sensor
- RGB Color Sensor
- Mini Fan Sensor
- Dupont Line

## Installation
Download the archive and extract it to local directory, and then in the Arduino IDE go to "Sketch --> Import Library...", point the file dialogue to the file you just downloaded.

## Example


## Function Overview
- `Plant(uint8_t dhtPin);`<br>
Set up the soil and moisture sensor pin.<br><br>
-	`int readMoisture();`<br>
Read the value of the soil moisture.<br><br>
-	`float MoiToPercentage(int moiValue);`<br>
Turn the value of soil moisture into percentage for human to read.<br><br>
- `DHT(uint8_t dhtPin);`<br>
Set up the temperature and humidity sensor pin.<br><br>
-	`byte read_data();`<br>
Read the value of both temperature and humidity.<br><br>
-	`void set();`<br>
Set two values into an array.<br><br>
-	`float readTemperature();`<br>
Returns the value of temperature.<br><br>
-	`float readHumidity();`<br>
Returns the value of humidity.<br><br>
- `Fan(uint8_t fanPin);`<br>
Set up the mini fan sensor pin.<br><br>
-	`void fanning(float temperature);`<br>
Start up the sensor while the temperature is too high.<br><br>
- `LED(byte clk_pin, byte data_pin, byte number_of_leds);`<br>
Declare the RGB LED sensor pin and the amount of leds.<br><br>
- `void init();`<br>
Set up the RGB LED sensor pin.<br><br>
-	`void setColorRGB(byte led, byte red, byte green, byte blue);`<br>
Set the color to show into the RGB LED sensor.<br><br>
-	`void lighting(float moisture);`<br>
Shows the status of your plant with different colors.<br><br>
