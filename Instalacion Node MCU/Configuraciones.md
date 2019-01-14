# Configuración previa para uso del Nodo MCU
Para poder utilizar el Nodo MCU en Arduino IDE es necesario seguir los siguientes paso:

1. Descargar el driver "CH341SER" e instalarlo en la pc.
2. Ingresar a Arduino e ir a Archivo/Preferencias y pegar el siguiente link "http://arduino.esp8266.com/stable/package_esp8266com_index.json" en el cuadro de texto que dice Gestor de URLs Adicionales de Tarjetas.  
3. Ir a Herramientas/"Placa: "/Gestor de tarjetas y buscar "ESP 8266" para su instalación. Este paquete incluye la tarjeta con la que vamos a trabajar.
4. Seleccionar la version 2.4.2 de ESP 8266 e instalarla.
5. Para seleccionar la tarjeta con la que vamos a trabajar, debemos ir a Herramientas y en Placa seleccionar "NodeMCU 1.0 (ESP-12E Module)"
6. Una vez conectada la tarjeta a la PC, no olvidar seleccionar el puerto con el que están trabajando, para ello ir a Herramientas/Puerto.


