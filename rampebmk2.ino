#include <IRremote.h>
#include <Servo.h>

int ledrouge = 4 ;
int moteur = 9 ;
int ledorange = 5 ;
int ledverte = 6 ;
int buzz = 2 ;

int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

Servo myservo;


void setup() {

  myservo.attach(moteur);
  pinMode(ledrouge, OUTPUT);
  pinMode(ledorange, OUTPUT);
  pinMode(ledverte, OUTPUT);
  pinMode(buzz, OUTPUT);
  irrecv.enableIRIn();
  Serial.begin(9600);

}

void loop() {

  myservo.write(90);
  digitalWrite(ledrouge, HIGH);
  if (irrecv.decode(&results))
    Serial.println("POWER");
  {
    if (results.value = 0xFFA25D);
    irrecv.resume();
    delay (5000);
    digitalWrite(ledrouge, LOW);
    
  for (int i = 0; i <= 3; i++) {
    digitalWrite(ledorange, HIGH);
    digitalWrite(buzz, HIGH);
    delay (2000);
    digitalWrite(ledorange, LOW);
    digitalWrite(buzz, LOW);
    delay (1000);

    digitalWrite(ledorange, HIGH);
    digitalWrite(buzz, HIGH);
    delay (1000);
    digitalWrite(ledorange, LOW);
    digitalWrite(buzz, LOW);

    digitalWrite(ledverte, HIGH);
    digitalWrite(buzz, HIGH);
    delay (3000);
    digitalWrite(ledverte, LOW);
    digitalWrite(buzz, LOW);


    myservo.write(0);
    delay (3000);
    digitalWrite(ledverte, LOW);
    irrecv.resume();
  }
}
}
