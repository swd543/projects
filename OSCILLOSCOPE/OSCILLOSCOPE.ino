#define ANALOG_IN A0
 
void setup() {
  delay(1000);
  Serial.begin(115200); 
}
 
void loop() {
  int val = analogRead(ANALOG_IN);                                              
  Serial.write( 0xff );                                                         
  Serial.write( (val >> 8) & 0xff );                                            
  Serial.write( val & 0xff );
}
