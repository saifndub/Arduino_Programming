/*
 * https://www.youtube.com/watch?v=3HwBBZE3P_E
 */
 
#include <LiquidCrystal.h> // includes the LiquidCrystal Library
#include <dht.h>
#define dataPin 8
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
dht DHT;
void setup() {
   Serial.begin(9600);
  lcd.begin(16,2); // 
}
void loop() {
  int readData = DHT.read22(dataPin);
  float t = DHT.temperature;
  float h = DHT.humidity;
  lcd.setCursor(0,0); 
  lcd.print("Temp.: "); 
  lcd.print(t); 
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humi.: ");
  lcd.print(h);
  lcd.print(" %");
   // Printing the results on the serial monitor
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("    Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  delay(2000);

}
