
void setup() {
  // put your setup code here, to run once:
  pinMode(A3,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
}

int PIN;

void loop() {
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  PIN = analogRead(A3);
  Serial.println(PIN);
  analogWrite(5,PIN);
  if(PIN > 200){
    digitalWrite(5,HIGH); 
  }
  if(PIN > 400){
    digitalWrite(6,HIGH); 
  }
  if(PIN > 600){
    digitalWrite(7,HIGH); 
  }
  delay (100);
}
