int value; 
float volt;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(A0);
  volt = value*0.0049;
  Serial.println(volt);

}
