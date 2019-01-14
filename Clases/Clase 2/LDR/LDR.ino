/* CLASE 2: SENSORES
 *  LDR + NODEMCU V3
 */

void setup() {
  Serial.begin(9600);   // inicializando comunicación serial
}

void loop() {

  int sensorValue = analogRead(A0);   // Se lee el valor en el pin analógico 0
  float voltage = sensorValue * (5.0 / 1023.0);   // convertir el valor analógico leído (which goes from 0 - 1023) a voltaje (0 - 5V)

  Serial.println(voltage);   // imprimir el valor leído
  delay(1000);

}
