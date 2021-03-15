#define water A0
#define motor 4    // motor (bulb) pin
#define motor_but 3  // motor button to turn on anf off 
int motor_on = 0;    // initial motor is off 
void setup() {
  // put your setup code here, to run once:
pinMode(motor_but,INPUT);
pinMode(motor,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
long level;                  // variable which cake the level
level= analogRead(water);  // read the analog value of water sensor 
int readbut=digitalRead(motor_but);   // read the button value that it is on or off 

delay(1000);
if (readbut == 1)    // if button is pressed
{
  motor_on=1;      // signal to start the motor(bulb) 
}
if (motor_on==1)
{
  digitalWrite(motor,HIGH);   // motor will start
}


if (level > 630 )     // if it reach the value you set (630)
{
  digitalWrite (motor,LOW);  // motor will stopped (bulb will not glow)
  motor_on = 0;   // make signal motor to be off 
  delay(1000);
}

}
