int trigpin = A0;
int echopin = A1;
float distance;
float duration;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin,HIGH);
  distance = (0.034 * duration)/2 ; 
  Serial.print("The distance is = ");
  Serial.print(distance);
  Serial.println("cm");
  delay(2000);
}
