#define EN1 3
#define EN2 4
#define EN3 5
#define EN4 6

void setup() {
  DDRC = 0b111111;
  Serial.begin(9600);
  pinMode ( 2 , OUTPUT ); 
  pinMode ( EN1 , OUTPUT );
  pinMode ( EN2 , OUTPUT );
  pinMode ( EN3 , OUTPUT );
  pinMode ( EN4 , OUTPUT );
  Serial.setTimeout(2);
}
int y[4] = {0,0,0,0};
int en = 0;
void loop() {
  digitalWrite( EN1 , HIGH );
  digitalWrite( EN2 , HIGH );
  digitalWrite( EN3 , HIGH );
  digitalWrite( EN4 , HIGH );
 
  int x = Serial.parseInt();
  
  if(x){
    y[0] = x/1000;
    x = x%1000;
    y[1] = x/100;
    x = x % 100;
    y[2] = x/10;
    y[3] = x%10;
  }
  switch ( en ){
    case(0): digitalWrite( EN1 , LOW ); break;
    case(1): digitalWrite( EN2 , LOW ); break;
    case(2): digitalWrite( EN3 , LOW ); break;
    case(3): digitalWrite( EN4 , LOW ); break;
  }
//0b111111, 0b011000, 0b110110, 0b111100, 0b011001, 0b101101, 0b101111, 0b111000, 0b111111, 0b111101, 
  switch(y[en]){
    case (0):
    PORTC = 0b111111;
    digitalWrite( 2 , LOW );
    delay(1);
    break;
    case(1):
    PORTC=0b011000;
    digitalWrite( 2 , LOW );
    delay(1);
    break;
    case(2):
    PORTC= 0b110110;
    digitalWrite( 2 , HIGH);
    delay(1);
    break;
    case(3):
    PORTC=0b111100;
    digitalWrite( 2 , HIGH);
    delay(1);
    break;
    case(4):
    PORTC=0b011001;
    digitalWrite( 2 , HIGH );
    delay(1);
    break;
    case(5):
    PORTC= 0b101101;
    digitalWrite( 2 , HIGH );
    delay(1);
    break;
    case(6):
    PORTC =0b101101;
    digitalWrite( 2 , HIGH );
    delay(1);
    break;
    case(7):
    PORTC= 0b111000;
    digitalWrite( 2 , LOW );
    delay(1);
    break;
    case(8):
    PORTC=0b111111;
    digitalWrite( 2 , HIGH );
    delay(1);
    break;
    case(9):
    PORTC= 0b111101;
    digitalWrite( 2 , HIGH );
    delay(1);
    break;    
  }
    en = ( en + 1 ) % 4;

 }
