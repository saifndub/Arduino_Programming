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
void firstone() {
  customclear();
  j = 7;
  byte Char0[8] = {  B11100, B11000, B11000, B11000, B10000, B10000, B10000, B00000 };
  byte Char1[8] = {  B11111, B11111, B11111, B11110, B11110, B11110, B11100, B11100 };
  byte Char2[8] = {  B11100, B11000, B11000, B11000, B10000, B10000, B10000, B00000 };
  byte Char3[8] = {  B11110, B11110, B11110, B11100, B11100, B11100, B11000, B11000 };
  byte Char4[8] = {  B11000, B10000, B10000, B10000, B00000, B10000, B10000, B11000 };
  byte Char5[8] = {  B11100, B11100, B11100, B11000, B11000, B11000, B10000, B10000 };
  byte Char6[8] = {  B10000, B00000, B10000, B10000, B11000, B11000, B11000, B11100 };
  lcd.createChar(0, Char0);   lcd.createChar(1, Char1);   lcd.createChar(2, Char2);
  lcd.createChar(3, Char3);   lcd.createChar(4, Char4);   lcd.createChar(5, Char5);
  lcd.createChar(6, Char6);
}
void secondone() {
  customclear();
  j = 7;
  byte Char6[8] = {  B10000, B00000, B10000, B10000, B11000, B11000, B11100, B11100 };
  byte Char7[8] = {  B11000, B11000, B11000, B10000, B10000, B10000, B00000, B10000 };
  byte Char8[8] = {  B10000, B10000, B11000, B11000, B11000, B11100, B11100, B11100 };
  byte Char9[8] = {  B11000, B10000, B10000, B00000, B10000, B10000, B10000, B11000 };
  byte Char10[8] = {  B11000, B11000, B11100, B11100, B11100, B11110, B11110, B11110 };
  byte Char11[8] = {  B00000, B10000, B10000, B10000, B11000, B11000, B11000, B11100 };
  byte Char12[8] = {  B11100, B11100, B11110, B11110, B11110, B11111, B11111, B11111 };
  lcd.createChar(6, Char6);   lcd.createChar(5, Char7);    lcd.createChar(4, Char8);
  lcd.createChar(3, Char9);   lcd.createChar(2, Char10);   lcd.createChar(1, Char11);
  lcd.createChar(0, Char12);
}

void setup() {
  //lcd.begin();
  lcd.init();               // initialize the lcd
  lcd.backlight();          //backlight turn on

}

void loop() {
  fillset();
}





void fillset() {
  firstone();
  for (i = 1; i < j; i++)
  {
    if ((i % 2) == 1) {
      lcd.setCursor(z, 1);
      lcd.write(i);               // lcd.setCursor(11, 1); lcd.print(i);
    }
    else {
      lcd.setCursor(z, 2);
      lcd.write(i);               // lcd.setCursor(11, 2); lcd.print(i);
    }
    //delay(50);
  }
  i = 6;
  secondone();
  for (; i >= 0; i--)
  {
    if ((i % 2) == 0) {
      lcd.setCursor(z, 2);
      lcd.write(i);              // lcd.setCursor(11, 2);   lcd.print(i);
    }
    else {
      lcd.setCursor(z, 1);
      lcd.write(i);              // lcd.setCursor(11, 1); lcd.print(i);
    }
    delay(70);
  }


  secondone();
  for (i = 0; i < j; i++)
  {
    if ((i % 2) == 1) {
      lcd.setCursor(z, 1);
      lcd.write(i);             // lcd.setCursor(11, 1);   lcd.print(i);
    }
    else {
      lcd.setCursor(z, 2);
      lcd.write(i);             // lcd.setCursor(11, 2);   lcd.print(i);
    }
    //delay(50);
  }
  i = 6;
  firstone();
  for (; i >= 0; i--)
  {
    if ((i % 2) == 0) {
      lcd.setCursor(z, 2);
      lcd.write(i);             // lcd.setCursor(11, 2);   lcd.print(i);
    }
    else {
      lcd.setCursor(z, 1);
      lcd.write(i);             // lcd.setCursor(11, 1);   lcd.print(i);
    }
    delay(70);
  }
}

/*
  firstone();
  for(i = 1; i < j; i++)
  {
   if((i%2)==1){
    lcd.setCursor(10, 1);
    lcd.write(i);
    lcd.setCursor(11, 1);
    lcd.print(i);
   }
   else{
    lcd.setCursor(10, 2);
    lcd.write(i);
    lcd.setCursor(11, 2);
    lcd.print(i);
   }
   //delay(1000);
  }
  i= 6;
  secondone();
  for(; i >= 0; i--)
  {
   if((i%2)==0){
    lcd.setCursor(10, 2);
    lcd.write(i);
    lcd.setCursor(11, 2);
    lcd.print(i);
   }
   else{
    lcd.setCursor(10, 1);
    lcd.write(i);
    lcd.setCursor(11, 1);
    lcd.print(i);
   }
   //delay(1000);
  }
*/
