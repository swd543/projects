#include <EEPROM.h>
//6604CFC8


long r=0x6604CFC8;
int p=500;

void setup() 
{
  Serial.begin(9600);
  //splitWrite(p,r,0xf0);
  
  

  delay(4000);
}

void loop() {
  splitRead(p);
delay(500);
}
  
  
void splitWrite(int c, long data, byte def) //only 5 bytes reserved, 4 for data and 1 for identifier
{
  long l=data;
  while(l>0x00)
  {
    byte b=l%0x100;
    l=l/0x100;
    EEPROM.write(c,b);
    c++;
  }
  EEPROM.write(c,def);
}

long splitRead(int c)
{
  long t=0x00;
  int s[4];
  for(int i=0;i<4;i++)
  {
    s[i] = EEPROM.read(c);
    c++;
  }
  for(int j=0;j<4;j++)
  {
    Serial.print(s[j],HEX);
  }
} 
