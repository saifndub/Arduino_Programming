#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
//LiquidCrystal lcd(10, 9, 8, 7, 6, 5);
int trigpin = 8;
int echopin = 9;
int buzzer = 11;
float time;
float cm;
float inch;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(20 , 4);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  time = pulseIn(echopin, HIGH);
  cm = (time / 58.82) ;
  inch = (cm / 2.54);
  lcd.setCursor(0, 0);
  lcd.print("Obstacle distance:");
  lcd.setCursor(0, 1);
  lcd.print(cm);
  lcd.print("cm");

  lcd.setCursor(10, 1);
  lcd.print(inch);
  lcd.print("inch");

  lcd.setCursor(2, 3);
  lcd.print("Electroo World");

  if (cm < 20)
  {
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(0, 2);
    lcd.print("Obstacle in Range");
  }
  else
  {
    digitalWrite(buzzer, LOW);
  }
  delay(1000);
  lcd.clear();
}
