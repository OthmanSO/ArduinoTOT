void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(3,OUTPUT);
}
int x,y;
boolean push;
boolean pushbefore;
boolean out = false;
void loop() {
  x = analogRead(A0);
  y = analogRead(A1);
  pushbefore = push;
  push = digitalRead(2);
  delay(5);
  if(push && push !=pushbefore){
    out = !out;
    digitalWrite(3, out);
  }
}
