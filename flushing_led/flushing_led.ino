
void setup() {
  // put your setup code here, to run once:
  pinMode(A3,INPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}

int PIN;
int send;

void loop() {
  PIN = analogRead(A3);
  send = map(PIN, 0 , 1023 , 0 , 100);
  Serial.print(send);
  Serial.write("% \n");
  analogWrite(5,PIN);
  delay (100);
}
