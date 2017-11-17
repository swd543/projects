#include <ps2.h>
PS2 mouse(6, 5);


void mouse_init()
{
  delay(3000);        // Start the serial monitor, you fool!
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
  delay(4000);
  Serial.print("done.\n");
  Serial.println("\nYou may start.");
}

void setup()
{
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
     // ignore ack 
  mstat = mouse.read();
  mx = mouse.read();
  my = mouse.read();
  mstat=mstat & 0x0f;
  /* send the data back up */
  Serial.print(mstat, BIN);
  Serial.print("\tX=");
  Serial.print(mx, DEC);
  Serial.print("\tY=");
  Serial.println(my, DEC);
  
  Serial.println();
  delay(20);  /* twiddle */
}
