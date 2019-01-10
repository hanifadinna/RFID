#define BUZZER 4 //buzzer pin

void setup() 
{
    Serial.begin(9600);   // Initiate a serial communication
     pinMode(BUZZER, OUTPUT);
     noTone(BUZZER);

}

void loop (){

  digitalWrite(BUZZER, HIGH);
  delay(500);
  tone(BUZZER, 500);
  delay(300);
  noTone(BUZZER);
}

