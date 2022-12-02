# ESP32-CAM<br>
## 1. 프로그램 업로드용 결선 방법 <br>
아래 두 가지 방법 중 한 가지의 방법을 선택하여 구성한 후 컴퓨터의 USB 단자에 연결<br>

### 1.1 FTDI 이용
<img src="https://user-images.githubusercontent.com/24539773/204515143-75981249-23a6-4a84-af99-289dc6b4e4c0.png" width="280" height="200" align="left">
<br><br><br><br><br><br><br><br><hr>

### 1.2 Arduino UNO 보드 이용<br>
<img src="https://user-images.githubusercontent.com/24539773/204515770-8448b033-690c-46bc-b4b8-9ba480a757cd.png" width="280" height="200" align="left">
<br><br><br><br><br><br><br><br><hr>

## 2. PlatformIO(IDE)에서 프로젝트 생성 <br>
<a href="https://platformio.org/" target="_blank">
  <img src="https://user-images.githubusercontent.com/24539773/204492337-c76cb87f-93e6-4132-af63-6062e60ef4e8.png" width="280" height="200" align="left">
</a>

<img src="https://user-images.githubusercontent.com/24539773/205210647-87ed6b04-49c6-4079-a95b-1ed1a1ef54e4.png" width="420" height="230" align="left">
<br><br><br><br><br><br><br><br><br><br>
Name: 개발자 지정 이름<br>

**Board**: "**AI Thinker ESP32-CAM**" 선택<br>
**framework**: "**Arduino**" 선택<br>
<hr>

## 3. Camera Library 추가

**다음 중 한가지 방법으로 camera library를 platformio에 추가**<br>
<ol>
  <li>PlatformIO HOME ==> Libraries에서 "espressif\esp32-camera" 선택하여 현재 프로젝트에 추가</li>
  <img src="https://user-images.githubusercontent.com/24539773/205213815-f62b6013-49f7-4ea0-8e34-52c18d78559a.png" width="500" height="200" align="left">
  <br><br><br><br><br><br><br><br><br><br>
  <li>Espressif Github("https://github.com/espressif/esp32-camera")에서 zip 형식으로 다운로드한 후 압축 해제하여 PlatformIO의 해당 Project하위에 있는 "Lib" 폴더에 복사(단, 이 방법으로 Lib 폴더에 추가한 경우에는 platformio.ini 파일을 열고 "build_flags = -I../lib/{라이브러리 최상위 폴더명}"을 추가해야 함.)</li>
 <img src="https://user-images.githubusercontent.com/24539773/205217298-690e8de5-d3f1-4930-b658-72daaab38ea1.png" width="500" height="200" align="left">
 
  <br><br><br><br><br><br><br><br><br>
</ol>
<hr>

## 4. Arduino용 CameraWebServer 프로젝트에서 필요한 파일 가져오기
<ol>
  <li>Arduino IDE에서 CameraWebServer 예제 프로젝트 열기</li>
  <img src="https://user-images.githubusercontent.com/24539773/205213382-a8a83a5c-f60f-43d9-b8dd-a3436d550cbc.png" width="280" height="200" align="left">
  <br><br><br><br><br><br><br><br><br><br>
  <li>아래 그림과 같이 CameraWebServer 예제 프로젝트 화면에 "CameraWebServer","app_httpd.cpp","camera_index.h","camera_pins."의 총 4개의 탭이 나타남.)</li>
  <img src="https://user-images.githubusercontent.com/24539773/205215215-e9c56807-44c7-4e96-baed-1258f8ebc5ea.png" width="280" height="200" align="left">
  <br><br><br><br><br><br><br><br><br><br>
</ol>
<hr>

## 5. Build and Upload to ESP32-CAM 보드
<hr>

## 6. 실행  
<ol>
  <li>PlatformIO에서 Serial Monitor 열기</li>
  <li>ESP32-CAM 모듈 실행 모드: ESP32-CAM 모듈의 GPIO0번 핀과 GND핀 연결 제거한 후 ESP32-CAM 보드에 있는 RESET 버튼 눌러줌</li>
  <li>웹브라우저 열고 PlatformIO의 Serial Monitor에서 확인한 IP 주소로 이동 </li>
  <li>화면에 나타난 카메라 설정 화면의 제일 아래쪽에 있는 "Start Stream" 버튼 클릭</li>
</ol>
<hr>

 

