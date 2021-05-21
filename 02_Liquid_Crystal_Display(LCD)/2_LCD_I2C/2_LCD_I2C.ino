#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 20 chars and 4 line display
int saif = 6.652;
void setup()
{
  lcd.init();               // initialize the lcd
  
  //lcd.begin(20, 4);
  lcd.backlight();          //backlight turn on
  
  // Print a message to the LCD.
  lcd.setCursor(1, 0);
  lcd.print("Hello Friends");
  lcd.setCursor(0, 1);
  lcd.print("Electro Arduino");
  lcd.setCursor(0, 2);
  lcd.print(saif+String("%"));
  lcd.print(saif+(String)"%");
  //lcd.print();
  //lcd.print("Digital Arduino!");
  //delay(5000);
  //lcd.clear();
}


void loop()
{

}
