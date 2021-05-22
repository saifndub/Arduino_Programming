//Big size motor is suitable
#include <Stepper.h>
Stepper motor(2048, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
  motor.setSpeed(2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println("ClockWise ");
  motor.step(512);
  delay(2000);
  Serial.println("Anti ClockWise ");
  motor.step(-512);
  delay(2000);
  
}
