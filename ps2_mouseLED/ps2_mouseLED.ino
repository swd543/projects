#include <ps2.h>
PS2 mouse(6, 5); //6 CLK (White) 5 DATA (Blue)


void mouse_init()
{
  delay(4000);        // Start the serial monitor, you fool!
  mouse.write(0xf5);  // serial mode report off
  mouse.read();
  mouse.write(0xff);  // reset
  Serial.print("Reset ack : ");
  Serial.println(mouse.read(),HEX);
  
  mouse.write(0xf2);  //request device id, 0 for standard, 4 for scroll
  Serial.print("DevID ack : ");
  Serial.println(mouse.read(),HEX);
  Serial.print("DevID : ");
  Serial.println(mouse.read());
  
  
  mouse.write(0xf4);  //report on
  Serial.print("Report on : ");
  Serial.println(mouse.read(),HEX);
  Serial.print("\nInitializing mouse....");    
  delay(1500);
  Serial.print("done.\n");
  Serial.println("\nYou may start.");
}

void setup()
{
  pinMode(9,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  mouse_init();
}

/*
 * get a reading from the mouse and report it back to the
 * host via the serial line.
 */
void loop()
{
  char mstat;
  char mx;
  char my;
  int x;
  int y;
  
     // ignore ack 
  mstat = mouse.read();
  mx = mouse.read();
  my = mouse.read();
  mstat=mstat & 0x0f;
  
  x=mx,DEC;
  y=my,DEC;
  
  /* send the data back up */
  Serial.print(mstat, BIN);
  Serial.print("\tX=");
  Serial.print(x);
  Serial.print("\tY=");
  Serial.println(y);
  Serial.println();
  
  if(x>5)
    digitalWrite(11,HIGH);
  else if(x < -5)
    digitalWrite(13,HIGH);
  else;
  
  
  if(y>5)
    digitalWrite(9,HIGH);
  else if(y < -5)
    digitalWrite(3,HIGH);
  else;
  
  delay(20);  /* twiddle */
  
  digitalWrite(9,LOW);
  digitalWrite(3,LOW);
  digitalWrite(11,LOW);
  digitalWrite(13,LOW);
  
}
