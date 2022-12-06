# ADS1115
Almost all microcontrollers come with ADC pins, but they lack high precision. In a lot of projects, analog values need to be measured with high accuracy, or the voltage level of the measured signal is not within the microcontroller measurement range, or even the microcontroller used doesn’t have an ADC pin. In such cases, analog to digital converter modules are used.
ADS1115 module is an analog to digital converter module that has 16-bit precision and can measure a maximum voltage of 7 volts. This module uses I2C communication protocol, so it has a high speed and occupies a small number of the microcontroller pins.

![image](https://user-images.githubusercontent.com/24539773/205572192-566919d2-e452-40cd-a8a2-e063216aa6f6.png)


# Circuit
<img src="https://user-images.githubusercontent.com/24539773/205836159-1374036f-f17c-4c4d-aea5-19165aabbda1.png" width="550" height="280" align="center">
<br>

# For more info 
 
 - [Assembly and Wiring](https://learn.adafruit.com/adafruit-4-channel-adc-breakouts/assembly-and-wiring)

# Library
 ![image](https://user-images.githubusercontent.com/24539773/205836049-3f79cdf1-b2bf-400d-88a0-029b40cdf49d.png)

# Example Project
- Arduino Uno의 ADC 분해능은 10 bit 이므로 아날로그 신호를 읽어 들일 때 0 부터 $2\^{10} - 1(1023)$까지의 범위로 값을 얻을 수 있는 반면, 16 bit 분해능을 가진 ADS1115를 이용하면 0부터 $2\^{16}-1(65535)$까지의 범위로 값을 얻을 수 있으므로 아날로그 신호를 보다 정교하게 구분할 수 있다. 예제 프로젝트에서는 조도센서(Light Sensor TEMP 6000)의 아날로그 신호를 입력 받을 때 ADS1115를 이용하여 Arduino Uno의 Analog Input핀을 바로 이용했을 때 보다 더 정교하게 구분된 센싱 값을 출력해 본다. 

- 결선 방법

|ADS1115|Arduino Uno|Light Sensor TEMP6000)|
|---|---|---|
|VCC|5V|VCC|
|GND|GND|GND|
|SCL|A5(SCL)||
|SDA|A4(SDA)||
|A0||A0|

- [Example Code](https://github.com/iispace/Arduino_Learning_Tutorials/blob/main/ADS1115/source.cpp)
