# SSD1306 OLED 0.91" <br>
<img width="386" height="121" alt="image" src="https://github.com/user-attachments/assets/a920b0a2-34dd-4a8a-bcb9-23383e671a16" />

128x32 pixel display
 
<br><br>

<hr>

# IDE<br>
<a href="https://platformio.org/" target="_blank">
  <img src="https://user-images.githubusercontent.com/24539773/204492337-c76cb87f-93e6-4132-af63-6062e60ef4e8.png" width="280" height="200" align="left">
</a>
<br><br><br><br><br><br><br><br>
<hr>

# Library<br>
<img width="1094" height="206" alt="image" src="https://github.com/user-attachments/assets/78daa246-c7c8-4dfd-9840-2f9c26687fd1" />

<br>


# OLED 0.91" Pin Connection to Arduino Uno (I2C)<br>
| Number | SSD1306 OLED 0.91 | Arduino Uno |
| :-: | :-: | :-: |
|1|GND|GND|
|2|VCC|3.3V|
|3|SCL|A5|
|4|SDA|A4|

<br>


# Example Code

```
/*
TinyGPSPlus library 설치 후 GPS 모듈로 읽어 들인 위도,경도 정보를 OLED 0.91" display 장치에 출력

Neo-6M GPS module | Arduino Uno
-------------------------------
       VCC        | 5V
       RX         | D5
       TX         | D4
       GND        | GND

*/
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

/*
   This sample sketch demonstrates the normal use of a TinyGPSPlus (TinyGPSPlus) object.
   It requires the use of SoftwareSerial, and assumes that you have a
   9600-baud serial GPS device hooked up on pins 4(rx) and 5(tx).
*/
static const int RXPin = 4, TXPin = 5;
static const uint32_t GPSBaud = 9600;

// The TinyGPSPlus object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial gps_Serial(RXPin, TXPin);


/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C.

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
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
const char* gps_ver = TinyGPSPlus::libraryVersion();

void testText();
void displayInfo();
void gpsInfo2display(double, double);

void setup() {
  Serial.begin(115200);
  gps_Serial.begin(GPSBaud);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
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
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display(). These examples demonstrate both approaches...
  Serial.print(F("TinyGPSPlus library v. ")); 
  Serial.println(TinyGPSPlus::libraryVersion());

  display.clearDisplay();

}

void loop() {

  testText();


  // This sketch displays information every time a new sentence is correctly encoded.
  while (gps_Serial.available() > 0)
    if (gps.encode(gps_Serial.read()))
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }

}


void displayInfo()
{
  Serial.print(F("Location: ")); 
  display.print("L:");
  if (gps.location.isValid())
  {
    double lat = gps.location.lat();
    double lng = gps.location.lng();

    Serial.print(lat, 6);
    Serial.print(F(","));
    Serial.print(lng, 6);
    gpsInfo2display(lat, lng);
    
  }
  else
  {
    Serial.print(F("No GPS"));
    display.print("xx");
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}

void testText(){
  if (row_y >= 30) {
    row_y = 0;
    display.clearDisplay();
  }
  display.setCursor(0, row_y);
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.print("[");
  display.print(seq_no);
  display.print("]");

  display.display();
  // Serial.print('[');
  // Serial.print(seq_no);
  // Serial.print(']');
  // Serial.println("test");
  row_y += 10;
  seq_no += 1;
  delay(1000);
}

void gpsInfo2display(double lat_, double lng_){
  if (row_y >= 30) {
    row_y = 0;
    display.clearDisplay();
  }
  display.setCursor(0, row_y);
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  // display.print("[");
  // display.print(seq_no);
  // display.print("]");
  display.print(lat_, 6);
  display.print(",");
  display.print(lng_, 6);

  display.display();
  // Serial.print('[');
  // Serial.print(seq_no);
  // Serial.print(']');
  // Serial.println("test");
  row_y += 10;
  seq_no += 1;
  delay(1000);
}

void testscrolltext(void) {
  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(F("scroll"));
  display.display();      // Show initial text
  delay(100);

  // Scroll in various directions, pausing in-between:
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);
}


```
