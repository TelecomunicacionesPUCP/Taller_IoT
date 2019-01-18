//Se debe agregar las librerias necesarias
#include <ESP8266WebServer.h>
#include <ESP8266WebServerSecure.h>
#include <ESP8266WebServerSecureAxTLS.h>
#include <ESP8266WebServerSecureBearSSL.h>

#include <ESP8266WiFi.h>

//Se coloca las credenciales de la red WiFi 
char ssid[] = "redpucp";
char password[] = "C9AA28BA93";

//Se declara una variable tipo Objeto WebServer que escuchará las peticiones http por el puerto 80
ESP8266WebServer server(80);

//Este método se encargará de responder las peticiones http en el directorio raiz 
void handleRequest() {
  Serial.println("Solicitud Recibida");
  String body = "<h1>Bienvenido!!</h1>";
  server.send(200, "text/html", body); //A la variable "server" se le debe pasar como parámetros el código http de respuesta, el tipo 
                                       //de contenido que se enviará en el body y el contenido del body 
}

//Este método se encargará de responder a las demás peticiones que no existan
void handleNotFound() {
  Serial.println("Error");
  String body = "<h1>No se encontro la pagina</h1>";
  server.send(404, "text/html", body); //A la variable "server" se le debe pasar como parámetros el código http de respuesta, el tipo 
                                       //de contenido que se enviará en el body y el contenido del body 
}
void setup(){

  Serial.begin(9600); //Se inicializa la comunicación serial
  Serial.println("Prueba de Servidor");

//Nos conectamos a la red WiFi
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi conectado!");

//Configuramos e inicializamos el servidor web
  server.on(("/"), handleRequest); //Cualquier petición http que se realice en el directorio raiz, se ejecutará el método "handleRequest"
  server.onNotFound(handleNotFound); //Para cualquier otra petición http, se ejecutará el método "handleNotFound"
  server.begin();

  Serial.println("Servidor iniciado");
  Serial.println("La IP local es: ");
  Serial.println(WiFi.localIP());
}

void loop(){
  server.handleClient(); //El servidor procesará todas las peticiones que reciba
}
