#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "redpucp";
const char* password = "C9AA28BA93";
String host = "maker.ifttt.com";
String apiKey = " ";


int Status = 12; //Se define el pin a usar, en este caso será el D6 para el Buzzer
int sensor = 13; //Se define el pin a usar, en este caso será el D7 para el PIR

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
  Serial.println(WiFi.localIP()); //Se obtiene la dirección IP asignada

  pinMode(sensor, INPUT); // declare sensor as input
  pinMode(Status, OUTPUT);  // declare LED as output
  digitalWrite(Status, 0);
}

void loop(){
  long state = digitalRead(sensor);
  
  if (state == HIGH) {
    digitalWrite (Status, 255);
    Serial.println("Movimiento Detectado");
    
    HTTPClient http;
    String url = "http://" + host + "/trigger/alarma_intruso/with/key/" + apiKey;
    Serial.println(url);
    http.begin(url);
  
    int httpCode = http.GET();
    if (httpCode > 0) Serial.println(http.getString());
    else Serial.println("Error conexión");
    http.end();
  }
  
  else {
    digitalWrite (Status, 0);
    Serial.println("Movimiento no Detectado");
  }
 
  delay(5000);
}
