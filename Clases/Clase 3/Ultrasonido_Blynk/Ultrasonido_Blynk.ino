/*
 * Taller IoT PUCP Verano 2019
 * Clase 3: Ultrasonido_Blynk
 * Actividad: Conexión sensor de ultrasonido a la aplicación Blynk
 */

//Definimos los pines a utilizar del nodeMCU
#define TRIGGER D1 //GPIO5
#define ECHO    D2 //GPIO4


#define BLYNK_PRINT Serial  //Se define que los valores obtenidos se imp Definición para que se impriman los mensajes de Blynk
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Colocar el token de autenticación enviado a sus correos
char auth[] = "  ";

//Se define las credenciales para la conexión WiFi
char ssid[] = "redpucp";
char pass[] = "C9AA28BA93";

void setup() {
  
  Serial.begin (9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {
  
  long duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1;

   if (distance <= 150) {
    Blynk.virtualWrite(V0, 255);
}
  else {
    Blynk.virtualWrite(V0, 0);
  }

 if (distance <= 100) {
    Blynk.virtualWrite(V1, 255);
}
  else {
    Blynk.virtualWrite(V1, 0);
  }

   if (distance <= 80) {
    Blynk.virtualWrite(V2, 255);
}
  else {
    Blynk.virtualWrite(V2, 0);
  }

   if (distance <= 40) {
    Blynk.virtualWrite(V3, 255);
}
  else {
    Blynk.virtualWrite(V3, 0);
  }

   if (distance <= 20) {
    Blynk.virtualWrite(V4, 255);
}
  else {
    Blynk.virtualWrite(V4, 0);
  }

  
  
  Serial.print(distance);
  Serial.println("Centimeter:");
  Blynk.virtualWrite(V5, distance);
  delay(200);
  Blynk.run();
}
