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
  
  Serial.begin (9600);  // Se inicialzia la comunicación serial
  Blynk.begin(auth, ssid, pass); // Se inicia la comunicación con Blynk con los datos definidos previamente
  
  //Se define los pines de salida del ultrasonido
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {
  
  //Se define las variables a utilizar
  long duration
  long distance;
  
  digitalWrite(TRIGGER, LOW); 
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH); //El pin D1 comienza a trasmitir, es decir manda una señal por un determinado intervalo de tiempo
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  
  //El comando pulseIn() leerá el pulso del pin 2, esperará que el pulso cambie de Low a High para empezar a medir el tiempo. 
  //Luego esperará a que regrese el pulso a Low para detener el tiempo, esto se debe a que el pulso que medirá será el HIGH
  duration = pulseIn(ECHO, HIGH); //El valor que no da es la longitud del pulso en microsegundos
  
  distance = (duration/2) / 29.1;

   
  //Para el uso de los LEDs, se define condicionales y de acuerdo a la distancia obtenida se prenderá un LED 
  //Los colores del LED se definen en la APP de Blynk
  //Cada LED tendra asignado un pin virtual (V0, V1, V2, V3 y V4)
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

  
  Serial.print(distance); //Se imprime el valor de la distancia
  Serial.println("Centimeter:");
  
  Blynk.virtualWrite(V5, distance); // Uso de un pin virtual V5

  delay(200);
  Blynk.run(); // Se mantiene la conexión con Blynk
}
