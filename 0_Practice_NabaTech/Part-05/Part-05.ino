int led = 13;
int inp = 3;
int state;

void setup() {
  // put your setup code here, to run once:

  pinMode(led,OUTPUT);
  pinMode(inp,INPUT);
    
}

void loop() {
  // put your main code here, to run repeatedly:

  state = digitalRead(inp);
  digitalWrite(led, state);
  //delay(1000);
  //digitalWrite(led, LOW);
  //delay(1000);

}
