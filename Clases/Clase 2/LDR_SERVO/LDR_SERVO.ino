#include <Servo.h>

const int ledPin=D1;
const int LDRPin= A0;

Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(2);
  servo.write(0);
  delay(2000);
  pinMode(ledPin, OUTPUT);
  pinMode(LDRPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrStatus= analogRead(LDRPin);
    if (ldrStatus<=300){
      servo.write(0);
      delay(1000);
      //digitalWrite(ledPin, HIGH);
      //Serial.print(ldrStatus);
      //Serial.println("LDR detecta oscuridad, el LED se enciende");
      
    }
    else{
      servo.write(90);
      delay(1000);
      //digitalWrite(ledPin, LOW);
      //Serial.println("LED apagado");
    }

}
