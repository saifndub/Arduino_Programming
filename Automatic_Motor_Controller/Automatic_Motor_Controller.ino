#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 20 chars and 4 line display

int x = 0;
int y = 0;
int i = 0;
int j = 0;
int v;
int trigpin = A1;
int echopin = A0;
int buzz = 10;
float min = 10.00;
float max = 100.00;
float time;
float cm;
float inch;

void setup() {
  // put your setup code here, to run once:

  lcd.init();               // initialize the lcd
  lcd.backlight();          //backlight turn on

  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(buzz, OUTPUT);

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
void loop() {

  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  time = pulseIn(echopin, HIGH);
  cm = (time / 58.82) ;
  inch = (cm / 2.54);

  if (cm < min)
  {
    /*lcd.clear();
      digitalWrite(buzz, HIGH);
      delay(100);
      digitalWrite(buzz, LOW);
      delay(100);
      lcd.setCursor(0, 0);
      lcd.print("Dangerous Situation");
      lcd.setCursor(0, 1);
      lcd.print("Obstacle in Range");
      lcd.setCursor(3, 3);
      lcd.print("Digitarduino");*/
  }
  else //if(cm > 30)
  {
    lcd.setCursor(0, 3);
    lcd.print("LOW");

    lcd.setCursor(16, 3);
    lcd.print("HIGH");

    if ((cm < 100) && (cm > 10))
    {
      lcd.setCursor(7, 3);
      lcd.print(cm);
      x = cm / 5;

      v = 0;
      while (v < x)
      {
        for (int i = 0; i < j; i++)
        {
          lcd.setCursor(v, 2);
          lcd.write(i);
          delay(100);
          lcd.setCursor(5,0);
          lcd.write("Saif");
        }
        lcd.setCursor(v, 2);
        lcd.write(255);
        delay(100);
        v++;
      }
      /*customset1();
        for (int k = 0; k < 10; k++)
        {
        for (int i = 0; i < j; i++)
        {
          lcd.setCursor(k, 2);
          lcd.write(i);
          //delay(100);
        }
        lcd.write(255);
        }*/

    }

    delay(1000);
    //lcd.clear();
  }

}
