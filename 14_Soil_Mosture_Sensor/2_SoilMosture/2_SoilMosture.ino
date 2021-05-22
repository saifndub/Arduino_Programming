/*https://www.youtube.com/watch?v=ejJOD0WQGRM&t=724s
 * 
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 20 chars and 4 line display

int soil;
int moisture;
void setup()
{
  //lcd.init();               // initialize the lcd
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.backlight();          //backlight turn on
  
  lcd.setCursor(0, 0);
  lcd.print("Welcome This Project");
  delay(500);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  soil = analogRead(A0);
  moisture = map(soil, 0, 1023, 100, 0);
  lcd.setCursor(0, 0);
  lcd.print("Moisture : ");
  lcd.print(moisture);
  lcd.print("%");
  Serial.println(moisture);
  delay(500);
  lcd.clear();
}
