#include <Arduino.h>
#include <Adafruit_ADS1X15.h>
#include <SPI.h>
#include <LCDWIKI_GUI.h>  // Core graphics library
#include <LCDWIKI_SPI.h>  // Hardware-specific library

Adafruit_ADS1115 ads1115;  /* Use this for the 16-bit version */
//Adafruit_ADS1015 ads;     /* Use this for the 12-bit version */

#define MODEL ST7735S128
#define CS 8    // Connect TFT_LCD CS pin to Arduino Uno D8
#define RST 10  // Connect TFT_LCD RST pin to Arduino Uno D10
#define CD A3   // (CD means RS) Connect TFT_LCD CD pin to Arduino Uno A3
//#define LED A0 //if you don't need to control the LED pin,you should set it to -1 and set it to 3.3V
#define LED 9 //-1 //if you don't need to control the LED pin,you should set it to -1 and set it to 3.3V

LCDWIKI_SPI my_lcd(MODEL,CS,CD, RST,LED); //model,cs,dc,reset,led

unsigned long show_text_frame(void)
{
  unsigned long time_start = micros();
    //my_lcd.Set_Draw_color(32, 0,255); // blue
    my_lcd.Set_Draw_color(195, 0,255); // purple
    my_lcd.Fill_Rectangle(0, 0, my_lcd.Get_Display_Width()-1, 10);
    my_lcd.Set_Text_colour(0, 255, 0); // green  
    my_lcd.Set_Text_Size(1);
    my_lcd.Set_Text_Mode(1);
    //my_lcd.Print_String("* Color TFT Display *", CENTER, 2);
    my_lcd.Print_String("* Light Sensor TEMP6000 *", CENTER, 2);

    my_lcd.Set_Draw_color(128, 128, 128);
    my_lcd.Fill_Rectangle(0, my_lcd.Get_Display_Height()-1-10, my_lcd.Get_Display_Width()-1, my_lcd.Get_Display_Height()-1);
    my_lcd.Set_Text_colour(255, 255, 255);   
    my_lcd.Set_Text_Size(1);
    my_lcd.Set_Text_Mode(1);
    my_lcd.Print_String("<www.lcdwiki.com>", CENTER, my_lcd.Get_Display_Height()-9);

    my_lcd.Set_Draw_color(255,255,0); 
    my_lcd.Draw_Rectangle(0, 11, my_lcd.Get_Display_Width()-1, my_lcd.Get_Display_Height()-1-11);   
    return micros() - time_start;
}


void setup(){

  pinMode(CS, INPUT);

  my_lcd.Init_LCD();
  my_lcd.Fill_Screen(0x0);
  my_lcd.Set_Rotation(1);

  Serial.begin(9600);
  Serial.println("Hello!");
  Serial.println("Getting single-ended reading from Light Sensor TEMP 6000");
  
  ads1115.begin();   // begin ADS1115 with its default I2C Address (0x48) // ADS1115 모듈의 기본 주소인 0x48을 사용하여 장치 시작
  
}

void loop(){

  my_lcd.Fill_Screen(0x0);
  show_text_frame();

  int line_no = 1;
  
  int16_t adc0;

  adc0 = ads1115.readADC_SingleEnded(0);
  float ratio = float(adc0) / 65535.0;
  float square_ratio = pow(ratio, 2.0);
  float volts0 = ads1115.computeVolts(adc0);

  String reading_str = "Intensity:";
  my_lcd.Set_Text_colour(255, 165, 0);   
  my_lcd.Set_Text_Size(1);
  my_lcd.Set_Text_Mode(1);
  my_lcd.Print_String(reading_str, (my_lcd.Get_Display_Width()-120)/2-1, (my_lcd.Get_Display_Height()-96)/2+line_no*8-1);
  my_lcd.Set_Text_colour(0, 255, 0); 
  int x_offset = 60;
  int y_offset = 96;
  my_lcd.Print_Number_Int(adc0, (my_lcd.Get_Display_Width()-120)/2-1+x_offset, (my_lcd.Get_Display_Height()-y_offset)/2+line_no*10-1, 0, ' ', 10);

  line_no += 1;
  my_lcd.Set_Text_colour(255, 165, 0);
  my_lcd.Print_String("volt:", (my_lcd.Get_Display_Width()-120)/2-1, (my_lcd.Get_Display_Height()-y_offset)/2+line_no*8-1);
  my_lcd.Set_Text_colour(0, 255, 0); 
  my_lcd.Print_Number_Int(volts0, (my_lcd.Get_Display_Width()-120)/2-1+x_offset, (my_lcd.Get_Display_Height()-y_offset)/2+line_no*10-1, 0, ' ', 10);   

  line_no += 1;
  my_lcd.Set_Text_colour(255, 165, 0);
  my_lcd.Print_String("ratio:", (my_lcd.Get_Display_Width()-120)/2-1, (my_lcd.Get_Display_Height()-y_offset)/2+line_no*8-1);
  my_lcd.Set_Text_colour(0, 255, 0); 
  my_lcd.Print_Number_Float(ratio, 2, (my_lcd.Get_Display_Width()-120)/2-1+x_offset-6, (my_lcd.Get_Display_Height()-y_offset)/2+line_no*10-1, '.', 5,' ');   

  Serial.print("reading: "); Serial.print(adc0); 
  Serial.print(", ratio: "); Serial.print(ratio);
  Serial.print(", square_ratio: "); Serial.println(square_ratio);
  
  delay(2000);
}
