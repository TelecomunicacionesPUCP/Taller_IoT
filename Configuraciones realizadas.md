1. Instalar driver "CH341SER" en pc.
2. En arduino, ir a Archivo, preferencias y colocar el siguiente link "http://arduino.esp8266.com/stable/package_esp8266com_index.json"
3. En arduino, ir a Herramientas, "Placa: Arduino/Genuino Uno", Gestor de tarjetas y buscar "ESP 8266". 
4. Instalar la version 2.4.2 de ESP 8266
5. En arduino, ir a Herramientas y seleccionar la placa "NodeMCU 1.0 (ESP-12E Module)"

PROBANDO

1. Ir a Archivo, Ejemplos, Basics, Blink y copiar el archivo y guardarlo como "Test"
2. Para trabajar con el LED interno, modificar donde dice "LED_BUILTIN" y colocar 2 (de GPIO2) haciendo referencia al pin D4
3. Antes de subir el programa, hay que verificar que el puerto con el que se va a trabajar esté seleccionado, para ello ir a 
   Herramientas, Puertos y Seleccionar el puerto.
