/* Taller IoT PUCP Verano 2019
*   CLASE 3: WiFi
*    ACTIVIDAD: Conexión a una red WiFi
*/

//Primero se debe agregar la libreria necesaria
#include <ESP8266WiFi.h>

//Se declara como variables las credenciales de la red WiFi 
const char* ssid     = "redpucp";
const char* password = "C9AA28BA93";

void setup() {
  Serial.begin(9600); //Se inicializa la comunicación serial
  delay(10);
  
  Serial.print("Conectando a ");
  Serial.println(ssid); 
  
  WiFi.mode(WIFI_STA);

  //Nos conectamos a la red WiFi
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Direccion IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  
}
