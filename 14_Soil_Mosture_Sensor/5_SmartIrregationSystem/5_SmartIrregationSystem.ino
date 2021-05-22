/* https://www.youtube.com/watch?v=sZqCSftVRr8&t=7s
 * 
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 20 chars and 4 line display

//int soil;
int sensorpin = A1;
int motorpin = 9;
int sensorValue = 0;
void setup()
{
  pinMode(Msensorpin, INPUT);
  pinMode(motorpin, OUTPUT);
  Serial.begin(9600);
  
  lcd.begin(20, 4);         // initialize the lcd
  lcd.backlight();          //backlight turn on
  
  lcd.setCursor(0, 0);
  lcd.print("Welcome This Project");
  delay(500);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("SMART IRRIGATION");
  sensorValue = analogRead(sensorpin);
  moisture = map(sensorValue, 940, 170, 0, 100);
  Serial.println(sensorValue);

  if(sensorValue >= 70){
    Serial.println(sensorValue);
    digitalWrite(motorpin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Moisture In Soil ");
    lcd.setCursor(0, 2);
    lcd.print(sensorValue+(String)"%");
    lcd.setCursor(0, 3);
    lcd.print(Pump Off"");
  }
   else if(sensorValue < 70){
    Serial.println(sensorValue);
    digitalWrite(motorpin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Moisture In Soil ");
    lcd.setCursor(0, 2);
    lcd.print(sensorValue+(String)"%");
    lcd.setCursor(0, 3);
    lcd.print(Pump On"");
  }
  delay(500);
  lcd.clear();
}
