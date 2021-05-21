#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x27, 20, 4);

int i = 6;

byte Char1[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111

};
byte Char2[] = {
  B11111,
  B11111,
  B11110,
  B11110,
  B11100,
  B11100,
  B11000,
  B11000

};
byte Char3[] = {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100

};
byte Char4[] = {
  B11000,
  B11000,
  B11100,
  B11100,
  B11110,
  B11110,
  B11111,
  B11111

};


void setup() {
  //lcd.begin();

  lcd.init();               // initialize the lcd
  lcd.backlight();          //backlight turn on

  lcd.createChar(1, Char1);
  lcd.createChar(2, Char2);
  lcd.createChar(3, Char3);
  lcd.createChar(4, Char4);

  for (i = 0; i < 5; i++)
  {
    lcd.setCursor(i, 1);
    lcd.write(byte(1));

    lcd.setCursor(i, 2);
    lcd.write(byte(1));

    delay(2000);
  }
}

void loop() {

  lcd.setCursor(i, 1);
  lcd.write(byte(2));
  delay(500);
  lcd.clear();
  lcd.setCursor(i, 1);
  lcd.write(byte(3));
  delay(500);
  lcd.clear();
  lcd.setCursor(i, 1);
  lcd.write(byte(4));
  delay(500);
  lcd.clear();
  lcd.setCursor(i, 1);
  lcd.write(byte(3));
  delay(500);
  lcd.clear();

}
