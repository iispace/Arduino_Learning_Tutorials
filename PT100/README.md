# PT100 with Arduino Uno + Liquid Crystal Display(LCD)
![image](https://user-images.githubusercontent.com/24539773/162856833-ae9f8c99-9017-44dc-bdee-9b0525193b2a.png)




## 재료:
- PT100 (3 wires, Resistance Temperature Detectors Type)
  - PT100 센서의 저항 값은 매우 작고 낮은 수준이기 때문에, 이 값을 정확히 읽기 위해서는 매우 민감한 증폭기가 필요함. 즉, PT100은 저항을 낮은 값으로 출력하기 때문에, 이를 정확하게 읽기 위해 고정밀도의 전자 회로가 필요.
  - MAX31865는 이러한 고정밀도 전자 회로의 역할을 할 부품.
- [MAX31865 Breakout board](https://learn.adafruit.com/adafruit-max31865-rtd-pt100-amplifier)
- Arduino Uno
- 4P Terminal


## 1. MAX31865 Breakout board 준비
- PT100이 3선인 경우 MAX31865 Breakout board의 pad를 아래 그림과 같이 손질해 주어야 한다.
  <br>(참고: https://learn.adafruit.com/adafruit-max31865-rtd-pt100-amplifier/rtd-wiring-config)

  <center><img src="https://user-images.githubusercontent.com/24539773/162855044-91cc2508-3ed3-4405-8e56-97d5b5a8c1d4.png" width="500" height="280"/></center>
  <center><img src="https://user-images.githubusercontent.com/24539773/162856293-7fc2d82e-c198-4858-86f5-3ef05cc41450.png" width="400" height="200"/></center>
 
- MAX31865 Breakout board pad 손질 완성 후 PT100 연결한 모습
  <center><img src="https://user-images.githubusercontent.com/24539773/162855440-d11c4ae8-6019-4878-8c22-a4cacb83f208.png" width="600" height="450"/></center>


## 2. MAX31865 과 Arduino Uno 연결

![image](https://user-images.githubusercontent.com/24539773/162887344-df82fe97-4a6a-43bb-b99e-e6af0da2bcb9.png)   




## 3. 예제
[소스코드](https://github.com/iispace/Arduino_Learning_Tutorials/blob/main/PT100/PT100%20with%20Arduino)
