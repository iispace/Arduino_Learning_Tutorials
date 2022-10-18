# Hydrogen Production using Solar Cell 

## Demonstration
<br>[<center><img src="https://user-images.githubusercontent.com/24539773/196377972-527d2924-88d5-4b47-9260-29a7a02c319b.png" width="70" height="120"></center>](https://user-images.githubusercontent.com/24539773/196376279-32f31e34-47ea-4e26-a1ec-ab6935458446.mp4)


## 1. Materials
 - Board: [Arduino Nano 33 IoT](https://store-usa.arduino.cc/products/arduino-nano-33-iot) x 1 
   <br><center><img src="https://user-images.githubusercontent.com/24539773/196139174-9f35df38-fccd-4a61-90d6-cf9083055df7.png" width="200" height="80"></center>


 - Solar Cell: 12V 430mA (165mm x 210mm) x 1
   <br>![image](https://user-images.githubusercontent.com/24539773/196139610-4e6d90d5-6e4b-46d4-8e78-0af7e12ff71a.png)

 -  Potentiometer: Slide potentiometer(10Kohm, 60mm) x 2
    <br>![image](https://user-images.githubusercontent.com/24539773/196350969-8646e479-9e8a-47fc-9b25-ee3d71f4157f.png)

 -  Battery: 18650 Lithium polymer battery (3.65V, 2850mAh) x 1, 18650 Battery holder x 1
    <br>![image](https://user-images.githubusercontent.com/24539773/196349785-b9a09ef9-d343-412e-a822-a2fdb1dd49be.png)


 -  Frame: Aluminum profile(size of 40mm x 40mm, Length 300mm x 1, 150mm x 1 ) and two inner brakets 
    <br>![image](https://user-images.githubusercontent.com/24539773/196350311-7adfaa03-97c6-4c93-b4c9-c62e0cd8cbb3.png)
    
 -  Frame: Din Rail (Length: 230mm)
    <br>![image](https://user-images.githubusercontent.com/24539773/196353980-31e0c2aa-33df-4bc7-980d-269f3ed3f85c.png)


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
    <br>![image](https://user-images.githubusercontent.com/24539773/196352560-17552857-d3d2-477f-96f2-989258d99ee5.png)

 -  On/Off switch
    <br><center><img src="https://user-images.githubusercontent.com/24539773/196354352-5f242a60-c9c4-473d-8d55-353b666bb7b5.png" width="100" height="90"></center>

 -  Cloud for data collection: ThingSpeak
 -  BreadBoard: mini breadboard(170 pins) x 2, breadboard(400 pins) x 1 
    <br><center><img src="https://user-images.githubusercontent.com/24539773/196348869-1e9d2e9c-a9f2-4d7d-b831-109af46239d8.png" width="400" height="150"></center>

 -  3D Printing materials
    <br>![image](https://user-images.githubusercontent.com/24539773/196356253-ee5e9109-9289-4f88-8111-bd555e74a5ee.png)
    
  -  White faced hardboardsheet
     <br>![image](https://user-images.githubusercontent.com/24539773/196353788-55b3b72c-7d84-47ef-b806-3e516b995f52.png)



## 2. Schematics
<br><center><img src="https://user-images.githubusercontent.com/24539773/196371457-1cb8d361-acf9-4144-a707-81acd359aa04.png" width="800" height="400"></center>
The circuit figure below shows only a general idea of the wire connection of the above schematics except for the battery charging parts and another solar cell attached to hydrogen fuel cell. (The circuit figure was created on Thinkercad.com)
<br><center><img src="https://user-images.githubusercontent.com/24539773/196358283-7389504e-3d19-4e49-b7f1-f55cd1048d6f.png" width="700" height="400"></center>


## 3. IDE
- IDE: PlatformIO
  <br><center><img src="https://user-images.githubusercontent.com/24539773/196131306-1eaf5d87-9d2f-4f19-916e-f541fe38f737.png" width="300" height="200"></center>
- Board: NANO 33 IoT
- Framework: Arduino
- External Libraries: Servo, ThingSpeak, WiFiNINA
  <br><center><img src="https://user-images.githubusercontent.com/24539773/196130832-361869a0-7b5f-4159-92f5-91269914a8f6.png" width="850" height="400"></center>

## 4. Source code
- [main.cpp](https://github.com/iispace/IoT/blob/main/Hydrogen_Prod/main.cpp)
