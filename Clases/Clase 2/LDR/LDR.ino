/* Taller IoT PUCP Verano 2019
*   CLASE 2: SENSORES
*    ACTIVIDAD: LDR + NODEMCU V3
*/

void setup() {
  Serial.begin(9600);   // Se inicializa la comunicación serial
}

void loop() {

  int sensorValue = analogRead(A0);   // Se lee el valor correspondiente al pin analógico 0
  float voltage = sensorValue * (5.0 / 1023.0);   // Se convierte el valor analógico leído (que oscila entre 0 - 1023) a voltaje (0 - 5V)

  Serial.println(voltage);   // Se imprime el valor leído
  delay(1000);

}
