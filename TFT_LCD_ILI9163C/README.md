# 1.44" TFT LCD (ILI9163C Driver IC)<br>
<figure>
  <img src="https://github.com/user-attachments/assets/f85a97e1-f940-49e5-b4b0-68ca56afb17f" width="300" height="300" align="left">
  <figcaption align="center"> <a href="https://electronics-lab.com/project/using-1-44-color-tft-display-ili9163c-arduino">사진 출처</a></figcaption> 
</figure>
 
<br><br><br><br><br><br><br><br><br><br><br><br><br>
<hr> 

# IDE<br>
<a href="https://platformio.org/" target="_blank">
  <img src="https://user-images.githubusercontent.com/24539773/204492337-c76cb87f-93e6-4132-af63-6062e60ef4e8.png" width="280" height="200" align="left">
</a>
<br><br><br><br><br><br><br><br>
<hr>

# Library<br>
<img width="1661" height="593" alt="image" src="https://github.com/user-attachments/assets/b40d0b58-636b-4eeb-88f0-ffb550f58c8c" />

<br>


# TFT LCD Pin Description<br>
| Number | Pin Label | Description |
| :-: | :-: | :-: |
|1|VCC|5V/3.3V power input 
|2|GND|GND
|3|CS| LCD chip select signal, low level enable
|4|RST| LCD reset signal, low level reset
|5|A0| LCD screen register/data selection signal, high level:register, low level:data
|6|SDA|SPI bus write data signal
|7|SCK|SPI bus clock signla
|8|LED| Backlight control, light up at high level, if no control is needed, connect to 3.3V constant light
 

# Wiring<br>
| Arduino UNO | TFT LCD(Hardware SPI) |  
| :-: | :-: | 
| 3.3V/5V | VCC | 
| GND | GND | 
|D10|CS |
|D09|RST |
|D08|A0 |
|D11 (MOSI)|SDA|
|D13|SCK|
|3.3V|LED| 

<br>

# Arduino Uno Pinout

<img width="1188" height="818" alt="image" src="https://github.com/user-attachments/assets/1a894d6b-f20b-4a78-b04d-da52c2f870b7" />
[그림 출처: https://deepbluembedded.com/arduino-uno-pinout]

<br>

# header 파일 수정 
(1) 본 제품은 PCB 색상이 검정색인 제품과 빨간색인 제품이 있고, PCB의 색상에 따라 설정된 GRAM의 OFFSET이 다르다. 그런데, 간혹 빨간색 PCB 제품인데도 검정색 PCB 제품의 OFFSET 설정을 해 주어야 하는 제품도 있는데, 테스트 프로그램을 업로드하여 실행해 보면 지금 사용하고 있는 제품의 설정에 수정이 필요한 지 그렇지 않은 지를 확인할 수 있다[[1]](#ref1). 여기서 GRAM이란 Graphic RAM으로, TFT LCD 컨트롤러 칩 내부에 있는 메모리를 말한다. ILI9163C 컨트롤러 칩을 탑재한 LCD의 경우, 칩 자체는 160x128의 해상도를 지원하도록 설계되었지만, 실제 물리적인 LCD 패널은 그 보다 작은 128x128 해상도를 지원하기 때문에 OFFSET 설정이 맞지 않는 경우에는 아래의 왼쪽 사진(비정상)과 같이 화면의 일부를 사용할 수 없게 되고, 해당 영역은 노이즈가 출력되는 것처럼 보인다.

<img width="611" height="324" alt="image" src="https://github.com/user-attachments/assets/3c632beb-636c-43f6-ae18-f78c3aedbffc" />

<br><br>
(2) PlatformIO의 Libraries 메뉴에서 TFT_ILI9163 라이브러리를 찾아 보면, 아래와 같이 해당 라이브러리를 설명하는 화면의 내용 중에 동작을 테스트할 수 있는 예제 코드가 있다. 이 코드를 아두이노에 업로드하여 동작을 확인했을 때 위에 있는 (비정상) 사진처럼 보인다면 TFT_ILI9163_settings.h 파일에서 제품 선택 옵션을 바꾸면 간단히 해결된다.

<img width="1046" height="765" alt="image" src="https://github.com/user-attachments/assets/b1a4e7a5-a976-469d-874e-57e83156381d" />

<br><br>
(3) TFT_ILI9163_settings.h 파일을 열고 아래 그림처럼 "#define __144_RED_PCB__" 부분을 주석처리하고, 그 아랫줄에 있는  "//#define __144_BLACK_PCB__" 부분의 주석을 해제하면 끝!.

<img width="650" height="500" alt="image" src="https://github.com/user-attachments/assets/679f9d00-8e60-47ff-93dd-e63c571afb12" />



<br>
<br>



# Simplied Example Code

```
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

// Color definitions
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF

/*
Connection to Arduino Uno
 MOSI:  11//Arduino UNO  
 MISO:  12//Arduino UNO  
 SCK:   13//Arduino UNO  
 */
#define __CS 10
#define __DC 9
#define __A0 8

// Generate TFT_LCD instance in the name of 'display'
TFT_ILI9163C display = TFT_ILI9163C(__CS,__A0, __DC);

int left_limit = 3;      // left-side start poisition for more visibility
int top_limit = 3;
int bottom_limit = 120;  // max line number for more visibility

void tftPrintText(int,  int, uint16_t, const char*);

void setup() {
    display.begin();
    Serial.begin(9600);

    display.setRotation(45);  // to make TFT-LCD horizontally oriented
    delay(100);

    display.clearScreen();
    display.setCursor(left_limit,top_limit);
    delay(100); 

    tftPrintText(left_limit, top_limit, YELLOW, "TFT LCD is working now !!");
    delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void tftPrintText(int col, int row, uint16_t color, const char* text) {
  display.clearScreen();
  display.setCursor(col, row);
  display.setTextColor(color, BLACK);
  display.setTextSize(1);
  display.print(text);
  Serial.println(text);
}
```

<br>
<br>
<hr>

# Reference
[1] <a id="ref1"></a> [Arduino StackExchange-ILI9163C screen not working properly](https://arduino.stackexchange.com/questions/21581/ili9163c-screen-not-working-properly)
