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
  
  mouse.write(0xf3);  //Set sample rate 200
  Serial.print("Sample rate ack : ");
  Serial.println(mouse.read(),HEX);
  mouse.write(0xc8); //200
  Serial.print("Sample rate 200 ack : ");
  Serial.println(mouse.read(),HEX);
  
  mouse.write(0xf3);  //Set sample rate 100
  Serial.print("Sample rate ack : ");
  Serial.println(mouse.read(),HEX);
  mouse.write(0x64); //100
  Serial.print("Sample rate 200 ack : ");
  Serial.println(mouse.read(),HEX);
  
  mouse.write(0xf3);  //Set sample rate 80
  Serial.print("Sample rate ack : ");
  Serial.println(mouse.read(),HEX);
  mouse.write(0x50); //80
  Serial.print("Sample rate 80 ack : ");
  Serial.println(mouse.read(),HEX);
  
  mouse.write(0xf2);  //request device id, 0 for standard, 3 for scroll
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

void loop()
{}
