# 제목: Timer Module
  
  - 외부 RTC 모듈(DS3231M)을 이용해서 STM32 보드에 정해진 시간 간격으로 전원을 인가 할 수 있 있는 모듈
  - Timer Module에 있는 4핀 커넥터에 STM32  보드를 연결하면, 연결된 STM32 보드를 주기적으로 켰다 끄는 역할 (배터리 절약)

# 재료

1. External RTC module(DS3231M) x 1
2. NPN 트랜지스터(BC547B or BC847B) x 1
3. Capacitor (16V, 0.1&micro;F) x 2
4. N-channel MOSFET(STP16NF06 or 2N7002NXAKR) x 1
5. Resistor (100K&Omega;) x 2

# Timer Module 이미지

<img width="1105" height="467" alt="image" src="https://github.com/user-attachments/assets/5bd61589-9c40-4e2c-aa69-12847039a317" />


# Schematic

<img width="1360" height="459" alt="image" src="https://github.com/user-attachments/assets/66359573-e0b6-496a-bd78-0baabddd892a" />

<img width="1251" height="814" alt="image" src="https://github.com/user-attachments/assets/149c61b6-3910-4186-904c-e9bf16a09937" />
