/*
 * Taller IoT PUCP Verano 2019
 * Clase 3: Temperatura y Humedad con Blynk
 * Actividad: Conexión sensor de temperatura y humedad a la aplicación Blynk
 */

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "e8d42f00376b4722adf9209fefb61ed6";

// Credenciales del WiFi
char ssid[] = "redpucp";
char pass[] = "C9AA28BA93";

#define dht_dpin  2          // Se define el pin a usar, en este caso será el PIN D4 (GPIO 2)

#define DHTTYPE DHT11     // Se define tipo de DHT (DHT11)


DHT dht(dht_dpin, DHTTYPE);
BlynkTimer timer;


void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // o dht.readTemperature(true) para obtener valores en Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Fallo en la lectura del sensor!");
    return;
  }
  Serial.println("Humedad y Temperatura\n");
  Serial.print("Humedad = ");
  Serial.print(h);
  Serial.println("%");
  Serial.print("Temperatura = ");
  Serial.print(t); 
  Serial.println("C");
  Serial.println();
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
}

void setup()
{
  //Se inicializa la comunicación serial
  Serial.begin(9600);

  //Se pasan como parámetros las credenciales del WiFi y el token que vinculará el node con Blynk
  Blynk.begin(auth, ssid, pass);
  

  dht.begin();

  // Timer, llamará a la función cada segundo
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
