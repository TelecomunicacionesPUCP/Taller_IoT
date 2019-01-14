/*
 * Taller IoT PUCP Verano 2019
 * Trabajando con un sensor de Temperatura y Humedad 
 */

// Primero se debe incluir las siguientes librerias del sensor DHT
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Se define el tipo de sensor a utilizar, en este caso será el DHT11
#define DHTTYPE DHT11

// Se define el Pin a utilizar, en este caso será el GPIO 2
#define dht_dpin 2

// Se crea una variable tipo Objeto DHT y se le pasa los 2 parámetros definidos previamente
DHT dht(dht_dpin, DHTTYPE); 

void setup(void) { 
  dht.begin();
  Serial.begin(9600); //Inicializando comunicación serial
  Serial.println("Humedad y Temperatura\n\n");
  delay(700);
}

// Con esa función se comenzará a capturar los valores de la Temperatura y Humedad
void loop() {
  //Cada valor capturado se asigna a una respectiva variable
  float h = dht.readHumidity();
  float t = dht.readTemperature();         

  // Se muestran los valores sensados de temperatura y humedad
  Serial.print("Humedad = ");
  Serial.print(h);
  Serial.println("%");
  Serial.print("Temperatura = ");
  Serial.print(t); 
  Serial.println("C");
  Serial.println();
  delay(800);   //Este bucle se repetirá cada 800 ms
}
