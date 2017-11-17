#define bug 3
#define ip A0
#define del 50

extern int rand()
{
  int t=random(0,200);
  analogWrite(bug,t);
  delay(del);
}
extern int fade()
{
  for(int i=0;i<200;i++)
  {
    analogWrite(bug,i);
    delay(del*10/199);
  }
  for(int i=200;i>=0;i--)
  {
    analogWrite(bug,i);
    delay(del*10/200);
  }
}
extern int tick()
{
  analogWrite(bug,200);
  delay(500);
  analogWrite(bug,0);
  delay(500);
}

void setup()
{
  pinMode(bug,OUTPUT);
  pinMode(ip,INPUT);
}
void loop()
{
  if(digitalRead(ip)==LOW)
    tick();
  else
    rand();
  delay(5);
}
