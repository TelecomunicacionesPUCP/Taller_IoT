/* 
 *  Taller IoT PUCP Verano 2019
 *  Control Remoto activado por voz con Google Assistant, Blynk y IFTTT
 *  
 *  Se usa la libreria IRremoteESP8266 para hacer el envío de los pulsos
 *  con la codificación necesaria para prender un televisor AOC que usa
 *  la codificación RC6.
 *  
 *  Para decodificar los códigos se usa el archivo de ejemplo IRrecvDumpV2
 *  dentro de la misma librería.
 *  
 *  Se usa Blynk como intermediario entre IFTTT y la placa para su conexión
 *  mediante la API de Blynk, lo cual nos permite interactuar con la placa solo
 *  sabiendo su token generado.
 *  
 *  IFTTT se encarga de enviar a la placa una actualización a uno de los pines
 *  virtuales que usa Blynk para que se mande una señal correspondiente.
 */

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
  Serial.println("Se uso el pin V1");

  irsend.sendRC6(0xD, 20, 2); // Se envía la señal D en codificación RC6 repetida 2 veces
}

// Pin V2 de subir volumen (se tiene como parámetro la cantidad de volumen a subir)
BLYNK_WRITE(V2) {
  Serial.println("Se uso el pin V2");

  int veces = param.asInt(); // Cantidad de volumen a subir
  bool cambio = false; // Bit de cambio (característica de la codificación RC6)

  for (int i = 0; i < veces; i++) {
    if (cambio) irsend.sendRC6(0x10, 20);
    else irsend.sendRC6(irsend.toggleRC6(0x10, 20)); Se usa una función de la librería para cambiar la información que se envía
    cambio = !cambio;
    delay(200);
  }
}

// Pin V3 de bajar volumen (se tiene como parámetro la cantidad de volumen a bajar)
BLYNK_WRITE(V3) {
  Serial.println("Se uso el pin V3");

  int veces = param.asInt(); // Cantidad de volumen a subir
  bool cambio = false; // Bit de cambio (característica de la codificación RC6)

  for (int i = 0; i < veces; i++) {
    if (cambio) irsend.sendRC6(0x11, 20);
    else irsend.sendRC6(irsend.toggleRC6(0x11, 20)); // Se usa una función de la librería para cambiar la información que se envía
    cambio = !cambio;
    delay(200);
  }
}

// Pin V4 de subir canal
BLYNK_WRITE(V4) {
  Serial.println("Se uso el pin V4");

  irsend.sendRC6(0x20, 20);
}

// Pin V5 de bajar canal
BLYNK_WRITE(V5) {
  Serial.println("Se usó el pin V5");

  irsend.sendRC6(0x21, 20);
}

void loop()
{
  // Se mantiene la conexión con Blynk
  Blynk.run();
}
