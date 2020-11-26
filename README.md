# Band Pass Filter controlled by Arduino

![Under construction](https://github.com/pu2clr/auto_bpf_arduino/blob/master/images/under_construction.png)

It is a HF band pass filter controlled by Arduino. It is designed for HF receivers. 
With this project, you can use a set of up to four HF bandpass filters that can be selected by Arduino. 
To do that you will need just two digital Arduino pins.

This project includes a bandpass filter design based on [“Softrock Ensemble RX II (HF/LF) Auto Band Pass Filters“](http://www.wb5rvz.org/ensemble_rx_ii/index), an Arduino Library to control the filter, documentation and examples. 

Mr. Jim Regan, W0CHL, did a great job on auto bandpass filter. I recommend his design. Please, check Reagan's documentation on [https://github.com/JimReagans/Si4735-radio-PCB-s-and-bandpass-filter](https://github.com/JimReagans/Si4735-radio-PCB-s-and-bandpass-filter)



Ricardo Lima Caratti, PU2CLR


## Contents 

1. Preface
2. Thanks
3. Schematic
4. Arduino Driver for Auto Band Pass filters
   1. Sketch setup
   2. How to test your filter
5. Photos
6. References


## Preface

Originally based on the [“Softrock Ensemble RX II (HF/LF) Auto Band Pass Filters“](http://www.wb5rvz.org/ensemble_rx_ii/index) from WB5RVZ, this project uses an Arduino controller instead an ATtiny85. Also, the RF output of the original filter has been modified to be easily attached to the SI4735, AKC6955, KT0915 and others DSP based receivers istead the [SoftRock Ensemble RX II device](http://www.wb5rvz.org/ensemble_rx_ii/index?projectId=16). Mr. Jim Regan, W0CHL, did a great job on auto bandpass filter. I recommend his design. Please, check Reagan's documentation on [https://github.com/JimReagans/Si4735-radio-PCB-s-and-bandpass-filter](https://github.com/JimReagans/Si4735-radio-PCB-s-and-bandpass-filter). Here you will find Arduino code and some experiments with this auto bandpass filter. 


### Know more about DSP receivers controlled by Arduino 

1. [PU2CLR Si4735 Library for Arduino](https://pu2clr.github.io/SI4735/). This library was built based on “Si47XX PROGRAMMING GUIDE; AN332” and it has support to FM, AM and SSB modes (LW, MW and SW). It also can be used on all members of the SI47XX family respecting, of course, the features available for each IC version;
2. [PU2CLR SI4844 Arduino Library](https://github.com/pu2clr/SI4844). This is an Arduino library for the SI4844, BROADCAST ANALOG TUNING DIGITAL DISPLAY AM/FM/SW RADIO RECEIVER,  IC from Silicon Labs.  It is available on Arduino IDE. This library is intended to provide an easier interface for controlling the SI4844.
3. [PU2CLR AKC695X Arduino Library](https://pu2clr.github.io/AKC695X/). The AKC695X is a family of IC DSP receiver from AKC technology. The AKC6955 and AKC6959sx support AM and FM modes. On AM mode the AKC6955 and AKC6959sx work on LW, MW and SW. On FM mode they work from 64MHz to 222MHz.
4. [PU2CLR KT0915 Arduino Library](https://pu2clr.github.io/KT0915/). The KT0915 is a full band AM (LW, MW and SW) and FM DSP receiver that can provide you a easy way to build a high quality radio with low cost.
5. [PU2CLR RDA5807 Arduino Library](https://pu2clr.github.io/RDA5807/). The RDA5807 is a FM DSP integrated circuit receiver (50 to 115MHz) with low noise amplifier support. This device requires very few external components if compared with other similar devices. It also supports RDS/RBDS functionalities, direct auto gain control (AGC) and real time adaptive noise cancellation function.
6. [PU2CLR SI470X Arduino Library](https://pu2clr.github.io/SI470X/). It is a Silicon Labs device family that integrates the complete functionalities for FM receivers, including RDS (Si4703).


# SCHEMATIC

The schematic below uses two [FST3253](https://www.mouser.com/datasheet/2/149/FST3253-113358.pdf) or two [SN74CBT3253D](https://www.ti.com/lit/ds/symlink/sn74cbt3253.pdf?HQS=TI-null-null-mousermode-df-pf-null-wwe&ts=1596797600884&ref_url=https%253A%252F%252Fbr.mouser.com%252F) device switches to select one of four bandpass filters. 

![Bandpass filter schematic](https://github.com/pu2clr/auto_bpf_arduino/blob/master/images/schematic_01.png)

* Filter 0 (180KHz to 4MHz )
  * L1 and L3: 5.5 uH; 35 turns; wire: #30; Toroid: T30-2(Red) 
  * L2: 2.6uH; 24 Turns; wire #30; Toroid T30-2(Red)

* Filter 1 (4MHz to 8MHz)
  * L4 and L6: 2.00 uH; 21 turns; wire: #30; Toroid: T30-2(Red)
  * L5: 0.46uH; 10 Turns; wire #30; Toroid T30-2(Red)

* Filter 2 (16MHz to 16MHz)
  * L7 and L9: 1uH; 19 turns; wire #30; Toroid T25-6(Yellow)
  * L8: 0.27uH: 10 turns; wire #30; Toroid T25-6 c(Yellow)

* Filter 3 (16MHz to 30MHz)
  * L10 and L12: 0.46uH: 13 turns; wire #30; Toroid T25-6 (Yellow)
  * L11: 0.13uH: 7 turns; wire #30;  Toroid T25-6 (Yellow).


## Arduino Driver for Auto Band Pass filters



## Photos



## References

1. [SN74CBT3253DUAL 1-OF-4 FET MULTIPLEXER/DEMULTIPLEXER](https://www.ti.com/lit/ds/symlink/sn74cbt3253.pdf?HQS=TI-null-null-mousermode-df-pf-null-wwe&ts=1596797600884&ref_url=https%253A%252F%252Fbr.mouser.com%252F)
2. [FST3253Dual 4:1 Multiplexer/Demultiplexer Bus Switch](https://www.mouser.com/datasheet/2/149/FST3253-113358.pdf)
3. [Constant-K LC Band Pass Filter Circuit Design & Calculations](https://www.electronics-notes.com/articles/radio/rf-filters/constant-k-simple-bandpass-lc-rf-filter-design-calculations.php)
4. [LC Filters Design Tool](https://rf-tools.com/lc-filter/)
5. [Bandpass LC Filters](https://youtu.be/mv_T6eBp3Lk)
6. [Ensemble RX II (HF/LF)](http://www.wb5rvz.org/ensemble_rx_ii/index)
7. [Ensemble RX II (HF/LF) Auto Band Pass Filters](http://www.wb5rvz.org/ensemble_rx_ii/05_bpf)
