
# LED를 Photodiode로 사용해 보기 

- 이 실험은 "Continuous observation of vegetation canopy dynamics using an integrated low-cost, near-surface remote sensing system"라는 논문에서 LED를 이용해 빛의 세기를 측정하는 LED sensor를 만든 것을 보고 그 개념을 이해하기 위해 시도한 것임.
- LED를 역방향으로 연결하여 빛에 의해 생성된 역방향 전류가 저항에 전압을 만들게 하고, 그 전압을 ADC로 읽어 오도록 설정
- LED 역방향 연결 방법: LED의 Cathode(음극)에 +5V를 연결하고, anode(양극)에는 1M&Omega; 저항을 통해 GND로 연결
  - 역방향으로 전압을 걸 때, 역방향 전압이 너무 높아지면, PN 접합이 파괴되며 큰 전류가 흐르면서 LED가 손상되므로, LED가 손상되지 않도록 저항을 연결해서 역방향 전압을 낮추어야 함. 
- 이 실험은 저항에 따른 노이즈와 대역폭의 한계 외에 정밀도 또한 낮은 방법임에도 불구하고 LED를 거꾸로 이용해서 포토다이오드로 동작시키는 방법을 구현해 보기 위해 <b>매우 엉성하게 구성한 것임(주변에 굴러다니던 LED를 아무거나 사용하는 바람에 데이터시트를 통해 전기적 특성을 확인하지 못하고 그냥 사용하였으므로 물리적으로 불안정한 회로일 수 있음. 그러므로, 이 내용을 참고 삼아 따라 하지는 마시길!!!)</b>
- LED가 만들어내는 광전류는 매우 낮은 수준이므로, 이 신호를 증폭해 주는 TIA 소자(예 LTC1050와 같은 입력 바이어스 전류가 매우 작은 타입의 연산 증폭기)와 커패시터 등을 회로에 추가하면 더 정밀한 측정값을 얻을 수 있다고...

# 재료

- Arduino Uno x 1
- LED (any color) x 2 (포토다이오드로 사용할 것 1개, 조명용으로 사용할 것 1개)
- 3 Pin 미니 슬라이스 스위치 x 1
- 포토다이오드 LED 보호 저항 : 1M&Omega; x 1 (포토다이오드로 사용할 LED에 역방향 전압을 걸 때, LED 소자가 파괴되지 않도록 보호하기 위한 저항)
- 조명 LED 풀업 저항 : 220&Omega; X 1 (부유 현상 억제용 저항)

  - 역방향 내전압(Reverse Voltage) 5V에서 안전하게 견딜 수 있는 최대 역방향 누설 전류(Reverse Current)가 5&micro;A 인 LED에 공급 전압 5V를 역방향으로 걸 때, LED에 흐르는 전류가 5&micro;A 이하가 되도록 직렬 저항(R)을 연결해야 함.
    - 직렬 저항(R)의 크기는 다음과 같이 계산하였음.

      <img width="985" height="656" alt="image" src="https://github.com/user-attachments/assets/565a05da-5e59-4587-91f3-2cff0963a91b" />

    - 만일 사용할 LED의 [datasheet](https://www.arduino.cc/documents/datasheets/LEDRGB-L-154A4SURK.pdf)가 다음과 같다면, 아래 데이터시트 그림에 있는 Hyper Red LED를 역방향으로 안전하게 연결하기 위해 필요한 직렬 저항(R)의 크기는 500K&Omega;가 될 것임.

      <img width="637" height="369" alt="image" src="https://github.com/user-attachments/assets/4669d7cb-373b-4f9b-be71-303f09ec4b7d" />
      <img width="562" height="157" alt="image" src="https://github.com/user-attachments/assets/feb88883-c322-4aac-9268-578e8aeb9b3e" />

      
# LED를 역방향으로 연결하는 결선도 예시 

<img width="1296" height="474" alt="image" src="https://github.com/user-attachments/assets/e70317c3-7115-4ea5-9021-925900cc60e8" />


# 실험체 결선도 

<img width="1316" height="502" alt="image" src="https://github.com/user-attachments/assets/c0f71bee-cdb7-43cd-a7aa-9c7020e9d5ed" />


# 구현 사진

<img width="1309" height="461" alt="image" src="https://github.com/user-attachments/assets/1d5f09a3-fdf7-4547-9b3f-d0e92d2d494f" />



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

# 측정 결과

포토다이오드로 동작시킨 LED에 스마트폰의 플래쉬 라이트를 비추거나 비추지 않는 방법으로 광원의 세기를 조절하며 측정한 결과는 아래와 같음.

<img width="477" height="288" alt="image" src="https://github.com/user-attachments/assets/3b1f6ec4-2780-4ac0-8df9-0a9543b17405" />

위 그래프의 가로축은 측정 시간(초), 세로축은 analogRead(A0)값.
