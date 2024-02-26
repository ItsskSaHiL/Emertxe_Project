/*
 * File : isr.c
 * Name : Sk Sahil
 */
#include <xc.h>
#include "main.h"
#include "adc.h"

extern unsigned char duty_cycle;

void __interrupt() isr(void)
{
    //static unsigned int duty_cycle;
    static unsigned char loop_counter = 0;
    /* Using Timer 0 for making the PWM */
    
  if (TMR0IF == 1)
  {
        /* TMR0 Register valur + 6 (offset count to get 250 ticks) + 2 Inst Cycle */
        TMR0 = TMR0 + 8;
        
    if (loop_counter <= duty_cycle)
    {
        LED1 = ON;
    }
   else if(loop_counter >= duty_cycle && loop_counter < PERIOD)
    {
        LED1 = OFF;
    }
    if (loop_counter++ == PERIOD)
    {
        loop_counter = 0;
    }
    TMR0IF = 0;
  }
}