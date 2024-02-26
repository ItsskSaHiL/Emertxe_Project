/*
 * Name : Sk Sahil 
 * File:   main.c
 * Assigment : A30 - Implement a key detection feedback using UART
 * Date : 07/10/2022
 * Discription : 
 * Problem Statement:
 Implement a key detection feedback using UART. The pressed key number should be printed on the serial application.

Output Requirements:
 On a press of any key from digital keypad, a message has to be sent to host system.
 The message should be like ?Switch X Pressed?, where X could range from 1 to 4.
Setup required:
 Host with a serial application (minicom in Linux, Termite in Windows).
 Baud  rate of 9600  rate of 9600, No parity and 8 data bits.
Inputs:
 Digital Keypad.
 */

#include <xc.h>
#include "uart.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void)
{
    init_uart(9600);
    init_digital_keypad();
    
     puts("UART Key Detection\n\r");
}

void main(void) {
    unsigned char key;
    
    init_config();

    while (1)
    {
        key = read_digital_keypad(STATE); //Read the key press
        for(int i = 300;i--; ); //Bouncing effect
        
        /* Check For key Press 1 - 4 */
        if(key == SW1)
        {
            puts("switch 1 is press\n\r");
        }
        if(key == SW2)
        {
            puts("switch 2 is press\n\r");
        }
        if(key == SW3)
        {
            puts("switch 3 is press\n\r");
        }
        if(key == SW4)
        {
            puts("switch 4 is press\n\r");
        }
        
    }
    return;
}
