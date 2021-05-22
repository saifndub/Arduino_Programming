int pir = 7;
int buzzer = 8;
int state;

void setup() {
  // put your setup code here, to run once:

  pinMode(buzzer,OUTPUT);
  pinMode(pir,INPUT);
    
}

void loop() {
  // put your main code here, to run repeatedly:

  state = digitalRead(pir);
  digitalWrite(buzzer, state);

}
