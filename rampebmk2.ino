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
  myservo.write(90);

}

void loop() {
  irrecv.decode(&results);
  Serial.println(results.value);
    if (results.value == 0xFF30CF){
        Serial.println("1");
        rebour();
      }
  irrecv.resume();
  results.value = 0;
  delay (1000);
}

void rebour () {
    digitalWrite(ledrouge, HIGH);
    delay (2000);
    digitalWrite(ledrouge, LOW);
    
    digitalWrite(ledorange, HIGH);
    delay (2000);
    digitalWrite(buzz, HIGH);
    delay (100);
    digitalWrite(ledorange, LOW);
    digitalWrite(buzz, LOW);
    Serial.println("2");
    
    digitalWrite(ledorange, HIGH);
    delay (1000);
    digitalWrite(buzz, HIGH);
    delay (100);
    digitalWrite(ledorange, LOW);
    digitalWrite(buzz, LOW);
    Serial.println("3");

    digitalWrite(ledverte, HIGH);
    delay (1000);
    digitalWrite(buzz, HIGH);
    delay (100);
    myservo.write(0);
    delay (3000);
    digitalWrite(ledverte, LOW);
    digitalWrite(buzz, LOW);
    Serial.println("GO");
   
}
