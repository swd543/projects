#include <IRremote.h>
#include <IRremoteInt.h>

//#include <IRremote.h>
#define numberOfKeys 5  //change this value to change the amount of keys to be recorded!
#define ir A0
#define op 13
#define sn 4


//const int ir = A0;
//const int op       = 13;
//const int numberOfKeys = 5;
long irKeyCodes[numberOfKeys];
unsigned long cycle_period=0;
IRrecv irrecv(ir);
decode_results results;


void setup()
{
  delay(4000);
  Serial.begin(9600);
  pinMode(ir, INPUT);
  pinMode(sn, INPUT);
  pinMode(op, OUTPUT);
  irrecv.enableIRIn();             
  learnKeycodes();
  cycle_period = sync();                  
  Serial.println("Press a remote key");
}

void loop()
{
  long key;
  unsigned long  brightness;

  if (irrecv.decode(&results))
  {
    irrecv.resume();
    key = convertCodeToKey(results.value);
    if(key >= 0)
    {
      Serial.print("Got key ");
      Serial.println(key);
      brightness = map(key, 0,numberOfKeys-1, 0,10000);
      digitalWrite(op,HIGH);
      delayMicroseconds(brightness);
      digitalWrite(op,LOW);
      //analogWrite(op, brightness);
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

unsigned long sync()
{
  unsigned long period=0;
  int pin;
  
  while(1)
  {
    pin = digitalRead(sn);
    if(pin == HIGH)
     {
      period = micros();
      break;
     }
  }
   period = pulseIn(sn,LOW);
   return period;
}

