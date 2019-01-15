/* Taller IoT PUCP Verano 2019
*   CLASE 2: SENSORES
*    ACTIVIDAD: LDR + SERVO + NODEMCU V3
*/

//Primero se debe incluir la librería correspondiente 
#include <Servo.h>

//Definiendo variables constantes
const int LDRPin= A0;

//Se crea una variable tipo Objeto SERVO
Servo servo;

void setup() {
  Serial.begin(9600); //Se inicializa la comunicación serial
  servo.attach(2); //Se adjunta el pin del nodeMCU que controlará al Servo, en este caso sera el pin D4 (GPIO2)
  servo.write(0); //Se setea al servo en un ángulo inicial, en este caso a 0°
  delay(1000);
  pinMode(LDRPin, INPUT); //Se define los pines de entrada y salida

}

void loop() {

  int ldrStatus= analogRead(LDRPin);
    if (ldrStatus<=800){
      servo.write(0); //Si el valor de la variable ldrStatus es menor o igual a 800, entonces el servo mantiene su ángulo inicial
      Serial.println("Servo Cerrado"); //Se imprime mensaje
      delay(1000);
      
    }
    else{
      servo.write(90); //Si el valor de la variable ldrStatus es mayor a 800, entonces el servo cambia a 90°
      Serial.println("Servo Abierto"); //Se imprime mensaje
      delay(1000);
    }
}
