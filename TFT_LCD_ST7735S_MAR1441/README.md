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
| 3.3V /5 | VCC | VCC
|D13||CLK
|D11||SDI
|A5|CS|CS
|A4 or ${RESET pin}^{(1)}$|RST|RST
|A3|RS|RS
|A2|SDI|
|A1|CLK|
|A0 or ${Any Digital Pin}^{(2)}$|LED|LED 

<br>
(1):만일 아두이노 UNO 보드에 TFT-LCD display와 함께 ADS1115와 같이 I2C 통신을 하는 모듈을 함께 연결해야 할 경우에는 TFT-LCD의 RST 핀을 A4에 연결하면 안된다. A4는 I2C 통신을 위해 사용되는 SDA핀이므로, TFT-LCD의 RST 핀을 아두이노 우노 보드의 RESET 핀에 연결하고, 프로그램에서 "#define RST A4"를 "#define RST 0"로 수정하면 동작한다.<br>
(2): TFT-LCD의 백라이트 LED(white LED)를 제어할 필요가 없다면 아두이노 Uno의 아날로그 입력 핀의 사용을 줄이기 위해 A0 핀 대신에 Digital핀 (예: D2)에 연결해서 동작시킬 수 있다. 단, Digital 핀에 연결할 경우에는 프로그램의 setup() 함수에서 pinMode를 선언해 주고, digitalWrite(핀번호, HIGH)로 설정해서 항상 LED가 켜져 있도록 한다.<br>
