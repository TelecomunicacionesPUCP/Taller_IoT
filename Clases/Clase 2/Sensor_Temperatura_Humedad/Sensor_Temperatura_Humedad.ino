/*
 * Taller IoT PUCP Verano 2019
 * Trabajando con un sensor de Temperatura y Humedad 
 */

//Primero se debe incluir las siguientes librerias del sensor DHT
#include <Adafruit_Sensor.h>

#include <DHT.h>
#include <DHT_U.h>

//Se define el tipo de sensor a utilizar, en este caso será el DHT11
#define DHTTYPE DHT11

//Se define el Pin a utilizar, en este caso será el GPIO 2
#define dht_dpin 2

//Se crea una variable tipo Objeto DHT y se le pasa los 2 parámetros definidos previamente
DHT dht(dht_dpin, DHTTYPE); 

//Se inicializa 
void setup(void)
{ 
  dht.begin();
  Serial.begin(9600);
  Serial.println("Humedad y Temperatura\n\n");
  delay(700);

}

void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();         
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
  delay(800);
}
