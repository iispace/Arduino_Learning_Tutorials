# STM32T103

<img width="489" height="520" alt="image" src="https://github.com/user-attachments/assets/3569231b-610d-4ff9-bb44-a57b0939febb" />

# Pinout

![The-Generic-STM32F103-Pinout-Diagram](https://github.com/user-attachments/assets/4c5665d7-aeef-4bf2-8cc6-63e62f13f4b3)


# Schematic

<img width="1169" height="827" alt="Schematic_STM32F103" src="https://github.com/user-attachments/assets/b37b6b3f-e939-4007-9320-86d26f903ba1" />



# Arduino VS STM32uino(Blue pill)

|Feature|Uno|STM32F103|Comments|
|:-:|:-:|:-:|:-:|
|MPU|ATMega328|STM32F103C8T6(Cortex M3)||
|Flash(KB)|32|64/128*|*128 in some models|
|SRAM(KB)|2|20||
|EEPROM(KB)|1|None||
|MPC Frequency(MHz)||72||
|Bus Width(bits)|8|32||
|UARTs(HW)|1|3||
|SPI|1|2||
|I<sup>2</sup>C|1|2||
|CAN||1||
|Timers|2(8 bits) + 1(16 bits)|3(16 bits) + 1 (advanced type)||
|Other||32.768KHz RTC crystal clock||
|ADC|10 bits(0 ~ 1023)|12 bits (0 ~ 4095)|Arduino UNO can use internal ADC reference(Aref), but the Blue pill uses VCC reference. Thus, [UNO can be more accurate](#ref1)|

<hr>

<a id="ref1"></a> 
# How to calculate ADC?

- ADC는 입력 전압을 기준전압(Vref)에 대한 비율로 계산하여 디지털 값으로 변환
- UNO는 analogReference() 함수를 통해 외부 Aref, 내부 1.1V 밴드갭, Vcc 중 하나를 기준전압으로 선택할 수 있고, Blue pill(STM103x)은 기본적으로 Vdda(Vcc = 3.3V), 즉 공급전압을 ADC 변환 기준전압으로 바로 사용
- UNO는 내부 1.1V 밴드갭 또는 Aref를 기준전압으로 사용할 수 있으므로 Vref의 값이 비교적 안정적이지만, STM103x는 0 ~ 3.3V 범위로 입력되는 전압을 그대로 Vref로 사용하기 때문에 공급(입력) 전압이 달라지면 Vref도 그만큼 변동됨. 즉, 외부 전원에 따라 변동하거나 노이즈가 섞일 수 있음.
- Vref가 변동하거나 노이즈가 섞이게 되면 ADC 측정값에 오차가 발생할 수 있으므로, 12-bit 분해능을 제공하는 STM103x 보다 오히려 10-bit 분해능을 가진 UNO가 ADC 변환은 더 정확할 수 있음. (단, STM103x에서도 내부 밴드갭 기준 전압인 Vrefint(약 1.2V)가 존재하므로, 이를 이용해 Vref의 변동이 크지 않도록 보정을 하게 되면 ADC 오차를 줄일 수 있음)
  - AVR 10-bit(UNO): ADC = round(Vin / Vref) * 1023, (Vref: Aref, 2<sup>10</sup> - 1 = 1023)
  - STM32 12-bit(Blue pill): ADC = round(Vin / Vref) * 4095, (Vref: Vdda, 2<sup>12</sup> - 1 = 4095)
  

<br>

# 프로그램 업로드 방법

- USB-TTL 사용

  <img width="472" height="486" alt="image" src="https://github.com/user-attachments/assets/5804a254-ac15-47b1-b957-1b6ed516b8ba" />
  <img width="498" height="486" alt="image" src="https://github.com/user-attachments/assets/d9bc7344-3abb-4f79-b39c-9ffcf0959dcd" />
  <img width="928" height="694" alt="image" src="https://github.com/user-attachments/assets/e231a3e6-27c7-4f9a-a8e5-c5ac065f1bdd" />
  
- ST-LINK V2 사용

  <img width="757" height="550" alt="image" src="https://github.com/user-attachments/assets/25d45562-c982-40f3-a642-1a6b0837cd49" />
  <img width="514" height="697" alt="image" src="https://github.com/user-attachments/assets/52b5ac31-70a7-45bb-a73f-bdbcf72eb11d" />
  



<hr>

# Reference

[1] [Source of pinout image and schematic](https://oshwlab.com/r3bers/STM32F103C8T6-Test-Board)

[2] [Converting an STM32F103 board to a Black Magic Probe](https://medium.com/@paramaggarwal/converting-an-stm32f103-board-to-a-black-magic-probe-c013cf2cc38c)
