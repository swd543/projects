void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
}

void loop() {
  Serial.println("Tick");
  digitalWrite(9,HIGH);
  delay(2);
  digitalWrite(9,LOW);
  for(int i=0;i<247;i++)
  {
    analogWrite(13,i);
    delay(2);
  }
  for(int i=247;i>=0;i--)
  {
    analogWrite(13,i);
    delay(2);
  } 
}
