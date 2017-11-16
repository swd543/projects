#define bug A3
#define op 3

void setup()
{
  pinMode(bug,INPUT);
  pinMode(op,OUTPUT);
}
void loop()
{
  if(digitalRead(bug)==HIGH)
    analogWrite(op,200);
  else
    analogWrite(op,0);
    
  delay(10);
}
    
