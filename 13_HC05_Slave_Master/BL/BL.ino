#include <SoftwareSerial.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);

  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    String value = Serial.readStringUntil('\n');
    Serial.println(value);
    
    if(value=="On" || "on" || "1")
    {
      digitalWrite(3,HIGH);
    }
    if(value=="Off")
    {
      digitalWrite(3,LOW);
    }
  }
}
