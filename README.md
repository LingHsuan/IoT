# Plant Itself

## Overview
許多人會在辦公桌上放個小盆栽，或在家中窗戶和陽台種各式的植物。<br>看著盆栽長大十分療癒，替它澆水更是其中一種樂趣！<br>還想要多些互動嗎？<br>現在只要準備一些設備，結合已完成的Library使用，<br>自己DIY做出的 Plant Itself 幫您掌握植物的狀態，得到多一份呵護！

## Preparation
- Plant
- Arduino Board
- Breadboard
- Soil Moisture Sensor
- Temperature and Humidity Sensor
- RGB Color Sensor
- Mini Fan Sensor
- Dupont line

## Examples
## Function Overview
- `Plant(uint8_t dhtPin);`<br>
Set up the soil and moisture sensor pin.
-	`int readMoisture();`<br>
Read the value of the soil moisture.
-	`float MoiToPercentage(int moiValue);`<br>
Turn the value of soil moisture into percentage for human to read.
- `DHT(uint8_t dhtPin);`<br>
Set up the temperature and humidity sensor pin.
-	`byte read_data();`<br>
Read the value of both temperature and humidity.
-	`void set();`<br>
Set two values into an array.
-	`float readTemperature();`<br>
Returns the value of temperature.
-	`float readHumidity();`<br>
Returns the value of humidity.
- `Fan(uint8_t fanPin);`<br>
Set up the mini fan sensor pin.
-	`void fanning(float temperature);`<br>
Start up the sensor while the temperature is too high.
- `LED(byte clk_pin, byte data_pin, byte number_of_leds);`<br>
Declare the RGB LED sensor pin and the amount of leds.
- `void init();`<br>
Set up the RGB LED sensor pin.
-	`void setColorRGB(byte led, byte red, byte green, byte blue);`<br>
Set the color to show into the RGB LED sensor.
-	`void lighting(float moisture);`<br>
Shows the status of your plant with different colors.

## Minutiae
