/*
 * File:   main.c
 */

#include <xc.h>
#include "main.h"
#include"digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

 
 unsigned char duty_cycle = 50;
 unsigned char flag = 1;
 
 void software_pwm(unsigned char key)
 {
    static unsigned char loop_counter;
    static unsigned int wait = 0;
    
    
        if(key == SW1)
        {   
            duty_cycle = 99;
             TMR2IE = 1;
        }
           
    if (loop_counter <= duty_cycle)
    {
        LED1 = ON;
    }
    else
    {
        LED1 = OFF;
    }
    
    if (loop_counter == PERIOD)
    {
        loop_counter = 0;
    }
    
    loop_counter++;
}

 static void init_config(void)
 {
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    
    PEIE=1;
    GIE=1;
   
   init_timer2();
}

void main(void) 
{
    unsigned char key;
    init_config();

    while (1)
    {
        key = read_digital_keypad(STATE);
        for(int i = 200;i--; ); 
        
       // if(flag == 1)
        
          software_pwm(key);
        
       /* if(flag == 2)
        {
          //software_pwm(key);
          flag = 1;
        //  TMR2IE = 0;
        }*/
    }
    return;
}