/*
 * Taller IoT PUCP Verano 2019
 * Trabajando con un LED RGB
 *
 * Se configura un LED RGB para que muestre diferentes
 * colores de acuerdo a la configuración dada por el
 * valor RGB.
 */

int redPin = 14; // GPIO14 = D5, color rojo
int greenPin = 12; // GPIO12 = D6, color verde
int bluePin = 13; // GPIO13 = D7, color azul

void setup() {
  // Se definen todos los pines como OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop() {
  /*
   * Se usa esta función para asignar un color
   * (rojo, verde, azul).
   * Se pueden usar valores de 0 - 255.
   */
  setColor(255, 0, 0);  
  delay(500); // Se espera medio segundo antes de pasar al siguiente color
  setColor(0, 255, 0);  
  delay(500);
  setColor(0, 0, 255);  
  delay(500);
  setColor(255, 0, 255);  
  delay(500);
}

void setColor(long red, long green, long blue) {
  /*
   * Los valores que se deben escribir al final
   * tienen que estar en el rango de 0 - 1024.
   * Por lo tanto, se multiplica el valor dado
   * de 0 - 255 por el factor de dividir
   * 1024 entre 255.
   */
  long factor = 1024.0/255.0;
  red = red * factor;
  green = green * factor;
  blue = blue * factor;
  
  /*
   * El LED RGB con el que se trabaja funciona con un
   * ánodo común, por lo que los valores tienen que
   * estar invertidos para que funcione correctamente
   * (0 = mayor intensidad, 255 = menor intensidad).
   */
  red = 1024 - red;
  green = 1024 - green;
  blue = 1024 - blue;

  // Se escribe el valor deseado a cada pin del LED.
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
