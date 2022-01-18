#include <Servo.h>

Servo s;
int out;
int PIN;

void setup() {
  Serial.begin(9600);
  pinMode(A5,INPUT);
  s.attach(A4);
}



void loop() { 
  
  PIN = analogRead(A5);
  out = map( PIN , 0 , 255 , 0 , 100 );
  Serial.println(out);
  if( out <= 40 ){
    s.write(20);
    delay(100);
  }else{
    s.write(60);
    delay(50);
  }
}
