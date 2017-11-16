void setup() {
  for(long i=25;i<13500;i+=4)
  {
    tone(9,i);
    analogWrite(13,(i/60));
    delay(1);
  }
  for(long i=13500;i>=25;i-=4)
  {
    tone(9,i);
    analogWrite(13,(i/60));
    delay(1);
  }
  noTone(9);

}

void loop() {
  
}
