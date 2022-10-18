# Hydrogen Production using Solar Cell 


## 1. Materials
 - Board: [Arduino Nano 33 IoT](https://store-usa.arduino.cc/products/arduino-nano-33-iot) x 1 
   <br><center><img src="https://user-images.githubusercontent.com/24539773/196139174-9f35df38-fccd-4a61-90d6-cf9083055df7.png" width="350" height="150"></center>


 - Solar Cell: 12V 430mA (165mm x 210mm) x 1
   <br>![image](https://user-images.githubusercontent.com/24539773/196139610-4e6d90d5-6e4b-46d4-8e78-0af7e12ff71a.png)

 -  Potentiometer: Slide potentiometer(10Kohm, 60mm) x 2
    <br><center><img src="https://user-images.githubusercontent.com/24539773/196139798-0f99e40f-3033-4aea-8e89-70e18fa872e2.png" width="300" height="150"></center>

 -  Battery: 18650 Lithium polymer battery (3.65V, 2850mAh) x 1, 18650 Battery holder x 1
    <br><center><img src="https://user-images.githubusercontent.com/24539773/196142917-96c628a4-c243-45d7-97d8-1ee9a2eac63f.png" width="180" height="130"></center>
    <br>![image](https://user-images.githubusercontent.com/24539773/196143255-030dae8d-5aaf-44dc-a31b-cfddcaa98608.png)


 -  Frame: Aluminum profile(size of 40mm x 40mm, Length 300mm x 1, 150mm x 1 ) and two inner brakets 
    <br>![image](https://user-images.githubusercontent.com/24539773/196143647-7780ec18-cb9c-42e8-8c5e-1da83c12dcef.png)
    <br>![image](https://user-images.githubusercontent.com/24539773/196342645-c2c19511-9486-40a7-9dfa-8e017d8fcdb0.png)

 -  Serve motor: MG996R (180 degree) x 2
    <br>![image](https://user-images.githubusercontent.com/24539773/196140738-d56a92d2-846e-47ed-a68b-455eb37a92dd.png)
    <br><center><img src="https://user-images.githubusercontent.com/24539773/196348289-68f05b2b-3754-41da-ab18-15733a44907c.png" width="600" height="200"></center>


 -  MOSFET module: IRF520 x 1
    <br><center><img src="https://user-images.githubusercontent.com/24539773/196126013-d468d98e-1329-424f-954f-2957cacb88dc.png" width="200" height="200"></center>
 -  Capacitor: (470uF, 16V) x 2
    <br>![image](https://user-images.githubusercontent.com/24539773/196141943-f7f55970-9b65-4627-8c66-d29f4d0bb8db.png)

 -  Gas container: 20ml Syringe without needle x 2 (One for hydrogen, the other for oxgen)
    <br>![image](https://user-images.githubusercontent.com/24539773/196142093-68618e82-0b3f-4c0b-a6c3-c265447f8009.png)

 -  Limit Switch: Micro Limit Switch (20mm x 10mm x 4mm) x 1
    <br>![image](https://user-images.githubusercontent.com/24539773/196125048-a510d89f-af0a-44c9-9fc9-8f59de2e4870.png)
    <br>![image](https://user-images.githubusercontent.com/24539773/196144259-121463aa-755d-4f15-8f19-072e7159a8f2.png)


 -  Cloud for data collection: ThingSpeak
 -  BreadBoard: mini breadboard(170 pins) x 2, breadboard(400 pins) x 1 
    <br><center><img src="https://user-images.githubusercontent.com/24539773/196348869-1e9d2e9c-a9f2-4d7d-b831-109af46239d8.png" width="600" height="200"></center>

 -  3D Printing materials
    <br>![image](https://user-images.githubusercontent.com/24539773/196142578-59014d55-f3eb-4a76-bcc3-9f58dda46296.png)


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
