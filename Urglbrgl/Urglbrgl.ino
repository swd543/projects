int c=0;

void setup() {
  Serial.begin(9600);

}

void loop() {
 if(c<255)
  c++;
 else
  c=0;
 Serial.println(c);
 analogWrite(13,c);
 delay(50); 
}
