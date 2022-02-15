# 02-IMU-in-Arduino-through-Xbees-to-Computer

This is how to hookup a BNO080 (VR IMU) to a Sparkfun Fio v3 and send data through Xbees to the computer and into Max.

### Hardware
- Sparkfun Fio v3
  - [pins](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/hardware-overview-fio-v3)
- BNO080
  - [hookup guide](https://learn.sparkfun.com/tutorials/qwiic-vr-imu-bno080-hookup-guide)
  - QWIIC from BNO080 to Fio v3:
    - blue to D2
    - yellow to D3
    - red to 3v3
    - black to GND
- Xbee
  - (2) [XBee 3 Module PCB Antenna](https://www.sparkfun.com/products/15126)
  - (1) [Sparkfun XBee Explorer USB](https://www.sparkfun.com/products/11812)

### Software
- Arduino Code = I used the "Example 1 - Rotation Vector" file from Sparkfun (that came with the library) but I had to change all serial functions in the code to read 'Serial1'
- Max Code = this just gives us the five float values of a complex valued rotation vector, or quaternion

# Xbee setup

I followed [this tutorial](https://learn.sparkfun.com/tutorials/exploring-xbees-and-xctu#configuring-networks)

1. install [FTDI drivers](https://ftdichip.com/drivers/vcp-drivers/)
2. install [XCTU](https://hub.digi.com/support/products/xctu/) (the program that you use to configure the Xbee)
    - I downloaded/installed XCTU v.6.5.8 MacOS X which I updated to 6.5.9 upon first launch
3. launch XCTU and plug in the Xbee attached the Explorer USB attached to the computer
4. <img src="/media/XCTU_add-xbee.png" width="300"> <img src="/media/XCTU_choose-usb.png" width="300">

| Setting  | Acronym | XBee Node1 | XBee Node2 |
| ------------- | ------------- | ------------- | ------------- |
| Channel  | CH  | C | C |
| PAN ID | ID | E557 | E557 |
| Destination Address High | DH | 0 | 0 |
| Destination Address Low | DL | 1 | 0 |
| 16-bit Source Address | MY | 0 |1 |
