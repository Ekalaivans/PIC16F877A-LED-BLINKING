//# PIC16F877A-LED-BLINKING
//Blink the led using the Microchip PIC DEV board(PIC16F877a)
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XSTAL_FREQ 20000000
#define led0 RB0
#define led1 RB1
#define led2 RB2
#define led3 RB3
#define Button RB4

void delay(unsigned int d);

void main(void) 
{
   // TRISB = 0b00001000;           
    TRISB=0x00;
    while(1)
    {
        RB0=1;
        __delay_ms(100);
        RB0=0;
        __delay_ms(100);
      /*  if(RB4==0)
        {
        led0 = 1; led1 = 0; led2 = 0; led3 = 0;
        delay(30);
        
        led0 = 0; led1 = 1; led2 = 0; led3 = 0;
        delay(30);
        
        led0 = 0; led1 = 0; led2 = 1; led3 = 0;
        delay(30);
        
        led0 = 0; led1 = 0; led2 = 0; led3 = 1;
        delay(30);
        
        led0 = 0; led1 = 0; led2 = 0; led3 = 1;
        delay(30);
        
        led0 = 0; led1 = 0; led2 = 1; led3 = 0;
        delay(30);
        
        led0 = 0; led1 = 1; led2 = 0; led3 = 0;
        delay(30);
        
        led0 = 1; led1 = 0; led2 = 0; led3 = 0;
        delay(30);
    }
        else
        {
          led0 = 0; led1 = 0; led2 = 0; led3 = 0;
        }*/
  }
}

void delay(unsigned int d)
{
    int i, j;
    for(i = 0; i < d; i++)
    {
        for(j = 0; j < 1000; j++)
        {
            // Empty loop for delay
        }
    }
}      // it's a simple GPIO program mat that looks complex. dont feel like complex just a i //use one gpio pin only
