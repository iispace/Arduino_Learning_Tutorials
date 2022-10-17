#include <Arduino.h>
#include <Servo.h>
#include <ThingSpeak.h>
#include <WiFiNINA.h>

#define servoV 10
#define servoH 9
#define LIMITSW 8
#define MOSFET 7

Servo horizontal;
Servo vertical;
WiFiClient client;

// LDR pin connection
int ldrlt = 0;
int ldrld = 1;
int ldrrt = 2;
int ldrrd = 3;

//WiFi Connection Info
char ssid[] = "SSID";
char pass[] = "PASSWORD";
unsigned long ChannelNumber = ThingSpeak_ChannelNumber;
const char* APIKey = "THINGSPEAK_WRITEAPIKEY";
int keyIndex = 0; // your network key index number (needed only for WEP)

// Servo motors' initial angle
int servoh = 90;
int servov = 90;
///
void GetVerticalAngle(int _avt, int _avd, int _dvert, int _tol){
    // check if the diffirence is in the tolerance else change vertical angle
    if (-1*_tol > _dvert || _dvert > _tol) {
        if (_avt > _avd)
        {
            servov = ++servov;
            if (servov > 180) 
            { 
                servov = 180;
            }
        }
        else if (_avt < _avd)
        {
            servov= --servov;
            if (servov < 0)
            {
                servov = 0;
            }
        }
    }
}
  
void GetHorizontalAngle(int _avl, int _avr, int _dhoriz, int _tol){
// check if the diffirence is in the tolerance else change horizontal angle
  if (-1*_tol > _dhoriz || _dhoriz > _tol) 
  {
    if (_avl > _avr)
    {
      servoh = --servoh;
      if (servoh < 0)
      {
      	servoh = 0;
      }
    }
    else if (_avl < _avr)
    {
      servoh = ++servoh;
       if (servoh > 180)
       {
       	servoh = 180;
       }
    }
    else if (_avl = _avr)
    {
      // do nothing
    }  
  }
}

int CheckLimitSwitch(){
  int swValue = digitalRead(LIMITSW);
  Serial.println("****************************************");
  Serial.print("LIMIT Switch is "); Serial.println(swValue);
  Serial.println("****************************************");
  delay(100);
  // The default setting of the Limit Switch is COM-NC, which means normal value of Limist switch is HIGH.
  // When the Limit switch is in normal state, send HIGH signal to the MOSFET so that electric current can flow to Hydrogen fuel cell.
  // When the Limit switch is pushed, the value is changed to LOW from HIGH and this time send LOW signal to the MOSFET to cut off the electric current to Hydrogen fuel cell.
  if(swValue == LOW){         
    digitalWrite(MOSFET, LOW);  // (COM - NO)
    Serial.println("MOSFET OFF");
  }
  else if (swValue == HIGH){    // (COM - NC)
    digitalWrite(MOSFET, HIGH);
    Serial.println("MOSFET ON");
  }
  return swValue;
}

void SendDataToThingSpeak(int value){
  ThingSpeak.setField(1, value);  // set value of Field No. 1 in the ThingSpeak Channel. 
  int x = ThingSpeak.writeFields(ChannelNumber, APIKey);
  if (x == 200){
    Serial.println("Channel update successful");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code: " + String(x));
  }
}


void setup() {
  pinMode(LIMITSW, INPUT);
  pinMode(MOSFET, OUTPUT);
  
  Serial.begin(9600);
  WiFi.begin(ssid, pass);

  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
  }

  while(!Serial);  // for debugging only.  Comment out this line for production

  Serial.println("\nWiFi Connected!!");
  ThingSpeak.begin(client);
  
  vertical.attach(servoV); 
  vertical.write(90);    // == vertical.writeMicroseconds(1500);
  delay(15);
  horizontal.attach(servoH);
  horizontal.write(90); // == horizontal.writeMicroseconds(1500);
  delay(2000);
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
  }
  // Check out status of the Limit Switch to cut out or to flow electric current to Hydrogen fuel cell.
  int value = CheckLimitSwitch();

  // Send certain value(i.e., 100 in this example) to ThingSpeak if Limit switch is pushed.
  /* !!! CAUTION !!! 
     The minimum interval for sending data to ThingSpeak is 20 seconds (20000 in millseconds).
     Therefore, do not push the Limit switch within 20 secondds again!!! 
  */
  
  if (value == 0){
    int valueToSend = 100;
    SendDataToThingSpeak(valueToSend);
  }

  // Read LDR sensors values
  int lt = analogRead(ldrlt);
  int ld = analogRead(ldrld);
  int rt = analogRead(ldrrt);
  int rd = analogRead(ldrrd);

  // Serial.println("===========================================");
  // Serial.print("ldrlt: "); Serial.print(lt); Serial.print(", ");
  // Serial.print("ldrld: "); Serial.print(ld); Serial.print(", ");
  // Serial.print("ldrrt: "); Serial.print(rt); Serial.print(", ");
  // Serial.print("ldrrd: "); Serial.print(rd); Serial.println();

  delay(50);

  //int dtime = analogRead(4) / 20;  // delay time per loop. Remove comment mark if you install a potentiometer to A4 pin and comment out the very next line. 
  int dtime = 20;
  //int tol = analogRead(5) / 4;     // tolerance of LDR sensor to activate servo. Remove comment mark if you install a potentiometer to A5 pin and comment out the very next line.
  int tol = 50;

  // Serial.print("dtime: "); Serial.print(dtime); Serial.print(", ");
  // Serial.print("tol: "); Serial.print(tol); Serial.println();
  // Serial.println("--------------------------------------------");

  delay(50);
  
  // average of LDR values for each direction (UP, DOWN, LEFT, RIGHT)
  int avt = (lt + rt) / 2; // average LDR values of UP direction
  int avd = (ld + rd) / 2; // average LDR values of DOWN direction
  int avl = (lt + ld) / 2; // average LDR values of LEFT direction
  int avr = (rt + rd) / 2; // average LDR values of RIGHT direction

  int dvert = avt - avd; // Difference betwwen UP and DOWN
  int dhoriz = avl - avr;// Difference between LEFT and RIGHT

  //Serial.print("(avt: "); Serial.print(avt); Serial.print(",  "); Serial.print("avd: "); Serial.print(avd); Serial.print("),  ");  
  //Serial.print("(avl: "); Serial.print(avl); Serial.print(",  "); Serial.print("avr: "); Serial.print(avr); Serial.println(")");
  //Serial.print("dvert: "); Serial.print(dvert); Serial.print(", "); Serial.print("dhoriz: "); Serial.println(dhoriz); 
  //Serial.println("--------------------------------------------");

  GetVerticalAngle(avt, avd, dvert, tol);
  vertical.write(servov);
  Serial.print("servov = ");Serial.println(servov);
  
  GetHorizontalAngle(avl, avr,dhoriz, tol);
  horizontal.write(servoh);
  Serial.print("servoh = ");Serial.println(servoh);Serial.println();
  
  delay(dtime); 
}
