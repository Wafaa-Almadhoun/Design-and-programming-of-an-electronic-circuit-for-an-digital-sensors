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
  
