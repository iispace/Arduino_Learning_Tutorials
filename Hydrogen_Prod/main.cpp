#include <Arduino.h>
#include <WiFiNINA.h>
#include <ThingSpeak.h>
#include <Adafruit_INA219.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include <SPI.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define I2C_OLED 0x3C    // OLED I2C 주소
#define I2C_INA219 0x40  // INA219 전류센서 I2C 주소 

#define LIMITSW 8
#define MOSFET 7
#define GREEN_LED 6
#define RED_LED 5

WiFiClient client;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_INA219 ina219(I2C_INA219);

/*
 * WiFi Connection Info
*/ 
char ssid[] = "yourSSID";
char pass[] = "yourpassword";
unsigned long myChannelNumber = yourThingSpeakChannelNumber;
const char* myWriteAPIKey = "yourThingSpeakWriteAPIKey";
int keyIndex = 0; // your network key index number (needed only for WEP)

/*
 * ThingSpeak Restriction
*/
long lastConnectionTime = 0;
const int ThingSpeakInterval = 20 * 1000;  // 20 seconds interval for ThingSpeak update

/*
 * INA219 mA Sensor
*/
uint32_t total_sec = 0;
float total_mA = 0.0;

void printSIValue(float value, char* units, int precision, int maxWidth){
  // Print a value in SI units with the units left justified and value right justified.
  // Will switch to milli prefix if value is below 1.

  // Add milli prefix if low value
  if(fabs(value) < 1.0){
    display.print('m');
    maxWidth -= 1;
    value *= 1000.0;
    precision = max(0, precision-3);
  }

  // Print units
  display.print(units);
  maxWidth -= strlen(units);

  // Leave room for negative sign if value is negative
  if (value < 0.0){
    maxWidth -= 1;
  }

  // Find how many digits are in value
  int digits = ceil(log10(fabs(value)));
  if(fabs(value) < 1.0){
    digits = 1; // Leave room for 0 when value is below 0.
  }

  // Handle if not enough width to display value, just print dashes.
  if (digits > maxWidth){
    // Find width with dashes (and extra dash for negative values)
    for (int i=0; i < maxWidth; ++i){
      display.print('-');
    }
    if (value < 0.0){
      display.print('-');
    }
    return;
  }
  // Compute actual precision for printed value based on space left after
  // printing digits and decimal point.  Clamp within 0 to desired precision.
  int actualPrecision = constrain(maxWidth-digits-1, 0, precision);

  // Compute how much padding to add to right justify.
  int padding = maxWidth-digits-1-actualPrecision;
  for (int i=0; i < padding; ++i) {
    display.print(' ');
  }

  // Finally, print the value!
  display.print(value, actualPrecision);
}

void PrintStrOLED(int _size, const char* _str){
  
  display.clearDisplay();
  display.display();
  delay(500);

  display.setTextSize(_size);
  display.invertDisplay(false);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(F(_str));

  display.display();
}

void CheckLimitSwitch(){
  int swValue = digitalRead(LIMITSW);
  Serial.println("****************************************");
  Serial.print("LIMIT Switch is "); Serial.println(swValue);
  Serial.println("****************************************");
  delay(100);
  // 스위치 기본 설정: COM-NC (=> 평소 HIGH 상태)
  // 스위치 눌리지 않았을 때: HIGH => MOSFET에 HIGH 신호를 주어 수소연료전지에 전원 인가
  // 스위치 눌렸을 때:        LOW =>  MOSFET에 LOW 신호를 주어 수소연료전지에 전원 차단
  if(swValue == LOW){         
    digitalWrite(MOSFET, LOW);  // 스위치 눌린 상태 (COM - NO)
    delay(10);
    digitalWrite(GREEN_LED, LOW);
    delay(10);
    digitalWrite(RED_LED, HIGH);   
    delay(10);
    Serial.println("MOSFET OFF");
  }
  else if (swValue == HIGH){    // 스위치 눌리지 않은 상태 (COM - NC)
    digitalWrite(MOSFET, HIGH);
    delay(10);
    digitalWrite(RED_LED, LOW); 
    delay(10);   
    digitalWrite(GREEN_LED, HIGH);   
    delay(10);
    Serial.println("MOSFET ON");
  }
}

