# 1.44" TFT LCD (ILI9163C Driver IC)<br>
<a href="https://electronics-lab.com/project/using-1-44-color-tft-display-ili9163c-arduino" target="_blank">
  <img src="https://github.com/user-attachments/assets/f85a97e1-f940-49e5-b4b0-68ca56afb17f" width="300" height="300" align="left">
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
<img width="1661" height="593" alt="image" src="https://github.com/user-attachments/assets/b40d0b58-636b-4eeb-88f0-ffb550f58c8c" />

<br>


# TFT LCD Pin Description<br>
| Number | Pin Label | Description |
| :-: | :-: | :-: |
|1|VCC|5V/3.3V power input 
|2|GND|GND
|3|CS| LCD chip select signal, low level enable
|4|RST| LCD reset signal, low level reset
|5|A0| LCD screen register/data selection signal, high level:register, low level:data
|6|SDA|SPI bus write data signal
|7|SCK|SPI bus clock signla
|8|LED| Backlight control, light up at high level, if no control is needed, connect to 3.3V constant light
 

# Wiring<br>
| Arduino UNO | TFT LCD(Software SPI) | TFT LCD(Hardware SPI) |
| :-: | :-: | :-: |
| GND | GND | GND
| 3.3V/5V | VCC | VCC
|D13||CLK
|D11||SDI(DIN)
|A5 or ${Digital \ Pin}^{(1)}$|CS(D/C)|CS(D/C)
|A4 or ${Digital \ Pin}^{(1)}$|RST|RST
|A3|RS|RS
|A2|SDI(DIN)|
|A1|CLK|
|A0 or ${Digital \ Pin}^{(2)}$|LED|LED 

<br>
(1) 만일 아두이노 UNO 보드에 1.44" TFT-LCD display(ST7735S)와 함께 ADS1115와 같이 I2C 통신을 하는 모듈을 함께 연결해야 할 경우에는 TFT-LCD의 RST핀과 CS핀을 각각 A4, A5에 연결하면 안된다. A4, A5는 I2C 통신을 위해 사용되는 SDA, SCL핀이므로, TFT-LCD의 RST핀과 CS핀을 아두이노 우노 보드의 Digital핀 중에서 시리얼 통신의 TX, RX 동작을 위한 D0와 D1을 제외한 핀(예 D10, D8)에 연결하고 프로그램에서 아래와 같이 선언하면 된다.<br><br>

- #define CS 8   // TFT_LCD의 CS핀을 Arduino Uno의 D8에 연결한 경우 
- #define RST 10 // TFT_LCD의 RST핀을 Arduino Uno의 D10에 연결한 경우

단, CS핀을 이와 같이 Uno의 Digital pin에 연결한 경우, setup()함수에서 pinMode를 INPUT으로 설정해 주어야 한다. 

- pinMode(CS, INPUT);

<br>

(2) 아두이노 Uno의 아날로그 입력 핀 사용을 줄이기 위해 TFT-LCD의 백라이트 LED(white LED)를 UNO 보드의 A0 핀 대신에 Digital핀 중에서 시리얼 통신의 TX, RX 동작을 위한 D0와 D1을 제외한 핀(예: D9)에 연결해서 동작시킬 수 있다. Digital 핀에 연결할 경우, 프로그램의 setup() 함수에서 pinMode를 선언해 주지 않았지만 잘 동작한다.<br>


# Example Project

[Light Sensor(TEMP6000) with ADS1115(Display on 1.44" TFT_LCD)](https://github.com/iispace/Arduino_Learning_Tutorials/tree/main/ADS1115/example2)
