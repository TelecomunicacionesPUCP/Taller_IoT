/* Parpadea LED 
Se enciende un LED por un segundo, luego se apaga por un segundo, repetidamente */
 
int led = 2; // asigna una variable al GPIO2 del NODEMCU v3 (Lolin) GPIO2 = D4

// Esta sección corre una vez y cuando se presiona reset 
void setup() {                
  // incializa el pin digital como una salida (OUTPUT)
  pinMode(led, OUTPUT);     
}

// Esta sección se mantiene corriendo una y otra vez por siempre (LOOP)
void loop() {
  digitalWrite(led, HIGH);   // enciende el LED (el nivel de voltaje es alto HIGH)
  delay(1000);               // espera un segundo
  digitalWrite(led, LOW);    // apaga el LED haciendo el nivel de voltaje caer LOW
  delay(1000);               // espera un segundo
}
