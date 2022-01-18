#include <Servo.h>

Servo s;
int out;
int PIN;

void setup() {
  pinMode(A3,INPUT);
  Serial.begin(9600);
  s.attach(5);
}



void loop() { 
  
  PIN = analogRead(A3);
  out = map( PIN , 0 , 1023 , 0 , 180 );
  s.write(out);
}
