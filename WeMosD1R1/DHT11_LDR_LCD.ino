/*
 * WeMos D1 R1(ESP-12F) 보드
 * LDR Sensor with 10K(ohm) 저항
 * LED with 220(ohm) 저장
 */
#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header
 
#include "DHT.h"
#define DHTTYPE DHT11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

int LDR = A0;            // select the input pin for LDR(Light Dependent Resistor)
const int LED = 16;      //ESP8266PIN배열의 GPIO16번 핀, WeMos 보드 윗면에 표시된 D13/SCK/D5 핀에 led 다리가 긴곳을 연결.
const int DHTPIN = 14;   //ESP8266PIN배열의 GPIO14번 핀, WeMos 보드 윗면에 표시된 D2 핀에 연결
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

int reading = 0;
int val = 0; // variable to store the sensor value 

hd44780_I2Cexp lcd; // declare lcd object: auto locate & auto config expander chip  

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(LCD_COLS, LCD_ROWS); // initialize the lcd for 16 chars 2 lines, turn on backlight
  // ------- Quick 3 blinks of backlight  -------------
  for (int i = 0; i<=3; i++){
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  // ------- Finish 3 blinks of backlight -------------
  lcd.backlight();
  
  dht.begin();
  pinMode(LED, OUTPUT);
  Serial.begin(9600);  
  Serial.println(F("LDR and DHT11 Test on WeMos D1 R1"));
  delay(2000);
}

void loop() {
  control_ldr();
  delay(250);
  control_dht();
  delay(250);
}


void control_dht(){
  float h = dht.readHumidity();
  // Read temperature as Celsius (default)
  float t = dht.readTemperature(); 
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again);
  if (isnan(h) || isnan(t)){
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // Compute heat index in Celsius(isFahrenheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print(F("Humidity: ")); Serial.print(h); Serial.print(F("% Temperature: "));
  Serial.print(t); Serial.print(F("°C Heat index: ")); Serial.print(hic);
  Serial.println(F("°C "));

  Serial.println(F("=================================="));
  
  lcd.setCursor(0,1);  lcd.print(t);
  lcd.setCursor(5,1);  lcd.print((char)223);  // (char)223: degree symbol
  lcd.setCursor(6,1);  lcd.print("C, ");
  lcd.setCursor(9,1);  lcd.print(h);
  lcd.setCursor(14,1); lcd.print("%");
  delay(5000);
  lcd.clear();
}

void control_ldr(){
  reading=analogRead(LDR);
  val = map(reading,0,1023,0,100);
  Serial.print(F("Analog reading: ")); Serial.print(reading);
  Serial.print(F(", mapped value(0~100):")); Serial.println(val);
  if (val <= 60)
  {
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);  
  }
  lcd.setCursor(0,0); lcd.print("LDR: ");
  lcd.setCursor(5,0); lcd.print(val);
} 
