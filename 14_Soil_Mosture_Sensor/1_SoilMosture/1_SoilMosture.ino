//#include <Wire.h>
#include <LiquidCrystal.h>
//LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int soil;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(20 , 4);
  lcd.setCursor(0, 0);
  lcd.print("Welcome This Project");
  delay(500);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  soil = analogRead(A0);
  lcd.setCursor(3, 0);
  lcd.print("Naba Teck");
  lcd.setCursor(5, 1);
  lcd.print("Value");
  lcd.print(soil);
  delay(500);
  lcd.clear();
}
