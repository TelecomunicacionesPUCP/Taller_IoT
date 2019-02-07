#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "redpucp";
const char* password = "C9AA28BA93";
const char* host = "maker.ifttt.com";
const char* apiKey = "dvrBskXq99ciGNlLOKRET";


int Status = 12; //Se define el pin a usar, en este caso será el D6 para el Buzzer
int sensor = 13; //Se define el pin a usar, en este caso será el D7 para el PIR

volatile int flag = false;
const char* alarma_state = "apagado";

void AlarmaStatus() {
   alarma_state = "encendido";  
   flag = true;
}

void setup() {
  Serial.begin(9600);

  Serial.print("Conectándose a ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }

  pinMode(sensor, INPUT); // declare sensor as input
  pinMode(Status, OUTPUT);  // declare LED as output
  digitalWrite(Status, 0);
}

void loop(){
  long state = digitalRead(sensor);
  delay(1000);
  
 if (state == HIGH) {
   digitalWrite (Status, 255);
   Serial.println("Movimiento Detectado");
   delay(5000);
 }
 
 else {
   digitalWrite (Status, 0);
   Serial.println("Movimiento no Detectado");
 }

 HTTPClient http;
 String url = host + "/trigger/alarma_intruso/with/key/" + apiKey;;
 http.begin(url);

 int httpCode = http.GET();
 if (httpCode > 0 && httpCode == HTTP_CODE_OK) Serial.println(http.getString());
 else Serial.println("Error conexión");
 http.end();
 
 delay(100);
}
