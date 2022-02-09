/*
AUTHOR: Hazim Bitar (techbitar)
DATE: Aug 29, 2013
LICENSE: Public domain (use at your own risk)
CONTACT: techbitar at gmail dot com (techbitar.com)
*/
 
#include <SoftwareSerial.h>
 
SoftwareSerial BTSerial(0, 1);   // RX | TX
#define ENA 5
#define ENB 6
#define in1 2
#define in2 3
#define in3 4
#define in4 7
#define rec 8
#define horn 9
#define front 10
#define back 11

void setup() 
{

  pinMode(front , OUTPUT);
  pinMode(back , OUTPUT);
  pinMode(horn , OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(9, OUTPUT); 
  
  /* this pin will pull the HC-05 pin 34 (KEY pin) HIGH to switch module to AT mode */
 
  digitalWrite(9, HIGH); 
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);  // HC-05 default speed in AT 
                          // command mode
}
 char y;
 
void loop()
{ 
  if (Serial.available()){
     y = Serial.read();
     switch(y){
      case 'F':
        digitalWrite(in2 , HIGH);
        digitalWrite(in1 , LOW);
        digitalWrite(in4 , HIGH);
        digitalWrite(in3 , LOW);
        break;
      case 'B':
        digitalWrite(in1 , HIGH);
        digitalWrite(in2 , LOW);
        digitalWrite(in3 , HIGH);
        digitalWrite(in4 , LOW);
        break;
      case 'S':
        digitalWrite(in1 , LOW);
        digitalWrite(in2 , LOW);
        digitalWrite(in4 , LOW);
        digitalWrite(in3 , LOW);
        break;
      case 'L':
        digitalWrite(in1 , LOW);
        digitalWrite(in2 , HIGH);
        digitalWrite(in4 , LOW);
        digitalWrite(in3 , LOW);
        break;
      case 'R':
        digitalWrite(in1 , LOW);
        digitalWrite(in2 , LOW);
        digitalWrite(in3 , LOW);
        digitalWrite(in4 , HIGH);
        break;
      case 'V':
        digitalWrite(horn , HIGH);
        break;
      case 'v':
        digitalWrite(horn , LOW);
        break;
      case 'W':
        digitalWrite(front , HIGH);
        break;
      case 'w':
        digitalWrite(front , LOW);
        break;
      case 'U':
        digitalWrite(back , HIGH);
        break;
      case 'u':
        digitalWrite(back , LOW);
        break;
        defult: break;
     }
     
     Serial.write(y);
}
}
