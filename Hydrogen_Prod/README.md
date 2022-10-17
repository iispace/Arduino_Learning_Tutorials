# Hydrogen Production using Solar Cell 


## 1. Materials
 - Board: [Arduino Nano 33 IoT](https://store-usa.arduino.cc/products/arduino-nano-33-iot) x 1 
   <br><center><img src="https://user-images.githubusercontent.com/24539773/196139174-9f35df38-fccd-4a61-90d6-cf9083055df7.png" width="400" height="150"></center>


 - Solar Cell: 12V 430mA (165mm x 210mm) x 1
   <br>![image](https://user-images.githubusercontent.com/24539773/196139610-4e6d90d5-6e4b-46d4-8e78-0af7e12ff71a.png)

 -  Potentiometer: Slide potentiometer(10Kohm, 60mm) x 2
    <br><center><img src="https://user-images.githubusercontent.com/24539773/196139798-0f99e40f-3033-4aea-8e89-70e18fa872e2.png" width="300" height="150"></center>

 -  Battery: 18650 Lithium polymer battery (3.65V, 2850mAh) x 1
 -  Frame: Aluminum profile(40mm x 40mm) 
 -  Serve motor: MG996R (180 degree) x 2
 -  MOSFET module: IRF520 x 1
    <br><center><img src="https://user-images.githubusercontent.com/24539773/196126013-d468d98e-1329-424f-954f-2957cacb88dc.png" width="200" height="200"></center>
 -  Capacitor: (470uF, 16V) x x
 -  Gas container: 20ml Syringe without needle x 2 (One for hydrogen, the other for oxgen)
 -  Limit Switch: Micro Limit Switch (20mm x 10mm x 4mm) x 1
    <br>![image](https://user-images.githubusercontent.com/24539773/196125048-a510d89f-af0a-44c9-9fc9-8f59de2e4870.png)

 -  Cloud for data collection: ThingSpeak
 -  BreadBoard: mini breadboard(170 pins) x 2, breadboard(400 pins) x 1 

## 2. Schematics
<br><center><img src="https://user-images.githubusercontent.com/24539773/196136024-046e4035-a7d5-4530-87c1-c7475ac1a868.png" width="800" height="500"></center>
<br><center><img src="https://user-images.githubusercontent.com/24539773/196137880-42384489-6d44-42a2-8436-636a1aa5b105.png" width="900" height="500"></center>


## 3. IDE
- IDE: PlatformIO
  <br><center><img src="https://user-images.githubusercontent.com/24539773/196131306-1eaf5d87-9d2f-4f19-916e-f541fe38f737.png" width="300" height="200"></center>
- Board: NANO 33 IoT
- Framework: Arduino
- External Libraries: Servo, ThingSpeak, WiFiNINA
  <br><center><img src="https://user-images.githubusercontent.com/24539773/196130832-361869a0-7b5f-4159-92f5-91269914a8f6.png" width="850" height="400"></center>

## 4. Source code
- [main.cpp](https://github.com/iispace/IoT/blob/main/Hydrogen_Prod/main.cpp)
