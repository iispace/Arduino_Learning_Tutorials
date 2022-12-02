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

## 4. Arduino용 CameraWebServer 프로젝트에서 Camera 설정과 관련된 헤더파일 파일 가져오기
<ol>
  <li>Arduino IDE에서 CameraWebServer 예제 프로젝트 열기</li>
  <img src="https://user-images.githubusercontent.com/24539773/205213382-a8a83a5c-f60f-43d9-b8dd-a3436d550cbc.png" width="280" height="200" align="left">
  <br><br><br><br><br><br><br><br><br><br>
  <li>아래 그림과 같이 CameraWebServer 예제 프로젝트 화면에 "CameraWebServer","app_httpd.cpp","camera_index.h","camera_pins."의 총 4개의 탭이 나타남.)</li>
  <img src="https://user-images.githubusercontent.com/24539773/205215215-e9c56807-44c7-4e96-baed-1258f8ebc5ea.png" width="280" height="200" align="left">
  <br><br><br><br><br><br><br><br><br><br>
  
  <li>PlatfirmIO의 lib폴더 하위에 "camera_config"라는 이름의 폴더(폴더명은 임의로 지정한 것)를 하나 생성한 후,위 이미지에서 보이는 camera_index.h 파일과 camera_pins.h 파일을 저장한다.</li>
  <img src="https://user-images.githubusercontent.com/24539773/205219964-26f80d78-19be-42ce-a67b-d15a0eb6817b.png" width="180" height="280" align="left">
  <br><br><br><br><br><br><br><br><br><br><br><br><br>
  
  <li>PlatformIO에서 ESP32-CAM을 사용하기 위한 기본 설정이 완료되었으므로, 이제 main.cpp파일에 필요한 프로그래밍을 할 수 있게 되었다.</li>
</ol>
<hr>

## 5. 예제 프로그래밍

- [CameraWebServer](https://github.com/iispace/Arduino_Learning_Tutorials/tree/main/ESP32-CAM/CameraWebServer)
- [Take Photo and Save to SD Card](https://github.com/iispace/Arduino_Learning_Tutorials/tree/main/ESP32-CAM/TakePhotoNSaveToSDCard/main.cpp)
 

