#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);  // Set the LCD I2C address

void setup()  
{
  lcd.init();               // initialize the lcd 
  lcd.backlight();
//  lcd.begin(); 
  
  lcd.setCursor(3,0);
  lcd.print("Hello YouTube!");
  lcd.setCursor(8,1);
  lcd.print("****");
  lcd.setCursor(0,2);
  lcd.print("This is a demo text");
  lcd.setCursor(8,3);
  lcd.print("****");
}

void loop() 
{ 
}
