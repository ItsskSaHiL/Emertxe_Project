/*
 * File:   isr.c
 * Author: Sk Sahil
 *
 * Created on September 14, 2022, 4:28 PM
 */


#include <xc.h>
#include "main.h"

extern unsigned char duty_cycle;

void __interrupt() isr(void)
{
   // static unsigned long int count = 0;
     static unsigned char loop_counter = 0;
       
    if (TMR2IF == 1)
    {     
        TMR0 = TMR0 + 15;
    if(loop_counter < duty_cycle)		                        
        {			               
            LED1 = ON;		            
        }		          
    else if(loop_counter >= duty_cycle && loop_counter < PERIOD )		                
        {						                
            LED1 = OFF;		          
        }			       
        if(loop_counter++ == PERIOD)		            
        {		                 
            loop_counter = 0;		           
        }      
      
    TMR2IF = 0;
        
    }
}