/*
 * Taller IoT PUCP Verano 2019
 * Clase Blynk: servo_Blynk
 * Actividad: Conexión del servo a una app 
 */

#include <Servo.h>

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


//Se crea una variable tipo Objeto SERVO
Servo servo;


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char token[] = "";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "redpucp";
char pass[] = "C9AA28BA93";


void setup() {
  Serial.begin(9600); //Se inicializa la comunicación serial
  servo.attach(2); //Se adjunta el pin del nodeMCU que controlará al Servo, en este caso sera el pin D4 (GPIO2)
  servo.write(0); //Se setea al servo en un ángulo inicial, en este caso a 0°
  delay(1000);
  
  // Se inicia la comunicación con Blynk con los datos dados
  Blynk.begin(token, ssid, pass);

}

BLYNK_WRITE(V2) {
  servo.write(param.asInt());
}
  
void loop() {
  Blynk.run();
}
