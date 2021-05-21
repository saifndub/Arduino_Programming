
int smokeA0 = A0;
int ledbuzz = 8;
int limit = 500;
int value;
//float duration;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledbuzz,OUTPUT);
  pinMode(smokeA0,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  value = analogRead(smokeA0);
  
  if(value >= limit)
  {
    digitalWrite(ledbuzz, HIGH);
    delay(100);
    digitalWrite(ledbuzz, LOW);
    delay(100);
  
    Serial.print("Gas Ditected :");
    Serial.println(value);
    //Serial.println("cm");
   
  }
  else
  {
    Serial.print("You are safe");
    Serial.println(value);
  }

   delay(1500);
}
