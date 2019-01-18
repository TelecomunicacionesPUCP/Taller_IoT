#include <ESP8266WiFi.h>

const char* ssid     = "redpucp";
const char* password = "C9AA28BA93";

void setup() {
  Serial.begin(9600);
  delay(10);
  
  Serial.print("Conectando a ");
  Serial.println(ssid);
  
  WiFi.mode(WIFI_STA);
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
