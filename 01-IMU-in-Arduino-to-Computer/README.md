# 01-IMU-in-Arduino-to-Computer

This is how to hookup a BNO080 (VR IMU) to a Sparkfun Fio v3 and send data directly to the computer via USB into Max.

> There may be issues with the battery and the fio v3. I haven't had issues yet, but I found this = http://www.forward.com.au/pfod/ArduinoProgramming/FioV3/index.html

### Materials

- Sparkfun Fio v3
  - [pins](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/hardware-overview-fio-v3)
- BNO080
  - [hookup guide](https://learn.sparkfun.com/tutorials/qwiic-vr-imu-bno080-hookup-guide)
  - QWIIC from BNO080 to fio v3:
    - blue to D2
    - yellow to D3
    - red to 3v3
    - black to GND

![circuit](/media/computer-direct.jpeg)
