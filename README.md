                               ACCESS SYSTEM

Introducción

Este datasheet mostrará la creación, diseño y funcionamiento del sistema de acceso con todos los pasos y lineamientos que se obtuvieron en el proceso de la realización de este.

Funcionamiento

Este proyecto consiste en el desarrollo de un sistema de acceso utilizando la antena RFID RC522 y tarjetas compatibles, implementado con un microcontrolador PIC16F877A. La placa del circuito fue diseñada y fabricada desde cero mediante una máquina CNC 3018. El sistema funciona leyendo el UID de la tarjeta mediante la antena RFID; si el UID es válido, se concede el acceso, encendiendo un LED verde e imprimiendo en una pantalla un mensaje de "Acceso Permitido". En caso de que el UID sea inválido, se deniega el acceso, encendiendo un LED rojo y mostrando en la pantalla "Acceso Denegado"

Alcances de esta aplicación

Este proyecto ofrece una solución altamente eficiente y de fácil instalación, ideal para su implementación en entornos industriales. Su diseño compacto y su capacidad de respuesta rápida permiten la recepción de datos de manera fluida y ágil. Esto lo convierte en una opción perfecta para grandes empresas, donde el alto volumen de empleados requiere un sistema de acceso que minimice tiempos de espera. Al utilizar nuestra solución, los trabajadores podrán ingresar a la empresa de manera rápida y sin demoras, optimizando el flujo de entrada y mejorando la experiencia general

Beneficios

En términos de seguridad, este sistema de acceso es altamente efectivo, ya que solo permitirá el ingreso a usuarios previamente registrados en la base de datos. Además, facilitará el control de las horas de llegada de los empleados, gracias a su rápida capacidad de respuesta, evitando así filas y tiempos de espera prolongados. El sistema también permitirá llevar un control preciso de los accesos, registrando si el trabajador se presentó ese día o si llegó en un horario diferente al establecido

Componentes

Microcontrolador pic16f877a

