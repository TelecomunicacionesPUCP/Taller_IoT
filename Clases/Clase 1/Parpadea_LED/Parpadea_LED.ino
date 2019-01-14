/*
Taller IoT PUCP Verano 2019
Parpadea LED

Se enciende un LED por un segundo, luego se apaga por un segundo, repetidamente
*/
 
int led = 2; // asigna una variable al GPIO2 del NODEMCU v3 (Lolin) GPIO2 = D4

// Esta sección corre una vez cuando se enciende el equipo
// y cuando se presiona reset
void setup() {                
  // incializa el pin digital como una salida (OUTPUT)
  pinMode(led, OUTPUT);     
}

// Esta sección se ejectua indefinidamente (LOOP)
void loop() {
  digitalWrite(led, HIGH);   // enciende el LED (el nivel de voltaje es alto = HIGH)
  delay(1000);               // espera un segundo (1000 ms = 1 s)
  digitalWrite(led, LOW);    // apaga el LED (el nivel de voltaje es bajo = LOW)
  delay(1000);               // espera un segundo (1000 ms = 1 s)
}