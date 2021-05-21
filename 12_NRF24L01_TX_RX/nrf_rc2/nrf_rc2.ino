#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//#include <DHT11.h>
#define led 2

RF24 radio(8, 9);
const uint64_t pipe = 0xE8E8F0F0E1LL;

boolean buttonState = 0;

void setup(void) {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  
  Serial.print("Humidity & Temp.");
  delay(2000);
  Serial.print("Starting.....");
  delay(2000);
}

void loop(void)
{
  if ( radio.available() )
  {
    bool done = false;
    while (!done)
    {
      Serial.print("OKKK");
      delay(10);
    }
    //radio.read(buttonState, sizeof(buttonState));
  if (buttonState == HIGH) {
    digitalWrite(led, HIGH);
    delay(10000);
  }
  else {
    digitalWrite(led, LOW);
  }
  }
  else
  {
  Serial.println("No Radio Found");
  delay(100);
  }
}
