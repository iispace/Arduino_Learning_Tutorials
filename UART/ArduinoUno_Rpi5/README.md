# Arduino와 Raspberry Pi 5의 UART(Serial) 통신

  - Arduino Uno의 기본 시리얼 핀인 D0(RX), D1(TX)는 프로그램 업로드 및 USB 시리얼 모니터와의 통신에 사용되는 하드웨어 UART 포트임. 따라서 이 포트는 다른 용도로 활용할 경우 업로드 과정이나 디버깅 기능과 충돌을 일으킬 수 있으므로 일반적인 사용자 애플리케이션에서는 사용을 지양하는 것이 바람직함.
  - 다행히 Arduino 보드에서는 SoftwareSerial 라이브러리를 통해 임의의 디지털 핀을 시리얼 통신 포트로 지정할 수 있음.
  - 본 예제에서는 D4(RX), D5(TX) 핀을 시리얼 통신에 활용하며, 기본 SoftwareSerial보다 안정성과 성능이 개선된 NeoSWSerial[[1]](#ref_1) 라이브러리를 사용하여 보다 효율적인 데이터 송수신을 구현함.
  - 또한, 3.3V logic signal을 보내는 라즈베리파이와 달리 아두이노 우노는 5V logic signal을 보내므로, 중간에 반드시 Logic Level Convert를 두어야 회로가 망가지지 않음.
    
<hr>

## 재료

  |항목|사진|
  |:-|:-|
  |아두이노 우노|<img width="231" height="166" alt="image" src="https://github.com/user-attachments/assets/7e57a03e-ebc7-4443-ae48-623859684d13" />|
  |라즈베리파이 5|<img width="252" height="167" alt="image" src="https://github.com/user-attachments/assets/a8550ae8-1b5f-4744-b022-7eaea8309490" />|
  |Bi-Directional Logic Level Converter (BD-LLC)|<img width="271" height="100" alt="image" src="https://github.com/user-attachments/assets/1620cbdf-9784-4856-940b-7ae82360c2c3" />|

<hr>

## 결선도

  <img width="1013" height="437" alt="image" src="https://github.com/user-attachments/assets/89dd71bf-2b02-4715-80f0-f89207b339d1" />

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
  
  ser = serial.Serial('/dev/ttyAMA0', 9600, timeout=1)
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

  https://github.com/user-attachments/assets/8bc2e712-7c10-4829-a4c4-161e7472e4ec


# References:

  <a id="ref_1">[1]</a> [NeoSWSerial](https://github.com/SlashDevin/NeoSWSerial?utm_source=platformio&utm_medium=piohome)
