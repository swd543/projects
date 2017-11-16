#define m1f  4
#define m1b  2
#define m1s  3

#define m2f  7
#define m2b  5
#define m2s  6

int s=126;

struct robot
{
   void init()
   {
     pinMode(m1f,OUTPUT);
     pinMode(m1b,OUTPUT);
     pinMode(m1s,OUTPUT);
     pinMode(m2f,OUTPUT);
     pinMode(m2b,OUTPUT);
     pinMode(m2s,OUTPUT);
     pinMode(13,OUTPUT);
   }
   void reset()
   {
     digitalWrite(m1f,LOW);
     analogWrite(m1s,0);
     digitalWrite(m2f,LOW);
     analogWrite(m2s,0);
     digitalWrite(m1b,LOW);
     digitalWrite(m2b,LOW);
   }
   void front(int x,int del)
   {
     digitalWrite(m1f,HIGH);
     analogWrite(m1s,x);
     digitalWrite(m2f,HIGH);
     analogWrite(m2s,x);
     delay(del);
     reset();
   }
   void back(int x,int del)
   {
     digitalWrite(m1b,HIGH);
     analogWrite(m1s,x);
     digitalWrite(m2b,HIGH);
     analogWrite(m2s,x);
     delay(del);
     reset();
   }
   void left(int x,int del)
   {
     digitalWrite(m1b,HIGH);
     analogWrite(m1s,x);
     digitalWrite(m2f,HIGH);
     analogWrite(m2s,x);
     delay(del);
     reset();
   }
   void right(int x,int del)
   {
     digitalWrite(m1f,HIGH);
     analogWrite(m1s,x);
     digitalWrite(m2b,HIGH);
     analogWrite(m2s,x);
     delay(del);
     reset();
   }
   void vsfront(int x)
   {
     reset();
     digitalWrite(m1f,HIGH);
     analogWrite(m1s,x);
     digitalWrite(m2f,HIGH);
     analogWrite(m2s,x);
   }
   void vsback(int x)
   {
     reset();
     digitalWrite(m1b,HIGH);
     analogWrite(m1s,x);
     digitalWrite(m2b,HIGH);
     analogWrite(m2s,x);
   }
   void vsleft(int x)
   {
     reset();
     digitalWrite(m1b,HIGH);
     analogWrite(m1s,x);
     digitalWrite(m2f,HIGH);
     analogWrite(m2s,x);
   }
   void vsright(int x)
   {
     reset();
     digitalWrite(m1f,HIGH);
     analogWrite(m1s,x);
     digitalWrite(m2b,HIGH);
     analogWrite(m2s,x);
   }
   void speedChange(boolean left,int n)
   {
     if(left)
       analogWrite(m1s,n);
     else
       analogWrite(m2s,n);
   }
   void bugaStunt()
   {
     reset();
     boolean stat=false;
     digitalWrite(13,stat);
     front(s,1000);
     back(255,500);
     vsright(50);
     for(int i=50;i<255;i++)
     {
       speedChange(false,i);
       delay(20);
     }
     reset();
     left(255,100);
     reset();
     for(int i=0;i<11;i++)
     {
       stat=!stat;
       digitalWrite(13,stat);
       delay(80);
     }
     return;
   }
};

robot r;

void setup()
{
  Serial.begin(9600);
  boolean a=HIGH;
  r.bugaStunt();
  for(int i=0;i<8;i++)
  {
    a=!a;
    digitalWrite(13,a);
    delay(100);
  }
}

void loop()
{
  while(Serial.available())
  {
    r.reset();
    char c=(char)Serial.read();
    Serial.println(c);
    if(c=='w')
      //digitalWrite(13,LOW);
      r.vsfront(s);
    else if(c=='a')
      r.vsleft(s);
    else if(c=='s')
      r.vsback(s);
    else if(c=='d')
      r.vsright(s);
    else if(c=='\0')
      r.reset();
    else if(c=='+' && s<=255)
      s+=10;
    else if(c=='-' && s>=0)
      s-=10;
    else if(c=='*')
      r.bugaStunt();
  }
}
