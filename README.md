# Plant Itself

## Overview
Plant Itself is an Arduino Library for getting datas from each sensors that you may want to know while planting flowers or plants, it is also an automatic system helping you plant good care!.

## Motivation
Most of us have plants in our house and place them by the window sill or on the balcony.<br>
Potted plants and flowers can improve your idea generation, mood, which make your brain work better, you may also feel joy while watering the plants!<br><br>
Do you want to plant flowers, but fear no time or forget to water? Do you want to get more interactive with those lovely flowers and plants? How can these plants survive if you're on a business trip or going abroad?<br>
All you need to do is to prepare some materials, combine with the sample code, then you'll get a "Plant Itself" which may really plant by itself!<br>

## Preparation
- Arduino Board
- Breadboard
- Soil Moisture Sensor
- Temperature and Humidity Sensor
- RGB Color Sensor
- Mini Fan Sensor
- Motor Drive Module
- Water Pump
- Dupont Line
<br>
![](https://github.com/LingHsuan/IoT/blob/master/docs/detail_sheet.jpg)

## Installation
Download the archive and extract it to local directory, and then in the Arduino IDE go to "Sketch --> Import Library...", point the file dialogue to the file you just downloaded.

## Examples
Examples are provided with the library:<br>
- `moistureStatus.ino` tells the status of moisture within red, yellow and green colors.
- `watering.ino` waters the plant when the soil is dry.
- `fanning.ino` turns the fan on to cool the plant.
- `plants.ino` does all things above, tells the status, waters and turns on the fan while needed.

## Function Overview
- `Plant(uint8_t dhtPin);`<br>
Set up the soil and moisture sensor pin.<br><br>
-	`int readMoisture();`<br>
Read the exact value of soil moisture.<br><br>
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
-	`Pump(uint8_t pumpAnodePin, uint8_t pumpCathodePin);`<br>
Set up the water pump pin.<br><br>
-	`void watering(float moisture, int temperature, int wateringTime);`<br>
Start up the sensor while the plant is too dry.<br><br>

## Demo
[Plant Ifself Demo](https://www.youtube.com/watch?v=XilohPDyfyM)<br>
[![](http://img.youtube.com/vi/XilohPDyfyM/0.jpg)](https://www.youtube.com/watch?v=XilohPDyfyM)

## Expansion
Plant Itself is for all large and small potted plants. If there are more sensors, motor and pipeline, which can control not only a potted plant, and even allows a whole garden automation. It is not olny limited to watering, but also for agricultural pesticide spraying, automatic lighting, etc. Users can flexibly adapt to their needs.
