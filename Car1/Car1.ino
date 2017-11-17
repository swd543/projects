#define fw 6
#define bk 5
#define lf 3
#define rt 4
#define tb 7

void setup() {
 analogWrite(fw,100);
 digitalWrite(lf,HIGH);
 delay(500);
 analogWrite(fw,0);
 digitalWrite(lf,LOW);
 analogWrite(bk,100);
 digitalWrite(rt,HIGH);
 delay(500);
 analogWrite(bk,0);
 digitalWrite(rt,LOW);
}

void loop() {
 
}
