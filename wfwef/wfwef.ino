
void setup() {
  
  Serial.begin(9600);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
digitalWrite(9,HIGH);
delay(333);
digitalWrite(10,HIGH);
delay(333);
digitalWrite(11,HIGH);
delay(333);
}

void loop()
{
  
int n=((random())*100);
Serial.println(n);
int p;
if(n<33)
  p=9;
else if(n>33 && n<66)
  p=10;
else
  p=11;


toggle(p);
delay(333);
}

void toggle(int d)
{
  pinMode(d,INPUT);
  if(digitalRead(d)==HIGH)
      digitalWrite(d,LOW);
  else
      digitalWrite(d,HIGH);
  pinMode(d,OUTPUT);
}
