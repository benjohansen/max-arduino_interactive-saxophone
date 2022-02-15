# 01-IMU-in-Arduino-to-Computer

This is how to hookup a BNO080 (VR IMU) to a Sparkfun Fio v3 and send data directly to the computer via USB into Max.

> There may be issues with the battery and the fio v3. I haven't had issues yet, but I found this = http://www.forward.com.au/pfod/ArduinoProgramming/FioV3/index.html

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

### Software
- follow the [hookup guide for the BNO080](https://learn.sparkfun.com/tutorials/qwiic-vr-imu-bno080-hookup-guide)
  - be sure to install the library Sparkfun created using the Arduino IDE library manager to search and install = SparkFun BNO080 Cortex Based IMU
- Arduino Code = I used the "Example 1 - Rotation Vector" file from Sparkfun (that came with the library)
- Max Code = this just gives us the five float values of a complex valued rotation vector, or quaternion

![circuit](/media/computer-direct.jpeg)

Note: I had a lot of problems uploading the Sparkfun Example1-RotationVector sketch to my sparkfun fio v3 because the USB port was not showing up in the Arduino IDE ... most likely because I tried uploading a different sketch for the BNO080 and it had issues which may have messed up the bootloading state ???? I'm really not sure.
Regardless, I fixed it by quickly pressing reset 2 times just to set the right port and quickly uploaded the Blink sketch that ships with the Arduino IDE. I think I may have had to even begin the upload first then press the reset on the fio twice + choose the port before the upload ended.
