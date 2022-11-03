# Electric Current Monitoring Device for Hydrogen Fuel Cell

## [Demonstration]
<a href="https://www.youtube.com/watch?v=nK51Hw02U4Y" target="_blank">
  <img src="https://user-images.githubusercontent.com/24539773/199675720-ab348480-f1a2-4dec-bd7a-c85738e47eb8.png" width="200" height="300" align="left">
</a>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<hr>

## [Materials]

- Board: [Arduino Nano 33 IoT](https://docs.arduino.cc/hardware/nano-33-iot)<br>
    ![Nano 33 IoT](https://user-images.githubusercontent.com/24539773/199675878-0c74c643-eb3e-45c0-8444-b8988ad9c63e.png)

- Battery: 18650 Lithium Polymer Battery(3.6V, 2850mA) x 2 with Holder
    <p><img src="https://user-images.githubusercontent.com/24539773/199676236-7f67ec33-d764-4940-b119-8ede25536cd7.png" width="200" height="170"></p>

- Frame: Aluminum profile (40mmx40mm) with inner braket
    <p><img src="https://user-images.githubusercontent.com/24539773/199676305-f830c8d7-ada7-4f1d-a302-87a730b9ad4e.png" width="410" height="150"></p>

- Din Rail: Din Rail(width: 35mm, length: 230mm) x 2
    <p><img src="https://user-images.githubusercontent.com/24539773/199676420-168f8716-8592-412d-8923-ad88f3cbda1e.png" width="210" height="150"></p>

- MOSFET module: IRF520 x 1
    <p><img src="https://user-images.githubusercontent.com/24539773/199676474-6e7319d6-4cf5-4582-8719-50af9c6f3a77.png" width="" height=""></p>

- Gas container: Syringe(20ml, without needle) x 2 (One for Hydrogen, the other for Oxygen)
    <p><img src="https://user-images.githubusercontent.com/24539773/199676537-722e8005-8d5c-4dda-b6b3-0358a30c7e4a.jpg" width="" height=""></p>

- Switches
    - Limit Switch x 1
        <p><img src="https://user-images.githubusercontent.com/24539773/199676590-3169ae67-6203-41e5-a930-8fd42fd4a95d.PNG" width="" height=""></p>
            
    - On/Off Switch x 1
        <p><img src="https://user-images.githubusercontent.com/24539773/199676636-3cbb31cf-a0fe-4a1b-8f4b-ceb40eb740c0.png" width="" height=""></p>
   
- Breadboards
    - 170 pins x 2
        <p><img src="https://user-images.githubusercontent.com/24539773/199676725-6d18d358-8a53-4761-8aa6-42cc1314d643.png" width="200" height=""></p>
        
    - 400 pins x 1
        <p><img src="https://user-images.githubusercontent.com/24539773/199676786-e5ecfc8b-c5f2-4e8f-a988-babe9306b475.png" width="200" height=""></p>
        
- 3D Printing materials
    <p><img src="https://user-images.githubusercontent.com/24539773/199676830-5adc9346-0b58-417f-819f-64831fb46c86.png" width="200" height=""></p>
    
- Cloud for data collection: [ThingSpeak](https://thingspeak.com/)


## [Schematics]

<p><img src="https://user-images.githubusercontent.com/24539773/199676935-a893b122-c23f-4107-8c47-1ddf29a60303.png" width="400" height=""></p>


## [IDE]
    
- IDE: PlatformIO
    <p><img src="https://user-images.githubusercontent.com/24539773/199676990-d7f82075-0775-4b61-88ef-88ac063ba88d.png" width="400" height=""></p>
    
- Board: NANO 33 IoT
- Framework: Arduino
- External Libraries: WiFiNINA, ThingSpeak, Adafruit INA219, Adafruit SSD1306, Adafruit GFX library
    <p><img src="https://user-images.githubusercontent.com/24539773/199677029-55af4af4-2fb9-4857-9f5c-06cf35b7bf30.png" width="400" height=""></p>

## [Source Code]
- [main.cpp](https://github.com/iispace/IoT/blob/main/Hydrogen_Prod/main.cpp)


