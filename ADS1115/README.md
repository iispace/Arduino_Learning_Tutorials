# ADS1115
Almost all microcontrollers come with ADC pins, but they lack high precision. In a lot of projects, analog values need to be measured with high accuracy, or the voltage level of the measured signal is not within the microcontroller measurement range, or even the microcontroller used doesn’t have an ADC pin. In such cases, analog to digital converter modules are used.
ADS1115 module is an analog to digital converter module that has 16-bit precision and can measure a maximum voltage of 7 volts. This module uses I2C communication protocol, so it has a high speed and occupies a small number of the microcontroller pins. 

![image](https://user-images.githubusercontent.com/24539773/205572192-566919d2-e452-40cd-a8a2-e063216aa6f6.png)


# [Datasheet](https://www.ti.com/lit/ds/symlink/ads1115.pdf?ts=1761490011559&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FADS1115)

# Circuit
<img src="https://user-images.githubusercontent.com/24539773/205836159-1374036f-f17c-4c4d-aea5-19165aabbda1.png" width="550" height="280" align="center">

<br>

# For more info 
 
 - [Assembly and Wiring](https://learn.adafruit.com/adafruit-4-channel-adc-breakouts/assembly-and-wiring)

# Library (in PlatformIO)
 ![image](https://user-images.githubusercontent.com/24539773/205836049-3f79cdf1-b2bf-400d-88a0-029b40cdf49d.png)

# Example Project
- Arduino Uno의 ADC 분해능은 10 bit 이므로 아날로그 신호를 읽어 들일 때 $0$부터 $2\^{10} - 1(1023)$까지의 범위로 값을 얻을 수 있는 반면, 16 bit 분해능을 가진 ADS1115를 이용하면 $0$부터 $2\^{16}-1(65535)$까지의 범위로 값을 얻을 수 있으므로 아날로그 신호를 보다 정교하게 구분할 수 있다. 예제 프로젝트에서는 조도센서(Light Sensor TEMP 6000)의 아날로그 신호를 입력 받을 때 ADS1115를 이용하여 Arduino Uno의 Analog Input핀을 바로 이용했을 때 보다 더 정교하게 구분된 센싱 값을 출력해 본다. 

- 결선 방법

|ADS1115|Arduino Uno|Light Sensor TEMP6000)|
|:-:|:-:|:-:|
|VCC|5V|VCC|
|GND|GND|GND|
|SCL|A5(SCL)||
|SDA|A4(SDA)||
|A0||A0|

- [(Example1) Light Sensor(TEMP6000) with ADS1115(Display on Serial monitor)](https://github.com/iispace/Arduino_Learning_Tutorials/blob/main/ADS1115/example1/main.cpp)
- [(Example2) Light Sensor(TEMP6000) with ADS1115(Display on 1.44" TFT_LCD)](https://github.com/iispace/Arduino_Learning_Tutorials/blob/main/ADS1115/example2/main.cpp)

<br>
<br>

# How to calculate ADC?

- ADC는 입력 전압을 기준전압(Vref)에 대한 비율로 계산하여 디지털 값으로 변환
- Arduino UNO의 경우, analogReference() 함수를 통해 외부 Aref, 내부 1.1V 밴드갭, Vcc 중 하나를 기준전압으로 선택할 수 있음
   - anlaogReference(DEFAULT)  : Vcc (Vcc를 기준전압으로 사용할 경우, analogReference() 함수를 별도로 설정하지 않아도 됨).
     
     - Vcc를 사용할 때, USB를 통해 전압을 공급하는 경우 전원이 불안정해 질 수 있음.
     - 아두이노의 배럴 커넥터(barrel connector)로 9V 전원을 공급하면 내장된 regulator에 의해 5V로 전원이 비교적 안정적으로 공급될 수 있음)
       
   - analogReference(INTERNAL) : 내부 1.1V 밴드갭 (단, 이 경우는 측정 범위가 1 ~ 1.1V로 제한되므로 저전압 센서 시 선택)
   - analogReference(EXTERNAL) : Aref (단, Aref 사용 시, [LM4040](https://learnarduinonow.com/2015/05/18/measuring-voltage-with-arduino-and.html)과 같은 정밀하고 안정적인 밴드갭 기반의 전압 소자를 통해 안정적인 기준전압을 공급해 주어야 정확한 ADC 값을 얻을 수 있음)
     
- UNO에서는 내부 1.1V 밴드갭 또는 Aref를 기준전압으로 사용하여 Vref 값을 안정적으로 유지할 수 있음.
- 그러나 0 ~ 5V 범위로 입력되는 공급 전압(Vcc)을 Vref로 사용하면 공급 전압에 따라 Vref도 그만큼 변동됨. 즉, Vref의 값이 외부 전원에 따라 변동하거나 노이즈가 섞일 수 있음.
- Vref가 변동하거나 노이즈가 섞이게 되면 ADC 측정값에 오차가 발생
  - AVR 10-bit(UNO): ADC = round(Vin / Vref) * 1023, (Vref: Aref, 2<sup>10</sup> - 1 = 1023)
  
