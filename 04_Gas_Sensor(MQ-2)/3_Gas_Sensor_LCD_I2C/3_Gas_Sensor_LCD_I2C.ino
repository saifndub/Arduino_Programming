#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display

int smokeA0 = A0;
int buzz = 8;
int limit = 500;
int value;

void setup() {
  // put your setup code here, to run once:
  
  //lcd.init();               // initialize the lcd 
  lcd.begin();
  lcd.backlight();          //backlight turn on
    
  pinMode(buzz,OUTPUT);
  pinMode(smokeA0,INPUT);

}
void buzzer()
{
    for(int i = 0; i <=5 ; i++)
    {
      digitalWrite(buzz, HIGH);
      delay(100);
      digitalWrite(buzz, LOW);
      delay(100);
    }
}
void gas()
{
    lcd.setCursor(0,0);
    lcd.print("You are in Danger ");
    lcd.setCursor(0,1);
    lcd.print("....Gas Ditected....");
    lcd.setCursor(0,2);
    lcd.print("Gas Level :");
    lcd.print(value); 
}
void alcohol()
{
    lcd.setCursor(0,0);
    lcd.print("You are in Danger ");
    lcd.setCursor(0,1);
    lcd.print("..Alcohol Ditected..");
    lcd.setCursor(0,2);
    lcd.print("Alcohol Level :");
    lcd.print(value); 
}
void smoke()
{
    lcd.setCursor(0,0);
    lcd.print("You are in Danger ");
    lcd.setCursor(0,1);
    lcd.print("...Smoke Ditected...");
    lcd.setCursor(0,2);
    lcd.print("Smoke Level :");
    lcd.print(value); 
}

void loop() {
  // put your main code here, to run repeatedly:

  value = analogRead(smokeA0);
 
  if(value <=350)
  {
    lcd.setCursor(2,0);
    lcd.print("You are safe ");    
//    Serial.print("Gas Ditected : ");
//    Serial.print(value);
  }
   else if(350 < value < 530)
  {
    smoke();
    buzzer();    
  }
   else if(530 < value < 660)
  {
    alcohol();
    buzzer();    
  }
  if(660 <= value)
  {
    gas();
    buzzer();    
  }

   delay(500);
   lcd.clear();
}
