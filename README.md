# RFID Based door unlocker
Ardiuno and RFID Based door unlocker<br/>
#### Components
1. MFRC522
2. LCD 16X2
3. Potentiometer
4. buzzer
5. LEDS - 2
6. Resistors
### Schematic
![](https://i.imgur.com/WMUdyhf.png)
*just for representation use pin out to connect
### Pin outs
#### 1.  MFRC 522
 |Pins| Digital Pins|
 |:---:|:--:|
 |Vcc|3.3V|
 |RST| 9|
 |GND|GND|
 |MISO/SCL/Tx|12|
 |MOSI|11|
 |	SCK|13|
 |SS/SDA/Rx|10|
 #### 2. LCD 
1.  RS pin to digital pin 7
1. Enable pin to digital pin 6
1. D4 pin to digital pin 5
1. D5 pin to digital pin 4
1. D6 pin to digital pin 8
1. D7 pin to digital pin 2
1. R/W pin to GND
1. VSS pin to GND
1. VCC pin to 5V
1. LED+ to 5V through a 220 ohm resisto
1. LED- to GND
#### 3.Connect Buzzer to A5
#### 4.Connect LEDs to A3,A4
### Instructions
First connect the RFID module to the ardiuno.<br/>
Add this library https://github.com/miguelbalboa/rfid to ardiuno ide.<br/>
In examples run the Firmware Check file to know the connections are correct
Rest connect according to the pin out
And run code 


Author: K.Kiran Reddy<br/>
Email: kiranreddykalakota2003@gmail.com

Library Author:miguelbalboa <br/>
Git: https://github.com/miguelbalboa
