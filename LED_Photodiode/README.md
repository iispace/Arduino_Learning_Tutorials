
# LED를 Photodiode로 사용해 보기

- LED를 역방향으로 연결하여 빛에 의해 생성된 역방향 전류가 저항에 전압을 만들게 하고, 그 전압을 ADC로 읽어 오도록 설정
- LED 역방향 연결 방법: LED의 Cathode(음극)에 +5V를 연결하고, anode(양극)에는 1M Ohm 저항을 통해 GND로 연결
- 이 방법은 저항에 따른 노이즈와 대역폭의 한계 및 정밀도가 모두 부족한 단점이 있으나 LED를 거꾸로 이용해서 포토다이오드로 동작시켜보는 실험을 해 보기 위해 매우 엉성하게 구성한 것임.
- LED가 만들어내는 광전류는 매우 낮은 수준이므로, 이 신호를 증폭해 주는 TIA 소자(예 LTC1050와 같은 입력 바이어스 전류가 매우 작은 타입의 연산 증폭기)와 커패시터 등을 회로에 추가하면 더 정밀한 측정값을 얻을 수 있음.

# 재료

- Arduino Uno x 1
- LED (any color) x 2 (포토다이오드로 사용할 것 1개, 조명용으로 사용할 것 1개)
- 3 Pin 미니 슬라이스 스위치 x 1
- 저항: 1MOhm x 1, 220Ohm X 1
  

# 결선도 

<img width="1296" height="474" alt="image" src="https://github.com/user-attachments/assets/e70317c3-7115-4ea5-9021-925900cc60e8" />


# 구현 사진

<img width="1242" height="445" alt="image" src="https://github.com/user-attachments/assets/24593fe7-99e5-4c0b-9f55-e0f2f9eff7ce" />


# 코드
```
#include <Arduino.h>

void setup(){

 pinMode(13, OUTPUT);
 Serial.begin(9600);
 delay(50);
 Serial.println("LED Photodiode Test Start");
 delay(50);
 digitalWrite(13, HIGH);
}

void loop(){

int reading = analogRead(A0);
int volt = reading * (5.0 / 1023.0);
Serial.print("reading: ");
Serial.print(reading);
Serial.print(" Voltage: ");
Serial.println(volt);
delay(1000);
}
```
