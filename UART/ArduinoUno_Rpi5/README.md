# Arduino와 Raspberry Pi 5의 UART(Serial) 통신

  - Arduino Uno의 기본 시리얼 핀인 D0(RX), D1(TX)는 프로그램 업로드 및 USB 시리얼 모니터와의 통신에 사용되는 하드웨어 UART 포트임. 따라서 이 포트는 다른 용도로 활용할 경우 업로드 과정이나 디버깅 기능과 충돌을 일으킬 수 있으므로 일반적인 사용자 애플리케이션에서는 사용을 지양하는 것이 바람직함.
  - 다행히 Arduino 보드에서는 SoftwareSerial 라이브러리를 통해 임의의 디지털 핀을 시리얼 통신 포트로 지정할 수 있음.
  - 본 예제에서는 D4(RX), D5(TX) 핀을 시리얼 통신에 활용하며, 기본 SoftwareSerial보다 안정성과 성능이 개선된 NeoSWSerial[[1]](#ref_1) 라이브러리를 사용하여 보다 효율적인 데이터 송수신을 구현함.
  - Raspberry Pi 5 (이하 Rpi 5)에서도 여러개의 UART를 지원하고 있으므로, 필요에 따라 UART1, UART2 등을 추가로 활성화해서 사용 가능(Rpi 5는 최대 UART5까지 지원하는 것으로 알고는 있으나 정확한 것은 확인이 필요함!!)
  - 또한, 라즈베리파이는 3.3V logic level인데 아두이노 우노는 5V logic level이므로, 중간에 반드시 Logic Level Convert를 두어야 회로가 망가지지 않음. 여기서는 Sparkfun Bi-Directional Logic Level Convert(BD-LLC)를 사용함.
    
    
<hr>

## 재료

  |항목|사진|
  |:-|:-|
  |아두이노 우노|<img width="231" height="166" alt="image" src="https://github.com/user-attachments/assets/7e57a03e-ebc7-4443-ae48-623859684d13" />|
  |라즈베리파이 5|<img width="252" height="167" alt="image" src="https://github.com/user-attachments/assets/a8550ae8-1b5f-4744-b022-7eaea8309490" />|
  |Bi-Directional Logic Level Converter (BD-LLC)|<img width="271" height="100" alt="image" src="https://github.com/user-attachments/assets/1620cbdf-9784-4856-940b-7ae82360c2c3" />|

<hr>

## Rpi 5에 추가 UART 활성화

  ```

  ```

## 결선도

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

  <a id="ref_1">[1]</a> [NeoSWSerial](https://github.com/SlashDevin/NeoSWSerial?utm_source=platformio&utm_medium=piohome)
  
  [Raspberry Pi 5 / Ubuntu 24.04 Can't get GPIO14/15;TX.RX;pins8/10 to work](https://groups.google.com/g/hbrobotics/c/JY6jtt0Vn18/m/AfYaEfIZAwAJ)
