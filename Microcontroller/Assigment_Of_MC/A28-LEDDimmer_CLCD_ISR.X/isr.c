/*
 * File : isr.c
 * Name : Sk Sahil 
 */
#include <xc.h>
#include "main.h"

/* Using the global variable */
extern unsigned short duty_cycle;         
void __interrupt() isr(void)
{      
    static unsigned int loop_counter = 0;  

    if (TMR0IF == 1)
    {
        TMR0 = TMR0 + 8;         
        /*LED blinking was increasing when we are increasing the Nobe in pot meter*/          
        if(loop_counter < duty_cycle)		                        
        {			               
            LED1 = ON;		            
        }		          
        else if((loop_counter >= duty_cycle) && (loop_counter < PERIOD ))	                
        {						                
            LED1 = OFF;		          
        }			       
        if(loop_counter++ == PERIOD)		            
        {		                 
            loop_counter = 0;		           
        }      
        TMR0IF = 0;       
    }
}