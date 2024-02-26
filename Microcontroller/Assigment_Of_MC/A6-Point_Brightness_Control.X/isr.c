/*
 * File:   isr.c
 * Author: Sk Sahil
 *
 * Created on September 14, 2022, 4:28 PM
 */


#include <xc.h>
#include "main.h"

extern unsigned char duty_cycle;
extern unsigned char flag;

void __interrupt() isr(void)
{
    static unsigned long int count = 0;
   //  static unsigned char loop_counter;
       
    if (TMR2IF == 1)
    {     
       // duty_cycle = duty_cycle - 20;
       if(count++ == 40000)
        {
           TMR2IE = 0;
         //  flag = 2;
           duty_cycle = 10;
        }
        TMR2IF = 0;
        
    }
}