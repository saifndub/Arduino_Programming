#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display

int sensor = 8 ;
int buzz = 7 ;
int value = HIGH ;

void setup() {
  // put your setup code here, to run once:
  //lcd.init();               // initialize the lcd 
  lcd.begin();
  lcd.backlight();          //backlight turn on

  pinMode(buzz,OUTPUT);
  pinMode(sensor,INPUT);
  //Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Welcome our Project");
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

  value = digitalRead(sensor);

  if(value == LOW)
  {
      lcd.setCursor(0, 0);
      lcd.print("FLAME, FLAME, FLAME");
      lcd.setCursor(1, 2);
      lcd.print(value);

     for(int i = 0; i <=5 ; i++)
    {
      digitalWrite(buzz, HIGH);
      delay(100);
      digitalWrite(buzz, LOW);
      delay(100);
    }
   
  }
  else 
  {
    digitalWrite(buzz, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Be Cool");
  }
  
   delay(1000);
   lcd.clear();
}
