#define fw 4
#define bk 5
#define lf 6
#define rt 7
#define tb 3

void setup() {
 pinMode(tb,INPUT);
  
}

void loop() {
 int spd=0;
 int c=0;
 if(tb!=0)
 {
   do{
     
 
 analogWrite(13,spd);   
  
}


void speed(int pin, int l)
{
pinMode(pin,OUTPUT);
digitalWrite(pin,HIGH);
delay(l);
digitalWrite(pin,LOW);
delay(10-l);
}



