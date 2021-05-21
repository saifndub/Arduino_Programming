#include <LiquidCrystal.h>

int i = 315;
//LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(20 , 4);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(3, 1);
  lcd.print("Naba Teck");
  lcd.setCursor(2, 2);
  lcd.print("Tutorial No : Saif");
  Serial.println("I am Saif");

}
