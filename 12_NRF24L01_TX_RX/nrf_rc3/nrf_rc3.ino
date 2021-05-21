/* Receiver */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN Pins
const uint64_t address = 0xF0F0F0F0E1LL;


void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() 
{
  if (radio.available()) {
    //char recvData[32] = "";
    int recvData = "";
    radio.read(&recvData, sizeof(recvData));
    Serial.println(recvData);
    delay(1000);
  }
}
