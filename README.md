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
- `Plant(uint8_t dhtPin);`
-	`int readMoisture();`
-	`float MoiToPercentage(int moiValue);`
- `DHT(uint8_t dhtPin);`
-	`void init();`
-	`byte read_data();`
-	`void set();`
-	`float readTemperature();`
-	`float readHumidity();`
- `Fan(uint8_t fanPin);`
-	`void fanning(float temperature);`
- `LED(byte clk_pin, byte data_pin, byte number_of_leds);`
-	`void setColorRGB(byte led, byte red, byte green, byte blue);`
-	`void lighting(float moisture);`

## Minutiae
## License
