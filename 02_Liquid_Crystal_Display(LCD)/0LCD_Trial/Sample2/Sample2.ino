#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x27, 20, 4);

// define integers for the cursor location
int x = 0;
int y = 0;
int z = 5;
int i = 0;
int j = 0;


void setup() {
  // put your setup code here, to run once:
  //lcd.begin();
  lcd.init();               // initialize the lcd
  lcd.backlight();          //backlight turn on
  lcd.clear();
}

void customclear()
{
  // ensures all custom character slots are clear before new custom
  // characters can be defined.
  byte blank[8] = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
  for (int i = 0; i < 8; i++)
  {
    lcd.createChar(i, blank);
  }
}
// filles a segment one line at a time fron left to right.
void customset1()
{
  customclear();
  j = 4;
  // arrays to form one set of custom characters
  byte line1[8] = {  B10000, B10000, B10000, B10000, B10000, B10000, B10000, B10000 };
  byte line2[8] = {  B11000, B11000, B11000, B11000, B11000, B11000, B11000, B11000 };
  byte line3[8] = {  B11100, B11100, B11100, B11100, B11100, B11100, B11100, B11100 };
  byte line4[8] = {  B11110, B11110, B11110, B11110, B11110, B11110, B11110, B11110 };

  // assignes each segment a write number
  lcd.createChar(0, line1);
  lcd.createChar(1, line2);
  lcd.createChar(2, line3);
  lcd.createChar(3, line4);
}
void fillset()
{
  for (int i = 0; i < j; i++)
  {
    if (x == 15)
    {
      lcd.clear();
      x = -1;
      break;      
    }
    lcd.setCursor(x, y);
    lcd.write(i);
    delay(100);
  }
  lcd.setCursor(x, y);
  lcd.write(255);
  delay(100);
  x++;
  
  if (x < 20)
  {
    fillset();
  }
  if (x > 19)
  {
    x = 0;
    y++;
    if (y < 2)
    {
      fillset();
    }
  }
  if (y > 1)
  {
    x = 0;
    y = 0;
    lcd.clear();
  }
}

void loop()
{
  customset1();
  fillset();
}
