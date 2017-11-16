void setup() {      //white clk/d+, blue dout/d-
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  analogWrite(10,170);
  delay(10);
  pinMode(10,INPUT);
  pinMode(9,INPUT);
}

void loop() {
  if(digitalRead(9)==HIGH)
  Serial.print("HIGH    ");
  else
  Serial.print("LOW     ");
  if(digitalRead(10)==HIGH)
  Serial.print("HIGH\n");
  else
  Serial.print("LOW\n");
  delay(100);
}
