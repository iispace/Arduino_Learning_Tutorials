# 제목: Timer Module
  
  - 외부 RTC 모듈(DS3231M)을 이용해서 STM32 보드에 정해진 시간 간격으로 전원을 인가 할 수 있 있는 모듈
  - Timer Module에 있는 4핀 커넥터에 STM32  보드를 연결하면, 연결된 STM32 보드를 주기적으로 켰다 끄는 역할 (배터리 절약)

# 재료

1. External RTC module(DS3231M) x 1
2. NPN 트랜지스터(BC547B or BC847B) x 1
3. Capacitor (16V, 100&micro;F) x 3
4. N-channel MOSFET(STP16NF06 or 2N7002NXAKR) x 1
5. Resistor (100K&Omega;) x 3
6. On/Off Button Switch(Self-locking Type) x 1
7. Schottky Diode (SMA(DO-214AC)) x 1   ===> 일반 다이오드에 비해 배터리 효율과 고속 반응에는 유리하지만, 역누설 전류가 상대적으로 크고, 고온 안정성이 떨어질 수 있음.
8. AMS1117-5.0V x 1 (12V to 5V linear regulator)
9. XHB-2A Connector x 1  (배터리 연결 커넥터)
10. XHB-4A(White)/4needle x 1  (STM32 보드 연결 커넥터)
11. Header-Female-2.54_1x6  (외부 RTC 모듈 연결 커넥터)
12. DC-005(2.0mm) x 1  (DC 전원 소켓 커넥터)
13. Green LED x 1

### BOM

  <img width="751" height="290" alt="image" src="https://github.com/user-attachments/assets/5786d9d6-8a9c-4130-980a-a17fff71de9b" />



# Schematic 

    
<img width="600" height="400" alt="image" src="https://github.com/user-attachments/assets/b3037240-b7b7-4b6c-bc33-d23ae1096b08" />

# Gerber image

<img width="1494" height="333" alt="image" src="https://github.com/user-attachments/assets/5a780567-2531-4b98-9490-b5a0be0a1b76" />


<br>

# Timer Module 이미지

<img width="459" height="300" alt="image" src="https://github.com/user-attachments/assets/c9797537-5fd4-4fa3-b98b-9feb90071900" />



