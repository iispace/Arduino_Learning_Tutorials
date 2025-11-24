# GPS 정보 OLED Display에 출력하기

## SSD1306 OLED 0.91" <br>
<img width="386" height="121" alt="image" src="https://github.com/user-attachments/assets/a920b0a2-34dd-4a8a-bcb9-23383e671a16" />

128x32 pixel display

## Neo-6M GPS 모듈 <br>

<img width="220" height="200" alt="image" src="https://github.com/user-attachments/assets/12c303d8-8e4d-4e58-a03b-f696b4cd10bd" />
<br>
<img width="255" height="150" alt="image" src="https://github.com/user-attachments/assets/a91fed65-2ca7-4b03-b4c8-ea1124b7f689" />

 
<br><br>

<hr>

## IDE<br>
<a href="https://platformio.org/" target="_blank">
  <img src="https://user-images.githubusercontent.com/24539773/204492337-c76cb87f-93e6-4132-af63-6062e60ef4e8.png" width="280" height="200" align="left">
</a>
<br><br><br><br><br><br><br><br>
<hr>

## Libraries<br>
<img width="1094" height="206" alt="image" src="https://github.com/user-attachments/assets/78daa246-c7c8-4dfd-9840-2f9c26687fd1" />

<img width="1095" height="207" alt="image" src="https://github.com/user-attachments/assets/cc03992f-c00a-4e0d-aa93-83028459f48a" />

<br>


## OLED 0.91" Pin Connection to Arduino Uno(I2C)<br>
| Number | SSD1306 OLED 0.91 | Arduino Uno |
| :-: | :-: | :-: |
|1|GND|GND|
|2|VCC|3.3V|
|3|SCL|A5||
|4|SDA|A4||


## Neo-6M GPS module Pin Connection to Arduino Uno<br>
| Number | Neo-6M GPS module | Arduino Uno |
| :-: | :-: | :-: |
|1|GND|GND|
|2|TX|D4|
|3|RX|D3|
|4|VCC|5V|

<br>


## Example Code

```
/*
TinyGPSPlus library 설치 후 GPS 모듈로 읽어 들인 위도,경도 정보를 OLED 0.91" display 장치에 출력

Neo-6M GPS module | Arduino Uno
-------------------------------
       VCC        | 5V
       RX         | D3
       TX         | D4
       GND        | GND

*/
#include <Arduino.h>
#include <SoftwareSerial.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <TinyGPSPlus.h>
TinyGPSPlus gps;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000 };

int row_y = 0;
int seq_no = 0;

SoftwareSerial gps_Serial(4, 3); // RX, TX on Uno
// put function declarations here:
void displayTinyGPSVersion();
void displayInfo(char *);

void setup() {
  Serial.begin(9600);     // PC <-> Arduino
  gps_Serial.begin(9600); // GPS <-> Arduino

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  display.display();  // 기본 Adafruit 로고 출력
  delay(2000);        // Pause for 2 seconds

  displayTinyGPSVersion();
  delay(1000);
}


void loop() {
    while (gps_Serial.available() > 0) {
    char c = gps_Serial.read();

    // NMEA 문장을 모두 파싱했을 때만 처리
    if (gps.encode(c)) {
      // 새 위치가 갱신되었을 때만 출력 (중복 출력 방지)
      if (gps.location.isUpdated() && gps.location.isValid()) {
        // 실수 문자열 변환
        char latStr[20];
        char lngStr[20];
        dtostrf(gps.location.lat(), 0, 6, latStr); // 전체폭 자동, 소수 6자리
        dtostrf(gps.location.lng(), 0, 6, lngStr);

        //char info[64];
        //snprintf(info, sizeof(info), "Lat: %s Lng: %s", latStr, lngStr);

        // OLED 0.91"에는 lat과 Lng 정보가 한 줄에 출력되지 않으므로, 두 줄로 나누어 출력하기 위함.
        char info_lat[32];
        snprintf(info_lat, sizeof(info_lat), "Lat: %s", latStr);
        char info_lng[32];
        snprintf(info_lng, sizeof(info_lng), "Lng: %s", lngStr);

        Serial.print(info_lat);
        Serial.print(", ");
        Serial.println(info_lng);

        displayInfo(info_lat);
        displayInfo(info_lng);

      } else {
        // 문장 완료됐지만 위치가 아직 유효하지 않을 때만 한 번 표시
        displayInfo("Location: Invalid");
      }

      // 필요하면 여기서만 디버깅 로그 출력 (문장 단위)
      // Serial.println("NMEA sentence parsed.");
    }

    // 디버깅용 원시 NMEA 출력이 필요하다면, 주석 해제하되 과다 출력에 유의
    // Serial.print(c);
  }
}

void displayTinyGPSVersion(){
  char* gps_ver = TinyGPSPlus::libraryVersion();
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.print("TinyGPSPlus: ");
  display.print(gps_ver);
  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(3000);
  display.clearDisplay();
}

void displayInfo(char * info){
  if (row_y > SCREEN_HEIGHT - 8) {
    row_y = 0;
    display.clearDisplay();
  }
  display.setCursor(0, row_y);
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.print(info);
  display.display();
  row_y += 8; 
}

```

## 테스트

<img width="396" height="300" alt="image" src="https://github.com/user-attachments/assets/8b134821-a5db-4ed8-a28b-25f3363604c6" />


https://github.com/user-attachments/assets/e249633c-ffc3-46f6-b98b-a7e8927b5ca5

