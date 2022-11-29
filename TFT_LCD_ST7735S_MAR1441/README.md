# 1.44" TFT LCD (SR7735S Driver IC / SKU:MAR1441)<br>
<a href="http://www.lcdwiki.com/1.44inch_Arduino_SPI_Module_ST7735S_SKU:MAR1441" target="_blank">
  <img src="https://user-images.githubusercontent.com/24539773/204490332-9cf94e98-bf61-46d1-9cb9-082cf2dba9d3.png" width="300" height="300" align="left">
</a>
<a href="http://www.lcdwiki.com/1.44inch_Arduino_SPI_Module_ST7735S_SKU:MAR1441" target="_blank">
  <img src="https://user-images.githubusercontent.com/24539773/204490643-7c29de37-8f31-4f9e-a9c5-e84aa88c70be.png" width="200" height="150" align="left">
</a>
<br><br><br><br><br><br><br><br><br><br><br><br><br>
<hr>

# IDE<br>
<a href="https://platformio.org/" target="_blank">
  <img src="https://user-images.githubusercontent.com/24539773/204492337-c76cb87f-93e6-4132-af63-6062e60ef4e8.png" width="280" height="200" align="left">
</a>
<br><br><br><br><br><br><br><br>
<hr>

# Library<br>
![image](https://user-images.githubusercontent.com/24539773/204491960-996f7807-f053-4ae6-8fc6-7845f323df58.png)
<br>


# TFT LCD Pin Description<br>
| Number | Pin Label | Description |
| :-: | :-: | :-: |
|1|VCC|3.3V ~ 5V
|2|GND|GND
|3|GND|GND
|4|NC|Not defined, reserved
|5|NC|Not defined, reserved
|6|LED|Backlight control, High level lighting, if not controlled, connect 3.3V always bright
|7|CLK|SPI bus clork signal
|8|SDI|SPI bus write data signal
|9|RS| LCD register/data selection signal, high level: register, low level: data
|10|RST|LCD reset signal, low level reset
|11|CS| LCD chip select signal, low level enable

# Wiring<br>
| Arduino UNO | TFT LCD(Software SPI) | TFT LCD(Hardware SPI) |
| :-: | :-: | :-: |
| GND | GND | GND
| 3.3V | VCC | VCC
|D13||CLK
|D11||SDI
|A5|CS|CS
|A4|RST|RST
|A3|RS|RS
|A2|SDI|
|A1|CLK|
|A0|LED|LED
