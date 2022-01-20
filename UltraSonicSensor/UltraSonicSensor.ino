void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
}

int time ;
int distance;

void loop() {
  
  time = 0;
  //write 0 to 2 micro
  digitalWrite(3,LOW);
  delayMicroseconds(2);
  //write 1 to 10 micro
  digitalWrite(3,HIGH);
  delayMicroseconds(10);
  //echo back
  time = pulseIn(2,HIGH);
  distance =  0.017 * time;
  Serial.println(distance);
  digitalWrite(4,LOW);
  if (distance < 20)
    digitalWrite(4,HIGH);
}
