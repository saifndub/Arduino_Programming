
#include <Servo.h>
int servopin = 9;
 
Servo motor;

void setup() {
  // put your setup code here, to run once:
  motor.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.write(0);
  delay(1000);
  motor.write(90);
  delay(1000);
  motor.write(180);
  delay(1000);

}
