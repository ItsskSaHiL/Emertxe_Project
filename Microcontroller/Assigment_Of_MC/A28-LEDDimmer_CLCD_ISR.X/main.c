/*
 * Name : Sk Sahil 
 * file : main.c
 * Assigment : A28 - Implement a LED dimmer application using PWM (Time ISR Based)
 * Date : 28/09/22
 * Discription : 
 * Problem Statement:
       Implement a LED dimmer application using PWM (Timer ISR Based). The current percentage of brightness  should displayed on the CLCD as Horizontal Bar.

Output Requirements:
      As soon as the board is powered on or reset, The LED should glow with 0% Duty Cycle (i.e OFF) and the CLCD should print the title message on the first line.
      The Increment Brightness Input should increase the Duty Cycle upto 100% (Total ON) which should be reflected on the CLCD as progress bar
      The Decrement Brightness Input should decrease the Duty Cycle to 0% (Total OFF) which should be reflected on the CLCD as progress bar.
Inputs
     MKP1 - Increase Brightness input, Level Triggered
     MKP2 - Decrease Brightness input, Level Triggered

 
 */

#include <xc.h>
#include "main.h"
#include "timers.h"
#include "clcd.h"
#include "matrix_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)
     
/*global variable declaration*/   
unsigned short duty_cycle = 0;     

void init_config(void) {
    LED_ARRAY1 = OFF;
    LED_ARRAY1_DDR = LED_ARRAY1_DDR & 0x3F;    
      
    init_timer0();
    init_clcd();
    init_matrix_keypad();
    /*For print Hard code message in CLCD*/
    clcd_print("LED Brightness", LINE1(0));
    clcd_print("00%->", LINE2(0));
    /* Enable all the Global Interrupts */
    GIE = 1;
}

void main(void) {   
    unsigned char key,val,val2;
    unsigned char str[] = "      ";
    static int i = 5;
    init_config();

    while (1)
    {
        key = read_matrix_keypad(LEVEL);  // 0 1 2 3 4 5 6 7 8 9 '*' '#'  ALL_RELEASED
        
        val = duty_cycle%10;
        val2 = duty_cycle/10;
        
        /*When the MKS1 press then increment in duty cycle also reprent in CLCD */ 
        if(key == 1)
        {
             i = (duty_cycle/10) + 5;
            clcd_putch(val2 + '0', LINE2(0));
            clcd_putch(val + '0', LINE2(1));
            clcd_putch(0xFF, LINE2(i));
            if(duty_cycle < PERIOD)  // Increment For less then period
            {
                duty_cycle++;
                
                //LED1 = !LED1;
              for(int j = 200;j--; );  
            }
        }
        /*When the MKS2 press then decrement in duty cycle also reprent in CLCD */ 
        if(key == 2)
        {
             i = (duty_cycle/10) + 5;
            clcd_putch(val2 + '0', LINE2(0));
            clcd_putch(val + '0', LINE2(1));
            clcd_putch(" ", LINE2(i));
            if(duty_cycle > 0 && duty_cycle <= PERIOD)
            {
                duty_cycle--;
               // LED1 = !LED1;
                for(int j = 200;j--; );  
            }
        }
    }
    return;
}
