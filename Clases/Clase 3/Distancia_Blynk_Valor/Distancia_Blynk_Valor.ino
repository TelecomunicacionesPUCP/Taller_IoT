/*
 * Taller IoT PUCP Verano 2019
 * Clase 3: Sensor Ultrasonido Blynk
 * Actividad: Conexión del sensor de ultrasonido a Blynk
 */

// Definición para que se impriman los mensajes de Blynk
#define BLYNK_PRINT Serial

// Librerías necesarias para conectarse a Blynk
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Librería para el sensor de Ultrasonido
#include <Ultrasonic.h>

// Definición del sensor y la variable de distancia
// Se usan los pines GPIO 12 y 13 (D6 y D7 respectivamente)

// IMPORTANTE: desconectar el sensor antes de subir
// y conectarlo recién cuando se haya subido el sketch
Ultrasonic ultrasonic(12, 13);
int distancia;

// Token de autenticación para conectarse al proyecto de Blink
// CAMBIAR
char* token = "";

// Datos de la red para conectarse a Internet
// CAMBIAR
char* ssid = "redpucp";
char* password = "C9AA28BA93";

void setup()
{
  // Inicializar la comunicación serial
  Serial.begin(9600);

  // Se inicia la comunicación con Blynk con los datos dados
  Blynk.begin(token, ssid, password);
}

// Uso de un pin virtual (pin V0)
// IMPORTANTE: esta fuera del loop
BLYNK_READ(V0)
{
  // Se lee la distancia del sensor
  distancia = ultrasonic.read();

  // Lo escribimos al puerto serial para asegurar que se
  // ha leído correctamente del sensor
  Serial.println(distancia);

  // Se manda a Blynk para que se muestre
  Blynk.virtualWrite(V0, distancia);
}

void loop()
{
  // Se mantiene la conexión con Blynk
  Blynk.run();
}
