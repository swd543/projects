void setup() {
  pinMode(8,INPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  
  
  
  if(digitalRead(8)==HIGH)
 {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  
   
   
   
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  
  
  digitalWrite(9,HIGH);
  delay(200);
  digitalWrite(9,LOW);
  digitalWrite(11,HIGH);
  delay(200);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
  delay(200);
  digitalWrite(10,LOW);
  digitalWrite(12,HIGH);
  delay(200);
  digitalWrite(12,LOW);
 }
 else
   delay(20);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
 
}
