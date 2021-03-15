#define water A0  // water sensor pin 
#define Redlight 3 
#define buzzer 4
void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
pinMode(Redlight,OUTPUT);
pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
long level;           //  variable which gets the level of water 
level= analogRead(water);  //  read the analog value of the water sensor 

delay(1000);
if (level > 600 )   //  water crossing this level (600)
{
  digitalWrite (Redlight,HIGH);  // red light will glow
  tone(buzzer,500);         // buzzer make a alert sound
  delay(1000);
}
else      // water is under the level
{
  digitalWrite(Redlight,LOW);  // light will be darken
  noTone(buzzer);  // buzzer not alert
  delay(1000);
}
}
