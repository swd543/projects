void setup() {
  

}

void loop() {
int f=(random())*255;
int g=(random())*255;
int h=(random())*255;
int j=(random())*255;

analogWrite(13,f);
analogWrite(9,g);
analogWrite(10,h);
analogWrite(11,j);

delay(100);
}