void SendDataToThingSpeak(float v1, float v2, float v3){
  ThingSpeak.setField(1, v1);  // Field 번호 "1"의 값을 value로 설정함 (Volt)
  ThingSpeak.setField(2, v2);  // Field 번호 "2"의 값을 value로 설정함 (mA)
  ThingSpeak.setField(3, v3);  // Field 번호 "3"의 값을 value로 설정함 (power_mW)
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (x == 200){
    Serial.println("Channel update successful");
    String msg = "Channel update successful " + String(x);
    PrintStrOLED(1, msg.c_str());
  }
  else{
    Serial.println("Problem updating channel. HTTP error code: " + String(x));
    String msg = "Problem updating channel. HTTP error code: " + String(x);

    PrintStrOLED(1, msg.c_str());
  }
}


struct measurementPower {
  float Volt;
  float mA;
  float power_mW;
  float total_mAH;
};

struct measurementPower update_power_display(){
  struct measurementPower output;

  // Read voltage and current from INA219
  float shuntvoltage = ina219.getShuntVoltage_mV();
  float busvoltage = ina219.getBusVoltage_V();
  float current_mA = ina219.getCurrent_mA();

  // Compute load voltage, power, and milliamp-hours.
  float loadvoltage = busvoltage + (shuntvoltage / 1000);
  float power_mW = loadvoltage * current_mA;
  total_mA += current_mA;
  total_sec += 1;
  float total_mAH = total_mA / 3600.0;

  // Update display
  display.clearDisplay();
  display.setCursor(0,0);

  // Mode 0, display volt and amps
  printSIValue(loadvoltage, "V:", 2, 10);
  display.setCursor(0,12);  // Original value is display.setCursor(0,16);
  printSIValue(current_mA/1000.0, "A:", 5, 10);

  display.display();

  output.Volt = loadvoltage;
  output.mA = current_mA;
  output.power_mW = power_mW;
  output.total_mAH = total_mAH;

  return output;
}

void setup() {

  pinMode(LIMITSW, INPUT);
  pinMode(MOSFET, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.begin(9600);

  WiFi.begin(ssid, pass);

  if(!display.begin(SSD1306_SWITCHCAPVCC, I2C_OLED)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  if (!ina219.begin()){
    Serial.println("Failed to find INA219 chip");
    PrintStrOLED(1, "Failed to find INA219 chip");
    while(1) {delay(10);}
  }
  Serial.println("INA219 Current sensor connected!");
  PrintStrOLED(1, "INA219 Connected!");

  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
    PrintStrOLED(1, "...");
  }
  Serial.println("\nWiFi Connected!!");
  PrintStrOLED(1, "WiFi Connected!!");

  ThingSpeak.begin(client);

  for(int i=0; i<5; i++){
    digitalWrite(GREEN_LED, HIGH);
    delay(100);
    digitalWrite(RED_LED, HIGH);
    delay(100);
    digitalWrite(GREEN_LED, LOW);
    delay(100);
    digitalWrite(RED_LED, LOW);
    delay(100);
  }

  digitalWrite(GREEN_LED, HIGH);
  delay(1000);
}

void loop() {
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(WiFi.SSID());
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);
      Serial.print("."); delay(1000);
    }
    Serial.println("WiFi Connected!!!");  
    PrintStrOLED(1, "WiFi Connected!!");
  }

  // 리미트 스위치 상태 확인 => 연료전지 전원 차단(RED LED ON, GREEN LED OFF) 또는 인가(RED LED OFF, GREEN LED ON)
  CheckLimitSwitch();
  delay(1000);

  measurementPower measurement = update_power_display();
  long now = millis();
  if (now - lastConnectionTime > ThingSpeakInterval) {
    SendDataToThingSpeak(measurement.Volt, measurement.mA, measurement.power_mW);
    lastConnectionTime = now;
  }
  delay(1000);
}
