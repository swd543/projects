void setup() 
{
analogWrite(9,225);
delay(250);
analogWrite(10,225);
delay(250);
analogWrite(11,225);
delay(250);
analogWrite(13,225);
delay(250);
}

void loop() 
{
int r=random()*100;
if(r>75)
{
  if(analogRead(13)==225)
    analogWrite(13,0);
   else
    analogWrite(13,225);
}
else if(r>50)
{
  if(analogRead(11)==225)
    analogWrite(11,0);
   else
    analogWrite(11,225);
}
else if(r>25)
{
  if(analogRead(10)==225)
    analogWrite(10,0);
   else
    analogWrite(10,225);
}
else
{
  if(analogRead(9)==225)
    analogWrite(9,0);
   else
    analogWrite(9,225);
}

delay(250);
}
