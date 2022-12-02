# ESP32-CAM<br>
<a href="https://github.com/SeeedDocument/forum_doc/blob/master/reg/ESP32_CAM_V1.6.pdf">ESP32-CAM Schematics</a>
<hr>

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
  <li>Espressif Github("https://github.com/espressif/esp32-camera") 에서 zip 형식으로 다운로드한 후 압축 해제하여 PlatformIO의 해당 Project하위에 있는 "lib" 폴더에 복사(단, 이 방법으로 Lib 폴더에 추가한 경우에는 platformio.ini 파일을 열고 "build_flags = -I../lib/{라이브러리 최상위 폴더명}"을 추가해야 함.)</li>
  <li>platformio.ini 파일을 열고 "monitor_speed = 115200" 을 추가해 준다.</li>
  <li>아래 이미지에서 왼쪽은 PlatformIO의 Libraries 메뉴에서 esp32-camera를 추가했을 때의 설정모습이며, 오른쪽은 lib폴더 하위에 압축을 해제한 zip 파일 형식의 라이브러리를 추가했을 때 설정 모습.</li><br>
  <img src="https://user-images.githubusercontent.com/24539773/205223400-b96f9042-1413-4b64-ad29-ca552bd22d4b.png" width="300" height="150" align="left">
  
 <img src="https://user-images.githubusercontent.com/24539773/205222512-8f317eff-e449-4826-9ed9-7e80c0fbbb4f.png" width="300" height="150" align="left">
 
  <br><br><br><br><br><br><br>
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
  <li>위 이미지에서 보이는 CameraWebServer.ino 파일의 내용을 전부 복사하여 PlatfirmIO의 main.cpp에 덮어쓰기 한다.</li>
  <li>PlatfirmIO의 lib폴더 하위에 "camera_config"라는 이름의 폴더(폴더명은 임의로 지정한 것)를 하나 생성한 후,위 이미지에서 보이는 camera_index.h 파일과 camera_pins.h 파일을 저장한다.</li>
  <img src="https://user-images.githubusercontent.com/24539773/205219964-26f80d78-19be-42ce-a67b-d15a0eb6817b.png" width="180" height="280" align="left">
  <br><br><br><br><br><br><br><br><br><br><br><br><br>
  
<li>PlatformIO의 main.cpp 파일을 열고, 카메라 모델을 ESP32-CAM 보드에 맞게 AI-THINKER로 설정해 주기 위해 "#define CAMERA_MODEL_WROVER_KIT // Has PSRAM"을 주석 처리하고, "#define CAMERA_MODEL_AI_THINKER // Has PSRAM"의 주석을 없애서 "CAMERAL_MODEL_AI_THINKER"가 카메라 모델로 define 되도록 한다. </li>
  <img src="https://user-images.githubusercontent.com/24539773/205226040-5eac6643-8434-47d4-ba11-5769dbd54f9f.png" width="280" height="150" align="left">
 <br><br><br><br><br><br><br><br>
  
  <li>main.cpp를 Build한 후 PlatformIO의 PROBLEMS 창을 보니 더이상 지원하지 않는 literal 상수가 있는 것 같다. 권고내용을 보고 그대로 따라 바뀌준다.</li>
  <img src="https://user-images.githubusercontent.com/24539773/205221333-fb813f83-7362-4625-81b2-9782823b5cfe.png" width="280" height="200" align="left">
  <br><br><br><br><br><br><br><br><br><br>
</ol>
<hr>

## 5. Build and Upload to ESP32-CAM 보드
<img src="https://user-images.githubusercontent.com/24539773/205227045-67c091c2-dc08-49f0-9727-5c8e6af3cdc6.png" width="444" height="74" align="left">
<br><br><br><br><br>
<hr>

## 6. 실행  
<ol>
  <li>PlatformIO에서 Serial Monitor 열기</li>
  <img src="https://user-images.githubusercontent.com/24539773/205221650-5c583c83-306c-4cb3-8842-247bb8bbe668.png" width="618" height="40" align="left">
   <br><br><br>
  <li>ESP32-CAM 모듈 실행 모드로 변경: ESP32-CAM 모듈의 GPIO0번 핀과 GND핀 연결 제거한 후 ESP32-CAM 보드에 있는 RESET 버튼 눌러줌</li>
  <li>PlatformIO의 Serial Monitor에서 WiFi 연결 상태와 IP 주소 확인 </li>
  <img src="https://user-images.githubusercontent.com/24539773/205224279-0395b15e-f333-4f4f-83b6-03ddfbe75e18.png" width="400" height="130" align="left">
  <br><br><br><br><br><br><br>
  
  <li>웹브라우저 열고 PlatformIO의 Serial Monitor에서 확인한 IP 주소로 이동 </li>
  
  <li>화면에 나타난 카메라 설정 화면의 제일 아래쪽에 있는 "Start Stream" 버튼 클릭</li>
  <img src="https://user-images.githubusercontent.com/24539773/205224879-325266df-04b7-4ac2-91e1-1097e4e58734.png" width="500" height="650" align="left">
   <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
</ol>
<hr>

 

