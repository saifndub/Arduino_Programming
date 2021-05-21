#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//#include <DHT11.h>

#define button 4

/*int pin = A0;
DHT11 dht11(pin);
float temperature[2];

double Fahrenheit(double celsius) {
return ((double)(9 / 5) * celsius) + 32;
}

double Kelvin(double celsius) {
return celsius + 273.15;
}*/

RF24 radio(8, 9);
const uint64_t pipe = 0xE8E8F0F0E1LL;
boolean buttonState = 0;

void setup(void) {
  pinMode(button, INPUT);
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop(void)
{
/*float temp, humi;
dht11.read(humi, temp);
temperature[0] = temp;
temperature[1] = humi;
radio.write(temperature, sizeof(temperature));*/
    buttonState = digitalRead(button);
    radio.write(&buttonState, sizeof(buttonState));
    delay(1000);
}
