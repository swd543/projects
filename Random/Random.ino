#define bug 3

void setup() {
  Serial.begin(9600);
  delay(200);
}

void loop() {
   char c=Serial.read();
   switch(c)
   {
      case '0' : analogWrite(bug,0);
                  break;
      case '1' : analogWrite(bug,255*1/10);
                  break;
      case '2' : analogWrite(bug,255*2/10);
                  break;
      case '3' : analogWrite(bug,255*3/10);
                  break;
      case '4' : analogWrite(bug,255*4/10);
                  break;
      case '5' : analogWrite(bug,255*5/10);
                  break;
      case '6' : analogWrite(bug,255*6/10);
                  break;
      case '7' : analogWrite(bug,255*7/10);
                  break;
      case '8' : analogWrite(bug,255*8/10);
                  break;
      case '9' : analogWrite(bug,255*9/10);
                  break;
      default:;
      /*default :
                 int r=random(0,255);
                  analogWrite(bug,r);
                  Serial.println(r);*/
   }
   delay(100);  
}
