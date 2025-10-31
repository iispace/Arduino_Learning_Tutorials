# HC-05

- 클래식 블루투스 2.0
- 블루투스 4.0 BLE인 HM-10과는 프로토콜이 달라 직접 페어링할 수 없음

  ## AT command mode 진입 및 설정 방법

  - 아두이노에 프로그램 업로드
    
    <img width="756" height="700" alt="image" src="https://github.com/user-attachments/assets/e3887ba5-17f1-48fc-88e6-0b00cfd799d8" />

  - 연결

    |HC-05|Arduino|
    |:-:|:-:|
    |VCC|5V|
    |GND|GND|
    |Rx|D6|
    |Tx|D7|

  - HC-05모듈 AT 모드 부팅

      - HC-05의 Reset 버튼을 누른 상태에서 HC-05의 GND핀 점퍼선 연결을 분리한 후, Reset 버튼을 누르고 있는 상태에서 GND 다시 연결 (제품에 따라서는 GND핀이 아니라 VCC핀의 연결을 다시 해야 AT 모드로 진입되는 것도 있는 듯.)
      - HC-05의 파란색 LED와 빨간색 LED가 모두 2초마다 한 번씩 깜빡이는 상태가 되었다면 성공적으로 AT 모드로 진입 된 것.

      <img width="575" height="361" alt="image" src="https://github.com/user-attachments/assets/96bf08d0-8bd0-4f00-b74b-5d613fe7e5f9" />

  
  - Serial monitor에서 시리얼 포트 연결 및 모듈 설정
    
    <img width="1953" height="590" alt="image" src="https://github.com/user-attachments/assets/618f1710-27ff-42bd-9e73-69e96f4b5f78" />