![pic](https://github.com/user-attachments/assets/905c4dd1-3df3-4ba5-838a-b8b5155ba1cc)

Arquitectura de 8 bits: Basado en la arquitectura Harvard modificada, lo que permite acceso independiente a la memoria de programa y la memoria de datos.
Velocidad del reloj: Opera hasta 20 MHz con un oscilador externo.
Memoria:

14 KB de memoria flash para el almacenamiento del programa.

368 bytes de RAM para datos.

256 bytes de EEPROM para almacenamiento no volátil de datos.

Puertos de entrada/salida:

33 pines de I/O digitales divididos en cinco puertos (PORTA, PORTB, PORTC, PORTD, y PORTE).

Módulos de comunicación:

USART para comunicación serie (RS-232).

SPI y I²C para comunicación síncrona.

Convertidor A/D: 8 canales de 10 bits para convertir señales analógicas a digitales.

Temporizadores: Incluye 3 temporizadores de 8/16 bits (Timer0, Timer1, Timer2).

Interrupciones: Soporta varias fuentes de interrupción como los temporizadores, la comunicación USART, el puerto SPI, y otros eventos internos/externos.

Modos de bajo consumo: Dispone de modo SLEEP para ahorro de energía.

Voltaje de operación: Funciona con un rango de voltaje entre 2V y 5.5V, lo que lo hace compatible con diversas aplicaciones de baja y media potencia.

Programable In-System (ICSP): Se puede programar directamente en la placa, lo que facilita el desarrollo y depuración del sistema.

Antena RFC-522

![RFC-522](https://github.com/user-attachments/assets/7cfc57b7-56a7-4b0d-93ac-7b8dfd11ee8e)

Frecuencia de operación: 13.56 MHz.

Protocolos compatibles: ISO14443A, MIFARE (Classic 1K y 4K, entre otros).

Tensión de operación: 2.5V a 3.3V (aunque es comúnmente utilizado con microcontroladores de 5V con niveladores de voltaje).

Interfaz de comunicación: SPI (Serial Peripheral Interface) es la principal, aunque también soporta I2C y UART.

Distancia de lectura: Aproximadamente 0-6 cm (depende del tipo de tarjeta y las condiciones ambientales).

Velocidad de comunicación: Hasta 10 Mbit/s en SPI.

Corriente en modo de operación: 13-26 mA. Corriente en modo de espera: 10 µA. Temperatura de operación: -20°C a +80°C.
Tamaño: El módulo mide aproximadamente 60 mm x 40 mm.

Compatibilidad con tarjetas MIFARE: Soporta tarjetas MIFARE Classic 1K, MIFARE Classic 4K, y etiquetas ultraligeras (UltraLight).

Regulador LM317

![Regulador](https://github.com/user-attachments/assets/c4bbc4c2-0b73-476c-8f08-9eef97edb05d)

Rango de voltaje de salida ajustable: 1.25V a 37V.

Corriente de salida máxima: 1.5 A (con disipación de calor adecuada).

Tensión de entrada mínima: Necesita al menos 3V más que el voltaje de salida deseado (dropout voltage).

Protección contra sobrecarga: El LM317tiene un limitador de corriente interno que lo protege de sobrecargas.

Protección contra sobrecalentamiento: Incluye un sistema de protección térmica que apaga el regulador si la temperatura es demasiado alta.

Rango de voltaje de entrada: Generalmente hasta 40V.

Precisión de salida: ±1.5% (dependiendo de las resistencias y de la estabilidad de la fuente de entrada).

Requerimiento de componentes externos: Dos resistencias para ajustar el voltaje de salida y un par de condensadores (opcional) para estabilizar el regulador.

Eficiencia: Es menos eficiente que los reguladores conmutados, ya que es un regulador lineal y disipa el exceso de energía en forma de calor.

Disipación de potencia: Necesita un disipador de calor para trabajar con corrientes elevadas o diferencias grandes entre el voltaje de entrada y de salida.

Componentes adicionales:

Tarjetas RFID
Resistencias
Leds
Condensadores
Pantalla LCD
Cristal
Botón

Componentes que actúan como entradas:

El componente principal que actúa como entrada en nuestro sistema de acceso es la antena RC522 y respectivamente tales tarjetas RFID, ya que al acercar las tarjetas a la antena

Componentes que actúan como salidas:

Los componentes que actúan como salidas en nuestro sistema de acceso son los leds y la pantalla LCD que al procesar la señal del microcontrolador este indicará con un led verde si se le da el permiso de acceder y mediante la pantalla LCD imprimir un mensaje de “Acceso permitido” de lo contrario se encenderá un led rojo e imprimiendo en pantalla “Acceso denegado”.

DISEÑO 3D

![caja](https://github.com/user-attachments/assets/0aa611f0-ea0e-4a61-b973-42628ac9220a)

Aqui podemos ver la caja portadora en donde va a ir todo nuestro circuito, se desarrolló con una impresora 3D.


ESQUEMÁTICO

![esquematico](https://github.com/user-attachments/assets/6549615f-16a7-470f-8efc-172405b20c5e)

En esta imagen se puede observar el diseño del esquemático que vamos a obtener al momento de generar nuestra PCB con cada una de las conexiones correspondientes

El circuito de la antena y del regulador de voltaje van por fuera de nuestra PCB pero se dejaron cada uno de los pines indicados para hacer la respectiva conexión con el microcontrolador.


VISUALIZACIÓN 3D

![placa 3D](https://github.com/user-attachments/assets/25faa962-939b-4f6b-b8b7-50461aaa31c2)



DISEÑO PCB

![PCB](https://github.com/user-attachments/assets/f8554c19-1816-44f7-9d7c-8ec77f785825)

CODIGO

Funciones clave

1. show_UID_on_LCD: Función para leer y mostrar la UID en la pantalla LCD (libreria LCD)
2. check_valid_user: Función para verificar si el UID coincide con algún usuario
3. access_granted: Función para manejar el acceso correcto
4. access_denied: Función para manejar el acceso denegado

Conclusión

Nuestro sistema de acceso ofrece una solución eficaz para mejorar la seguridad, con una instalación sencilla y adaptable a diversos sectores empresariales e industriales. Facilita un control eficiente y automatizado de los accesos, permitiendo la gestión segura de las entradas. Además, el sistema está diseñado con la posibilidad de mejorar en el futuro, incorporando una funcionalidad para registrar y verificar el historial de accesos, lo cual aún no se ha implementado pero representa una importante área de mejora en nuestro desarrollo.
