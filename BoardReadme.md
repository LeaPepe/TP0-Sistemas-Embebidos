# Carpeta board


Contiene las librerias y definiciones que se utilizan tanto por la placa (edu ciaa), como por el mismo chip lpc de nxp. Como toda carpeta de archivos C, en general las subcarpetas contienen la carpeta inc, donde van los headers que contienen las descripciones de las funciones y definiciones varias, y la carpeta src que contiene las implementaciones de las funciones descriptas. Adicionalmente contiene un archivo que le dice al compilador donde se encuentran todos los archivos a compilar. 

## lpc_chup_43xx

Esta carpeta contiene las librerias de los drivers que facilita la compania que construye el chip. Los archivos pueden contener: funciones, definiciones de registros, constantes utiles, pines, etc. 
Posee varios modulos utiles, asi como las configuraciones para los distintas caracteristicas que posee el micro. Entre ellas se describen las que, a mi criterio, son las principales:

### Chip

Definiciones propias del chip, ya que esta libreria contiene definiciones de varios chips, entre ellos el 43xx (M0 y M4) o 18xx. Dependiendo de la configuracion del usuario, seran las librerias que se utilicen

### Clock

Posee todo lo necesario para poder inicializar y configurar y realizar lecturas o escrituras en el clock del micro y sus derivados (PLL, divisor). Entre las definiciones principales se pueden destacar:
- Funciones para inicializacion y configuracion del clock, pll, divisor.
- Estructura de la clase PLL, con funciones para configuracion
- Frecuencias de operacion del clock o PLL.
- Habilitar / Deshabilitar clock interno.

###Registros
- eeprom
- rom

### INTERRUPCIONES

Cuenta con diversas librerias de interrupciones, con funciones para inicializar y configurarlos.

- Timers: Alarmas, Cronometros, Repetitivos, etc.
- Real Time Clock: libreria para crear un reloj de tiempo real y otra para hacer pasaje de distintas zonas horarias
- Watchdog:
- Externas

### Comunicacion

- Serial GPIO
- UART
- I2C
- SPI
- Bus CAN
- Ethernet
- USB

### OTROS

 - encriptacion AES
 - Libreria para displays LCD
 - Libreria para manejo de memorias SSD
 - Conversores ADC / DCA

## lpc_startup
 
 Inicializaciones
 
 
## edu_ciaa_nxp
 
 Inicializacion y configuracion de los modulos utilizados en la placa. 