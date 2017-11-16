struct disp
{
  private:
    const int d [8]={6,7,8,13,12,11,10,9};
    boolean dot=true;
  public:
    void reset()
    {
        for(int i=0;i<8;i++)
        {
          pinMode(d[i],OUTPUT);
          digitalWrite(d[i],HIGH);
          if(dot)
            digitalWrite(d[7],LOW);
        }
    }
    void init(int del)
    {
      reset();
      for(int i=0;i<8;i++)
      {
         digitalWrite(d[i],LOW);
         delay(del);
      }
    }
    void dout(char c)
    {
      switch(c)
      {
        case '0':
        reset();
        digitalWrite(d[4],LOW);
        digitalWrite(d[3],LOW);
        digitalWrite(d[5],LOW);
        digitalWrite(d[0],LOW);
        digitalWrite(d[1],LOW);
        digitalWrite(d[2],LOW);
        break;
        
        case '1':
        reset();
        digitalWrite(d[2],LOW);
        digitalWrite(d[3],LOW);
        break;
        
        case '2':
        reset();
        digitalWrite(d[4],LOW);
        digitalWrite(d[3],LOW);
        digitalWrite(d[6],LOW);
        digitalWrite(d[0],LOW);
        digitalWrite(d[1],LOW);
        break;
        
        case '3':
        reset();
        digitalWrite(d[4],LOW);
        digitalWrite(d[3],LOW);
        digitalWrite(d[6],LOW);
        digitalWrite(d[2],LOW);
        digitalWrite(d[1],LOW);
        break;
        
        case '4':
        reset();
        digitalWrite(d[5],LOW);
        digitalWrite(d[6],LOW);
        digitalWrite(d[3],LOW);
        digitalWrite(d[2],LOW);
        break;
        
        case '5':
        reset();
        digitalWrite(d[4],LOW);
        digitalWrite(d[5],LOW);
        digitalWrite(d[6],LOW);
        digitalWrite(d[2],LOW);
        digitalWrite(d[1],LOW);
        break;
        
        case '6':
        reset();
        digitalWrite(d[4],LOW);
        digitalWrite(d[5],LOW);
        digitalWrite(d[6],LOW);
        digitalWrite(d[0],LOW);
        digitalWrite(d[1],LOW);
        digitalWrite(d[2],LOW);
        break;
        
        case '7':
        reset();
        digitalWrite(d[4],LOW);
        digitalWrite(d[3],LOW);
        digitalWrite(d[2],LOW);
        break;
        
        case '8':
        reset();
        digitalWrite(d[0],LOW);
        digitalWrite(d[1],LOW);
        digitalWrite(d[2],LOW);
        digitalWrite(d[3],LOW);
        digitalWrite(d[4],LOW);
        digitalWrite(d[5],LOW);
        digitalWrite(d[6],LOW);
        break;
        
        case '9':
        reset();
        digitalWrite(d[4],LOW);
        digitalWrite(d[5],LOW);
        digitalWrite(d[6],LOW);
        digitalWrite(d[3],LOW);
        digitalWrite(d[1],LOW);
        digitalWrite(d[2],LOW);
        break;
        
        case 'a':
        reset();
        digitalWrite(d[4],LOW);
        digitalWrite(d[5],LOW);
        digitalWrite(d[6],LOW);
        digitalWrite(d[0],LOW);
        digitalWrite(d[3],LOW);
        digitalWrite(d[2],LOW);
        break;
        
        case 'b':
        reset();
        digitalWrite(d[5],LOW);
        digitalWrite(d[6],LOW);
        digitalWrite(d[0],LOW);
        digitalWrite(d[1],LOW);
        digitalWrite(d[2],LOW);
        break;
        
        case 'c':
        reset();
        digitalWrite(d[4],LOW);
        digitalWrite(d[5],LOW);
        digitalWrite(d[0],LOW);
        digitalWrite(d[1],LOW);
        break;
        
        case 'd':
        reset();
        digitalWrite(d[1],LOW);
        digitalWrite(d[6],LOW);
        digitalWrite(d[0],LOW);
        digitalWrite(d[3],LOW);
        digitalWrite(d[2],LOW);
        break;
        
        case 'e':
        reset();
        digitalWrite(d[4],LOW);
        digitalWrite(d[5],LOW);
        digitalWrite(d[6],LOW);
        digitalWrite(d[0],LOW);
        digitalWrite(d[1],LOW);
        break;
        
        case 'f':
        reset();
        digitalWrite(d[4],LOW);
        digitalWrite(d[5],LOW);
        digitalWrite(d[6],LOW);
        digitalWrite(d[0],LOW);
        break;
        
        case 'x':
        init(100);
        reset();
        break;
        
        default:
        reset();
      }     
    }
    void toggleDot()
    {
        dot=!dot;
    } 
};




#define del 200
struct disp a;

void setup() {
  a.init(100);
  Serial.begin(9600);
}

char c;

void loop() {
  while(Serial.available())
  {
    c=Serial.read();
    a.dout(c);
    a.toggleDot();
    int x=(int)c;
    if(x<0)
    x=-x;
    analogWrite(3,x);
    delay(10);
  }
}




//const int d [8]={6,7,8,12,10,13,11,9};
/* a.dout('1');
  delay(del);
  a.dout('2');
  delay(del);
  a.dout('3');
  delay(del);
  a.dout('4');
  delay(del);
  a.dout('5');
  delay(del);
  a.dout('6');
  delay(del);
  a.dout('7');
  delay(del);
  a.dout('8');
  delay(del);
  a.dout('9');
  delay(del);
    a.dout('a');
  delay(del);
    a.dout('b');
  delay(del);
    a.dout('c');
  delay(del);
    a.dout('d');
  delay(del);
    a.dout('e');
  delay(del);
    a.dout('f');
  delay(del);*/
