

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x27, 20, 4);

byte customChar[] = {
  0b00000,
  0b00000,
  0b00000,
  0b00111,
  0b00100,
  0b00100,
  0b00100,
  0b00100
};

void setup() {
  //lcd.begin();

  lcd.init();               // initialize the lcd
  lcd.backlight();          //backlight turn on

  lcd.createChar(10, customChar);
  lcd.home();
  lcd.write(10);
  lcd.setCursor(2, 0);
  lcd.write(255);
}

void loop() { }
