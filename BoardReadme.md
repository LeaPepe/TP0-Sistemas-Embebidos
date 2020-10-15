# Carpeta board


Contiene las librerias y definiciones que se utilizan tanto por la placa EDU-CIAA, como por el mismo chip lpc de nxp. Como toda carpeta de archivos C, en general las subcarpetas contienen la carpeta inc, donde van los headers que contienen las descripciones de las funciones y definiciones varias; y la carpeta src que contiene las implementaciones de las funciones descriptas. Adicionalmente contiene un archivo que le dice al compilador donde se encuentran todos los archivos a compilar. 

## lpc_chip_43xx

Esta carpeta contiene las librerias de los drivers que facilita la compania que construye el chip. Los archivos en general contienen: funciones, definiciones de registros de uso particular o general, constantes utiles, pines, etc. 
Tambien posee varios modulos utiles que son generalmente utilizados en las aplicaciones de estos micros, asi como las configuraciones para los distintas caracteristicas que posee. 

### Chip

Definiciones propias del chip, ya que esta libreria contiene definiciones de varios chips, entre ellos el 43xx (M0 y M4) o 18xx. Dependiendo de la configuracion del usuario, seran las librerias que se utilicen.

### CMSIS

Cortex Microcontroller Software Interface Standard. Posee definiciones en general, y luego particulares tanto para 18xx como para 43xx.

### Clock 

Posee todo lo necesario para poder inicializar y configurar y realizar lecturas o escrituras en el clock del micro y sus derivados (PLL, divisor). Entre las definiciones principales se pueden destacar:
- Funciones para inicializacion y configuracion del clock, pll, divisor.
- Estructura de la clase PLL, con funciones para configuracion
- Frecuencias de operacion del clock o PLL.
- Habilitar / Deshabilitar clock interno.

### Memoria

- EEPROM [ [Header](board/lpc_chip_43xx/inc/eeprom_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/eeprom_18xx_43xx.c) ].
- ROM  [[H1]](board/lpc_chip_43xx/inc/iap.h) | [H2](board/lpc_chip_43xx/inc/iap_18xx_43xx.h) | Source](board/lpc_chip_43xx/src/iap_18xx_43xx.c)]
- Externa [ [Header](board/lpc_chip_43xx/inc/emc_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/emc_18xx_43xx.c) ].
- Flash [ [Header](board/lpc_chip_43xx/inc/fmc_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/fmc_18xx_43xx.c) ].

### Interrupciones

Cuenta con diversas librerias de interrupciones, con funciones para inicializar y configurarlos.

- Timers [ [Header](board/lpc_chip_43xx/inc/timer_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/timer_18xx_43xx.c) ]. 
- Alarmas [ [Header](board/lpc_chip_43xx/inc/atimer_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/atimer_18xx_43xx.c) ]. 
- Cronometros [ [Header](board/lpc_chip_43xx/inc/atimer_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/atimer_18xx_43xx.c) ]. 
- Repetitivos [ [Header](board/lpc_chip_43xx/inc/ritimer_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/ritimer_18xx_43xx.c) ].
- Watchdog [ [Header](board/lpc_chip_43xx/inc/wwdt_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/wwdt_18xx_43xx.c) ].
- Estado [ [Header](board/sct_chip_43xx/inc/dac_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/sct_18xx_43xx.c) ]
- Eventos [ [Header](board/lpc_chip_43xx/inc/evrt_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/evrt_18xx_43xx.c) ].



### Puertos

- GPIO 
- GPIO group
 - Conversores ADC [ [Header](board/lpc_chip_43xx/inc/adc_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/adc_18xx_43xx.c) ] / DCA [ [Header](board/lpc_chip_43xx/inc/dac_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/dac_18xx_43xx.c) ]. y de alta velocidad HSADC [ [Header](board/lpc_chip_43xx/inc/hsadc_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/hsadc_18xx_43xx.c) ]

### Comunicacion

En general, estas librerias poseen la estructura de los registros, definiciones de mascaras, pines, interrupciones, etc. Funciones de configuracion, inicializacion, lectura, escritura para los distintos tipos de comunicaciones frecuentemente utilizadas.

- UART/USART [ [Header](board/lpc_chip_43xx/inc/uart_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/uart_18xx_43xx.c) ]
- I2C: Posee un [Header](board/lpc_chip_43xx/inc/i2c_common_18xx_43xx.h) general, donde se define la estructura de los registros; y tambien funciones y definiciones para "Master-only" [Header](board/lpc_chip_43xx/inc/i2cm_18xx_43xx.h)|Source(board/lpc_chip_43xx/src/i2cm_18xx_43xx.c)] y "Slave-only" [ [Header](board/lpc_chip_43xx/inc/i2c_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/i2c_18xx_43xx.c) ]. 
- SPI [ [Header](board/lpc_chip_43xx/inc/spi_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/spi_18xx_43xx.c) ].
- Bus CAN [ Header(board/lpc_chip_43xx/inc/ccan_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/ccan_18xx_43xx.c) ].
- Ethernet [ [Header](board/lpc_chip_43xx/inc/enet_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/enet_18xx_43xx.c) ].
- USB [ [Header](board/lpc_chip_43xx/inc/usbhs_18xx_43xx.h)| [Source](board/lpc_chip_43xx/src/usbhs_18xx_43xx.c) ].

### Otros

 - Real Time Clock: [ [Header](board/lpc_chip_43xx/inc/rtc_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/rtc_18xx_43xx.c) ].Driver para un reloj de tiempo, y una libreria para hacer pasaje de distintas zonas horarias [Header](board/lpc_chip_43xx/inc/rtc_ut.h). 
 - encriptacion AES [ [Header](board/lpc_chip_43xx/inc/aes_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/aes_18xx_43xx.c) ]. 
 - Libreria para displays LCD [ [Header](board/lpc_chip_43xx/inc/lcd_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/lcd_18xx_43xx.c) ]. 
 - Libreria para memorias SSD [ [Header](board/lpc_chip_43xx/inc/sdmmc_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/sdmmc_18xx_43xx.c) ]. 
 - PWM [ [Header](board/lpc_chip_43xx/inc/mcpwm_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/mcpwm_18xx_43xx.c) ].
 - Power Management [ [Header](board/lpc_chip_43xx/inc/pmc_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/pmc_18xx_43xx.c) ].
 - Codificador en Cuadratura [ [Header](board/lpc_chip_43xx/inc/qei_18xx_43xx.h) | [Source](board/lpc_chip_43xx/src/qei_18xx_43xx.c) ]

## lpc_startup
 
 Inicializacion de la placa. Utiliza una funcion para inicializar todo lo que se vaya a utilizar en la placa,y ya depende de funciones propias de la EDU-CIAA en este caso, ya que incluye *board.h* .
 
 
## edu_ciaa_nxp
 
 Se definen todos los pines de la placa con sus respectivos nombres (LED, GPIO, I2C, etc.), frecuencias, debug mode, velocidades, etc.
 Tambien se implementan las funciones de inicializacion del lpc_startup, es decir, lo que realiza la placa al iniciar: clock, mux, uart, etc.