#define ENA 5
#define ENB 6
#define in1 3
#define in2 4
#define in3 7
#define in4 9

void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
}

int count = 0;

void loop() { 
  count = (count +10)%255;
  
  analogWrite(ENA,count);
  analogWrite(ENB,count);
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , LOW);
  digitalWrite(in3 , LOW);
  digitalWrite(in4 , HIGH);

  delay ( 500 ) ;
//
//  digitalWrite(in2 , HIGH);
//  digitalWrite(in1 , LOW);
//  digitalWrite(in4 , LOW);
//  digitalWrite(in3 , HIGH);
//
//  delay(1000);

//
//  digitalWrite(in1 , HIGH);
//  digitalWrite(in2 , LOW);
//  digitalWrite(in4 , LOW);
//  digitalWrite(in3 , HIGH);
//  
//  delay(1000);
//
//  digitalWrite(in1 , HIGH);
//  digitalWrite(in2 , LOW);
//  digitalWrite(in4 , LOW);
//  digitalWrite(in3 , HIGH);
//  
//  delay(1000);
//  
}
