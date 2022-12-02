# ESP32-CAM<br>
## 1. 프로그램 업로드용 결선 방법 <br>
### 1.1 FTDI 이용
<img src="https://user-images.githubusercontent.com/24539773/204515143-75981249-23a6-4a84-af99-289dc6b4e4c0.png" width="280" height="200" align="left">
<br><br><br><br><br><br><br><br><hr>

### 1.2 Arduino UNO 보드 이용<br>
<img src="https://user-images.githubusercontent.com/24539773/204515770-8448b033-690c-46bc-b4b8-9ba480a757cd.png" width="280" height="200" align="left">
<br><br><br><br><br><br><br><br><hr>

## 2. IDE <br>
<a href="https://platformio.org/" target="_blank">
  <img src="https://user-images.githubusercontent.com/24539773/204492337-c76cb87f-93e6-4132-af63-6062e60ef4e8.png" width="280" height="200" align="left">
</a>
<br><br><br><br><br><br><br><br>
<hr>

## 2. 프로젝트 생성
<img src="https://user-images.githubusercontent.com/24539773/205210647-87ed6b04-49c6-4079-a95b-1ed1a1ef54e4.png" width="420" height="230" align="left">
<br><br><br><br><br><br><br><br><br><br>
Name: 개발자 지정 이름<br>

**Board**: "**AI Thinker ESP32-CAM**" 선택<br>

**framework**: "**Arduino**" 선택<br>

<hr>

## 3. Camera Library 추가
다음 중 한가지 방법으로 camera library를 platformio에 추가:<br>
<ol>
  <li>Using PlatformIO Library Manager: espressif/esp32-camera</li>
  <li>Download zip file from repository ("https://github.com/espressif/esp32-camera") => exract it => put entire extraction under Project\Lib directory</li>
</ol>
### 2.2 Source Code
Working on it....<br>
## 3. 실행 모드 전환
ESP32-CAM 모듈 실행 모드: ESP32-CAM 모듈의 GPIO0번 핀과 GND핀 연결 제거
<br> 
