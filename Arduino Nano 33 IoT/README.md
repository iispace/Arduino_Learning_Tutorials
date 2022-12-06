![image](https://user-images.githubusercontent.com/24539773/205570536-6a08cc6b-6b34-4fba-a817-5334299714a9.png)

# [Tech Spec](https://store-usa.arduino.cc/products/arduino-nano-33-iot)

# Trouble Shooting

1. [USB 인식 실패(Windows 10)](https://forum.arduino.cc/t/solved-arduino-nano-33-iot-not-recognized-by-windows-10/621376)
 
|| 작업 | 
|---| ----------- | 
|1|Arduino Nano 33 IoT 보드에 있는 RESET 버튼 빠르게 두 번 눌러서 부트로더 모드 실행 | 
|2|제대로 되었다면 보드의 D13번 핀 옆에 있는 BuiltIn LED가 주황색으로 점멸(Hart beating)하는 것이 보인다|
|3|윈도우 장치관리자(devmgmt.msc)를 열고 인식된 포트 번호 확인|
|4|Arduino IDE 또는 PlatformIO와 같은 IDE 도구에서 인식된 포트 번호로 프로그램 업로드|
||만일 새로 작성하거나 수정한 프로그램을 업로드하려 할 때 "장치 인식 실패" 오류가 또 발생한다면 작성한 프로그램의 소스 코드를 자세히 보아야 한다. 컴파일과정에서 오류가 없었더라도 코드에는 여전히 오류가 존재할 수 있다. (예: 장치명.begin()과 같은 명령이 누락된 경우, 컴파일할 때는 오류가 검출되지 않지만, 해당 명령어가 누락되면 프로그램이 의도대로 동작하지 못하며, 장치 인식 오류의 원인이 되기도 한다). <br>setup()과 loop() 함수 내부의 모든 내용을 지워서 BareMinimum 상태로 만든 후 프로그램을 업로드해 보았을 때 업로드가 된다면, 오류의 원은은 내가 작성한 코드에 있는 것이므로 책상에서 일어나 팔다리를 한번씩 쭉 편 후, 다시 코드를 한 줄씩 확인해 보자|
 
 
