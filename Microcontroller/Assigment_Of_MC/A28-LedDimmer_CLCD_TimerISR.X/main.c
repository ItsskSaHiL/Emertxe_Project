/*
 * File:   main.c
 */

#include <xc.h>
#include "main.h"
#include"adc.h"
#include"timers.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

 
 unsigned char duty_cycle;

 static void init_config(void)
 {
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    PEIE=1;
    GIE=1;
   init_adc();
   init_timer0();
}

void main(void)
{
    init_config();
    
    unsigned int wait = 0;
    while (1) 
    {  
     duty_cycle = (read_adc()/10);  
    }
    return;
}