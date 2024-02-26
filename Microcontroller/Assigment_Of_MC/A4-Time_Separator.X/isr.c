/*
 * Name : Sk Sahil
 *  Ceating Time Separator  using timer 
 * File : isr.c
 * Date : 04/09/2022
 */
#include <xc.h>
#include "main.h"

void __interrupt() isr(void)
{
    static unsigned int count0 = 0;
    static unsigned int count1 = 0;
    static unsigned int count2 = 0;
    
    if (TMR0IF == 1)
    {
        /* TMR0 Register valur + 6 (offset count to get 250 ticks) + 2 Inst Cycle */
        TMR0 = TMR0 + 8;
        
        if (++count0 == 10000)
        {
            count0 = 0;
            
            LED1  = !LED1 ;
        }
        
        TMR0IF = 0;
    }
    
    // This is for timer1 ISR
    if (TMR1IF == 1)
    {
        /* Again Initilize for get 250 ticks */
        TMR1H = 0xFF;
        // Only change happen in lower bit 
        /* TMR1L value + 5 (0x05 wchich is lower value) + 3(Ins cycle)*/
        TMR1L = TMR1L + 8;
        if (++count1 == 10000)
        {
            count1 = 0;
            
            LED2 = !LED2;
        }
        
        TMR1IF = 0;
    }
    
    // This is for timer2 ISR
    if (TMR2IF == 1)
    {
        if (++count2 == 10000)
        {
            count2 = 0;
            
            LED3 = !LED3;
        }
        
        TMR2IF = 0;
    }
}