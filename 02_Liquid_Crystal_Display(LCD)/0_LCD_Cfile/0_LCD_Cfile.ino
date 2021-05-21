// Follow the below link :
// https://arduino.stackexchange.com/questions/176/how-do-i-print-multiple-variables-in-a-string
void setup()
{
  Serial.begin(9600);
  Serial.print("Saif");
}

void loop()
{
  int l=2;
  char *j = "test";
  long k = 123456789;
  char s = 'g';
  float f = 2.3;

  //ardprintf("test %d %l %c %s %f", l, k, s, j, f);

  Serial.print("Saif1");
  Serial.print("Saif2");
  delay(1000);

}
