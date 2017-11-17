#include <Servo.h>
#include <IRremote.h>

#define numberOfKeys 10  //change this value to change the amount of keys to be recorded!
#define ir A3
#define op 5
#define servo 13

Servo buga;

//const int ir = A0;
//const int op       = 13;
//const int numberOfKeys = 5;
long irKeyCodes[numberOfKeys];

IRrecv irrecv(ir);
decode_results results;


void setup()
{
  //delay(4000);
  Serial.begin(9600);
  pinMode(ir, INPUT);
  pinMode(op, OUTPUT);
  irrecv.enableIRIn();             
  learnKeycodes();                  
  Serial.println("Press a remote key");
  buga.attach(servo);
}

void loop()
{
  long key;
  int  brightness;

  if (irrecv.decode(&results))
  {
    irrecv.resume();
    key = convertCodeToKey(results.value);
    if(key >= 0)
    {
      Serial.print("Got key ");
      Serial.println(key);
      brightness = map(key, 0,numberOfKeys-1, 0, 180);
      analogWrite(op, brightness);
      buga.write(brightness);
    }
  }
}


void learnKeycodes()
{
  while(irrecv.decode(&results))
    irrecv.resume();
 
  Serial.println("Ready to learn remote codes!");
  long prevValue = -1;
  int i=0;
  while( i < numberOfKeys)
  {
    Serial.print("Please press remote key ");
    Serial.print(i);
    while(true)
    {
      if( irrecv.decode(&results) )
      {
          if(results.value != -1 && results.value != prevValue)
          {
            showReceivedData();
            irKeyCodes[i] = results.value;
            i = i + 1;
            prevValue = results.value;
            irrecv.resume();
            break;
          }
        irrecv.resume();
      }
    }
  }
  Serial.println("Learning complete");
}

int convertCodeToKey(long code)
{
  for( int i=0; i < numberOfKeys; i++)
  {
    if( code == irKeyCodes[i])
    {
      return i;
    }
  }
  return -1;
}

/*void learnKeycodes()
{
  while(irrecv.decode(&results))
    irrecv.resume();
 
  Serial.println("Ready to learn remote codes");
  long prevValue = -1;
  int i=0;
  while( i < numberOfKeys)
  {
    Serial.print("press remote key ");
    Serial.print(i);
    while(true)
    {
      if( irrecv.decode(&results) )
      {
          if(results.value != -1 && results.value != prevValue)
          {
            showReceivedData();
            irKeyCodes[i] = results.value;
            i = i + 1;
            prevValue = results.value;
            irrecv.resume();
            break;
          }
        irrecv.resume();
      }
    }
  }
  Serial.println("Learning complete");
}

int convertCodeToKey(long code)
{
  for( int i=0; i < numberOfKeys; i++)
  {
    if( code == irKeyCodes[i])
    {
      return i;
    }
  }
  return -1;
}*/


void showReceivedData()
{
  if (results.decode_type == UNKNOWN)
  {
    Serial.println("-Could not decode message");
  }
  else
  {
    if (results.decode_type == NEC) {
      Serial.print("- decoded NEC: ");
    }
    else if (results.decode_type == SONY) {
      Serial.print("- decoded SONY: ");
    }
    else if (results.decode_type == RC5) {
      Serial.print("- decoded RC5: ");
    }
    else if (results.decode_type == RC6) {
      Serial.print("- decoded RC6: ");
    }
    Serial.print("hex value = ");
    Serial.println( results.value, HEX);
  }
}
