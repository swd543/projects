void setup() {
 Serial.begin(9600);
 pinMode(5,INPUT);
 pinMode(6,INPUT);
}

void loop() {
  tone(11,1200);
  int a=digitalRead(5);
  int b=digitalRead(6);
  if(a==HIGH)
   Serial.print(" 5 HI ");
  else
   Serial.print(" 5 LOW ");
  if(b==HIGH)
   Serial.print(" 6 HI ");
  else
   Serial.print(" 6 LOW ");
  Serial.println();
  delay(1000);
  
}
