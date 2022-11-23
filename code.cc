#include<Servo.h>
const int trigger = 7;
const int eco = 6;
long duracao;
float dist2;
float dist1;
Servo servo;
const int triggerLed = 11;
const int ecoLed = 10;
const int led = 2;
long duracaoLed;

void setup(){
  pinMode (trigger, OUTPUT);
  pinMode (eco, INPUT);
  pinMode (triggerLed, OUTPUT);
  pinMode (ecoLed, INPUT);
  pinMode (led, OUTPUT);
  Serial.begin (9600);
}

void loop () {

  digitalWrite (trigger, LOW);
  delayMicroseconds (5);
  digitalWrite (trigger, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigger, LOW);
  delayMicroseconds (10);

  duracao = pulseIn (eco,HIGH);

  dist1 = (duracao * 0.034)/2;

  servo.attach (8);

  if (dist1<=28) {
    servo.write (90);
    Serial.print (dist1);
    Serial.print ("cm = ");
    Serial.println ("aberto");
    delay (4000);
  }
    else {
      servo.write (0);
      Serial.print (dist1);
      Serial.print ("cm = ");
      Serial.println ("fechada"); 
    }
  
  digitalWrite (triggerLed, LOW);
  delayMicroseconds (5);
  digitalWrite (triggerLed, HIGH);
  delayMicroseconds (10);
  digitalWrite (triggerLed, LOW);
  delayMicroseconds (10);
  
  duracaoLed = pulseIn (ecoLed,HIGH);
  
  dist2 = (duracaoLed * 0.034)/2;
  
  if (dist2<=4) {
    digitalWrite(led, HIGH);
    Serial.print (dist2);
    Serial.print ("cm = ");
    Serial.println ("led ligado");
    delay (3000);
  }
    else {
      digitalWrite(led, LOW);
      Serial.print (dist2);
      Serial.print ("cm = ");
      Serial.println ("led desligado"); 
    }
}
