/*
 * Taller IoT PUCP Verano 2019
 * Clase 3: RGB_Blynk
 * Actividad: Conexión del LED RGB a la aplicación Blynk
 */

// Definición para que se impriman los mensajes de Blynk
#define BLYNK_PRINT Serial

// Librerías necesarias para conectarse a Blynk
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

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

  // Inicializar los pines como salidas para el LED
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);

  // Se inicia la comunicación con Blynk con los datos dados
  Blynk.begin(token, ssid, password);
}

// Uso de un pin virtual
// IMPORTANTE: esta fuera del loop
BLYNK_WRITE(V1)
{
  // Como se usa un pin virtual, los datos que vienen de la aplicación
  // se recepcionan de esta manera
  int r = param[0].asInt(); // Se define que este dato es un entero
  int g = param[1].asInt();
  int b = param[2].asInt();

  // Al ser un LED con ánodo común, se tienen que invertir los valores
  r = 1023 - r;
  g = 1023 - g;
  b = 1023 - b;

  // Estos valores se escriben en los pines indicados
  analogWrite(D5 ,r);
  analogWrite(D6, g);
  analogWrite(D7, b);
}

void loop()
{
  // Se mantiene la conexión con Blynk
  Blynk.run();
}
