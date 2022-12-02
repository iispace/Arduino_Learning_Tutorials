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
