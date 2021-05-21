#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display

int trigpin = A0;
int echopin = A1;
int buzz = 10;
float time;
float cm;
float inch;

void setup() {
  // put your setup code here, to run once:
  
  lcd.init();               // initialize the lcd 
  //lcd.begin();
  lcd.backlight();          //backlight turn on
  
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(buzz,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  time = pulseIn(echopin,HIGH);
  cm = (time / 58.82) ; 
  inch = (cm /2.54);

  if(cm < 10)
  {
    //lcd.clear();
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(100);
    lcd.setCursor(0,0);
    lcd.print("Dangerous Situation");
    lcd.setCursor(0,1);
    lcd.print("Obstacle in Range"); 
    lcd.setCursor(3,3);
    lcd.print("Digitarduino");
  }
  else //if(cm > 30)
  {
    lcd.setCursor(0,0);
    lcd.print("Obstacle distance :");
    lcd.setCursor(0,1);
    lcd.print(cm);
    lcd.print("cm");

    lcd.setCursor(10,1);
    lcd.print(inch);
    lcd.print("inch");

    lcd.setCursor(3,3);
    lcd.print("Digitarduino");
    digitalWrite(buzz,LOW);

    delay(1000);
    lcd.clear();
  }
  
}
