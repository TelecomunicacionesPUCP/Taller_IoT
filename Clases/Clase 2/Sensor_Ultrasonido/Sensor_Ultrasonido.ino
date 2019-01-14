/*
 * Talller IoT PUCP Verano 2019
 * Sensor de Ultrasonido
 * 
 * Se usa el sensor HC-SR04 para medir distancias
 * y luego mostrarlas en el monitor Serial.
 * Se usa la libreria Ultrasonic escrita por
 * Erick Simoes.
 * 
 * Primero se sube este archivo con el sensor completamente
 * desconectado, luego de que se haya cargado completamente
 * se realizan todas las conexiones y se abre el monitor
 * serial para observar las mediciones.
 */

// Se incluye la librería a usar
#include <Ultrasonic.h>

// En este caso se usan los pines GPIO 12 y 13, que
// corresponden a los pines D6 y D7 respectivamente.
Ultrasonic ultrasonic(12, 13);

// En esta variable se guardará la distancia obtenida por el sensor
int distance;

void setup() {
  // Se configura la velocidad del monitor serial a 9600 bps
  Serial.begin(9600);
}

void loop() {
  // Se usa la función de la librería para obtener la medición
  distance = ultrasonic.read();

  // Se imprime este resultado 
  Serial.print("Distancia = ");
  Serial.print(distance);
  Serial.println(" cm.");
  delay(1000);
}
