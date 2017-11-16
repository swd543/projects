void setup() {
  

}

void loop() {
int f=(random())*255;  
analogWrite(13,f);
delay(20);
}
