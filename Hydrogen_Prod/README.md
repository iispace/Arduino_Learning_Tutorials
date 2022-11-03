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
    <p><img src="Pics/Dinrail.png" width="210" height="150"></p>

- MOSFET module: IRF520 x 1
    <p><img src="Pics/Mosfet_module.png" width="" height=""></p>

- Gas container: Syringe(20ml, without needle) x 2 (One for Hydrogen, the other for Oxygen)
    <p><img src="Pics/Syringe.jpg" width="" height=""></p>

- Switches
    - Limit Switch x 1
        <p><img src="Pics/Limit_Switch.png" width="" height=""></p>
    - On/Off Switch x 1
        <p><img src="Pics/OnOff_Switch.png" width="" height=""></p>

- Breadboards
    - 170 pins x 2
        <p><img src="Pics/BB170.png" width="200" height=""></p>
    - 400 pins x 1
        <p><img src="Pics/BB400.png" width="200" height=""></p>

- 3D Printing materials
    <p><img src="Pics/3DPrintings.png" width="200" height=""></p>

- White faced hardboardsheet
    <p><img src="Pics/WhiteFormBoard.png" width="400" height=""></p>

- Cloud for data collection: [ThingSpeak](https://thingspeak.com/)


## [Schematics]

<p><img src="Pics/schematic.png" width="400" height=""></p>

## [IDE]
    
- IDE: PlatformIO
    <p><img src="Pics/platformIO.png" width="400" height=""></p>

- Board: NANO 33 IoT
- Framework: Arduino
- External Libraries: WiFiNINA, ThingSpeak, Adafruit INA219, Adafruit SSD1306, Adafruit GFX library
    <p><img src="Pics/external_lib.png" width="400" height=""></p>

## [Source Code]
- [main.cpp](https://github.com/iispace/IoT/blob/main/Hydrogen_Prod/main.cpp)


