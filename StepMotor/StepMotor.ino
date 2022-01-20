#define all_low_for_anding 0b00001111

byte out = 0b00010000;
byte outhalf = 0b00110000;
byte tmp = 0;
void setup() {
  DDRD = 0b11110000 | DDRD;
}

void loop() {
  //save needed value in tmp
  tmp = DDRD & all_low_for_anding;
  // shift output 
  out = out << 1;
  if(out == 0b00000000){
    out = 0b00010000;
  }
  //merge out and saved value
  tmp = tmp | out;
  PORTD = out;
  delay(2);


  //save needed value in tmp
  tmp = DDRD & all_low_for_anding;
  // shift output 
  outhalf = outhalf << 1;
  if(outhalf == 0b00000000){
    outhalf = 0b00010000;
  }
  //merge out and saved value
  tmp = tmp | outhalf;
  PORTD = outhalf;
  delay(2);
}
