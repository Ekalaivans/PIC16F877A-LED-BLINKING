// PIC16F877A - LED Blink + LED Sequence with Button
// Compiler: XC8
// Device: PIC16F877A
// Clock: 20MHz

// CONFIG
#pragma config FOSC = HS     // High-speed Oscillator
#pragma config WDTE = OFF    // Watchdog Timer disabled
#pragma config PWRTE = OFF   // Power-up Timer disabled
#pragma config BOREN = OFF   // Brown-out Reset disabled
#pragma config LVP = OFF     // Low-Voltage Programming disabled
#pragma config CPD = OFF     // Data EEPROM Code Protection off
#pragma config WRT = OFF     // Flash Program Write disabled
#pragma config CP = OFF      // Code Protection off

#include <xc.h>
#define _XTAL_FREQ 20000000   // 20MHz crystal

// Define LED pins
#define led0 RB0
#define led1 RB1
#define led2 RB2
#define led3 RB3
#define Button RB4   // Button input

void main(void) {
    TRISB0 = 0; // RB0 output
    TRISB1 = 0; // RB1 output
    TRISB2 = 0; // RB2 output
    TRISB3 = 0; // RB3 output
    TRISB4 = 1; // RB4 input (button)

    // Initialize all LEDs OFF
    led0 = led1 = led2 = led3 = 0;

    while(1) {
        if(Button == 0) {  // Button pressed (active low)
            // LED chase effect
            led0 = 1; led1 = 0; led2 = 0; led3 = 0; __delay_ms(200);
            led0 = 0; led1 = 1; led2 = 0; led3 = 0; __delay_ms(200);
            led0 = 0; led1 = 0; led2 = 1; led3 = 0; __delay_ms(200);
            led0 = 0; led1 = 0; led2 = 0; led3 = 1; __delay_ms(200);
            led0 = 0; led1 = 0; led2 = 1; led3 = 0; __delay_ms(200);
            led0 = 0; led1 = 1; led2 = 0; led3 = 0; __delay_ms(200);
            led0 = 1; led1 = 0; led2 = 0; led3 = 0; __delay_ms(200);
        }
        else {
            // Default: simple blink only on RB0
            led0 = 1; __delay_ms(500);
            led0 = 0; __delay_ms(500);
        }
    }
}

