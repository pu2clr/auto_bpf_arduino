# Band Pass Filter controlled by Arduino


![Under construction](https://github.com/pu2clr/auto_bpf_arduino/blob/master/images/under_construction.png)

It is a HF band pass filter controlled by Arduino. 
With this project, you can use a set of up to four HF bandpass filters that can be selected by Arduino. 
To do that you will need just two digital Arduino pins. 


## Preface

Originally based on the [“Ensemble RX II (HF/LF) Auto Band Pass Filters“](http://www.wb5rvz.org/ensemble_rx_ii/index) from WB5RVZ, this project uses an Arduino controller instead an ATtiny85. Also, the RF output of the original filter has been modified to be easily attached to the SI4735, AKC6955, KT0915 and others DSP based receivers istead the [SoftRock Ensemble RX II device](http://www.wb5rvz.org/ensemble_rx_ii/index?projectId=16).


### Know more about DSP receivers controlled by Arduino 

1. [PU2CLR Si4735 Library for Arduino](https://pu2clr.github.io/SI4735/). This library was built based on “Si47XX PROGRAMMING GUIDE; AN332” and it has support to FM, AM and SSB modes (LW, MW and SW). It also can be used on all members of the SI47XX family respecting, of course, the features available for each IC version;
2. [PU2CLR SI4844 Arduino Library](https://github.com/pu2clr/SI4844). This is an Arduino library for the SI4844, BROADCAST ANALOG TUNING DIGITAL DISPLAY AM/FM/SW RADIO RECEIVER,  IC from Silicon Labs.  It is available on Arduino IDE. This library is intended to provide an easier interface for controlling the SI4844.
3. [PU2CLR AKC695X Arduino Library](https://pu2clr.github.io/AKC695X/). The AKC695X is a family of IC DSP receiver from AKC technology. The AKC6955 and AKC6959sx support AM and FM modes. On AM mode the AKC6955 and AKC6959sx work on LW, MW and SW. On FM mode they work from 64MHz to 222MHz.
4. [PU2CLR KT0915 Arduino Library](https://pu2clr.github.io/KT0915/). The KT0915 is a full band AM (LW, MW and SW) and FM DSP receiver that can provide you a easy way to build a high quality radio with low cost.
5. [PU2CLR RDA5807 Arduino Library](https://pu2clr.github.io/RDA5807/). The RDA5807 is a FM DSP integrated circuit receiver (50 to 115MHz) with low noise amplifier support. This device requires very few external components if compared with other similar devices. It also supports RDS/RBDS functionalities, direct auto gain control (AGC) and real time adaptive noise cancellation function.
6. [PU2CLR SI470X Arduino Library](https://pu2clr.github.io/SI470X/). It is a Silicon Labs device family that integrates the complete functionalities for FM receivers, including RDS (Si4703).


# SCHEMATIC

The schematic below uses two FST3253 device switches to select one of four bandpass filters. 

![Bandpass filter schematic](https://github.com/pu2clr/auto_bpf_arduino/blob/master/images/schematic_01.png)


L1 e L3: 2.00 uH; 21 turns; wire: #30; Toroid: T30-2(Red)
L2: 0.46uH; 10 Turns; wire #30; Toroid T30-2(Red)

L4 e L6: 1uH; 19 turns; wire #30; Toroid T25-6(Yellow)
L5: 0.27uH: 10 turns; wire #30; Toroid T25-6 c(Yellow)

L7 e L9: 0.46uH: 13 turns; wire #30; Toroid T25-6 (Yellow)
L8: 0.13uH: 7 turns; wire #30;  Toroid T25-6 (Yellow).

T1: 4 turns primary and secondary; wire #30; bifilar, binoculer ferrite BN-43-2402. Inductance of the single winding is 23.04 uH.
