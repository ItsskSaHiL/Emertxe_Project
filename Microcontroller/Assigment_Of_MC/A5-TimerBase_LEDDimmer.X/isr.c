/*
 * File : isr.c
 * Name : Sk Sahil
 */
#include <xc.h>
#include "main.h"

extern unsigned short duty_cycle;

void __interrupt() isr(void)
{
    static unsigned int loop_counter = 0;
    /* Using Timer 0 for making the PWM */
       
    if (TMR2IF == 1)
    {     
        
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
        
        TMR2IF = 0;
     }
}