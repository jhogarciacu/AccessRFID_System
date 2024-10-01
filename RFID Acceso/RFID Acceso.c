#include <16f877a.h>
#fuses HS,NOWDT,NOPROTECT,NOPUT,NOLVP,NOBROWNOUT
#use delay(clock=20M)
#use standard_io(A)
#use standard_io(D)
#use standard_io(B)

//led acceso --> salida
#define led_access PIN_B0                       
#define led_error PIN_B1
#define led_conf PIN_B5

//pines salida --> pantalla lcd
#define LCD_DB4   PIN_D4                        
#define LCD_DB5   PIN_D5
#define LCD_DB6   PIN_D6
#define LCD_DB7   PIN_D7
#define LCD_RS    PIN_D2
#define LCD_E     PIN_D3

// pines entrada --> RFID (comunicación spi)
#define MFRC522_CS  PIN_A0                     
#define MFRC522_SCK PIN_A1                     
#define MFRC522_SI  PIN_A2                     
#define MFRC522_SO  PIN_A3                     
#define MFRC522_RST PIN_A4                     
#include <RC522.h>                              
#include <LCD_16X2.c>                           

char user_1[4] = {0x6B, 0x3A, 0x45, 0x01};      
char user_2[4] = {0x43, 0x89, 0x2D, 0x31};
char user_3[4] = {0xAB, 0x60, 0x3B, 0x01};

char UID[4];                                    
unsigned int TagType;                           // Variable de verificacion de tag

int cardProcessed = 0;                          // Variable de estado de procesamiento de tarjeta

// Función para inicializar el sistema
void system_init() {
   output_low(led_access);                      
   output_low(led_error);
   lcd_init();                                  
   MFRC522_Init();                             
}

// Función para leer y mostrar la UID en la pantalla LCD
void show_UID_on_LCD() {
   lcd_clear();
   lcd_gotoxy(1,1);
   lcd_putc("ID: ");
   lcd_gotoxy(5,1);
   for(int i = 0; i < 4; i++) {
      printf(lcd_putc, "%X", UID[i]);
   }
}

// Función para verificar si el UID coincide con algún usuario
int check_valid_user() {
   return (MFRC522_Compare_UID(UID, user_1) || 
           MFRC522_Compare_UID(UID, user_2) || 
           MFRC522_Compare_UID(UID, user_3));
}

// Función para manejar el acceso correcto
void access_granted() {
   output_high(led_access);
   output_low(led_error);
   lcd_gotoxy(1,2);
   lcd_putc("Bienvenido a Estructuras");
   delay_ms(1000);
   output_low(led_access);
   output_low(led_error);
   lcd_clear();
}

// Función para manejar el acceso denegado
void access_denied() {
   output_high(led_error);
   output_low(led_access);
   lcd_gotoxy(1,2);
   lcd_putc("Acceso Denegado");
   delay_ms(1000);
   output_low(led_access);
   output_low(led_error);
   lcd_clear();
}

// Función principal
void main() {
   system_init();  // Inicializa el sistema

   while(true) {
      lcd_gotoxy(2,1);                          
      lcd_putc("IDENTIFIQUESE");
      output_high(led_conf);
      
      if(MFRC522_isCard(&TagType)) {             // Verificación si hay un tag disponible
         if(MFRC522_ReadCardSerial(&UID)) {      // Lectura y verificación si encontró algún tag
            show_UID_on_LCD();                   // Mostrar la UID en el LCD

            if(!cardProcessed) {                 // Solo procesar si no ha sido procesada
               if(check_valid_user()) {
                  access_granted();              // Acceso correcto
               } else {
                  access_denied();               // Acceso denegado
               }
               cardProcessed = 1;                // Marcar la tarjeta como procesada
            }
            MFRC522_Clear_UID(UID);              // Limpia temporalmente la ID
            delay_ms(100);
         } else {
            cardProcessed = 0;                   // Restablecer el estado si no se detecta ninguna tarjeta
         }
      }
   }
}

