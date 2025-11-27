# Arduino와 Raspberry Pi 5의 UART(Serial) 통신

  - Arduino Uno의 기본 시리얼 핀인 D0(RX), D1(TX)는 프로그램 업로드 및 USB 시리얼 모니터와의 통신에 사용되는 하드웨어 UART 포트임. 따라서 이 포트는 다른 용도로 활용할 경우 업로드 과정이나 디버깅 기능과 충돌을 일으킬 수 있으므로 일반적인 사용자 애플리케이션에서는 사용을 지양하는 것이 바람직함.
  - 다행히 Arduino 보드에서는 SoftwareSerial 라이브러리를 통해 임의의 디지털 핀을 시리얼 통신 포트로 지정할 수 있음.
  - 본 예제에서는 D4(RX), D5(TX) 핀을 시리얼 통신에 활용하며, 기본 SoftwareSerial보다 안정성과 성능이 개선된 NeoSWSerial[[1]](#ref_1) 라이브러리를 사용하여 보다 효율적인 데이터 송수신을 구현함.
  - Raspberry Pi 5 (이하 Rpi 5)에서도 여러개의 UART를 지원하고 있으므로, 필요에 따라 UART1, UART2 등을 추가로 활성화해서 사용 가능. Rpi 5는 UART0~UART4까지 5개의 UART를 지원[[2]](#ref_2).
  - 또한, 라즈베리파이는 3.3V logic level인데 아두이노 우노는 5V logic level이므로, 중간에 반드시 Logic Level Convert를 두어야 회로가 망가지지 않음. 여기서는 [Sparkfun Bi-Directional Logic Level Convert(BD-LLC)](https://www.sparkfun.com/sparkfun-logic-level-converter-bi-directional.html#content-documentation)를 사용함.
    
    
<hr>

## 재료

  |항목|사진|
  |:-|:-|
  |아두이노 우노|<img width="231" height="166" alt="image" src="https://github.com/user-attachments/assets/7e57a03e-ebc7-4443-ae48-623859684d13" />|
  |라즈베리파이 5|<img width="252" height="167" alt="image" src="https://github.com/user-attachments/assets/a8550ae8-1b5f-4744-b022-7eaea8309490" />|
  |Bi-Directional Logic Level Converter (BD-LLC)|<img width="271" height="100" alt="image" src="https://github.com/user-attachments/assets/1620cbdf-9784-4856-940b-7ae82360c2c3" />|

<hr>

## Rpi 5에 추가 UART 활성화

  1. Terminal을 열고 편집기로 "/boot/firmware/config.txt" 열기.
     - ``` pi@raspberrypi:~$ sudo nano /boot/firmware/config.txt ```
       
  2. 키보드 화살표를 이용하여 제일 아래쪽으로 내려가면 [all]이라는 구역이 나오는데, 여기에 다음과 같이 dtoverlay=uart1 또는 dtoverlay=uart2와 같은 형식으로 사용하고자 할 UART 추가

     <img width="366" height="300" alt="image" src="https://github.com/user-attachments/assets/829dd632-3dbc-40a5-8a4b-c6c5b930482f" />
     
  3. Ctrl+X를 입력한 후 수정사항을 저장할 수 있도록 y를 입력하고 [엔터]키를 치면 nano 편집기 종료
     
  4. 터미널에서 ```sudo reboot``` 명령을 실행하여 Rpi 5를 리부팅. (리부팅해야 UART 활성화 적용됨)
  5. Rpi 5가 리부팅 되었다면, 다시 터미널을 열고, ``` ls /dev/ttyAMA* ``` 명령어로 config.txt에 추가한 UART 장치가 보이는지 확인
     
     <img width="474" height="100" alt="image" src="https://github.com/user-attachments/assets/a414046e-7a2d-4215-8ed6-d9ac130eb717" />

  6. 마지막으로, 활성화된 UART와 연결된 GPIO 핀 번호를 확인하기 위해 다음과 같이 터미널에서 ``` pinctrl 0-15 ``` 명령 실행 (핀 GPIO0부터 GPIO15까지만 출력하는 명령. 더 많은 핀 번호를 보고 싶다면, 0-보고싶은 범위 끝 번호)

     <img width="324" height="300" alt="image" src="https://github.com/user-attachments/assets/92c160ee-dd2d-493c-a18c-ff90059b5dbd" />

  7. 위와 같이 /dev/에 장치가 잘 보이고, pinctrl에서도 추가된 UART의 핀 번호가 TXD, RXD와 매핑되었다면 추가 UART가 제대로 활성화된 것.

## Rpi 5와 Arduino Uno 연결하기

  <img width="774" height="330" alt="image" src="https://github.com/user-attachments/assets/15070ed1-244b-4ea1-89d6-a3be1c445c71" />

  <img width="780" height="324" alt="image" src="https://github.com/user-attachments/assets/c5d0cd81-4da0-4285-bbdc-9a925315c920" />

  <img width="765" height="332" alt="image" src="https://github.com/user-attachments/assets/e13dd3e6-3e45-4a6c-80f8-5780442b1c72" />


<hr>

## 코드

### 아두이노 업로드 코드
  ```
  // UART Communication Example for Arduino Uno <--> Raspberry Pi 5 

  #include <Arduino.h>
  #include <NeoSWSerial.h>  // NeoSWSerial: An efficient replacement for SoftwareSerial at baud rates 9600, 19200 and 38400. Simultaneous RX & TX, does not require additional TIMERs, interrupts not disabled during RX
   
  NeoSWSerial mySerial(4, 5); // RX, TX

  void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    mySerial.begin(9600);
    delay(20);
  }
  
  void loop() {
    // put your main code here, to run repeatedly:
    if (mySerial.available()){
      String msg = mySerial.readStringUntil('\n');
      Serial.println(msg);
    }
    mySerial.println("Hello from Uno!");
    delay(2000);
  }

  ```

### 라즈베리파이 5 코드

  ```
  import serial
  import time
  
  #ser = serial.Serial('/dev/ttyAMA0', 9600, timeout=1)  # UART0 사용시
  #ser = serial.Serial('/dev/ttyAMA1', 9600, timeout=1)  # UART1 사용시
  ser = serial.Serial('/dev/ttyAMA2', 9600, timeout=1)   # UART2 사용시
  time.sleep(2)  # 연결 안정화 대기
  
  while True:
      ser.write("Hello from Raspberry Pi 5\n".encode('utf-8'))
      #ser.write(b"Hellow from Rpi!\n")
      #print("Message sent\n")
      while ser.in_waiting > 0:
          print(ser.readline().strip().decode("utf-8"))
      time.sleep(2)  # 2초 지연
  ```

<hr>

### 테스트 동영상

  https://github.com/user-attachments/assets/7ab87a96-522a-4052-a999-e4ea87a1e7b1

  https://github.com/user-attachments/assets/89635fa8-51ed-4122-9e38-4a9df611a758



# References:

  [Raspberry Pi 5 / Ubuntu 24.04 Can't get GPIO14/15;TX.RX;pins8/10 to work](https://groups.google.com/g/hbrobotics/c/JY6jtt0Vn18/m/AfYaEfIZAwAJ)

  <a id="ref_1">[1]</a> [NeoSWSerial](https://github.com/SlashDevin/NeoSWSerial?utm_source=platformio&utm_medium=piohome)
  
  <a id="ref_2">[2]</a> [Rpi Documentation](https://www.raspberrypi.com/documentation/computers/configuration.html#raspberry-pi-zero-1-2-and-3)
  
