# Carpeta board


Contiene las librerias y definiciones que se utilizan tanto por la placa EDU-CIAA, como por el mismo chip lpc de nxp. Como toda carpeta de archivos C, en general las subcarpetas contienen la carpeta inc, donde van los headers que contienen las descripciones de las funciones y definiciones varias; y la carpeta src que contiene las implementaciones de las funciones descriptas. Adicionalmente contiene un archivo que le dice al compilador donde se encuentran todos los archivos a compilar. 

## lpc_chup_43xx

Esta carpeta contiene las librerias de los drivers que facilita la compania que construye el chip. Los archivos en general contienen: funciones, definiciones de registros de uso particular o general, constantes utiles, pines, etc. 
Tambien posee varios modulos utiles que son generalmente utilizados en las aplicaciones de estos micros, asi como las configuraciones para los distintas caracteristicas que posee. 

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

- Watchdog:
- Externas

### Comunicacion

En general, estas librerias poseen la estructura de los registros, definiciones de mascaras, pines, interrupciones, etc. Funciones de configuracion, inicializacion, lectura, escritura para los distintos tipos de comunicaciones frecuentemente utilizadas.

- UART/USART [[H](board/lpc_chip_43xx/inc/uart_18xx_43xx.h)|[S](board/lpc_chip_43xx/src/uart_18xx_43xx.c)]
- I2C: Posee un [Header](board/lpc_chip_43xx/src/i2c_common_18xx_43xx.c) general, donde se define la estructura de los registros; y tambien funciones y definiciones para "Master-only" [[H](board/lpc_chip_43xx/inc/i2cm_18xx_43xx.h)|[S](board/lpc_chip_43xx/src/i2cm_18xx_43xx.c)] y "Slave-only" [[H](board/lpc_chip_43xx/inc/i2c_18xx_43xx.h)|[S](board/lpc_chip_43xx/src/i2c_18xx_43xx.c)]. 
- SPI [[H](board/lpc_chip_43xx/inc/spi_18xx_43xx.h)|[S](board/lpc_chip_43xx/src/spi_18xx_43xx.c)].
- Bus CAN [[H](board/lpc_chip_43xx/inc/ccan_18xx_43xx.h)|[S](board/lpc_chip_43xx/src/ccan_18xx_43xx.c)].
- Ethernet [[H](board/lpc_chip_43xx/inc/enet_18xx_43xx.h)|[S](board/lpc_chip_43xx/src/enet_18xx_43xx.c)].
- USB [[H](board/lpc_chip_43xx/inc/usbhs_18xx_43xx.h)|[S](board/lpc_chip_43xx/src/usbhs_18xx_43xx.c)].

### OTROS

 - Real Time Clock: libreria para crear un reloj de tiempo real y otra para hacer pasaje de distintas zonas horarias
 - encriptacion AES
 - Libreria para displays LCD
 - Libreria para manejo de memorias SSD
 - Conversores ADC / DCA

## lpc_startup
 
 Inicializaciones
 
 
## edu_ciaa_nxp
 
 Inicializacion y configuracion de los modulos utilizados en la placa. 