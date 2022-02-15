/*
  Using the BNO080 IMU
  By: Nathan Seidle
  SparkFun Electronics
  Date: December 21st, 2017
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14586

  This example shows how to output the i/j/k/real parts of the rotation vector.
  https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation

  It takes about 1ms at 400kHz I2C to read a record from the sensor, but we are polling the sensor continually
  between updates from the sensor. Use the interrupt pin on the BNO080 breakout to avoid polling.

  Hardware Connections:
  Attach the Qwiic Shield to your Arduino/Photon/ESP32 or other
  Plug the sensor onto the shield
  Serial.print it out at 9600 baud to serial monitor.
*/

#include <Wire.h>

#include "SparkFun_BNO080_Arduino_Library.h"
BNO080 myIMU;

const int ledPin = 15; // the pin that the LED is attached to
int incomingByte;      // a variable to read incoming serial data into

const int buttonPin = 1;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status


void setup()
{
  Serial1.begin(9600);
  Serial1.println();
  Serial1.println("BNO080 Read Example");

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  Wire.begin();

  //Are you using a ESP? Check this issue for more information: https://github.com/sparkfun/SparkFun_BNO080_Arduino_Library/issues/16
//  //=================================
//  delay(100); //  Wait for BNO to boot
//  // Start i2c and BNO080
//  Wire.flush();   // Reset I2C
//  IMU.begin(BNO080_DEFAULT_ADDRESS, Wire);
//  Wire.begin(4, 5); 
//  Wire.setClockStretchLimit(4000);
//  //=================================

  if (myIMU.begin() == false)
  {
    Serial1.println("BNO080 not detected at default I2C address. Check your jumpers and the hookup guide. Freezing...");
    while (1);
  }

  Wire.setClock(400000); //Increase I2C data rate to 400kHz

  myIMU.enableRotationVector(50); //Send data update every 50ms

  Serial1.println(F("Rotation vector enabled"));
  Serial1.println(F("Output in form i, j, k, real, accuracy"));
}

void loop()
{
  //Look for reports from the IMU
  if (myIMU.dataAvailable() == true)
  {
    float quatI = myIMU.getQuatI();
    float quatJ = myIMU.getQuatJ();
    float quatK = myIMU.getQuatK();
    float quatReal = myIMU.getQuatReal();
    float quatRadianAccuracy = myIMU.getQuatRadianAccuracy();

    int bstate = 0;

    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);
    
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
     if (buttonState == HIGH) {
       bstate = 1;
      } else {
       bstate = 0;
      }

    Serial1.print(quatI, 2);
    Serial1.print(F(" "));
    Serial1.print(quatJ, 2);
    Serial1.print(F(" "));
    Serial1.print(quatK, 2);
    Serial1.print(F(" "));
    Serial1.print(quatReal, 2);
    Serial1.print(F(" "));
    Serial1.print(quatRadianAccuracy, 2);
    Serial1.print(F(" "));
    Serial1.print(bstate, 2);
    Serial1.print(F(" "));

    Serial1.println();

  }
  

  if (Serial1.available() > 0) {

    // read the oldest byte in the serial buffer:

    incomingByte = Serial1.read();

    // if it's a capital H (ASCII 72), turn on the LED:

    if (incomingByte == 'H') {

      digitalWrite(ledPin, HIGH);

    }

    // if it's an L (ASCII 76) turn off the LED:

    if (incomingByte == 'L') {

      digitalWrite(ledPin, LOW);

    }
  }
}
