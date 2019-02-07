// Definición para que se impriman los mensajes de Blynk
#define BLYNK_PRINT Serial

// Librerías necesarias para conectarse a Blynk
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Librerías necesarias para usar el LED IR
#include <IRremoteESP8266.h>
#include <IRsend.h>

const int pinLED = 4; // Se usa el GPIO 4 (D2)

IRsend irsend(pinLED); // Se crea una instancia del LED que envia

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

  // Inicializar la instancia de envio IR
  irsend.begin();

  // Se inicia la comunicación con Blynk con los datos dados
  Blynk.begin(token, ssid, password);
}

// Pin V0 de prendido y apagado de televisor
BLYNK_WRITE(V0) {
  Serial.println("Se uso el pin V0");

  irsend.sendRC6(0xC, 20, 2); // Se envía la señal C en codificación RC6 repetida 2 veces
}

// Pin V1 de silenciar
BLYNK_WRITE(V1) {
  Serial.println("Se usó el pin V1");

  irsend.sendRC6(0xD, 20, 2); // Se envía la señal D en codificación RC6 repetida 2 veces
}

void loop()
{
  // Se mantiene la conexión con Blynk
  Blynk.run();
}
