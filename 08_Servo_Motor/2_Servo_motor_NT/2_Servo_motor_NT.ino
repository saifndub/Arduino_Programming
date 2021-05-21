#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display

int servopin = 9;
int i;
 
Servo motor;

void setup() {
  // put your setup code here, to run once:
  
  //lcd.init();               // initialize the lcd 
  lcd.begin();
  lcd.backlight();          //backlight turn on
   
  motor.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:

    lcd.setCursor(0,0);
    lcd.println("Servo motor is started"); 
    lcd.setCursor(0,1);
    lcd.println("Position -> 0 Degree");
  motor.write(0);
  delay(500);
    lcd.setCursor(0,0);
    lcd.println("Direc : AntiClock"); 
    lcd.setCursor(0,1);
    lcd.println("Angle -> 90 Degree");
  motor.write(90);
  delay(2000);
  lcd.clear();
  
    lcd.setCursor(0,0);
    lcd.println("Direc : AntiClock"); 
    lcd.setCursor(0,1);
    lcd.println("Angle -> 180 Degree");
  motor.write(180);
  delay(2000);
  lcd.clear();

    lcd.setCursor(0,0);
    lcd.println("Direc : Clock Wise"); 
    lcd.setCursor(0,1);
    lcd.println("Angle -> 90 Degree");

  for(i = 180; i > 0; i=i-5)
  {
    motor.write(i);
    delay(100);
  }
  delay(2000);
  lcd.clear();

}
