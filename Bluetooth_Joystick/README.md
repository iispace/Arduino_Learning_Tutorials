# Bluetooth Joystick

<img width="528" height="400" alt="image" src="https://github.com/user-attachments/assets/8433b997-488d-4ba6-a52b-008feed9322d" />

# Materials

1. Arduino Uno x 1
2. Funduino Joystick shield x 1
3. 9V Battery enclosure with 9V battery x 1
4. HC-05 Bluetooth module x 1
   
<img width="496" height="400" alt="image" src="https://github.com/user-attachments/assets/32c718ec-5324-41d7-9e19-28aa6bda2e70" />

# Connection

|Joystick Shield|Arduino Uno|
| :-: | :-: | 
|VCC|5V|
|GND|GND|
|TX|D7|
|RX|D6|

# External library used
<img width="1067" height="185" alt="image" src="https://github.com/user-attachments/assets/2e839cf0-852f-45f3-b466-5e3daf750a7e" />

- [NeoSWSerial](https://docs.arduino.cc/libraries/neoswserial/) is an efficient replacement for SoftwareSerial at baud rate 9600, 19200, and 38400. Simultaneous RX & TX, does not require additional TIMERs, interrupts not disabled during RX. [More efficient than Arduino built-in SoftwareSerial.](https://github.com/SlashDevin/NeoSWSerial)

# Code

```
#include <Arduino.h>
#include <NeoSWSerial.h>

#define BT_RX 7  // 아두이노 7번 핀 <-> HC-05 TX 연결  
#define BT_TX 6  // 아두이노 6번 핀 <-> HC-05 RX 연결  

NeoSWSerial HC05(BT_RX, BT_TX); // RX, TX

int up_button = 2;      // 'G' 전달 버튼 (Go Straight)
int down_button = 4;    // 'B' 전달 버튼 (Go Back)
int buzzer_button = 5;  // '1' 전달 버튼 (Buzzer)
int stop_button = 3;    // '0' 전달 버튼 (Stop)

int joystick_button = 8;    // 조이스틱 쉴드의 방향 조정 장치을 누르면 정지 신호 전달 버튼으로 사용 ('0' 전달)
int buttons[] = {up_button, down_button, buzzer_button, stop_button, joystick_button};

int axis_x = A0;  // 조이스틱 쉴드 방향 조정 장치의 x축 연결 핀
int axis_y = A1;  // 조이스틱 쉴드 방향 조정 장치의 y축 연결 핀 

int axis_pins[2] = {axis_x, axis_y};
int axis_values[2] = {0, 0};

char data='0';

String carState = "";

void setup() {
  Serial.begin(9600);
  //HC05.begin(38400);  // HC-05 AT mode 기본 통신 속도
  HC05.begin(9600);     // HC-05 기본 Data 통신 속도
  pinMode(up_button, INPUT_PULLUP);
  pinMode(down_button, INPUT_PULLUP);
  pinMode(buzzer_button, INPUT_PULLUP);
  pinMode(stop_button, INPUT_PULLUP);
  pinMode(buzzer_button, INPUT_PULLUP);
  pinMode(joystick_button, INPUT_PULLUP);

  delay(1000);
  Serial.println("Test Master started...");
  
}

void loop() {
  if(digitalRead(up_button) == 0){   // button pressed
    data = 'G';      
    carState = "Go straight";
  }
  else if(digitalRead(down_button) == 0){
    data = 'B';       
    carState = "Go Back";
  }
  else if(digitalRead(buzzer_button) == 0){
    data = '1';       
    carState = "Buzzer on";
  }
  else if(digitalRead(stop_button) == 0){
    data = '0';      
    carState = "Stop";
  }
  else if(digitalRead(joystick_button) == 0){
    data = '0';      // Stop
    carState = "Stop";
  }
  else{
    //data = '.';      // No command
    for (int i = 0; i < 2; i++) {
      axis_values[i] = analogRead(axis_pins[i]);
      axis_values[i] = map(axis_values[i], 0, 1023, -10, 10);
    }

    if ((axis_values[0] == -10) && (axis_values[1] == -4)) {
    data = 'L';      // Turn Left
    carState = "Turn Left (Joystick)";
    }
    else if ((axis_values[0] == 3) && (axis_values[1] == -4)) {
      data = 'R';      // Turn Right
      carState = "Turn Right (Joystick)";
    }
    else if ((axis_values[0] == -4) && (axis_values[1] == 3)) {
      data = 'G';      // Go straight
      carState = "Go straight (Joystick)";
    }
    else if ((axis_values[0] == -4) && (axis_values[1] == -10)) {
      data = 'B';      // Go Back
      carState = "Go Back (Joystick)";
    }
    else if ((axis_values[0]== -4) && (axis_values[1] == -4) ) {
      data = '.';      // No command
      carState = "No command";
    }
  }
  

  if (data != '.') {
    HC05.write(data);       
    // Serial.print(data);
    // Serial.print(" axis x: ");
    // Serial.print(axis_values[0]);
    // Serial.print(" y: ");
    // Serial.println(axis_values[1]);
    delay(1);
  }
}
```
