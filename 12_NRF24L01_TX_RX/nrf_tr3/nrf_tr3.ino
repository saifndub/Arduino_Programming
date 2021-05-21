/* Transmitter */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN Pins
const uint64_t address = 0xF0F0F0F0E1LL;


void setup() 
{
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() 
{
  //const char sendData[] = "This!";
  int sendData = "173120001";
  radio.write(&sendData, sizeof(sendData));
  delay(500);

}
