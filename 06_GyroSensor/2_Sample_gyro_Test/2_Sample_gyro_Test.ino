#include <MPU6050_tockn.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

MPU6050 mpu6050(Wire);
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display

long timer = 0;
int LED = 9;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  //lcd.init();               // initialize the lcd 
  lcd.begin();
  lcd.backlight();          //backlight turn on
 
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}

void loop() {
  mpu6050.update();

  //if(millis() - timer > 1000){

    int gyroX = mpu6050.getAngleX();
    int gyroY = mpu6050.getAngleY();
    int gyroZ = mpu6050.getAngleZ();
    
    Serial.print("angleX : ");Serial.print(gyroX);
    Serial.print("  angleY : ");Serial.print(gyroY);
    Serial.print("  angleZ : ");Serial.println(gyroZ);

    lcd.setCursor(3,2);
    lcd.print("angleZ : ");
    lcd.print(gyroZ);

    //if(gyroZ > 30)
    //{
      //digitalWrite(LED, HIGH);
      //mpu6050.calcGyroOffsets(true);
      //mpu6050.update();
      //delay(5000);
      while((gyroZ / 10) == 9)
      {
        //gyroZ = 0;
      digitalWrite(LED, LOW);
      mpu6050.begin();
      mpu6050.calcGyroOffsets(true);
      lcd.clear();
      //mpu6050.update();
    }

  // timer = millis();
   
  //}

}
