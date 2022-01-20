#include <Key.h>
#include <Keypad.h>

void setup() {
  Serial.begin(9600);
  DDRC = 0b111111;
  pinMode(10, OUTPUT);
}


char x = 0;
char keys[4][4]={{16,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
byte rows [4]= {5,4,3,2};
byte columns [4]= {6,7,8,9};

void loop() {
 Keypad k = Keypad( makeKeymap(keys), rows, columns, 4, 4);
 char newx =k.getKey();
 if(newx && newx != x )
  x = newx;
 switch(x){
  case(16):
    PORTC = 0b111111;
    digitalWrite(10, LOW);
    break;
  case(1):
    PORTC = 0b000110;
    digitalWrite(10, LOW);
    break;
  case(2):
    PORTC = 0b011011;
    digitalWrite(10, HIGH);
    break;
  case(3):
    PORTC = 0b001111;
    digitalWrite(10, HIGH);
    break;
  case(4):
    PORTC = 0b100110;
    digitalWrite(10, HIGH);
    break;
  case(5):
    PORTC = 0b101101;
    digitalWrite(10, HIGH);
    break;
  case(6):
    PORTC = 0b111101;
    digitalWrite(10, HIGH);
    break;
  case(7):
    PORTC = 0b000111;
    digitalWrite(10, LOW);
    break;
  case(8):
    PORTC = 0b111111;
    digitalWrite(10, HIGH);
    break;
  case(9):
    PORTC = 0b101111;
    digitalWrite(10, HIGH);
    break;
  case(10):
    PORTC = 0b110111;
    digitalWrite(10,HIGH);
    break;
  case(11):
    PORTC = 0b111100;
    digitalWrite(10, HIGH);
    break; 
  case(12):
    PORTC = 0b111001;
    digitalWrite(10, LOW);
    break;
  case(13):
    PORTC = 0b011110;
    digitalWrite(10, HIGH);
    break;
  case(14):
    PORTC = 0b111001;
    digitalWrite(10, HIGH);
    break;
  case(15):
    PORTC = 0b110001;
    digitalWrite(10, HIGH);
    break;
  }
  Serial.println(x);
}
