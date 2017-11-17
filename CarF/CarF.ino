void setup() {
  pinMode(2,INPUT);
  pinMode(4,INPUT);
                          //2,4, 10,11, 9
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  
  pinMode(9,INPUT);
  pinMode(13,OUTPUT);
}

void loop()
{ int c=0;
  int a[1000];
  
  for(int q=0;q<1000;q++)
  a[q]=0;
  
  do{
  
  int k;
  int l=digitalRead(2); int r=digitalRead(4); int f=digitalRead(10); int b=digitalRead(11);
  
  if(f==HIGH && l==HIGH)
    k=3;
  else if(f=HIGH && r==HIGH)
    k=4;
  else if(b=HIGH && l==HIGH)
    k=5;
  else if(b=HIGH && r==HIGH)
    k=6;
  else if(f=HIGH && l==LOW && r==LOW)
    k=1;
  else if(b=HIGH && l==LOW && r==LOW)
    k=2;
  else
    k=0;
  
  a[c]=k;
  delay(20);
  c++;
} while(digitalRead(9)==0);

  digitalWrite(13,HIGH);
  delay(800);
  digitalWrite(13,LOW);
  delay(800);
  digitalWrite(13,HIGH);
  delay(800);
  digitalWrite(13,LOW);
  delay(800);
  digitalWrite(13,HIGH);
  delay(800);
  
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(9,OUTPUT);
  
do{
  if(a[c]==1)
    digitalWrite(11,HIGH);
  else if(a[c]==2)
    digitalWrite(10,HIGH);
  else if(a[c]==3)
    {
      digitalWrite(11,HIGH);
      digitalWrite(2,HIGH);
    }
  else if(a[c]==4)
    {
      digitalWrite(11,HIGH);
      digitalWrite(4,HIGH);
    }
  else if(a[c]==5)
    {
      digitalWrite(10,HIGH);
      digitalWrite(2,HIGH);
    }
  else if(a[c]==6)
    {
      digitalWrite(10,HIGH);
      digitalWrite(4,HIGH);
    }
  else;
  delay(70);
      digitalWrite(2,LOW);
      digitalWrite(4,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
  c--;
  }while(c!=0);
  digitalWrite(13,LOW);
}
