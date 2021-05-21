/*  https://www.youtube.com/watch?v=UY92TPZ4GqQ
 * 
 */
#include <dht.h>
#include <LiquidCrystal.h>
#define DHT11_PIN 7
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
dht DHT;

String data;
char b[50];

void setup(){
  lcd.begin(16, 2);
   Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  Serial.println("Temp: ");
  Serial.println(DHT.temperature);
 // Serial.println((char)223);
  Serial.println("C");
  float h=(DHT.humidity);
  float t=(DHT.temperature);
  Serial.println("Humidity: ");
  Serial.println(DHT.humidity);
  Serial.println("%");
   Serial.println(h);
    Serial.println(t);

   
  delay(2000);
}
