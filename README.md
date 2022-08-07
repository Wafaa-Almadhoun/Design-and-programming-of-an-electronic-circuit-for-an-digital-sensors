# Design-and-programming-of-an-electronic-circuit-for-an-digital-sensors



## Table of contents
* [Introduction](#Introduction)
* [Technologies](#technologies)
* [Components required](#Components-required)
* [Connections](#Connections)
* [Block diagram & simulation ](#Block-diagram-&-simulation)



## Introduction
This projects is to learn about several types of digital sensors and understand their scientific principle, 
operation and programming with Arduino ,We will cover several types : 👍 

 1. Ultrasonic Sensor
 2. MPU6050 Gyro Sensor 
 
   ###  Ultrasonic Sensor
   
        The HC-SR04 ultrasonic sensor uses SONAR to determine the distance of an object just like the bats do.
	It offers excellent non-contact range detection with high accuracy and stable readings in 
	an easy-to-use package from 2 cm to 400 cm or 1” to 13 feet.
         
	 The operation is not affected by sunlight or black material, although acoustically, 
	 soft materials like cloth can be difficult to detect. It comes complete with ultrasonic
	 transmitter and receiver module.



   ### MPU6050 Gyro Sensor
       
       MPU6050 sensor has many functions over the single chip. It consists a MEMS accelerometer, a MEMS gyro, 
       and temperature sensor. This module is very accurate while converting analog values to digital because
       it has a 16bit analog to digital converter hardware for each channel. This module is capable to 
       capture x, y and z channel at the same time. It has an I2C interface to communicate with the host 
       controller. This MPU6050 module is a compact chip having both accelerometer and gyro. This 
       is a very useful device for many applications like drones, robots, motion sensors.
       It is also called Gyroscope or Triple axis accelerometer.
   
     

## Technologies
Projects is created with:
* Arduino IDE 1.8.19 [To Downloud](https://www.arduino.cc/en/software)
* Proteus [To Downloud](https://www.labcenter.com/simulation/)
	
## Components required
### 1. Ultrasonic Sensor

    1. Arduino UNO
    2. ULTRASONIC Sensor (HC-SR04)
    3. jumper wirs
    4. power supply
    5. USB-A to Micro-USB Cable
    6. breadboard
    
### 2. MPU6050 Gyro Sensor

    1. Arduino UNO
    2. MPU-6050
    3. jumper wirs
    4. 10K POT
    5. Power supply
    6. breadboard
    7. Power supply
    8. LCD
    
    
## Connections

### 1. Ultrasonic Sensor

       Connect the +5V pin to +5v on your Arduino board.
       
       Connect Trigger to digital pin 7 on your Arduino board.
       
       Connect Echo to digital pin 6 on your Arduino board.
       
       Connect GND with GND on Arduino.
     
 ### 2.MPU6050 Gyro Sensor
 
 connected the 3.3v power supply and ground of MPU6050 to the 3.3v and ground of Arduino.
 
 SCL and SDA pins of MPU6050 is connected with Arduino’s A4 and A5 pin
 
 INT pin of MPU6050 is connected to interrupt 0 of Arduino (D2). 
 
 LCD’s RS, RW and EN are directly connected to 8, gnd and 9 of Arduino.
 
 Data pin are directly connected to digital pin number 10, 11, 12 and 13.
 
 

## Block diagram & simulation

### 1. Ultrasonic Sensor . 



![Screenshot 2022-08-07 040939](https://user-images.githubusercontent.com/64277741/183270942-6859a63c-73ab-407f-b670-678ed41fc3c4.png)

Figure (1): Ultrasonic Sensor circuit


 #### In our program, we have displayed the distance measured by the sensor in inches and cm via the serial port 
 

#### The Code 

const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}


### 2.MPU6050 Gyro Sensor

![MPU6050-Gyro-Sensor-Circuit-diagram-for-Interfacing-with-Arduino](https://user-images.githubusercontent.com/64277741/183271076-aebd9380-05b0-4143-94b6-2083de287c4f.png)


Figure (2): MPU6050 Gyro Sensor circuit 
#### can see  temperature, gyro, and accelerometer reading over serial monitor and LCD


#### The code 

 we have download the MPU6050 library from library manager and install it in Arduino IDE.
 
 #include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
#include <Wire.h>
#include <MPU6050.h>
void setup()
{
  lcd.begin(16,2);
  lcd.createChar(0, degree);
  Serial.begin(9600);
  Serial.println("Initialize MPU6050");
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    lcd.clear();
    lcd.print("Device not Found");
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
  count=0;
  mpu.calibrateGyro();
  mpu.setThreshold(3);
  void loop()
{
    lcd.clear();
    lcd.print("Temperature");
    long st=millis();
    Serial.println("Temperature");
    while(millis()<st+period)
    {
      lcd.setCursor(0,1);
      tempShow();
    }
    lcd.clear();
    lcd.print("Gyro");
    delay(2000);
    st=millis();
    Serial.println("Gyro");
    while(millis()<st+period)
    {
      lcd.setCursor(0,1);
      gyroShow();
    }
    lcd.clear();
    lcd.print("Accelerometer");
    delay(2000);
    st=millis();
  
