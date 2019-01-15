/*
 * Taller IoT PUCP Verano 2019
 *   CLASE 2: SENSORES
 *    ACTIVIDAD: SERVO + NODEMCU V3
 */

//Primero se debe incluir la librería correspondiente
#include <Servo.h> 

//Se crea una variable tipo Objeto Servo
Servo servo;

void setup() {
  servo.attach(2); //Se adjunta el pin del nodeMCU que controlará al Servo, en este caso sera el pin D4 (GPIO2)
  servo.write(0); //Se setea al servo en un ángulo inicial, en este caso a 0°
  delay(2000);

}

void loop() {
  servo.write(90); //El servo cambia de posición a 90°
  delay(1000);
  servo.write(0); //El servo cambia de posición a 0°
  delay(1000);
}
