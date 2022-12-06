#include <Arduino.h>
#include <Adafruit_ADS1X15.h>
#include <SPI.h>

Adafruit_ADS1115 ads1115;   /* Use this for the 16-bit version */
//Adafruit_ADS1015 ads;     /* Use this for the 12-bit version */

void setup(){
  Serial.begin(9600);
  Serial.println("Jello!");
  Serial.println("Getting single-ended reading from Light Sensor TEMP 6000");
  ads1115.begin();
}

void loop(){
  int16_t adc0;

  adc0 = ads1115.readADC_SingleEnded(0);
  float ratio = float(adc0) / 65535.0;
  float square_ratio = pow(ratio, 2.0);

  Serial.print("reading: "); Serial.print(adc0); 
  Serial.print(", ratio: "); Serial.print(ratio);
  Serial.print(", square_ratio: "); Serial.println(square_ratio); // Square the value to make more obvious (읽어들인 값의 의미가 더 잘 드러나도록 제곱한 값을 표시함)
  
  delay(2000);
}
