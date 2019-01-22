/* Taller IoT PUCP Verano 2019
*   CLASE 3: WiFi
*    ACTIVIDAD: Creación de un Servidor Web en el ESP8266
*/

//Se debe agregar las librerias necesarias
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

//Se declara como variable las credenciales de la red WiFi 
char ssid[] = "redpucp";
char password[] = "C9AA28BA93";

bool statusLED = LOW;
int pinLED = D5;

//Se declara una variable tipo Objeto WebServer que escuchará las peticiones http por el puerto 80
ESP8266WebServer server(80);

//Este método se encargará de responder las peticiones http en el directorio raiz 
void handleRoot() {
  Serial.println("Pagina principal");
  String body = "<h1>Bienvenido!!</h1>";
  body += "<p>Auemnta /on a la URL para prender el LED y /off para apagarlo</p>";
  server.send(200, "text/html", body);
}

//Este método se encargará de responder a las demás peticiones que no existan
void handleNotFound() {
  Serial.println("Error");
  server.sendHeader("Location", String("/"), true);
  server.send(302, "text/plain", "");
}

void handleOn() {
  Serial.println("LED encendido");
  statusLED = HIGH;
  digitalWrite(pinLED, statusLED);
  server.sendHeader("Location", String("/"), true);
  server.send(302, "text/plain", "");
}

void handleOff() {
  Serial.println("LED apagado");
  statusLED = LOW;
  digitalWrite(pinLED, statusLED);
  server.sendHeader("Location", String("/"), true);
  server.send(302, "text/plain", "");
}

void setup(){
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, statusLED); // Se inicia el LED en apagado

  Serial.begin(9600); //Se inicializa la comunicación serial
  Serial.println("Servidor para prender LED");

  //Nos conectamos a la red WiFi
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi conectado!");

//Configuramos e inicializamos el servidor web
  server.on(("/"), handleRoot); //Cualquier petición http que se realice en el directorio raiz, se ejecutará el método "handleRequest"
  server.on(("/on"), handleOn);
  server.on(("/off"), handleOff);
  server.onNotFound(handleNotFound); //Para cualquier otra petición http, se ejecutará el método "handleNotFound"
  server.begin();

  Serial.println("Servidor iniciado");
  Serial.println("La IP local es: ");
  Serial.println(WiFi.localIP());
}

void loop(){
  server.handleClient(); //El servidor procesará todas las peticiones que reciba
}
