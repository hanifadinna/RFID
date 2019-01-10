void setup(){
  pinMode(1, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop(){
  digitalWrite(1, HIGH);
  digitalWrite(7, LOW);
  delay(2000);
  digitalWrite(1,LOW);
  digitalWrite(7,HIGH);
  delay(2000);
}

